#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NRIGHE 4
#define NCOLONNE 6
#define PROBMINA 0.2

typedef struct{
    int minata;
    int coperta;
}Casella;

typedef struct{
    Casella griglia[NRIGHE][NCOLONNE];
}Campo;

typedef struct{
    int colonna;
    int riga;
}Mossa;

typedef enum{ in_corso, vinto, perso }Stato;

int mine_adiacenti(Campo *pc, int i, int j){
    int mine = 0;
    mine += i >= 1 && j >= 1 && pc->griglia[i-1][j-1].minata;

    mine +=(i>= 1 && pc->griglia[i-1][j].minata);

    mine +=(i>=1 && j < NCOLONNE-1 && pc->griglia[i-1][j+1].minata);

    mine +=(j >= 1 && pc->griglia[i][j-1].minata);

    mine +=(j < NCOLONNE-1 && pc->griglia[i][j+1].minata);

    mine +=(i < NRIGHE-1 && pc->griglia[i+1][j-1].minata);

    mine +=(i < NRIGHE-1 &&  pc->griglia[i+1][j].minata);

    mine +=(i < NRIGHE-1 && j < NCOLONNE-1 &&  pc->griglia[i+1][j+1].minata);

    return mine;
}

float rnd_float(float a, float b){
    //probabilità creazione mina
    return a + (b - a) * (float)rand() / RAND_MAX;
}

void inizializza(Campo *pc){
    int i, j;
    for(i = 0; i < NRIGHE; i ++)
        for(j = 0; j < NCOLONNE; j ++){
            pc->griglia[i][j].minata = rnd_float(0.0, 1.0) < PROBMINA;
            pc->griglia[i][j].coperta = 1;
        }
}

void stampa_indici_colonna(){
    int i;
    printf("   ");
    for(i = 0; i < NCOLONNE; i ++)
        printf("%c",'a'+ i);
    printf("\n");
}

void bordo_orizzontale(){
    int j;
    printf("  ");
    for(j = 0; j < NCOLONNE+2; j ++)
        printf("-");
    printf("\n");
}

void stampa(Campo *pc){
    int i, j;

    stampa_indici_colonna();
    bordo_orizzontale();
    
    for(i = 0; i < NRIGHE; i ++){

        printf("%2d",i+1);
        printf("|");

        for(j = 0; j < NCOLONNE; j ++){

            if(pc->griglia[i][j].coperta)
                printf("#");   
            else 
                if(pc->griglia[i][j].minata)
                    printf("*");
                else{
                    int m = mine_adiacenti(pc, i, j);
                    if(m > 0)
                        printf("%d",m);
                    else
                        printf(" ");
                }
        }
        printf("|\n");
    }

    bordo_orizzontale();
}

void leggi_mossa(Mossa *pm){
    char s[10];
    scanf("%s",s);
    pm->colonna = s[0] - 'a';
    pm->riga = s[1] - '1';
}

void esegui(Campo *pc, Mossa *pm){
    pc->griglia[pm->riga][pm->colonna].coperta = 0;
}

Stato stato(Campo *pc){
    int i, j;
    for(i = 0; i < NRIGHE; i ++)
        for(j = 0; j < NCOLONNE; j ++)
            if(pc->griglia[i][j].minata && !pc->griglia[i][j].coperta)
                return perso;

    for(i = 0; i < NRIGHE; i ++)
        for(j = 0; j < NCOLONNE; j ++)
            if(!pc->griglia[i][j].minata && pc->griglia[i][j].coperta)
                return in_corso;
        
    return vinto;
}

void scopri(Campo *pc){
    int i, j;
    for(i = 0; i < NRIGHE; i ++)
        for(j = 0; j < NCOLONNE; j ++)
            pc->griglia[i][j].coperta = 0;
}

Stato turno(Campo *pc){
    Mossa m;
    stampa(pc);
    leggi_mossa(&m);
    esegui(pc, &m);
    system("clear");
    return stato(pc);
}

int main(){
    Campo campo;
    Stato s;
    //griglia[i][j] vale 1 se c'è la bomba, 0 se non c'è
    inizializza(&campo);

    do{
        s = turno(&campo);
    }while(s == in_corso);

    if(s == vinto)
        printf("Hai vinto\n");
    else
        printf("Hai perso\n");

    scopri(&campo);
    stampa(&campo);

    return 0;
}