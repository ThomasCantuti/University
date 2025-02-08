#define _POSIX_C_SOURCE 200809L
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#ifdef USE_LIBUNISTRNG
#include <unistr.h>
#endif
#include "rxb.h"
#include "utils.h"

#define MAX_REQUEST_SIZE (64*1024)

int main(int argc, char **argv) {
    int err, sd, i = 1;
    struct addrinfo hints, *res, *ptr;
    rxb_t rxb;
    char *server, *porta;

    if (argc < 3) {
        fprintf(stderr, "Uso: %s server porta\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Ignora SIGPIPE per evitare crash in caso di scrittura su socket chiuso */
    signal(SIGPIPE, SIG_IGN);

    // Construzione dell'indirizzo a cui connettersi
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Risoluzione dell'host
    server = argv[1];
    porta = argv[2];
    if ((err = getaddrinfo(server, porta, &hints, &res)) != 0) {
        fprintf(stderr, "Errore risoluzione indirizzo %s: %s\n", server, gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    // Connessione con fallback
    for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
        // Se socket fallisce --> salto alla prossima iterazione di ptr
        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0) {
            perror("socket");
            continue;
        }
        // Se connect ha successo --> esco dal ciclo
        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0) {
            printf("Connessione riuscita al tentativo %d\n", i);
            break;
        }
        i++;
        close(sd);
    }

    // Verifica risultato restituito da getaddrinfo
    if (ptr == NULL) {
        fprintf(stderr, "Errore connessione\n");
        exit(EXIT_FAILURE);
    }

    // Liberazione risorse
    freeaddrinfo(res);

    // Inizializzazione buffer di ricezione
    rxb_init(&rxb, MAX_REQUEST_SIZE);

    while (1) {
        char categoria[4096];

        puts("Inserire la categoria ('fine' per terminare):");
        if (fgets(categoria, sizeof(categoria), stdin) == NULL) {
            perror("fgets categoria");
            exit(EXIT_FAILURE);
        }

        if (strcmp(categoria, "fine\n") == 0) {
            printf("Ricevuto 'fine' ... terminazione\n");
            break;
        }

        if (write_all(sd, categoria, strlen(categoria)) < 0) {
            perror("write categoria");
            exit(EXIT_FAILURE);
        }

        /* Leggo la risposta del server riga per riga */
        while (1) {
            char response[MAX_REQUEST_SIZE];
            size_t response_len = sizeof(response) - 1;
            memset(response, 0, sizeof(response));

            if (rxb_readline(&rxb, sd, response, &response_len) < 0) {
                fprintf(stderr, "Connessione chiusa dal server\n");
                rxb_destroy(&rxb);
                close(sd);
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRNG
            if (u_8check((uint8_t *)response, response_len) != NULL) {
                fprintf(stderr, "Risposta non in utf-8\n");
                close(sd);
                exit(EXIT_FAILURE);
            }
#endif
            puts(response);
            if (strcmp(response, "--- END REQUEST ---") == 0)
                break;
        }
    }

    close(sd);
    return EXIT_SUCCESS;
}
