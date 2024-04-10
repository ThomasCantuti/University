#include "lista.h"
#include <stdio.h>

void azzera(Lista l){
    while(l != NULL){
        l->dato = 0;
        l = l->next;
    }
}

void stampa(Lista l){
    while(l != NULL){
        printf("%d ", l->dato);
        l = l->next;
    }
    printf("\n");
}

void ListaNonOrdinata(Lista *pl, int n){
    int a[] = {6,2,3,2,4,7,0,2,5,1};
    int i;
    for(i = 0; i < n; i ++){
        (*pl) = (Nodo*)malloc(sizeof(Nodo));
        (*pl)->dato = a[i];
        (*pl)->next = NULL;
        pl = &(*pl)->next;
    }
}