#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex {
    int data;
    char color;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex** adjacencyList;
} Graph;

// Inizializza il grafo
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Vertex**)malloc(numVertices * sizeof(Vertex*));
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    
    return graph;
}

// Inserisce un bordo nel grafo
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

// Inizializza i colori dei vertici
void initializeColors(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->adjacencyList[i];
        while (vertex != NULL) {
            vertex->color = 'B';
            vertex = vertex->next;
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyList[i] != NULL && graph->adjacencyList[i]->color == 'B') {
            Vertex* vertex = graph->adjacencyList[i];
            while (vertex != NULL) {
                vertex->color = 'W';
                Vertex* adjacent = graph->adjacencyList[vertex->data];
                while (adjacent != NULL) {
                    if (adjacent->color == 'B') {
                        adjacent->color = 'W';
                    }
                    adjacent = adjacent->next;
                }
                vertex = vertex->next;
            }
        }
    }
}

// Verifica se ci sono vertici adiacenti con lo stesso colore
bool hasSameColorAdjacent(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->adjacencyList[i];
        while (vertex != NULL) {
            Vertex* adjacent = graph->adjacencyList[vertex->data];
            while (adjacent != NULL) {
                if (vertex->color == adjacent->color) {
                    return true;
                }
                adjacent = adjacent->next;
            }
            vertex = vertex->next;
        }
    }
    return false;
}

void pugilato(FILE* in_file, FILE* out_file) {
    int M, N, v1, v2;
    fscanf(in_file, "%d%d", &M, &N);
    Graph* graph = createGraph(N);

    for (int i = 0; i < M; i++) {
        fscanf(in_file, "%d%d", &v1, &v2);
        insertEdge(graph, v1, v2);
    }

    initializeColors(graph);

    if (hasSameColorAdjacent(graph)) {
        fprintf(out_file, "TRUE");
    } else {
        fprintf(out_file, "FALSE");
    }

    // Libera la memoria allocata
    for (int i = 0; i < N; i++) {
        Vertex* temp = graph->adjacencyList[i];
        while (temp) {
            Vertex* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjacencyList);
    free(graph);
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