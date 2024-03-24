#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

static volatile sig_atomic_t count = 0;

void handler() {
    printf("Byte ricevuti da P2: %d\n", count);
    exit(0);
}

int main (int argc, char** argv) {

    int pid, fd, p1p2[2], p0p2[2], status, nread;
    char filepath[200], nomeLibro[50], cognome[50], results[200];

    // controllo numero argomenti
    if (argc != 2) {
        printf("Errore: numero di argomenti\n");
        printf("Uso: controllo <dir>\n");
        exit(1);
    }

    // controllo che dir sia cartella e che sia dir assoluta
    if ( (fd = open(argv[1], O_DIRECTORY)) < 0  ) {
        printf("Errore: directory non esistente\n");
        exit(2);
    }
    close(fd);

    if (argv[1][0] != '/') {
        printf("Errore: directory non assoluta\n");
        exit(3);
    }

    // imposto gestione segnale
    signal(SIGINT, handler);

    while (1) {

        printf("Inserire cognome: ");
        scanf("%s", cognome);
        printf("Inserire nome libro: ");
        scanf("%s", nomeLibro);

        if (strcmp(cognome, "fine") == 0 || strcmp(nomeLibro, "fine") == 0) 
            break;
        
        sprintf(filepath, "%s/%s/%s.txt", argv[1], nomeLibro, cognome);

        if ( (fd = open(filepath, O_RDONLY)) < 0 ) {
            printf("%s non leggibile o non esiste\n", filepath);
            continue;
        }
        close(fd);

        // creo pipe
        if (pipe(p1p2) < 0) {
            printf("P0: errore pipe p1p2\n");
            exit(4);
        }
        if (pipe(p0p2) < 0) {
            printf("P0: errore pipe p0p2\n");
            exit(5);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: errore fork\n");
            exit(6);
        }
        if (pid == 0) {
            // codice P1

            // gestione segnale
            signal(SIGINT, SIG_DFL);

            // modifica fd
            close(p0p2[0]);
            close(p0p2[1]);
            close(p1p2[0]);

            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("sort", "sort", "-n", filepath, NULL);
            perror("P1: errore sort\n");
            exit(7);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: errore fork\n");
            exit(8);
        }
        if (pid == 0) {
            // codice P2

            // gestione segnale
            signal(SIGINT, SIG_DFL);

            // modifica fd
            close(p1p2[1]);
            close(p0p2[0]);

            close(0);
            close(1);

            dup(p1p2[0]);
            dup(p0p2[1]);

            close(p1p2[0]);
            close(p0p2[1]);

            execlp("grep", "grep", "ingresso", NULL);
            perror("P2: errore grep\n");
            exit(9);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        close(p0p2[1]);

        wait(&status);

        nread = read(p0p2[0], results, sizeof(results) - 1);
        if (nread < 0) {
            perror("P0: errore read\n");
            exit(10);
        }
        results[nread] = '\0';

        printf("%s\n", results);
        count += nread;
        close(p0p2[0]);
        wait(&status);
    }


    printf("Byte ricevuti da P2: %d\n", count);
    return 0;
}