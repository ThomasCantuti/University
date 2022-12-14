#include <stdio.h>
#include <stdlib.h>//ci sono malloc e free

int main(){
    //alloccare dinamicamente 12 byte
    float *p;
    p = (float *) malloc(12);

    //alloccare lo spazio necessario per 5 interi
    int *f;
    f = (int *) malloc(5*sizeof(int));

    double *pd;
    pd = (double*)malloc(sizeof(double));
    scanf("%lf", pd);
    printf("%lf\n", *pd);
    //libero lo spazio
    free(pd);
    return 0;
}