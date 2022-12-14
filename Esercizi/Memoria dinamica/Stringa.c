#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *allocca_stringa(int n){
    char *indirizzo = (char*)malloc((n*sizeof(char)));
    return indirizzo;
}

int main(){
    char *s;
    s = allocca_stringa(80);
    scanf("%s", s);
    printf("%d\n", strlen(s));
    free(s);
    return 0;
}