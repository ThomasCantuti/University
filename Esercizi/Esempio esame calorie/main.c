#include <stdio.h>
#include <stdlib.h>
#include "listaCalorie.h"

int main(int argc, char *argv[]){
    FILE *fb;
    Lista l;
    Record r;

    if(argc != 3){
        printf("Uso: %s file_binario file_testo\n", argv[0]);
        exit(1);
    }

    lista_vuota(&l);

    fb = fopen(argv[1], "rb");
    if(fb == NULL){
        printf("Errore apertura %s\n", argv[1]);
        exit(2);
    }

    fread(&r, sizeof(Record), 1, fb);
    insCoda(&l, r);

    fclose(fb);
    return 0;
}