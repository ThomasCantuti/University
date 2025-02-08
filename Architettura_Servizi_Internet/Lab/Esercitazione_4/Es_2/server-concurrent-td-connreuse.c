#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <limits.h>
#ifdef USE_LIBUNISTRING
#include <unistr.h>
#endif
#include "utils.h"
#include "rxb.h"

#define MAX_REQUEST_SIZE (64*1024)

// Gestore del segnale SIGCHLD
void sigchld_handler(int signo) {
    int status;
    (void)signo;

    // Gestione (deallocazione) figli terminati
    while (waitpid(-1, &status, WNOHANG) > 0)
        continue;
}

int main(int argc, char **argv) {
    int err, sd, ns, on;
    pid_t pid_child;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s porta\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Ignoro SIGPIPE
    signal(SIGPIPE, SIG_IGN);

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigchld_handler;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction SIGCHLD");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    // AF_UNSPEC: accetta sia IPv4 che IPv6
    // AF_INET: solo IPv4
    // AF_INET6: solo IPv6
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // Uso getaddrinfo per preparare le strutture dati per la connessione con socket e bind
    if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
        fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    // Creazione socket
    if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Disabilito attesa uscita fase TIME_WAIT prima di riavviare il server
    on = 1;
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Metto in ascolto il server sulla porta specificata
    if (bind(sd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("Errore bind");
        exit(EXIT_FAILURE);
    }

    // Libero memoria allocata da getaddrinfo
    freeaddrinfo(res);

    // Metto il server in ascolto (socket passiva)
    if (listen(sd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Attendo i client
    while (1) {
        printf("Server in ascolto ...\n");
        if ((ns = accept(sd, NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Generazione figlio per gestire la richiesta
        if ((pid_child = fork()) < 0) {
            perror("fork pid_child");
            exit(EXIT_FAILURE);
        }

        if (pid_child == 0) {
            // Processo figlio: gestisce la richiesta
            pid_t pid_n1, pid_n2;
            int status, pipe_n1n2[2];
            const char *end_request = "\n--- END REQUEST ---\n";
            rxb_t rxb;

            // Chiusura socket passiva
            close(sd);

            // Ripristina il comportamento di default per SIGCHLD
            memset(&sa, 0, sizeof(sa));
            sigemptyset(&sa.sa_mask);
            sa.sa_handler = SIG_DFL;
            if (sigaction(SIGCHLD, &sa, NULL) == -1) {
                perror("sigaction SIGCHLD");
                exit(EXIT_FAILURE);
            }

            // Inizializzazione buffer ricezione
            rxb_init(&rxb, MAX_REQUEST_SIZE);

            // Avvio gestione richiesta
            while (1) {
                char nome_vino[1024], anno[1024];
                size_t nome_vino_len, anno_len;
                char filename[PATH_MAX];

                memset(nome_vino, 0, sizeof(nome_vino));
                nome_vino_len = sizeof(nome_vino) - 1;

                // Lettura richiesta dal Client
                if (rxb_readline(&rxb, ns, nome_vino, &nome_vino_len) < 0) {
                    rxb_destroy(&rxb);
                    break;
                }
#ifdef USE_LIBUNISTRING
                if (u8_check((uint8_t*)nome_vino, nome_vino_len) != NULL) {
                    fprintf(stderr, "Richiesta non in utf-8\n");
                    close(ns);
                    exit(EXIT_SUCCESS);
                }
#endif

                memset(anno, 0, sizeof(anno));
                anno_len = sizeof(anno) - 1;
                if (rxb_readline(&rxb, ns, anno, &anno_len) < 0) {
                    rxb_destroy(&rxb);
                    break;
                }
#ifdef USE_LIBUNISTRING
                if (u8_check((uint8_t*)anno, anno_len) != NULL) {
                    fprintf(stderr, "Richiesta non in utf-8\n");
                    close(ns);
                    exit(EXIT_SUCCESS);
                }
#endif

                /* Se necessario, qui si potrebbe inserire una funzione di autorizzazione */
                // if (autorizza(nome_vino, password) != 1) {
                //     char *unauthorized = "Non autorizzato!\n";
                //     write_all(ns, unauthorized, strlen(unauthorized));
                //     write_all(ns, end_request, strlen(end_request));
                //     continue;
                // }

                snprintf(filename, sizeof(filename), "/Users/thomas/Documenti/GitHub/University/Architettura_Servizi_Internet/Lab/Esercitazione_4/Es_2/test.txt");

                // Creazione pipe
                if (pipe(pipe_n1n2) < 0) {
                    perror("creazione pipe");
                    exit(EXIT_FAILURE);
                }

                if ((pid_n1 = fork()) < 0) {
                    perror("fork pid_n1");
                    exit(EXIT_FAILURE);
                }

                if (pid_n1 == 0) {
                    // Nipote 1: esegue 'grep' per cercare 'nome_vino' nel file

                    // Chiusura descrittori non utilizzati
                    close(ns);
                    close(pipe_n1n2[0]);

                    // Redirezione output nipote 1
                    close(1);
                    if (dup(pipe_n1n2[1]) < 0) {
                        perror("dup pipe_n1n2[1]");
                        exit(EXIT_FAILURE);
                    }
                    close(pipe_n1n2[1]);

                    // Esecuzione comando 'grep'
                    execlp("grep", "grep", nome_vino, filename, (char *)NULL);
                    perror("execlp grep nome_vino");
                    exit(EXIT_FAILURE);
                }

                if ((pid_n2 = fork()) < 0) {
                    perror("fork pid_n2");
                    exit(EXIT_FAILURE);
                }

                if (pid_n2 == 0) {
                    // Nipote 2: esegue 'grep' per cercare 'anno' fra i risultati

                    // Chiusura descrittori non utilizzati
                    close(pipe_n1n2[1]);

                    // Redirezione stdin
                    close(0);
                    if (dup(pipe_n1n2[0]) < 0) {
                        perror("dup pipe_n1n2[0]");
                        exit(EXIT_FAILURE);
                    }
                    close(pipe_n1n2[0]);

                    // Redirezione stdout
                    close(1);
                    if (dup(ns) < 0) {
                        perror("dup ns");
                        exit(EXIT_FAILURE);
                    }
                    close(ns);

                    execlp("grep", "grep", anno, (char *)NULL);
                    perror("execlp grep anno");
                    exit(EXIT_FAILURE);
                }

                // Nel processo figlio principale:
                // 1. Chiusura la pipe (descrittori non utilizzati)
                close(pipe_n1n2[0]);
                close(pipe_n1n2[1]);

                // 2. Attesa terminazione nipoti
                waitpid(pid_n1, &status, 0);
                waitpid(pid_n2, &status, 0);

                // Invio messaggio di fine richiesta al Client
                if (write_all(ns, end_request, strlen(end_request)) < 0) {
                    perror("write_all end_request");
                    exit(EXIT_FAILURE);
                }
            }
            // Chiusura connessione figlio
            close(ns); // Commentare se connessione aperta per più richieste
            exit(EXIT_SUCCESS);
        }
        // Chiusura socket padre
        close(ns);
    }
    // Chiusura socket passiva
    close(sd);
    return EXIT_SUCCESS;
}
