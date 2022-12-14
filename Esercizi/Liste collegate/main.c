#include "lista.h"

int main(){
    Lista l;
    ListaNonOrdinata(&l, 6);

    stampa(l);
    azzera(l);
    stampa(l);

    return 0;
}