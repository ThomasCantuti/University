#include <stdio.h>
#include <stdlib.h>

int main(){
    int dim, i;
    int *a;
    printf("Dimensione array: ");
    scanf("%d", &dim);
    a = (int *)malloc(sizeof(int));
    for(i = 0; i < dim; i ++)
        a[i] = i;
    free(a);
    return 0;
}