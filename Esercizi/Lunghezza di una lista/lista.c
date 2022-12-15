#include "lista.h"
#include <stdlib.h>

void listaNonOrdinata(Lista* pl, int n) {

  int a[] = {6, 2, 3, 2, 4, 7, 0, 2, 5, 1};
  int i;

  for (i = 0; i < n; i++) {

    (*pl) = (Nodo*)malloc(sizeof(Nodo));
    (*pl)->dato = a[i];
    (*pl)->next = NULL;
    pl = &(*pl)->next;
  }
}

int lunghezza(Lista l){
    int contatore = 0;
    Nodo *p = l;
    while(p != NULL){
        contatore ++;
        p = p->next++;
    }
    return contatore;
}