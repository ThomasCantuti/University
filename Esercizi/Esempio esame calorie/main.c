#include <stdio.h>
#include <stdlib.h>
#include "listaCalorie.h"

int main(int argc, char *argv[]){
    FILE *fb;
    FILE *ft;
    Lista l;
    Record r;
    char nomeAlimento[31];
    float quantita;
    float calorieAlimento;
    float calorieTotali;

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

    while(fread(&r, sizeof(Record), 1, fb) == 1){
        insCoda(&l, r);
    }
    
    fclose(fb);

    ft = fopen(argv[2], "rt");
    if(ft == NULL){
        printf("Errore apertura %s\n", argv[2]);
        exit(2);
    }

    calorieTotali = 0;

    while(fscanf(ft,"%s%f", nomeAlimento, &quantita) == 2){
        calorieAlimento = calorie100grammi(l, nomeAlimento) / 100 * quantita;
        calorieTotali+= calorieAlimento;
    }
    
    printf("Calorie totali: %.2f\n", calorieTotali);

    return 0;
}