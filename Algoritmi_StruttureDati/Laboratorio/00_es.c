#include <stdio.h>
#include <stdlib.h>

FILE *in_file;
FILE *out_file;

int solve (int n) {

    if (n == 1) {
        fprintf(out_file, "%d ", n);
        return n;
    }

    if (n % 2 == 0) {
        fprintf(out_file, "%d ", n);
        return solve(n / 2);
    }
    else {
        fprintf(out_file, "%d ", n);
        return solve(n * 3 + 1);
    }

}

int main () {

    int n;

    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "a");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    fscanf(in_file, "%d", &n);
    solve(n);
    
    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }
    return 0;

}