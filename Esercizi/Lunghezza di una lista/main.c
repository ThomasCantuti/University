#include "lista.h"
#include <stdio.h>

int main(){
    Lista l;
    listaNonOrdinata(&l, 6);
    printf("Lunghezza lista: %d\n", lunghezza(l));
}