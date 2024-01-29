#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// volatile -> non ottimizza il codice, prende valore reale e non quello in memoria cache
// sig_atomic_t -> lettura e scrittura di un valore in modo consistente, indivisibile (no più istruzioni)

static volatile sig_atomic_t contatore;

void handle_sigusr1 (int signal_number) {
    contatore ++;
}

int main (int argc, char** argv) {

    int *pid;
    int Nf = 10;

    pid = (int *) malloc(Nf * sizeof(int));

    // gestione segnali
    signal(SIGUSR1, handle_sigusr1);

    // generazione figli
    for (int i = 0; i < Nf; i ++) {
        pid[i] = fork();
    }

    // invio SIGUSR1 a tutti i processi figli, padre escluso
    for ( int i = 0; i < Nf; i ++) {
        kill(pid[i], SIGUSR1);
    }

    // invio SIGUSR1 a tutti i processi figli, padre compreso
    kill(0, SIGUSR1);



    return 0;
}