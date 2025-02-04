#define _POSIX_C_SOURCE 200112L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include "rxb.h"

#define MAX_REQUEST_SIZE 4096

/*
    L'applicazione deve avere la seguente interfaccia:
    server porta
    arv[0] argv[1]
*/
int main (int argc, char *argv[]) {
    int sd, err;
    struct addrinfo hints, *res, *ptr;

    if (argc != 2) {
        fputs("Errore argomenti", stderr);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_flags = AI_PASSIVE;

    err = getaddrinfo(NULL, argv[1], &hints, &res);
    if (err != 0) {
        fprintf(stderr, "Errore getaddrinfo: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sd < 0) {
        fputs("Errore socket", stderr);
        exit(EXIT_FAILURE);
    }

    err = bind(sd, res->ai_addr, res->ai_addrlen);
    if (err < 0) {
        fputs("Errore bind", stderr);
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    err = listen(sd, SOMAXCONN);
    if (err < 0) {
        fputs("Errore listen", stderr);
        exit(EXIT_FAILURE);
    }

    while (1) {
        int ns, pid;
        size_t len;
        rxb_t buffer;
        char nomefile[MAX_REQUEST_SIZE + 1];

        ns = accept(sd, NULL, NULL);
        if (ns < 0) {
            fputs("Errore accept", stderr);
            exit(EXIT_FAILURE);
        }

        // gestione richiesta servizio

        // inizializzo buffer
        rxb_init(&buffer, MAX_REQUEST_SIZE * 2);

        // effettuo readline
        len = sizeof(nomefile);
        err = rxb_readline(&buffer, ns, nomefile, &len);
        if (err < 0) {
            fputs("Errore rxb_readline", stderr);
            exit(EXIT_FAILURE);
        }

        pid = fork();
        if (pid < 0) {
            fputs("Errore fork", stderr);
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // figlio
            close(1);
            err = dup(ns);
            if (err < 0) {
                fputs("Errore dup", stderr);
                exit(EXIT_FAILURE);
            }
            close(ns);

            execlp("head", "head", "-n", "5", nomefile, NULL);
            fputs("Errore execlp", stderr);
            exit(EXIT_FAILURE);
        }
        rxb_destroy(&buffer);

        close(ns);
    }

    close(sd);
}