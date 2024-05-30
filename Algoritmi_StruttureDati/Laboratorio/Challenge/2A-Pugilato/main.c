#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjacencyList;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
    
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

int isPresent(Graph* graph, int vertex) {
    int foundVertex = 0;
    
    // Check if the vertex is present in the graph
    for (int i = 0; i < graph->numVertices; i++) {
        Node* currentNode = graph->adjacencyList[i];
        while (currentNode != NULL) {
            if (currentNode->data == vertex) {
                foundVertex = 1;
                return 1;
            }
            currentNode = currentNode->next;
        }
        if (foundVertex) {
            return 0;
        }
    }
}

void connectVertices(Graph* graph, int vertex1, int vertex2) {
    int foundVertex1 = 0;
    int foundVertex2 = 0;
    
    // Check if vertex1 is present in the graph
    if (isPresent(graph, vertex1))
        foundVertex1 = 1;
    
    // Check if vertex2 is present in the graph
    if (isPresent(graph, vertex2))
        foundVertex2 = 1;
    
    // Connect the vertices if one of them is present, otherwise create the connection
    if (foundVertex1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = vertex2;
        newNode->next = graph->adjacencyList[vertex1];
        graph->adjacencyList[vertex1] = newNode;
    } else if (foundVertex2) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = vertex1;
        newNode->next = graph->adjacencyList[vertex2];
        graph->adjacencyList[vertex2] = newNode;
    } else {
        Node* newNode1 = (Node*)malloc(sizeof(Node));
        newNode1->data = vertex2;
        newNode1->next = graph->adjacencyList[vertex1];
        graph->adjacencyList[vertex1] = newNode1;
        
        Node* newNode2 = (Node*)malloc(sizeof(Node));
        newNode2->data = vertex1;
        newNode2->next = graph->adjacencyList[vertex2];
        graph->adjacencyList[vertex2] = newNode2;
    }
}

int hasCycle(Graph* graph) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(graph, i, -1, visited)) {
                free(visited);
                return 1;
            }
        }
    }
    
    free(visited);
    return 0;
}

int hasCycleUtil(Graph* graph, int vertex, int parent, int* visited) {
    visited[vertex] = 1;
    
    Node* currentNode = graph->adjacencyList[vertex];
    while (currentNode != NULL) {
        if (!visited[currentNode->data]) {
            if (hasCycleUtil(graph, currentNode->data, vertex, visited)) {
                return 1;
            }
        } else if (currentNode->data != parent) {
            return 1;
        }
        currentNode = currentNode->next;
    }
    
    return 0;
}

void pugilato (FILE *in_file, FILE *out_file) {
    int N, M;
    int v1, v2;
    Graph* graph;
    fscanf(in_file, "%d %d", &N, &M);
    if (N < 2)
        fprintf(out_file, "FALSE");
    else {
        graph = createGraph(N-1);
        for (int i = 0; i < M; i ++) {
            fscanf(in_file, "%d %d", &v1, &v2);
            connectVertices(graph, v1, v2);
        }
        if (hasCycle(graph))
            fprintf(out_file, "FALSE");
        else
            fprintf(out_file, "TRUE");
    }
    
}

int main() {
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");
    
    if (in_file == NULL || out_file == NULL) {
        return -1;
    }

    pugilato(in_file, out_file);

    if (fclose(in_file) != 0 || fclose(out_file) != 0) {
        return -2;
    }

    return 0;
}