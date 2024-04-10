#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *pf;
    int n;

    if(argc != 3){
        printf("Uso: %s nome_file.txt n_posizioni\n", argv[0]);
        exit(1);
    }
    n = atoi(argv[2]);

    pf = fopen(argv[1], "w+");
    verifica(pf);

    codifica(pf, n);
    rewind(pf);
    decodifica(pf, n);
    rewind(pf);
    mostra(pf);
    
    fclose(pf);
    
}