#include "lista.h"
#include <stdio.h>

int main(){
    Lista l;
    int numero;
    nuova(&l);

    while(!piena(&l)){
        printf("Inserisci un intero: ");
        scanf("%d",&numero);
        if(numero <= 0)
            break;
        inserimento_ordinato(&l, numero);
    }
    
    stampa(&l);
    return 0;
}