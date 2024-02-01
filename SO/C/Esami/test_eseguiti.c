#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait>

static volatile sig_atomic_t count = 0;

void handler () {
    printf("Numero totale di byte ricevuti: %d\n", count);
    exit(0);
}

int main (int argc, char** argv) {

    int pid, p0p1[2], p0p2[2], fd, status, nread, nwrite;
    char filepath[100], nomeRef[50], results[50];

    // controllo argomenti
    if (argc != 3) {
        perror("Errore: argomenti mancanti\n");
        exit(1);
    }

    // controllo se dir è directory relativa
    if (argv[1][0] == "/") {
        perror("Errore: directory non relativa\n");
        exit(2);
    }

    // controllo se dir è direcotory esistente
    if ( (fd = open(argv[1], O_DIRECTORY)) < 0 ) {
        perror("Errore: open directory\n");
        exit(3);
    }
    close(fd);

    //controllo se file esiste
    sprintf(filepath, "%s/%s.txt", argv[1], argv[2]);
    if ( (fd = open(argv[2], O_RDONLY)) < 0 ) {
        perror("Errore: open file\n");
        exit(4);
    }
    close(fd);

    // gestione segnali P0
    signal(SIGINT, handler);

    // creo pipe tra P0 e P1
    if (pipe(p0p1) < 0) {
        perror("P0: pipe p0p1\n");
        exit(5);
    }

    // creo pipe tra P0 e P2
    if (pipe(p0p2) < 0) {
        perror("P0: pipe p0p2\n");
        exit(6);
    }

    if ( (pid = fork()) < 0 ) {
        perror("Errore: fork di P1\n");
        exit(7);
    }
    if (pid == 0) {
        // codice P1

        signal(SIGINT, SIG_DFL);

        close(p0p1[1]);
        close(p0p2[0]);

        while(1) {
            // leggo nome refertatore da terminale
            nread = read(p0p1[0], nomeRef, sizeof(nomeRef) - 1);
            if (nread < 0) {
                perror("P1: read\n");
                exit(8);
            }
            nomeRef[nread] = '\0';

            pid = fork();
            if (pid < 0) {
                perror("P1: fork\n");
                exit(9);
            }
            if (pid == 0) {
                // codice P2

                close(p0p1[0]);

                close(1);
                dup(p0p2[1]);
                close(p0p2[1]);

                execlp("grep", "grep", nomeRef, filepath, NULL);
                perror("P2: grep\n");
                exit(10);
            }

            // attendo terminazione P2
            wait(&status);
        }
    }

    close(p0p1[0]);
    close(p0p2[1]);

    while (1) {
        
        printf("Inserire refertatore: ");
        scanf("%s", nomeRef);

        // P0 invia nome a P1
        nwrite = write(p0p1[1], nomeRef, strlen(nomeRef) + 1);
        if (nwrite != (int)(strlen(nomeRef) + 1)) {
            perror("P0: write\n");
            exit(11);
        }

        // P0 legge e stampa i risultati ricevuti da P2
        nread = read(p0p2[0], results, sizeof(results) - 1);
        if (nread < 0) {
            perror("P0: read\n");
            exit(12);
        }
        results[nread] = '\0';
        printf("%s\n", results);

        // incrementonumero di byte ricevuti
        count += nread;
    }

    return 0;
}