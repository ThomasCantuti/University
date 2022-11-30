#include <stdio.h>
#define dim 3

typedef int riga[dim];
typedef riga matrice[dim];

void stampa(matrice pm){
    int i, j;
    for(i = 0; i < 3; i ++){
        for(j = 0; j < 3; j ++)
            printf("%d ",pm[i][j]);
        printf("\n");
    }
}

void lettura(int m[][dim]){
    int i, j;
    for(i = 0; i < 3; i ++)
        for(j = 0; j < 3; j ++)
            scanf("%d",&m[i][j]);
}

int simmetrica(int m[][dim]){
    int i, j;
    for(i = 0; i < 3; i ++)
        for(j = i + 1; j < 3; j ++)
            if(m[i][j] != m[j][i])
                return 0;
    return 1;
    
}

int main(){
    int mat[dim][dim];
    matrice m;
    int i, j;
    lettura(mat);
    printf("\n");
    stampa(mat);
    if(simmetrica(mat))
        printf("Simmetrica\n");
    else
        printf("No simmetrica\n");
    return 0;
}