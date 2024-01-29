#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

    /*
    
    fd[2] è il file descriptor che fa comunicare lato lettura (fd[0]) e lato scrittura (fd[1])
    
    */

   int fd[2];
   int pid = fork();
   char dati[100] = "ciao";

   if (pid < 0) {
    
        perror("fork fallita");
        exit(3);
    
    } 
    
    if (pid == 0) {
    
        // istruzioni figlio
        read(fd[0], dati, sizeof(dati)); // legge/riceve da fd[0] i dati
        write(fd[1], dati, sizeof(dati)); // scrive/comunica su fd[1] i dati
        close(0); // chiude stdin nel file descriptor del figlio
        close(fd[1]); // chiude fd[1] (lato scrittura) nel file descriptor del figlio
        /*
        ora nel file descriptor del figlio ho:
        0: 
        1: stdout
        2: stderr
        3: fd[0] (lato lettura)
        4: 
        */
       dup(fd[0]); // duplica fd[0] (lato lettura) in 0 (primo posto libero che trova)
       /*
        ora nel file descriptor del figlio ho:
        0: fd[0] (lato lettura)
        1: stdout
        2: stderr
        3: fd[0] (lato lettura)
        4: 
        */
    
    } else if (pid > 0) {
    
        // istruzioni padre

   }

    return 0;
}