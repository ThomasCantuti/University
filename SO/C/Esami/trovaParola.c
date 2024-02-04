#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

static volatile sig_atomic_t count = 0;


void handler () {
    printf("Numero totale di ricerche: %d\n", count);
    exit(0);
}

int main (int argc, char** argv) {

    int pid, fd, status, p1p2[2];
    char cognome[20], prefisso[5];

    // controllo argmoenti
    if (argc != 2) {
        perror("Errore: numero di argomenti\n");
        exit(1);
    }

    // controllo se fileAnagrafica è assoluto
    if (argv[1][0] != '/') {
        perror("Errore: fileAnagrafica non è nome assoluto\n");
        exit(2);
    }

    // controllo se fileAnagrafica esiste ed è leggibile
    if ( (fd = open(argv[1], O_RDONLY)) < 0 ) {
        perror("Errore: file non esistente o non leggibile\n");
        exit(3);
    }

    // gestione segnale CTRL-C padre
    signal(SIGINT, handler);

    while (1) {

        printf("Inserire cognome: ");
        scanf("%s", cognome);
        printf("Inserire prefisso telefonico: ");
        scanf("%s", prefisso);

        if (strcmp(cognome, "fine") == 0 || strcmp(prefisso, "fine") == 0) {
            break;
        }

        // creo pipe
        if ( pipe(p1p2) < 0 ) {
            perror("P0: errore pipe p1p2\n");
            exit(4);
        }

        if ( (pid = fork()) < 0 ) {
            perror("P0: errore fork\n");
            exit(5);
        }
        if (pid == 0) {
            // codice P1
            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            signal(SIGINT, SIG_DFL);

            execlp("grep", "grep", cognome, argv[1], NULL);
            perror("P1: errore grep\n");
            exit(6);
        }

        if ( (pid = fork()) < 0 ) {
            perror("P0: errore fork\n");
            exit(7);
        }
        if (pid == 0) {
            // codice P2
            close(p1p2[1]);
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            signal(SIGINT, SIG_DFL);

            execlp("grep", "grep", prefisso, NULL);
            perror("P1: errore grep\n");
            exit(8);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        
        wait(&status);
        wait(&status);

        count ++;
    }


    printf("Numero totale di ricerche: %d\n", count);
    return 0;
}