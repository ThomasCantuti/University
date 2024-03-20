#include <stdlib.h>
#include <stdio.h>
#include <time.h>

clock_t start, stop;
double elapsed_time;

struct configuration {
    int min_size;
    int max_size;
    int step;
    int repetitions;
    int seed;
};

struct configuration init() {

    struct configuration config;

    config.min_size = 10;
    config.max_size = 1000;
    config.step = 10;
    config.repetitions = 50;
    config.seed = 362372;

    return config;
}

void insertionSort(int *arr, int size) {
    int key, i;
    for(int j = 0; j < size + 1; j ++) {
            int key = arr[j];
            i = j - 1;
            while( (i >= 0) && (arr[j] > key) ) {
                arr[i + 1] = arr[i];
                i --;
            }
            arr[i + 1] = key;
        }
}

int check(int *arr, int size) {
    for(int i = 0; i < size; i ++) {
        if(arr[i] < arr[i - 1]) {
            return 1;
        }
    }

    return 1;
}

double run(size_t size, int repetitions) {
    
    for(int i = 0; i < repetitions; i ++) {
        int arr[size];
        for(int j = 0; j < size; j ++)
            arr[j] = rand();
        start = clock();
        insertionSort(arr, size);
        stop = clock();
        if (check(arr, size) != 1) {
            printf("ERRORE: l'ordinamento è scorretto\n");
            exit(-1);
        }
        elapsed_time += (stop - start) / (double) CLOCKS_PER_SEC;
    }

    return elapsed_time / repetitions;
}

void run_experiments(struct configuration config) {

    for(int i = config.min_size; i < config.max_size; i += config.step) {
        
        srand(config.seed);
        elapsed_time = run(i, config.repetitions);
        printf("Elapsed time: %lf\n", elapsed_time);
        config.seed ++;
        printf("%d %lf\n", i, elapsed_time);
    }   
}

int main(void) {

    struct configuration config = init();
    run_experiments(config);

    return 0;
}
