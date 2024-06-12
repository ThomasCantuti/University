#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// Struttura dell'arco
typedef struct {
    int src, dest, weight;
} Edge;

// Struttura del grafo
typedef struct {
    int V, E;
    Edge* edge;
} Graph;

// Funzione per creare un grafo con V vertici e E archi
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Funzione per creare i collegamenti tra i vertici
void addEdge(Graph* graph, int edge_index, int src, int dest, int weight) {
    if (edge_index >= graph->E) {
        printf("Edge index out of bounds.\n");
        return;
    }
    graph->edge[edge_index].src = src;
    graph->edge[edge_index].dest = dest;
    graph->edge[edge_index].weight = weight;
}

// Struttura per rappresentare un sottoinsieme per l'unione-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Funzione per trovare il set di un elemento i (usando il path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Funzione per unire due insiemi x e y (usando union by rank)
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Funzione per confrontare due archi. Usata per qsort()
int compare(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

// Implementazione dell'algoritmo di Kruskal
int MST_Kruskal(Graph* graph) {
    int V = graph->V;
    Edge result[V];  // T[] contiene l'albero di copertura minimo
    int e = 0;  // Indice per result[]
    int i = 0;  // Indice per gli archi ordinati
    int minCost = 0;  // Somma dei costi degli archi nell'MST

    // Ordina tutti gli archi in ordine non decrescente di peso
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // Alloca memoria per creare V sottogruppi con un elemento ciascuno
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    // Crea V insiemi con un solo elemento
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Numero di archi da aggiungere per creare l'albero di copertura minimo sarà V-1
    while (e < V - 1 && i < graph->E) {
        // Prendi il prossimo arco più piccolo
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // Se l'inclusione di questo arco non causa un ciclo, includilo nel risultato
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
            minCost += next_edge.weight;  // Aggiungi il peso dell'arco al costo totale
        }
    }

    // Stampa i risultati
    printf("Edges in the constructed MST\n");
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    // Libera la memoria allocata
    free(subsets);

    return minCost;  // Restituisce il costo totale dell'MST
}

void sfortuna(FILE* in_file, FILE* out_file) {
    int N, M, v1, v2, w;
    fscanf(in_file, "%d%d", &N, &M);
    Graph* graph = createGraph(N, M);

    for (int i = 0; i < M; i++) {
        fscanf(in_file, "%d%d%d", &v1, &v2, &w);
        addEdge(graph, i, v1, v2, w);
    }

    fprintf(out_file, "%d", MST_Kruskal(graph));

    // Libera la memoria allocata
    free(graph->edge);
    free(graph);
}

int main() {
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