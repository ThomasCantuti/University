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
void merge(struct pair *pairs, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int i, j;
    struct pair left[n1], right[n2];

    for (i=0; i<n1; i++) {
        left[i] = pairs[start+i];
    }

    for (j=0; j<n2; j++) {
        right[j] = pairs[mid+1+j];
    }

    i = j = 0;

    for (int k=start; k<=end; k++) {
        if (i < n1) {
            if (j < n2) {
                pairs[k] = (left[i].x <= right[j].x) ? left[i++] : right[j++];
            } else {
                pairs[k] = left[i++];
            }
        } else {
            pairs[k] = right[j++];
        }
    }
}

/**
 * Implementazione di 'merge sort'.
 */
void merge_sort(struct pair *pairs, int start, int end) {
    if (start < end) {
        int mid = start + (end-start) / 2;
        merge_sort(pairs, start, mid);
        merge_sort(pairs, mid+1, end);
        merge(pairs, start, mid, end);
    }
}

/**
 * Implementazione di 'binary search'.
 */
struct pair find (struct pair *pairs, int low ,size_t pairs_size, int target) {
    if (low > pairs_size)
        return pairs[0];
    
    int mid = (low + pairs_size) / 2;
    if (pairs[mid].x == target)
        return pairs[mid];
    if (pairs[mid].x < target)
        return find (pairs, mid + 1, pairs_size, target);
    if (pairs[mid].x > target)
        return find (pairs, low, mid - 1, target);
}

/**
* Soluzione del problema implementando l'algoritmo
* binary search e scrivendo il risultato nel file output
*/
void solve (struct pair *pairs, int pairs_size, int query, FILE *out_file) {
    // uso algoritmo binary search
    struct pair p = find(pairs, 0, pairs_size, query);

    // se risultato trovato -> lo stampo
    // altrimenti -> stampo null
    if (p.x == query)
        fprintf(out_file, "%d ", p.id);
    else
        fprintf(out_file, "NULL ");
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

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    return 0;
}