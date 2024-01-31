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

int main (int argc, char **argv) {

    int pid, fd, status, p1p2[2], p2p3[0];
    
    // controllo argomenti
    if (argc != 2) {
        printf("Errore: usare trova_spettacoli nomeTeatro");
        exit(1);
    }

    

    printf("Numero di richieste servite: %d\n", count);
    return 0;
}