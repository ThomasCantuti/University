#define DIMENSIONE 50

typedef struct{
    int n_elementi;
    int dati[DIMENSIONE];
}Lista;

void nuova(Lista *pl);
void inserimento_ordinato(Lista *pl, int n);
int piena(Lista *pl);
void stampa(Lista *pf);