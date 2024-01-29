#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

    /*

    process structure del padre = process structure del figlio
    -> puntano a stessa text structure che punta allo stesso codice programma
    copiando user structure (puntato da process structure) -> figlio ha stesso file descriptor e gestione dei segnali del padre

    */

   int pid = fork();
    
    if (pid < 0) {
        perror("fork fallita");
        exit(3);
    }

    if (pid == 0) { // figlio -> pid = 0
        // istruzioni figlio
        pid = fork();
        if (pid == 0) { // nipote = figlio del figlio -> pid = 0
            // istruzioni nipote
        } 
        else if (pid > 0) { // figlio -> pid = 34
            // istruzioni figlio = figlio del padre
        }

    } else if (pid > 0) { // padre -> pid = 8
        // istruzioni padre
    }

    return 0;
}