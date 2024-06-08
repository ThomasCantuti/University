#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Vertex {
    int data;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    int numVertices;
    int* color;
    Vertex** adjacencyList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Vertex**)malloc(numVertices * sizeof(Vertex*));
    graph->color = (int*)malloc(numVertices * sizeof(int));
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->color[i] = -1;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->data = dest;
    newVertex->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newVertex;

    newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->data = src;
    newVertex->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newVertex;
}

bool isBipartite(Graph* graph, int src) {
    int* colorArr = graph->color;
    colorArr[src] = 1;
    
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];
        
        Vertex* temp = graph->adjacencyList[u];
        while (temp) {
            int v = temp->data;

            if (colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                queue[rear++] = v;
            } else if (colorArr[v] == colorArr[u]) {
                free(queue);
                return false;
            }
            temp = temp->next;
        }
    }

    free(queue);
    return true;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
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
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }
    
    int N, M;
    fscanf(file, "%d %d", &N, &M);
    
    Graph* graph = createGraph(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        fscanf(file, "%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    fclose(file);

    bool result = true;
    for (int i = 0; i < N; i++) {
        if (graph->color[i] == -1) {
            if (!isBipartite(graph, i)) {
                result = false;
                break;
            }
        }
    }

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Could not open file\n");
        freeGraph(graph);
        return 1;
    }

    if (result) {
        fprintf(file, "TRUE\n");
    } else {
        fprintf(file, "FALSE\n");
    }
    fclose(file);

    freeGraph(graph);
    return 0;
}