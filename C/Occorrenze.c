#include <stdio.h>
#define MAX 100

int leggi_due_interi(int* pn, int* pk){
    int n, k;
    do{
        printf("Inserire due numeri: ");
        scanf("%d%d",&n, &k);
    }while(n > MAX || k > n);
    *pn = n;
    *pk = k;
}

void stampa(int n, int *a){
    for(int i = 0; i < n; i ++)
        printf("%d ",a[i]);
    printf("\n");
}

void leggi_array(int n, int *a, int k){
    int i, num;

    for(i = 0; i < n; i++)
        a[i] = 0;

    for(i = 0; i < n; i++)
        do{
            printf("a[%d]: ", i);
            scanf("%d",&num);
            a[num]++;
        }while(a[i] < 0 && a[i] > k-1);
}

void occorrenze(int n, int *a, int *num, int *volte){
    int i, max = 0;

    for(i = 0; i < n; i ++)
        if(a[i] > max){
            max = a[i];
            *num = i;
            *volte = a[i];
        }
}

int main(){
    int n, k, a[MAX], num, volte;

    leggi_due_interi(&n, &k);
    printf("%d %d\n",n ,k);

    leggi_array(n, a, k);

    occorrenze(n, a, &num, &volte);
    printf("%d è apparso %d volte\n",num, volte);
}