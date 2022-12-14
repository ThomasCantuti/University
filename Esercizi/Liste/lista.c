#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void nuova(Lista *pl){
    pl->n_elementi = 0;
}

int piena(Lista *pl){
    return pl->n_elementi == DIMENSIONE;
}

void stampa(Lista *pf){
    int i;
    for(i = 0; i < pf->n_elementi; i++)
        printf("%d\n", pf->dati[i]);
}

void inserimento_ordinato(Lista *pl, int n){
    int i;
    if(piena(pl)){
        printf("Errore: lista piena\n");
        exit(1);
    }
    for(i = pl->n_elementi; i >= 1 && pl->dati[i-1] > n; i --){
        pl->dati[i] = pl->dati[i-1];
        pl->dati[i] = n;
        pl->n_elementi ++;
    }
}