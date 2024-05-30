#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(double* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double *L = (double*) calloc(n1, sizeof(double));
    double *R = (double*) calloc(n2, sizeof(double));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(double *arr, int start, int end) {
    if (start < end) {
        int mid = start + (end-start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int recursiveBinarySearch(double* arr, int start, int end, unsigned int raggio) {
    if (start >= end) {
        if (raggio >= arr[start]) return start + 1;
        if (raggio < arr[start]) return start;
    }

    int mid = (start + end) / 2;

    if (arr[mid] <= raggio) {
        return recursiveBinarySearch(arr, mid+1, end, raggio);
    } else {
        return recursiveBinarySearch(arr, start, mid-1, raggio);
    }
}

void pianeta_spritz(FILE *in_file, FILE *out_file) {
    int N, Q;
    long long x, y, z;
    fscanf(in_file, "%d %d", &N, &Q);

    double* distanza = (double*) calloc(N, sizeof(double));
    unsigned int raggio;

    for (int i = 0; i < N; i++) {
        fscanf(in_file, "%lld %lld %lld", &x, &y, &z);
        distanza[i] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    merge_sort(distanza, 0, N-1);

    for (int i = 0; i < Q; i ++) {
        fscanf(in_file, "%u", &raggio);
        fprintf(out_file, "%d\n", recursiveBinarySearch (distanza, 0, N - 1, raggio));
    }

    free(distanza);
}

int main() {
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        return -1;
    }

    pianeta_spritz(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        return -2;
    }

    return 0;
}