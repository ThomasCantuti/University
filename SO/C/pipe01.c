#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

    /*
    
    p0p1[2] è il file descriptor che fa comunicare lato lettura (p0p1[0]) e lato scrittura (p0p1[1])
    
    */

   int p0p1[2], p1p0[2];
   int pid;
   char dati[100] = "ciao";

   if (pipe(p0p1) < 0) { // crea pipe
        perror("pipe fallita");
        exit(1);
    }
    if (pipe(p1p0) < 0) { // crea pipe
        perror("pipe fallita");
        exit(1);
    }

    // voglio mandare/scrivere informazioni da P0 a P1
    // voglio ricevere/leggere informazioni da P1 a P0

    /* 
    file descriptor P0 attuale:
    0: stdin
    1: stdout
    2: stderr
    3: p0p1[0] -> non serve perché P0 vuole solo scrivere su questa pipe, non leggere
    4: p0p1[1] -> serve per mandare l’informazione a P1
    5: p1p0[0] -> serve per leggere/ricevere i risultati che gli manda il figlio P1
    6: p1p0[1] -> non serve perché P0 vuole solo leggere su questa pipe, non scrivere
    */
    close(p0p1[0]); // chiudo lato lettura che usa P0 per leggere da P1
    close(p1p0[1]); // chiudo lato scrittura che usa P0 per scrivere a P1
    /* 
    file descriptor P0 attuale:
    0: stdin
    1: stdout
    2: stderr
    3: 
    4: p0p1[1]
    5: p1p0[0]
    6: 
    */
    write(p0p1[1], dati, sizeof(dati)); // scrive/comunica su p0p1[1] i dati
    close(p0p1[1]); // chiudo lato scrittura perchè non mi serve più scrivere al figlio
    /* 
    file descriptor P0 attuale:
    0: stdin
    1: stdout
    2: stderr
    3: 
    4: 
    5: p1p0[0]
    6: 
    */

    // ora voglio che p1p0[0] di P0 venga usato come canale di ingresso:
    close(0); // chiudo stdin
    dup(p1p0[0]); // duplico p1p0[0] in indice 0 (stdin)
    close(p1p0[0]); // chiudo p1p0[0] in indice 5
    /* 
    file descriptor P0 attuale:
    0: stdin
    1: p1p0[0]
    2: stderr
    3: 
    4: 
    5: 
    6: 
    */

   if ((pid = fork()) < 0) {
    
        perror("fork fallita");
        exit(3);
    
    } 
    
    if (pid == 0) {
    
        // istruzioni figlio
        
        /* 
        file descriptor P1 attuale:
        0: stdin
        1: stdout
        2: stderr
        3: p0p1[0] -> serve perché da esso leggerà l’informazione che il padre P0 vuole mandargli 
        4: p0p1[1] -> non serve perché questo è adibito solo per essere usato dal padre P0 per mandare l’informazione a P1
        5: p1p0[0] -> non serve perché questo estremo lo usa solo il padre P0 per leggere/ricevere i risultati che gli manda il figlio P1
        6: p1p0[1] -> serve perché su di esso vuole scrivere per mandare in output i propri risultati al padre
        */
        close(p0p1[1]); // chiudo lato scrittura che usa P0 per scrivere a P1
        close(p1p0[0]); // chiudo lato lettura che usa P0 per leggere da P1
        /* 
        file descriptor P1 attuale:
        0: stdin
        1: stdout
        2: stderr
        3: p0p1[0]
        4: 
        5: 
        6: p1p0[1]
        */
       read(p0p1[0], dati, sizeof(dati)); // legge/riceve da p0p1[0] i dati
       close(p0p1[0]); // chiudo lato lettura perchè non mi serve più leggere dal padre
       /* 
        file descriptor P1 attuale:
        0: stdin
        1: stdout
        2: stderr
        3: 
        4: 
        5: 
        6: p1p0[1]
        */

       // ora voglio che p1p0[1] di P1 venga usato come canale di uscita:
        close(1); // chiudo stdout
        dup(p1p0[1]); // duplico p1p0[1] in indice 1 (stdout)
        close(p1p0[1]); // chiudo p1p0[1] in indice 6
        /* 
        file descriptor P1 attuale:
        0: stdin
        1: p1p0[1]
        2: stderr
        3: 
        4: 
        5: 
        6: 
        */
    
    } else if (pid > 0) {
    
        // istruzioni padre

   }

    return 0;
}