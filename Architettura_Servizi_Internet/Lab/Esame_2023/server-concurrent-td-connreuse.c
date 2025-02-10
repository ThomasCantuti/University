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
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_REQUEST_SIZE (64*1024)

void sigchld_handler (int signo) {
    int status;
    (void)signo;

    while (waitpid(-1, &status, WNOHANG) > 0)
        continue;
}

int main (int argc, char **argv) {
    int err, sd, ns, on;
    pid_t pid_child;
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

    while (1) {
        printf("Server in ascolto ...\n");
        if ((ns = accept(sd, NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if ((pid_child = fork()) < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid_child == 0) {
            pid_t pid_n1, pid_n2;
            int status, pipe_n1n2[2];
            const char *end_request = "\n--- END REQUEST ---\n";
            rxb_t rxb;

            close(sd);
            memset(&sa, 0, sizeof(sa));
            sigemptyset(&sa.sa_mask);
            sa.sa_handler = sigchld_handler;
            if (sigaction(SIGCHLD, &sa, NULL) == -1) {
                perror("sigaction SIGCHLD");
                exit(EXIT_FAILURE);
            }

            rxb_init(&rxb, MAX_REQUEST_SIZE);

            while (1) {
                char tipo_sensore[1024], nome_stanza[1024], N_letture[1024];
                size_t tipo_sensore_len, nome_stanza_len, N_letture_len;
                char filename[PATH_MAX];

                memset(tipo_sensore, 0, sizeof(tipo_sensore));
                tipo_sensore_len = sizeof(tipo_sensore) - 1;

                if (rxb_readline(&rxb, ns, tipo_sensore, &tipo_sensore_len) < 0) {
                    rxb_destroy(&rxb);
                    break;
                }
#ifdef USE_LIBUNISTRNG
                if (u_8check((uint8_t *) tipo_sensore, tipo_sensore_len) != NULL) {
                    fprintf(stderr, "Risposta non in UTF-8\n");
                    close(sd);
                    exit(EXIT_FAILURE);
                }
#endif

                memset(nome_stanza, 0, sizeof(nome_stanza));
                nome_stanza_len = sizeof(nome_stanza) - 1;

                if (rxb_readline(&rxb, ns, nome_stanza, &nome_stanza_len) < 0) {
                    rxb_destroy(&rxb);
                    break;
                }
#ifdef USE_LIBUNISTRNG
                if (u_8check((uint8_t *) nome_stanza, nome_stanza_len) != NULL) {
                    fprintf(stderr, "Risposta non in UTF-8\n");
                    close(sd);
                    exit(EXIT_FAILURE);
                }
#endif

                memset(N_letture, 0, sizeof(N_letture));
                N_letture_len = sizeof(N_letture) - 1;

                if (rxb_readline(&rxb, ns, N_letture, &N_letture_len) < 0) {
                    rxb_destroy(&rxb);
                    break;
                }
#ifdef USE_LIBUNISTRNG
                if (u_8check((uint8_t *) N_letture, N_letture_len) != NULL) {
                    fprintf(stderr, "Risposta non in UTF-8\n");
                    close(sd);
                    exit(EXIT_FAILURE);
                }
#endif

                // ./var/letture_sensori/nome_stanza.txt --> sarebbe quello corretto ma uso il percorso relativo del file per testing
                snprintf(filename, sizeof(filename), "/Users/thomas/Documenti/GitHub/University/Architettura_Servizi_Internet/Lab/Esame_2023/letture_sensori/%s.txt", nome_stanza);

                if (pipe(pipe_n1n2) < 0) {
                    perror("creazione pipe");
                    exit(EXIT_FAILURE);
                }

                if ((pid_n1 = fork()) < 0) {
                    perror("fork pid_n1");
                    exit(EXIT_FAILURE);
                }
                if (pid_n1 == 0) {
                    close(ns);
                    close(pipe_n1n2[0]);

                    close(1);
                    if (dup(pipe_n1n2[1]) < 0) {
                        perror("dup pipe");
                        exit(EXIT_FAILURE);
                    }
                    close(pipe_n1n2[1]);

                    execlp("grep", "grep", tipo_sensore, filename, (char *)NULL);
                    perror("execlp");
                    exit(EXIT_FAILURE);
                }

                if ((pid_n2 = fork()) < 0) {
                    perror("fork pid_n2");
                    exit(EXIT_FAILURE);
                }
                if (pid_n2 == 0) {
                    close(pipe_n1n2[1]);

                    close(0);
                    if (dup(pipe_n1n2[0]) < 0) {
                        perror("dup pipe");
                        exit(EXIT_FAILURE);
                    }
                    close(pipe_n1n2[0]);

                    close(1);
                    if (dup(ns) < 0) {
                        perror("dup ns");
                        exit(EXIT_FAILURE);
                    }
                    close(ns);

                    execlp("tail", "tail", "-n", N_letture, (char *)NULL);
                    perror("tail");
                    exit(EXIT_FAILURE);
                }

                close(pipe_n1n2[0]);
                close(pipe_n1n2[1]);

                waitpid(pid_n1, &status, 0);
                waitpid(pid_n2, &status, 0);

                if (write_all(ns, end_request, strlen(end_request)) < 0) {
                    perror("write_all");
                    exit(EXIT_FAILURE);
                }
            }
            close(ns);
            exit(EXIT_SUCCESS);
        }
        close(ns);
    }
    close(sd);
    return EXIT_SUCCESS;
}
