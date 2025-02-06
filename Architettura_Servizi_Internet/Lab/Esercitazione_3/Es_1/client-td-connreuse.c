#define _POSIX_C_SOURCE	200809L
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#ifdef USE_LIBUNISTRING
#  include <unistr.h> /* per libunistring */
#endif
#include "rxb.h"
#include "utils.h"

#define MAX_REQUEST_SIZE (64 * 1024)

int main (int argc, char **argv) {
    int err;
    struct addrinfo hints, *res, *ptr;
    char *host_remoto;
    char *servizio_remoto;
    int sd, i = 1;
    rxb_t rxb;

    if (argc < 2) {
        printf("Uso: rps <server> <options>...\n");
        exit(EXIT_FAILURE);
    }

    // Ignora SIGPIPE
    signal(SIGPIPE, SIG_IGN);

    // construzione indirizzo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // risoluzione host
    host_remoto = argv[1];
    servizio_remoto = "52000";
    if ((err = getaddrinfo(host_remoto, servizio_remoto, &hints, &res)) != 0) {
        fprintf(stderr, "Errore risoluzione nome: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    for (ptr = res; ptr != NULL; ptr = ptr->ai_next) {
        // creazione socket
        if ((sd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol)) < 0) {
            perror("Errore creazione socket");
            continue;
        }

        // connessione
        if (connect(sd, ptr->ai_addr, ptr->ai_addrlen) == 0) {
            printf("Connect riuscita al tentativo %d\n", i);
            break;
        }

        perror("Errore connessione");
        close(sd);
        i++;
    }

    if (ptr == NULL) {
        fprintf(stderr, "Errore di connessione: nessun indirizzo corrispondente trovato\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    // Inizializzazione buffer ricezione
    rxb_init(&rxb, MAX_REQUEST_SIZE);

    while (1) {
        char option[4096];

        // Lettura stringa richiesta
        puts("Inserisci opzione per ps: ");
        if (fgets(option, sizeof(option), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        if (strcmp(option, "fine\n") == 0) {
            break;
        }

        // Invio richiesta al server
        if (write_all(sd, option, strlen(option)) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // leggo risposta del server e stampo a video
        while (1) {
            char response[MAX_REQUEST_SIZE];
            size_t response_len;

            memset(response, 0, sizeof(response));
            response_len = sizeof(response) - 1;

            // ricezione risultato
            if (rxb_readline(&rxb, sd, response, &response_len) < 0) {
                rxb_destroy(&rxb);
                perror("Connessione chiusa dal server");
                exit(EXIT_FAILURE);
            }
#ifdef USE_LIBUNISTRING
            // verifico che il testo sia UTF-8
            if (u8_check((uint8_t *)response, response_len) != NULL) {
                fprintf(stderr, "Testo non UTF-8\n");
                close(sd);
                exit(EXIT_FAILURE);
            }
#endif
            // stampo riga letta da server
            printf("%s", response);

            // nuova richiesta al server
            if (strcmp(response, "--- END REQUEST ---") == 0) {
                break;
            }
        }
    }

    // Chiusura socket
    close(sd);
}
