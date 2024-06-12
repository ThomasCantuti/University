#include <stdio.h>
#include <stdlib.h>

struct Node {
    int representative;
    int size;
};

struct Edge {
    int src;
    int dst;
    int w;
};

// comparatore di pesi
// const = puntatore che non deve cambiare in memoria
// void = non si sa la dimensione
// ogni volta che il peso del primo elemento è minore del secondo --> esegui uno scambio
// ordinamento decrescente
int weights_comparator (const void *x, const void *y) {
    const struct Edge *a = x;
    const struct Edge *b = y;
    return a->w < b->w;
}

struct Cart {
    int value;
    int original_idx;
};

int carts_comparator (const void *x, const void *y) {
    const struct Cart *a = x;
    const struct Cart *b = y;
    return a->value < b->value;
}

int find (int n, struct Node *nodes) {
    while (n != nodes[n].representative) {
        n = nodes[n].representative;
    }
    return n;
}

void merge (int a, int b, struct Node *nodes) {
    a = find(a, nodes);
    b = find(b, nodes);

    if (nodes[a].size < nodes[b].size) {
        int temp = a;
        a = b;
        b = temp;
    }

    nodes[a].size += nodes[b].size;
    nodes[b].representative = a;
}

int same (int a, int b, struct Node *nodes) {
    return find(a, nodes) == find(b, nodes);
}

void kruskal (
    struct Node *nodes,
    struct Edge *edges,
    int n_edges,
    int current_weight,
    int *last_index,
    int *last_answer
) {
    while (*last_index < n_edges) {
        // se peso attuale > peso arco considerato ora --> esco
        if (current_weight > edges[*last_index].w)
            return;
        
        // rispetto all'arco che sto visitando prendo:
        int src_id = edges[*last_index].src; // punto di partenza
        int dst_id = edges[*last_index].dst; // punto di arrivo

        // se i due elementi non sono nello stesso gruppo
        if (!same(src_id, dst_id, nodes)) {
            // union tra partenza e arrivo in nodes
            merge(src_id, dst_id, nodes);
            // ho visitato un nodo che prima non si poteva raggiungere
            // quindi numero di utilizzi del rimpicciolitore diminuisce
            (*last_answer)--;
        }

        // passo al prossimo arco
        (*last_index)++;
    }
}

void castori (FILE* in_file, FILE* out_file) {
    int N, K, T;
    fscanf(in_file, "%d%d%d", &N, &K, &T);

    struct Node nodes[N]; // array di nodi
    struct Edge edges[K]; // array di archi
    struct Cart carts[T]; // array di carrelli
    int answers[T]; // array di riposte per ogni carrello

    // makeSet
    for (int i = 0; i < N; i ++) {
        nodes[i].representative = i;
        nodes[i].size = 1;
    }

    // creazione grafo
    for (int i = 0; i < K; i ++)
        fscanf(in_file, "%d%d%d", &edges[i].src, &edges[i].dst, &edges[i].w);

    // ordinamento decrescente
    qsort(edges, K, sizeof(struct Edge), weights_comparator);

    for (int i = 0; i < T; i ++) {
        fscanf(in_file, "%d", &carts[i].value);
        carts[i].original_idx = i;
    }

    // ordinamento dei carrelli -> dal più largo al più stretto
    qsort(carts, T, sizeof(struct Cart), carts_comparator);

    int last_index = 0; // punto in cui si trova il programma l'ultima volta che esce dalla funzione
    int last_answer = N - 1; // risposta attuale associata al current_weight
    for (int i = 0; i < T; i ++) {
        int current_weight = carts[i].value;
        kruskal(nodes, edges, K, current_weight, &last_index, &last_answer);
        answers[carts[i].original_idx] = last_answer;
    }

    for (int i = 0; i < T; i ++)
        fprintf(out_file, "%d\n", answers[i]);
}

int main () {
    FILE* in_file = fopen("input.txt", "r");
    FILE* out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -1;
    }

    castori(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    return 0;
}