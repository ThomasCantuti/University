#include <stdio.h>
#include <string.h>

#define dim 30
#define max 5

typedef struct{
    char marca[dim];
    int cilindrata;
    int anno;
    char nome[dim];
    char cognome[dim];
}automobili;

automobili inserisci_auto(automobili t_a){
    do{
        printf("Inserire cilindrata, anno: ");
        scanf("%d%d",&t_a.cilindrata,&t_a.anno);
    }while(!((t_a.anno >= 2000 && t_a.anno <= 2019) && (t_a.cilindrata >= 800 && t_a.cilindrata <= 2500)));

    printf("marca, nome e cognome: ");
    scanf("%s%s%s", t_a.marca, t_a.nome, t_a.cognome);
    return t_a;
}

automobili cerca_marca(automobili t_a[], char cerca_marca[dim], int dl){
    int i;
    for(i = 0; i < dl; i++)
        if(strcmp(t_a[i].marca, cerca_marca) == 0)
            return t_a[i];
}

void cilindrata_alta(automobili t_a[], int dl){
    int i;
    for(i = 0; i < dl; i ++)
        if(t_a[i].cilindrata > 1800)
            printf("%s ha cilindrata superiore a 1800cc\n", t_a[i].cognome);
}

int auto_immatricolate(automobili t_a[], int anno, int dl){
    int i, conta = 0;
    for(i = 0; i < dl; i ++)
        if(t_a[i].anno == anno)
            conta ++;
    return conta;
}

int main(){
    automobili tabella_auto[max];
    automobili t_a;
    char scegli_marca[dim];
    int scelta = 1, dl = 0, anno;
    
    //Inserimento auto vendute nel salone
    while(scelta){
        printf("Vuoi inserire un auto? (0 no, 1 si)\n");
        scanf("%d",&scelta);
        if(!scelta || dl > 5)
            break;
        tabella_auto[dl] = inserisci_auto(t_a);
        dl++;
    }

    //ricerca in base alla marca
    printf("Scegliere una marca: ");
    scanf("%s",scegli_marca);
    t_a = cerca_marca(tabella_auto, scegli_marca, dl);
    printf("Auto: %s %d %d %s %s\n", t_a.marca, t_a.cilindrata, t_a.anno, 
    t_a.nome, t_a.cognome);

    cilindrata_alta(tabella_auto, dl);

    printf("Anno di immatricolazione: ");
    scanf("%d",&anno);
    printf("Le auto imm. nello stesso anno sono %d\n", auto_immatricolate(tabella_auto, anno, dl));

    return 0;
}
