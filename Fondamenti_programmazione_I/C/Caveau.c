#include <stdio.h>
#define dim 20

typedef struct{
    int valore;
    char nome[dim];
}Pietre;

void valori(Pietre t_p[], int k){
    int i;
    for(i = 0; i < k; i ++){
        printf("Valore e nome: ");
        scanf("%d%s", &t_p[i].valore, t_p[i].nome);
    }
}

void riordina(Pietre t_p[], int k){
    int i, j;
    Pietre c;
    for(i = 0; i < k; i ++)
        for(j = 0; j < k; j ++)
            if(t_p[j+1].valore < t_p[j].valore){
                c = t_p[j];
                t_p[j] = t_p[j+1];
                t_p[j+1] = c;
            }
}

int main(){
    int k, i, n_pietre;
    printf("Pietre che riesco a portare in mano: ");
    scanf("%d", &k);
    Pietre tabella_pietre[k];
    valori(tabella_pietre, k);
    printf("\n");

    riordina(tabella_pietre, k);

    for(i = 0; i < k; i ++)
        printf("valore e nome: %d %s\n",tabella_pietre[i].valore, tabella_pietre[i].nome);

    printf("Quante pietre vuoi stampare? ");
    scanf("%d", &n_pietre);
    for(i = 0; i < n_pietre; i ++)
        printf("Nome: %s\n", tabella_pietre[i].nome);

    printf("Finito\n");
    return 0;
}
