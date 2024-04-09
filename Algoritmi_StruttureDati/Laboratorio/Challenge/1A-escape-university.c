#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000*1000

struct pair {
    int x;
    int id;
};


/**
 * Sottoprocedura di 'merge_sort' per unire due range.  
 */
void merge(struct pair *arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int i, j;
    struct pair left[n1], right[n2];

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
                arr[k] = (left[i].x <= right[j].x) ? left[i++] : right[j++];
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


void escape_university(FILE *in_file, FILE *out_file) {
    struct pair pairs[MAX_SIZE];
    int pairs_size = 0;

    int N, Q;
    fscanf(in_file, "%d %d", &N, &Q);

    for (int i = 0; i < N; i ++) {
        int id, s;
        fscanf(in_file, "%d %d", &id, &s);

        for (int j = 0; j < s-1; j ++) {
            int x;
            fscanf(in_file, "%d", &x);

            pairs[pairs_size].x = x;
            pairs[pairs_size].id = id;
            pairs_size ++;
        }
    }

    merge_sort(pairs, 0, pairs_size);

    for (int i = 0; i < Q; i++) {
        int query;
        fscanf(in_file, "%d", &query);
        solve(pairs, pairs_size, query, out_file);
    }
        


}

int main () {
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -1;
    }

    escape_university(in_file, out_file);

/*
    int N, Q;
    int S, x, id, file[N][S];
    int ans[Q], req[Q];

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