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

void mergeSort(double* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int recursiveBinarySearch(double* arr, int start, int end, unsigned int radius) {
    if (start >= end) {
        if (radius >= arr[start]) return start + 1;
        if (radius < arr[start]) return start;
    }

    int mid = (start + end) / 2;

    if (arr[mid] <= radius) {
        return recursiveBinarySearch(arr, mid+1, end, radius);
    } else {
        return recursiveBinarySearch(arr, start, mid-1, radius);
    }
}

void pianetaSpritz(FILE* in_file, FILE *out_file) {
    int N, Q;   
    fscanf(in_file, "%d %d", &N, &Q);

    unsigned int radius;
    double* distance = (double*) calloc(N, sizeof(double));

    for (int i=0; i<N; i++) {
        long long x, y, z;
        fscanf(in_file, "%lld %lld %lld", &x, &y, &z);
        distance[i] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    mergeSort(distance, 0, N-1);

    for (int i=0; i<Q; i++) {
        fscanf(in_file, "%u", &radius);
        fprintf(out_file, "%d\n", recursiveBinarySearch(distance, 0, N-1, radius));
    }

    free(distance);
}

int main(void) {
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");

    if (in_file == NULL || out_file == NULL) {
        return -1;
    }   

    pianetaSpritz(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        return -2;
    }

    return 0;
}