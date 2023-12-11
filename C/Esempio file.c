#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *pf;
    char parola[20];

    pf = fopen("prova.txt", "w");

    if(pf == NULL){
        printf("Errore apertura file\n");
        exit(1);
    }

    for(int i = 0; strcmp(parola, "fine") != 0; i ++){
        scanf("%s",parola); // = fscanf(stdin,"%s\n",parola)
        fprintf(pf, "%s\n",parola); // = fprintf(stdout,"%s\n",parola)
    }

    fclose(pf);

    pf = fopen("prova.txt", "r");

    // feof(pf) == 0 non lo uso perchè scrive due volte l'ultimo carattere
    for(int i = 0; fscanf(pf,"%s",parola) == 1; i ++){
        printf("%s ",parola);
    }

    printf("\n");        

    if (fclose(pf) != 0){
        printf("Errore chiusura file\n");
        exit(2);
    }

    return 0;
}