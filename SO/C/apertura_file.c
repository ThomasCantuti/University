#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main (int argc, char** argv) {

    int file_descriptor;
    int i = 0; // indice per scorrere gli argomenti

    // per controllare se file esiste, provo ad aprirlo

    /* 
    la open() potrebbe fallire anche se il file esiste, ad
    esempio nel caso in cui manchino i permessi di lettura, allora
    per gestire anche tale casistica, possiamo controllare il valore
    di errno
    */
    
    if((file_descriptor = open(argv[i], O_RDONLY)) < 0) {

        if(errno == ENOENT) {
            printf("non è possibile aprire il file %s", argv[i]);
            perror("mancano permessi di lettura");
            exit(2);
    } else {
        perror("open");
        exit(3);
        }
    }
}