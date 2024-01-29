#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define ROOT_PATH "/var/local/ticket"

static volatile sig_atomic_t count = 0;

void handler () {
    printf("Numero di richieste servite: %d\n", count);
    exit(0);
}

int main (int argc, char** argv) {

    int fd, n, gg, mm, yyyy, p1p2[2], p2p3[2], pid, status;
    char *filepath, *date;

    // controllo che il numero dei parametri sia corretto
    if (argc != 3) {
        printf("errore: numero sbagliato di parametri\n");
        printf("uso: trova_biglietti <destinazione> <n>\n");
        exit(1);
    }

    // controllo che n sia intero positivo
    if ( (n = atoi(argv[2])) <= 0 ) {
        printf("errore: <n> deve essere un intero positivo\n");
        exit(2);
    }

    // controllo che <destinazione> esista
    sprintf(filepath, "%s/%s.txt", ROOT_PATH, argv[1]);

    return 0;
}