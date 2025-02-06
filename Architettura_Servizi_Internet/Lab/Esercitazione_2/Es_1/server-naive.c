#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// gestore segnale SIGCHLD
void handler(int signo) {
    int status;
    (void)signo; // per evitare warning
    // eseguo wait non bloccanti finché ci sono processi figli terminati
    while (waitpid(-1, &status, WNOHANG) > 0)
        continue;
}

/*
    L'applicazione deve avere la seguente interfaccia:
    server porta
    arv[0] argv[1]
*/
int main (int argc, char **argv) {
    int sd, err, on;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc != 2) {
        fprintf(stderr, "Sintassi: %s porta\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // ignoro SIGPIPE
    signal(SIGPIPE, SIG_IGN);
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handler;

    if (sigaction(SIGCHLD, &sa, NULL) < 0) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // preparo direttive getaddrinfo
    memset(&hints, 0, sizeof(hints));
    // Uso AF_INET per forzare solo IPv4, AF_INET6 per forzare solo IPv6
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // uso getaddrinfo per preparare le strutture dati per la connessione con socket e bind
    if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
        fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    // creo socket
    if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        fputs("Errore socket", stderr);
        exit(EXIT_FAILURE);
    }

    // disabilito attesa uscita fase TIME_WAIT prima di riavvio server
    on = 1;
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        fputs("Errore setsockopt", stderr);
        exit(EXIT_FAILURE);
    }

    // metto in ascolto il server sulla porta specificata
    if ((bind(sd, res->ai_addr, res->ai_addrlen)) < 0) {
        fputs("Errore bind", stderr);
        exit(EXIT_FAILURE);
    }

    // libero memoria allocata da getaddrinfo
    freeaddrinfo(res);

    // metto il server in ascolto (socket passiva)
    if ((listen(sd, SOMAXCONN)) < 0) {
        fputs("Errore listen", stderr);
        exit(EXIT_FAILURE);
    }

    while (1) {
        int ns, pid, nread;

        // attendo richiesta di connessione
        if ((ns = accept(sd, NULL, NULL)) < 0) {
            fputs("Errore accept", stderr);
            exit(EXIT_FAILURE);
        }

        // creo processo figlio per gestire la richiesta
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // figlio
            char str1[4096], str2[4096], response[80];
            const char *ack = "ACK";

            // chiudo socket passiva
            close(sd);

            // leggo la prima stringa
            /* Inizializzo il buffer a zero e leggo sizeof(str1)-1
            * byte, così sono sicuro che il contenuto del buffer
            * sarà sempre null-terminated. In questo modo, posso
            * interpretarlo come una stringa C e passarlo
            * direttamente alla funzione strcmp. */
            memset(str1, 0, sizeof(str1));
            if ((nread = read(ns, str1, sizeof(str1) - 1)) < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // invio ACK al client
            if (write(ns, ack, strlen(ack)) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            // stesso procedimento per la seconda stringa
            memset(str2, 0, sizeof(str2));
            if ((nread = read(ns, str2, sizeof(str2) - 1)) < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // preparazione buffer con risposta
            if (strcmp(str1, str2) == 0)
                strncpy(response, "SI", sizeof(response));
            else
                strncpy(response, "NO", sizeof(response));

            // invio risposta al client
            if (write(ns, response, strlen(response)) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            // chiudo socket attiva
            close(ns);

            // termino processo figlio
            exit(EXIT_SUCCESS);
        }

        // padre

        // chiudo socket attiva
        close(ns);
    }

    close(sd);
}
