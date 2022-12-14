//interfaccia dell'ADT lista di interi con implementazione collegata
#include <stdlib.h>

typedef int Dato;

typedef struct nodo{
    Dato dato;
    struct nodo* next;
}Nodo;

typedef Nodo *Lista;

void azzera(Lista l);
void stampa(Lista l);

void ListaNonOrdinata(Lista *pl, int n);