#include <stdio.h>
#include <stdlib.h>

void pugilato (FILE *in_file, FILE *out_file) {

}

int main() {
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        return -1;
    }

    pugilato(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        return -2;
    }

    return 0;
}