#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define ROOT_PATH "/home/thomas"

static volatile sig_atomic_t count = 0;

void handler () {
    printf("Numero di richieste servite: %d\n", count);
    exit(0);
}

int main (int argc, char **argv) {

    int pid, fd, status, p1p2[2], p2p3[2], p0p3[2], N, nread;
    char nomeSpettacolo[20], filepath[100], results[50], str_n[50];

    // controllo numero argomenti
    if (argc != 2) {
        printf("Errore: usare trova_spettacoli nomeTeatro\n");
        exit(1);
    }

    // controllo se file esiste ed è leggibile
    sprintf(filepath, "%s/%s", ROOT_PATH, argv[1]);
    if ( (fd = open(filepath, O_RDONLY)) < 0 ) {
        perror("Errore: open file\n");
        exit(2);
    }
    close(fd);

    // gestione segnali P0
    signal(SIGINT, handler);

    while (1) {

        printf("Inserire nome spettacolo: ");
        scanf("%s", nomeSpettacolo);
        printf("Inserire numero di spettacoli da trovare: ");
        scanf("%d", &N);

        if (N == 0) 
            break;
        
        // creo pipe
        if (pipe(p1p2) < 0) {
            perror("P0: errore pipe p1p2\n");
            exit(3);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: errore fork di P1\n");
            exit(4);
        }
        if (pid == 0) {

            // codice P1
            signal(SIGINT, SIG_DFL);
            
            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", nomeSpettacolo, filepath, NULL);
            perror("P1: errore grep\n");
            exit(5);

        }
        
        if (pipe(p2p3) < 0) {
            perror("P0: errore pipe p2p3\n");
            exit(6);
        }
        
        pid = fork();
        if (pid < 0) {
            perror("P0: errore fork di P2\n");
            exit(7);
        }
        if (pid == 0) {

            // codice P2
            signal(SIGINT, SIG_DFL);

            close(p1p2[1]);
            close(p2p3[0]);

            close(0);
            close(1);

            dup(p1p2[0]);
            dup(p2p3[1]);

            close(p1p2[0]);
            close(p2p3[1]);

            execlp("sort", "sort", "-n", NULL);
            perror("P2: errore sort\n");
            exit(8);

        }

        if (pipe(p0p3) < 0) {
            perror("P0: errore pipe p0p3\n");
            exit(9);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: errore fork di P3\n");
            exit(10);
        }
        if (pid == 0) {

            // codice P3
            signal(SIGINT, SIG_DFL);

            close(p1p2[0]);
            close(p1p2[1]);
            close(p2p3[1]);
            close(p0p3[0]);

            close(0);
            close(1);

            dup(p2p3[0]);
            dup(p0p3[1]);
            
            close(p2p3[0]);
            close(p0p3[1]);

            sprintf(str_n, "%d", N);
            execlp("head", "head", "-n", str_n, NULL);
            perror("P3: errore head\n");
            exit(11);

        }

        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p3[0]);
        close(p2p3[1]);
        close(p0p3[1]);
        close(p0p3[1]);

        wait(&status);
        wait(&status);
        wait(&status);

        nread = read(p0p3[0], results, sizeof(results) - 1);
        if (nread < 0) {
            perror("P0: errore read\n");
            exit(12);
        }
        results[nread] = '\0';

        close(p0p3[0]);

        printf("%s\n", results);

        count ++;

    }

    printf("Numero di richieste servite: %d\n", count);
    return 0;
}