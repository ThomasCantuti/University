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

// Verifica se un vertice è presente nel grafo
int isPresent(Graph* graph, int vertex) {
    int foundVertex = 0;
    
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* currentVertex = graph->adjacencyList[i];
        while (currentVertex != NULL) {
            if (currentVertex->data == vertex) {
                foundVertex = 1;
                return 1;
            }
            currentVertex = currentVertex->next;
        }
        if (foundVertex) {
            return 0;
        }
    }
}

// Connette due vertici se uno dei due è presente, altrimenti crea la connessione
void connectVertices(Graph* graph, int vertex1, int vertex2) {
    int foundVertex1 = 0;
    int foundVertex2 = 0;
    
    // Verifica se vertice 1 è nel grafo
    if (isPresent(graph, vertex1))
        foundVertex1 = 1;
    
    // Verifica se vertice 2 è nel grafo
    if (isPresent(graph, vertex2))
        foundVertex2 = 1;
    
    // Connette i vertici se uno dei due è presente, altrimenti crea la connessione
    if (foundVertex1) {
        Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
        newVertex->data = vertex2;
        newVertex->next = graph->adjacencyList[vertex1];
        graph->adjacencyList[vertex1] = newVertex;
    } else if (foundVertex2) {
        Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
        newVertex->data = vertex1;
        newVertex->next = graph->adjacencyList[vertex2];
        graph->adjacencyList[vertex2] = newVertex;
    } else {
        Vertex* newVertex1 = (Vertex*)malloc(sizeof(Vertex));
        newVertex1->data = vertex2;
        newVertex1->next = graph->adjacencyList[vertex1];
        graph->adjacencyList[vertex1] = newVertex1;
        
        Vertex* newVertex2 = (Vertex*)malloc(sizeof(Vertex));
        newVertex2->data = vertex1;
        newVertex2->next = graph->adjacencyList[vertex2];
        graph->adjacencyList[vertex2] = newVertex2;
    }
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

// Inizializza i colori dei vertici
void initializeColors(Graph* graph) {
    for (int i = 0; i < graph->numVertices || graph->adjacencyList[i] == NULL; i++) {
        if (graph->adjacencyList[i] != NULL && graph->color[i] == 'B') {
            Vertex* vertex;
            for (vertex = graph->adjacencyList[i]; vertex != NULL; vertex = vertex->next) {
                graph->color[vertex->data] = 'W';
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
                if (graph->color[vertex[i].data] == graph->color[adjacent->data]) {
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
    Graph* graph = createGraph(M);

    for (int i = 0; i < N; i++) {
        fscanf(in_file, "%d%d", &v1, &v2);
        connectVertices(graph, v1, v2);
    }

    initializeColors(graph);

    if (hasSameColorAdjacent(graph)) {
        fprintf(out_file, "FALSE");
    } else {
        fprintf(out_file, "TRUE");
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
    free(graph->color);
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
