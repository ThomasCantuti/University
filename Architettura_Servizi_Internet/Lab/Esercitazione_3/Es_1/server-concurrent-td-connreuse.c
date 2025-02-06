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

void sigchld_handler(int signo) {
    int status;
    (void)signo;
    while (waitpid(-1, &status, WNOHANG) > 0)
        continue;
}

int main(int argc, char **argv) {
    int err, sd, ns, on, pid;
    struct addrinfo hints, *res;
    struct sigaction sa;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s porta\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = sigchld_handler;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction SIGCHLD");
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((err = getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
        fprintf(stderr, "Errore setup indirizzo bind: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }

    if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    on = 1;
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (bind(sd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("Errore bind");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    if (listen(sd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // attendo i client
    while (1) {
        printf("Server in ascolto ...\n");
        if ((ns = accept(sd, NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if ((pid = fork()) < 0) {
            perror("fork pid");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            /* Processo figlio: gestisce la richiesta */
            int status, pid2;
            const char *end_request = "\n--- END REQUEST ---\n";
            char option[MAX_REQUEST_SIZE];
            rxb_t rxb;

            close(sd);

            /* Ripristina il comportamento di default per SIGCHLD */
            memset(&sa, 0, sizeof(sa));
            sigemptyset(&sa.sa_mask);
            sa.sa_handler = SIG_DFL;
            if (sigaction(SIGCHLD, &sa, NULL) == -1) {
                perror("sigaction SIGCHLD");
                exit(EXIT_FAILURE);
            }

            rxb_init(&rxb, MAX_REQUEST_SIZE);
            while (1) {
                size_t option_len;

                memset(option, 0, sizeof(option));
                option_len = sizeof(option) - 1;
                if (rxb_readline(&rxb, ns, option, &option_len) < 0) {
                    rxb_destroy(&rxb);
                    break;
                }
#ifdef USE_LIBUNISTRING
                if (u8_check((uint8_t*)option, option_len) != NULL) {
                    fprintf(stderr, "Richiesta non in utf-8\n");
                    close(ns);
                    exit(EXIT_SUCCESS);
                }
#endif

                if ((pid2 = fork()) < 0) {
                    perror("fork pid2");
                    exit(EXIT_FAILURE);
                }
                /* Nipote 1: esegue 'ps' */
                if (pid2 == 0) {
                    // ridireziono stdout e stderr
                    close(1);
                    if (dup(ns) < 0) {
                        perror("dup");
                        exit(EXIT_FAILURE);
                    }
                    close(ns);

                    if (strlen(option) == 0) {
                        execlp("ps", "ps", (char *)NULL);
                        perror("execlp ps 1");
                        exit(EXIT_FAILURE);
                    } else {
                        execlp("ps", "ps", option, (char *)NULL);
                        perror("execlp ps 2");
                        exit(EXIT_FAILURE);
                    }
                }

                // attesa terminazione figlio (ps)
                wait(&status);

                // invio messaggio di fine richiesta
                if (write_all(ns, end_request, strlen(end_request)) < 0) {
                    perror("write_all end_request");
                    exit(EXIT_FAILURE);
            }
            // chiusura socket attiva figlio
            //close(ns);
            //exit(EXIT_SUCCESS);
        }
        // chiusura socket attiva padre
        close(ns);
    }
    // chiusura socket passiva
    close(sd);
    return EXIT_SUCCESS;
    }
}
