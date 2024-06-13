#include <stdio.h>
#include <stdlib.h>

struct Node {
    int representative;
    int size;
};

struct Edge {
    int src;
    int dst;
    long long w;
};

int weights_comparator (const void *x, const void *y) {
    const struct Edge* a = x;
    const struct Edge* b = y;
    return a->w > b->w;
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

long long kruskal (struct Node* nodes, struct Edge* edges, int num_edges) {
    long long cost = 0;

    for (int i = 0; i < num_edges; i ++) {
        if (!same(edges[i].src, edges[i].dst, nodes)) {
            merge (edges[i].src, edges[i].dst, nodes);
            cost += edges[i].w;
        }
    }
    return cost;
}

void sfortuna (FILE* in_file, FILE* out_file) {
    int N, M;
    fscanf(in_file, "%d%d", &N, &M);

    // creazione grafo
    struct Edge edges[M];
    for (int i = 0; i < M; i ++)
        fscanf(in_file, "%d%d%lld", &edges[i].src, &edges[i].dst, &edges[i].w);
    
    // creazione set
    struct Node nodes[N];
    for (int i = 0; i < N; i ++) {
        nodes[i].representative = i;
        nodes[i].size = 1;
    }
    
    qsort(edges, (size_t)M, sizeof(struct Edge), weights_comparator);

    fprintf(out_file, "%lld", kruskal(nodes, edges, M));
}

int main (void) {
    FILE* in_file = fopen("input.txt", "r");
    FILE* out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -1;
    }

    sfortuna(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    return 0;
}