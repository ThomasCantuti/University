#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex {
    int data;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex** adjacencyList;
    char* colors;
} Graph;

// Inizializza il grafo
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Vertex**)malloc(numVertices * sizeof(Vertex*));
    graph->colors = (char*)malloc(numVertices * sizeof(char));

    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->colors[i] = 'U'; // U for uncolored
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

// BFS per controllare la bipartizione del grafo
bool isBipartite(Graph* graph, int startVertex) {
    graph->colors[startVertex] = 'R'; // Start coloring with Red

    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        Vertex* temp = graph->adjacencyList[currentVertex];

        while (temp) {
            int adjacent = temp->data;
            if (graph->colors[adjacent] == 'U') {
                graph->colors[adjacent] = (graph->colors[currentVertex] == 'R') ? 'B' : 'R';
                queue[rear++] = adjacent;
            } else if (graph->colors[adjacent] == graph->colors[currentVertex]) {
                free(queue);
                return false;
            }
            temp = temp->next;
        }
    }

    free(queue);
    return true;
}

bool checkBipartite(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->colors[i] == 'U') {
            if (!isBipartite(graph, i)) {
                return false;
            }
        }
    }
    return true;
}

void pugilato(FILE* in_file, FILE* out_file) {
    int M, N, v1, v2;
    fscanf(in_file, "%d%d", &M, &N);
    Graph* graph = createGraph(M);

    for (int i = 0; i < N; i++) {
        fscanf(in_file, "%d%d", &v1, &v2);
        insertEdge(graph, v1, v2);
    }

    if (checkBipartite(graph)) {
        fprintf(out_file, "FALSE");
    } else {
        fprintf(out_file, "TRUE");
    }

    // Libera la memoria allocata
    for (int i = 0; i < M; i++) {
        Vertex* temp = graph->adjacencyList[i];
        while (temp) {
            Vertex* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjacencyList);
    free(graph->colors);
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
