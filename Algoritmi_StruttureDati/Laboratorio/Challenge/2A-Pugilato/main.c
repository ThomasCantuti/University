#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex {
    int data;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    char *color;
    Vertex** adjacencyList;
} Graph;

// Inizializza il grafo
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Vertex**)malloc(numVertices * sizeof(Vertex*));
    graph->color = (char*)malloc(numVertices * sizeof(char*));
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->color[i] = 'B';
    }
    
    return graph;
}

// Inserisce un vertice nel grafo
void insertEdge(Graph* graph, int vertex1, int vertex2) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->data = vertex2;
    newVertex->next = graph->adjacencyList[vertex1];
    graph->adjacencyList[vertex1] = newVertex;

    newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->data = vertex1;
    newVertex->next = graph->adjacencyList[vertex2];
    graph->adjacencyList[vertex2] = newVertex;
}

/*
Inizializza i colori dei vertici:
for (u in G.V)
    if (u.color = B)
        for (v in G.Adj[u])
            v.color = W

Per ogni vertice
    se il colore del vertice è Black
        per ogni adiacente al vertice
            adiacente = White
*/
void initializeColors(Graph* graph) {
    for (int i = 0; i < graph->numVertices || graph->adjacencyList[i] == NULL; i++) {
        if (graph->adjacencyList[i] != NULL && graph->color[i] == 'B') {
            for (Vertex* vertex = graph->adjacencyList[i]; vertex != NULL; vertex = vertex->next) {
                graph->color[vertex->data] = 'W';
            }
        }
    }
}

/*
Verifica se ci sono vertici adiacenti con lo stesso colore:
for (u in G.V)
    for (v in G.Adj[u])
        if (u.color = v.color)
            return true
return false

Per ogni vertice
    per ogni adiacente al vertice
        se colore vertice = colore adiacente
            return true -> insieme non possibile
return false -> insieme possibile
*/
bool hasSameColorAdjacent(Graph* graph) {
    for (int i = 0; i < graph->numVertices && graph->adjacencyList[i] != NULL; i++) {
        for (Vertex* vertex = graph->adjacencyList[i]; vertex != NULL; vertex = vertex->next) {
            if (graph->color[i] == graph->color[graph->adjacencyList[i]->data]) {
                return true;
            }
        }
    }
    return false;
}

void free_graph(Graph *graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Vertex* adjacencyList = graph->adjacencyList[v];
        while (adjacencyList != NULL) {
            Vertex* tmp = adjacencyList;
            adjacencyList = adjacencyList->next;
            free(tmp);
        }
    }
 
    free(graph->adjacencyList);
    free(graph->color);
    free(graph);
}

void pugilato(FILE* in_file, FILE* out_file) {
    int M, N, v1, v2;
    fscanf(in_file, "%d%d", &M, &N);
    Graph* graph = createGraph(M);

    for (int i = 0; i < N; i++) {
        fscanf(in_file, "%d%d", &v1, &v2);
        insertEdge(graph, v1, v2);
    }

    initializeColors(graph);

    if (hasSameColorAdjacent(graph)) {
        fprintf(out_file, "FALSE");
    } else {
        fprintf(out_file, "TRUE");
    }

    // Libera la memoria allocata
    free_graph(graph);
}

int main() {
    FILE* in_file = fopen("input.txt", "r");
    FILE* out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "I/O Error");
        return -1;
    }

    pugilato(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        fprintf(stderr, "I/O Error");
        return -2;
    }

    return 0;
}