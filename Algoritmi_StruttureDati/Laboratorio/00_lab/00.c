#include <stdio.h>
#include <stdlib.h>

FILE *in_file;
FILE *out_file;

int solve (int n) {
    int ans = 1;

    while (n != 1) {

        if (n % 2 == 0) n = n / 2;
        else n = n * 3 + 1;

        ans ++;
    }
    return ans;
    
}

int main () {

    int n;

    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    fscanf(in_file, "%d", &n);
    fprintf(out_file, "%d", solve(n));
    
    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }
    return 0;

}