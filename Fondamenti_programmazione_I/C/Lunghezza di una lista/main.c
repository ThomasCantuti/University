#include "lista.h"
#include <stdio.h>

int main(){
    Lista l;
    listaNonOrdinata(&l, 6);
    printf("Lunghezza: %d\n", lunghezza(l));
    printf("Massimo: %d\n", massimo(l));
}