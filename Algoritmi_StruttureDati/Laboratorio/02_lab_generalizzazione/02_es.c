#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/**
 * Vedi 'struct configuration'.
 */
#define MAX_ALGO 16
#define MAX_ALGO_BUFF 64

/**
 * Parametri di un esperimento.
 *
 * min_size: dimensione dell'array nel primo esperimento.
 * max_size: dimensione dell'array nell'ultimo esperimento.
 * step: incremento di dimensione dell'array tra un esperimento e il successivo.
 * repetitions: numero di volte in cui un esperimento è ripetuto, 
 *              al fine di ottenere tempi statisticamente validi.
 * seed: seme del generatore di numeri pseudocasuali,
 *              al fine di garantire la riproducibilità degli esperimenti.
 * 
 * Contiene anche un array di stringhe, che rappresentano
 * gli algoritmi di ordinamento protagonisti dell'esperimento.
 */
struct configuration
{
    int min_size;
    int max_size;
    int step;
    int repetitions;
    int seed;

    int n_algorithms;
    char algorithms[MAX_ALGO][MAX_ALGO_BUFF];
};

/**
 * Inizializza i parametri di un esperimento.
 * Vedi anche: 'struct configuration'. 
 */
void init(struct configuration *config) {
    printf("Inserire min_size (ad esempio, 10): ");
    scanf("%d", &config->min_size);

    printf("Inserire max_size (ad esempio, 1000): ");
    scanf("%d", &config->max_size);

    printf("Inserire step (ad esempio, 10): ");
    scanf("%d", &config->step);

    printf("Inserire repetitions (ad esempio, 50): ");
    scanf("%d", &config->repetitions);

    printf("Inserire seed (ad esempio, 362372): ");
    scanf("%d", &config->seed);

    // TODO: se stai leggendo questo commento, prova
    // a scrivere un piccolo controllo sui valori inseriti,
    // per garantire che siano sensati.
    // Ad esempio, 'repetitions' non può essere negativo.

    // TODO: prova a scrivere un ciclo che chiede all'utente 
    // quanti algoritmi vuole, e inserisca i loro nomi tra una
    // lista di proposte.
    int n_algorithms = 2;
    char *algos[] = {"INSERTION", "MERGE"};
    
    config->n_algorithms = n_algorithms;
    for (int algo_idx=0; algo_idx < n_algorithms; algo_idx++) {
        strcpy(config->algorithms[algo_idx], algos[algo_idx]);
    }
}

/**
 * Funzione antagonista: controlla che un array sia ordinato.
 */
int check(int *arr, int size) {
    for (int i=1; i<size; i++) {
        if (arr[i] < arr[i-1]) {
            return -1;
        }
    }

    return 1;
}

/**
 * Implementazione di 'insertion sort'.
 */
void insertion_sort(int *arr, int start, int end) {
    int key, i;
    
    for (int j = start; j < end+1; j++) {
        key = arr[j];
        i = j-1;

        while(i>=start && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

/**
 * Sottoprocedura di 'merge_sort' per unire due range.  
 */
void merge(int *arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int i, j, left[n1], right[n2];

    for (i=0; i<n1; i++) {
        left[i] = arr[start+i];
    }

    for (j=0; j<n2; j++) {
        right[j] = arr[mid+1+j];
    }

    i = j = 0;

    for (int k=start; k<=end; k++) {
        if (i < n1) {
            if (j < n2) {
                arr[k] = (left[i] <= right[j]) ? left[i++] : right[j++];
            } else {
                arr[k] = left[i++];
            }
        } else {
            arr[k] = right[j++];
        }
    }
}

/**
 * Implementazione di 'merge sort'.
 */
void merge_sort(int *arr, int start, int end) {
    if (start < end) {
        int mid = start + (end-start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

/**
 * Interfaccia per una generica funzione di ordinamento,
 * che ha come argomenti (in ordine):
 * 1) il riferimento al primo elemento di un array
 * 3) la fine del range da ordinare nell'array
 */
typedef void (*algo_ptr)(int*, int, int);

/**
 * Seleziona un algoritmo di ordinamento scegliendolo
 * in base alla stringa passata come argomento.
 * Vedi 'algo_ptr'.
 */
algo_ptr select_algorithm(char *algo_name) {
    if (strcmp(algo_name, "INSERTION") == 0) {
        return &insertion_sort;
    } else if(strcmp(algo_name, "MERGE") == 0) {
        return &merge_sort;
    } else {
        printf("Errore - l'algoritmo selezionato non è disponibile.");
        exit(-1);
    }
}

/**
 * Esegue un numero di misurazioni di tempi pari a 'repetitions'.
 * Ogni misurazione riguarda l'applicazione di un certo algoritmo
 * di ordinamento ad un array di dimensione 'size', inizializzato
 * con numeri pseudocasuali.
 * Restituisce un valore 'double', contenente il tempo medio di esecuzione.
 */
double run(int size, int repetitions, algo_ptr algorithm) {
    double elapsed_time = 0.0;

    for (int i=0; i<repetitions; i++) {
        int arr[size];
        for (int j=0; j<size; j++) {
            arr[j] = rand();
        }

        clock_t start, end;
        start = clock();
        algorithm(arr, 0, size-1);
        end = clock();

        if (check(arr, size) != 1) {
            printf("ERRORE: L'ordinamento è scorretto.\n");
            exit(-1);
        }

        elapsed_time += (end-start) / (double)CLOCKS_PER_SEC;
    }

    return elapsed_time / repetitions;
}

/**
 * Manager degli esperimenti. 
 * 
 * Chiama un esperimento più volte, gestendo di volta in volta
 * l'incremento della dimensione dell'array soggetto degli esperimenti.
 * 
 * Si occupa anche di inizializzare e variare il generatore di numeri
 * pseudocasuali, e di stampare a video i risultati.
 */
void run_experiments(struct configuration config, FILE *report) {
    // Stampa quello che, nel grafico finale, sarà l'asse delle x.
    for (int i=config.min_size; i<=config.max_size; i+=config.step) {
        fprintf(report, "%d \t", i);
    }
    fprintf(report, "\n");

    // Per ogni algoritmo caricato nella configurazione...
    for (int algo_idx=0; algo_idx<config.n_algorithms; algo_idx++) {

        // Esegui un esperimento, e stampa passo dopo passo l'asse delle y.
        for (int i=config.min_size; i<=config.max_size; i+=config.step) {
            srand(config.seed);
            double elapsed_time = run(
                i, 
                config.repetitions, 
                select_algorithm(config.algorithms[algo_idx])
            );
            config.seed++;

            fprintf(report, "%g \t", elapsed_time);
        }
        // Passa al prossimo algoritmo.
        fprintf(report, "\n");
    }
}

/**
 * Entry point per gli esperimenti.
 * 
 * Dopo aver chiesto all'utente di inserire una configurazione, 
 * esegue gli esperimenti.
 */
int main(void) {
    struct configuration config;
    init(&config);

    FILE *report = fopen("report.txt", "w");
    if (report == NULL) {
        printf("Errore apertura file di report.");
        return -1;
    }

    run_experiments(config, report);

    if (fclose(report) != 0) {
        printf("Errore chiusura file di report.");
    }

    return 0;
}