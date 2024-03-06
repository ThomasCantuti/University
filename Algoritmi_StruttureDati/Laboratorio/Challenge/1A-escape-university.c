#include <stdio.h>
#include <stdlib.h>

// idea: provare a creare una typdef con struttura file[key] = [value]
// con key = id e value = num (senza dim)

FILE *in_file;
FILE *out_file;

int solve (int n) {
    
}

int main () {

    int N, Q;
    int id, dim, *num;

    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    fscanf(in_file, "%d %d", &N, &Q);
    // lettura finche non arriva alla fine del file
        // lettura finchè non arriva alla fine della riga
    
    // soluzione

    //fprintf(out_file, "%d", 1);
    
    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }
    return 0;

}