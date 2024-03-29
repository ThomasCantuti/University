#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *in_file, *out_file;

    int N, Q;
    int S, x, id, file[N][S];
    int ans[Q], req[Q];

    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    // riempimento di null nell'array di risposta
    for (int i = 0; i < Q; i ++)
        ans[i] = 0;

    // lettura N Q
    fscanf(in_file, "%d %d", &N, &Q);
    // lettura id Sn x0...xSn-1
    for (int i = 0; i < N; i ++) {
        fscanf(in_file, "%d %d", &id, &S);
        file[i][0] = id;
        file[i][1] = S;
        for (int j = 2; j < S - 1; j ++)
            fscanf(in_file, "%d", &file[i][j]);
    }
    // lettura ultima riga input -> x che mi fa trovare l'id
    for (int i = 0; i < Q; i++)
        fscanf(in_file, "%d", &req[i]);

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < file[i][1]; j ++)
            printf("%d ", file[i][j]);
        printf("\n");
    }
/*
    // soluzione
    for (int row = 0; row < Q; row ++) {
        for (int col = 0; col < file[row][1]; col ++) {
            if (req[row] == file[row][col])
                ans[row] = file[row][0];
        }
    }

    // scrittura risposta su file output
    for (int i = 0; i < Q; i ++)
        fprintf(out_file, "%d ", ans[i]);
*/
    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }
    return 0;

}