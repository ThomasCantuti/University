#include <stdio.h>
#include <string.h>

void compatta(char a1[]){
    int i, n = 0;
    char a2[100];
    for(i = 0; i < strlen(a1); i ++){
        if(a1[i] != ' '){
            a2[n] = a1[i];
            n ++;
        }
    }
    strcpy(a1, a2);
}

int rimuovi_duplicati(char a1[], char a2[]){
    int i, j, c = 0;
    for(i = 0; i < strlen(a1); i ++)
        for(j = 0; j < strlen(a2); j ++)
            if(a1[i] == a2[j]){
                a1[i] = ' ';
                c++;
            }
    compatta(a1);
    return c;
}

int main(){
    char a1[100], a2[100];
    int eliminati;

    printf("Prima parola: ");
    scanf("%s", a1);

    printf("Seconda parola: ");
    scanf("%s", a2);

    eliminati = rimuovi_duplicati(a1, a2);

    printf("risultato = %s\n",a1);
    printf("eliminati = %d\n", eliminati);
    
    return 0;
}
