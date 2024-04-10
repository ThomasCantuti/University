#include "Figure.h"
#include <stdio.h>

int main(){
    Figura f;

    rettangolo(&f, 3, 2);
    printf("Perimetro: %.2f\n",perimetro(&f));
    printf("Area: %.2f\n",area(&f));

    quadrato(&f, 3);
    printf("Perimetro: %.2f\n",perimetro(&f));
    printf("Area: %.2f\n",area(&f));

    triangolo(&f, 4, 5, 8);
    printf("Perimetro: %.2f\n",perimetro(&f));
    printf("Area: %.2f\n",area(&f));

    cerchio(&f, 3);
    printf("Perimetro: %.2f\n",perimetro(&f));
    printf("Area: %.2f\n",area(&f));
    return 0;
}