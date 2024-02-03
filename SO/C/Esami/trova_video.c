#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

static volatile sig_atomic_t count = 0;

void handler () {
    printf("Numero di richieste servite: %d\n", count);
    exit(0);
}

int main (int argc, char** argv) {

    int pid, fd, p1p2[2], status;
    char filepath[200], tipo_video[20], data[20];
    char dirRelativa[2];

    // controllo numero argomenti
    if (argc != 2) {
        perror("Errore: numero di argomenti\n");
        exit(1);
    }

    // controllo se dir è directory relativa
    if (argv[1][0] == '/') {
        perror("Errore: dir è directory assoluta\n");
        exit(2);
    }

    // controllo se dir è una directory
    if ( (fd = open(argv[1], __O_DIRECTORY)) < 0 ) {
        perror("Errore: dir non è una directory");
        exit(3);
    }
    close(fd);


    signal(SIGINT, handler);

    while (1) {

        // richiesta data e tipo video
        printf("Inserire data in formato YYYYMM: ");
        scanf("%s", data);
        printf("Inserire tipo video (musicale, tutorial, trailer): ");
        scanf("%s", tipo_video);

        sprintf(filepath, "%s/%s.txt", argv[1], data);
        if ( (fd = open(filepath, O_RDONLY)) < 0 ) {
            perror("Errore: file non leggibile o non esistente\n");
            continue;
        }

        // creo pipe
        if (pipe(p1p2) < 0) {
            perror("P0: errore pipe p1p2\n");
            exit(4);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: fork\n");
            exit(5);
        }
        if (pid == 0) {

            // codice P1
            signal(SIGINT, SIG_DFL);

            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execlp("grep", "grep", tipo_video, filepath, NULL);
            perror("P1: errore grep\n");
            exit(6);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: fork\n");
            exit(7);
        }
        if (pid == 0) {

            // codice P2
            signal(SIGINT, SIG_DFL);

            close(p1p2[1]);
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            execlp("sort", "sort", "-r", "-n", NULL);
            perror("P2: errore sort\n");
            exit(8);
        }

        close(p1p2[0]);
        close(p1p2[1]);
        wait(&status);
        wait(&status);
        count ++;
        
    }

    printf("Numero di richieste servite: %d\n", count);
    return 0;

}