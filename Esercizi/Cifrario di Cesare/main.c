#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *pf;
    char c[1];
    int n, i;
    char parola[10];

    if(argc != 3){
        printf("Uso: %s nome_file.txt n_posizioni\n", argv[0]);
        exit(1);
    }

    strcpy(c, argv[2]);
    n = (int)c[0];
    printf("Posizioni da saltare = %d\n", n);
    
    /*printf("Parola da cifrare: ");
    scanf("%s", parola);

    for(i = 0; i < strlen(parola); i ++)
        parola[i] = parola[i] + n;
    
    printf("%s\n", parola);*/

    //pf = fopen(argv[1], "rt");

}