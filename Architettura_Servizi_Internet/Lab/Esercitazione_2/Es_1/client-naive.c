#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE (64*1024)

/*
*    L'applicazione deve avere la seguente interfaccia:
*    rstrcmp hostname porta   stringa1 stringa2
*    arv[0]  argv[1]  argv[2] argv[3]  argv[4]
*/
int main(int argc, char **argv) {
    int sd, err, nread;
    uint8_t buffer[4096];
    struct addrinfo hints, *res, *ptr;

    if (argc != 5) {
        fputs("Errore argomenti", stderr);
        exit(EXIT_FAILURE);
    }

    /* ignoro SIGPIPE */
	signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    err = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (err != 0) {
        fprintf(stderr, "Errore getaddrinfo: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    // connessione con fallback
    for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
        sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        // se socket fallisce, passo all'indirizzo successivo
        if (sd < 0) continue;

        // se connect ha successo, esco dal ciclo
        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0) break;

        // altrimenti chiudo il socket e passo all'indirizzo successivo
        close(sd);
    }

    // controllo che effettivamente il client sia connesso
    if (ptr == NULL) {
        fputs("Errore connessione", stderr);
        exit(EXIT_FAILURE);
    }

    // libero la memoria allocata da getaddrinfo
    freeaddrinfo(res);

    // invio prima stringa
    if (write(sd, argv[3], strlen(argv[3])) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // attendo ACK dal server
    if (read(sd, buffer, sizeof(buffer)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // invio seconda stringa
    if (write(sd, argv[4], strlen(argv[4])) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // attendo risultato (ACK) dal server
    while ((nread = read(sd, buffer, sizeof(buffer))) > 0) {
        if (write(1, buffer, nread) < 0) {
            perror("write su stdout");
            exit(EXIT_FAILURE);
        }
    }

    // controllo errori in lettura
    if (nread < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // stampo un newline prima di terminare
    if (write(1, "\n", 1) < 0) {
        perror("write su stdout");
        exit(EXIT_FAILURE);
    }

    // chiudo la connessione
    close(sd);

    return 0;
}
