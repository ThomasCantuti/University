#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// volatile -> non ottimizza il codice, prende valore reale e non quello in memoria cache
// sig_atomic_t -> lettura e scrittura di un valore in modo consistente, indivisibile (no più istruzioni)

static volatile sig_atomic_t contatore;

void sigintfiglio_handler(int sig) {
    printf("Figlio %d: Terminazione con valore counter %d\n", child_index, contatore);
    exit(0);
}

void sigintpadre_handler(int sig) {
    printf("Ricevuto CTRL-C --> Attendo sincronizzazione con i figli...\n");
    int status;
    for(int i = 0; i < 10; i++) {
        wait(&status);
    }
}

int main (int argc, char** argv) {

    int *pid;
    int Nf = 10;

    pid = (int *) malloc(Nf * sizeof(int));

    // gestione segnali padre
    signal(SIGUSR1, sigintpadre_handler);

    // generazione figli
    for (int i = 0; i < Nf; i ++) {
        pid[i] = fork();
        signal(SIGUSR1, sigintfiglio_handler);
    }

    // invio SIGUSR1 a tutti i processi figli, padre escluso
    for ( int i = 0; i < Nf; i ++) {
        kill(pid[i], SIGUSR1);
    }

    // invio SIGUSR1 a tutti i processi figli, padre compreso
    kill(0, SIGUSR1);

    return 0;
}