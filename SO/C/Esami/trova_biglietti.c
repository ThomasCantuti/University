#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
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
    char *filepath, *date, str_n;

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

        // creo pipe di comunicazione per p1p2
        if (pipe(p1p2) < 0) {
            perror("P0: pipe p1p2");
            exit(4);
        }

        // creo pipe di comunicazione per p2p3
        if (pipe(p2p3) < 0) {
            perror("P0: pipe p2p3");
            exit(5);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: fork P1");
            exit(6);
        }
        if (pid == 0) {
            // codice di P1

            // imposto segnale SIGINT gestito come default
            signal(SIGINT, SIG_DFL);

            // chiusura pipe tra P2 e P3
            close(p2p3[0]);
            close(p2p3[1]);

            // chiudo p1p2 in lettura e stdout
            close(p1p2[0]);
            close(1);

            // redirezione stdout -> p1p2[1]
            dup(p1p2[1]);

            // chiudo p1p2[1] ad indice 4
            close(p1p2[1]);

            // seleziona le offerte con la data richiesta
            execlp("grep", "grep", date, filepath, NULL);
            perror("P1: grep");
            exit(7);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: fork P2");
            exit(8);
        }
        if (pid == 0) {
            // codice di P2

            // imposto segnale SIGINT gestito come default
            signal(SIGINT, SIG_DFL);

            close(p1p2[1]);
            close(p2p3[0]);

            close(0);
            close(1);

            dup(p1p2[0]);
            dup(p2p3[1]);

            close(p1p2[0]);
            close(p2p3[1]);

            // ordino biglietti dal più economico
            execlp("sort", "sort", "-n");
            perror("P2: sort");
            exit(9);
        }

        pid = fork();
        if (pid < 0) {
            perror("P0: fork P3");
            exit(10);
        }
        if (pid == 0) {
            // codice di P3

            // imposto segnale SIGINT gestito come default
            signal(SIGINT, SIG_DFL);

            close(p1p2[0]);
            close(p1p2[1]);

            close(p2p3[1]);
            close(0);

            dup(p2p3[0]);
            close(p2p3[0]);

            // restituisco le prime N offerte più economiche
            sprintf(str_n, "%d", n);
            execlp("head", "head", "-n", str_n, date, NULL);
            perror("P3: head");
            exit(11);
        }

        // chiudo pipe di P0
        close(p1p2[0]);
        close(p1p2[1]);

        close(p2p3[0]);
        close(p2p3[1]);

        // attendo terminazione di P1, P2, P3
        wait(&status);
        wait(&status);
        wait(&status);

        // incremento counter richieste servite
        count ++;
    }

    printf("Numero di richieste servite: %d\n", count);

    return 0;
}