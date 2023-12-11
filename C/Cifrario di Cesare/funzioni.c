#include "funzioni.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void verifica(FILE *pf){
    if(pf == NULL){
        printf("Errore: apertura file\n");
        exit(1);
    }
}

void codifica(FILE *pf, int n){
    int i;
    char parola[30];
    printf("Parola da cifrare: ");
    scanf("%s", parola);
    for(i = 0; i < strlen(parola); i ++)
        parola[i] = parola[i] + n;

    printf("Codificata: %s\n", parola);

    fprintf(pf, "%s", parola);
}

void decodifica(FILE *pf, int n){
    int i;
    char parola[30];
    fscanf(pf, "%s", parola);
    for(i = 0; i < strlen(parola); i ++)
        parola[i] = parola[i] - n;

    printf("Decodificata: %s\n", parola);
}

void mostra(FILE *pf){
    int i;
    char parola[30];
    printf("File:\n");
    while(fscanf(pf, "%s", parola) > 0){
        printf("%s\n", parola);
    }

}