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

int main (int argc, char **argv) {
    int err, sd, i = 1;
    struct addrinfo hints, *res, *ptr;
    rxb_t rxb;
    char *server, *porta;

    if (argc != 3) {
        fprintf(stderr, "Uso: %s server porta\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    server = argv[1];
    porta = argv[2];
    if ((err = getaddrinfo(server, porta, &hints, &res)) != 0) {
        fprintf(stderr, "Errore risoluzione indirizzo %s: %s\n", server, gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0) {
            printf("Connessione riuscita al tentativo %d\n", i);
            break;
        }

        i ++;
        close(sd);
    }

    if (ptr == NULL) {
        fprintf(stderr, "Errore connessione\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    rxb_init(&rxb, MAX_REQUEST_SIZE);

    while (1) {
        char tipo_sensore[1024], nome_stanza[1024], N_letture[1024];

        puts("Inserire tipo di sensore ('fine' per terminare): ");
        if (fgets(tipo_sensore, sizeof(tipo_sensore), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(tipo_sensore, "fine\n") == 0) {
            printf("Ricevuto 'fine' ... terminazione\n");
            break;
        }

        puts("Inserire nome stanza ('fine' per terminare): ");
        if (fgets(nome_stanza, sizeof(nome_stanza), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(nome_stanza, "fine\n") == 0) {
            printf("Ricevuto 'fine' ... terminazione\n");
            break;
        }

        puts("Inserire numero di letture ('fine' per terminare): ");
        if (fgets(N_letture, sizeof(N_letture), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(N_letture, "fine\n") == 0) {
            printf("Ricevuto 'fine' ... terminazione\n");
            break;
        }

        if (write_all(sd, tipo_sensore, strlen(tipo_sensore)) < 0) {
            perror("write_all");
            exit(EXIT_FAILURE);
        }
        if (write_all(sd, nome_stanza, strlen(nome_stanza)) < 0) {
            perror("write_all");
            exit(EXIT_FAILURE);
        }
        if (write_all(sd, N_letture, strlen(N_letture)) < 0) {
            perror("write_all");
            exit(EXIT_FAILURE);
        }

        while (1) {
            char response[MAX_REQUEST_SIZE];
            size_t response_len = sizeof(response) - 1;
            memset(response, 0, sizeof(response));

            if (rxb_readline(&rxb, sd, response, &response_len) < 0) {
                rxb_destroy(&rxb);
                close(sd);
                exit(EXIT_FAILURE);
            }

#ifdef USE_LIBUNISTRNG
            if (u_8check((uint8_t *) response, response_len) != NULL) {
                fprintf(stderr, "Risposta non in UTF-8\n");
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
