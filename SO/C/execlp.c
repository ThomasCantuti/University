#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

    /*
    
    process structure padre != process structure figlio 
    -> ognuna punta a una text structure diversa che a loro volta puntano ognuna ad un codice diverso
    user structure e stack kernel uguali -> stesso file descriptor e gestione dei segnali
    codice, dati globali, stack e heap diversi
    
    */

    int pid = fork();

    if (pid < 0) {
        perror("fork fallita");
        exit(3);
    }

    if (pid == 0) {
        // istruzioni figlio
        execlp("ls", "ls", "-l", NULL);
        perror("execlp fallita");
        exit(4);
    } else if (pid > 0) {
        // istruzioni padre
        printf("Sono il padre\n");
    }

    return 0;
}