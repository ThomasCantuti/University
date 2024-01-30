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
    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        perror("P0: errore in open");
        exit(3);
    }
    close(fd);

    // imposto la gestione del segnale CTRL-C
    signal(SIGINT, handler);

    while(1) {
        // chiedo <giorno>, <mese>, <anno>
        printf("Inserire giorno mese anno (GG MM YYYY): ");
        scanf("%d %d %d", &gg, &mm, &yyyy);

        if (gg == -1 || mm == -1 || yyyy == -1)
            break;
        else if (gg < 0 || mm < 0 || yyyy < 0) {
            printf("errore: Inserire interi positivi\n");
            continue;
        } else if (gg < 1 || gg > 31) {
            printf("errore: Inserire giorno compresi tra 1 e 31\n");
            continue;
        } else if (mm < 1 || mm > 12) {
            printf("errore: Inserire mese compreso tra 1 e 12 \n");
            continue;
        }

        sprintf(date, "%02d%02d%04d", gg, mm, yyyy);

        // creo pipe
    }

    return 0;
}