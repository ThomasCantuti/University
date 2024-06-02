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

// Funzione che crea il grafo
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    
    return graph;
}

// Verifica se un vertice è presente nel grafo
int isPresent(Graph* graph, int vertex) {
    int foundVertex = 0;
    
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

// Conta il numero di archi nei cicli del grafo
int countCycles(Graph* graph) {
    int count = 0;
    
    for (int i = 0; i < graph->numVertices; i++) {
        Node* currentNode = graph->adjacencyList[i];
        while (currentNode != NULL) {
            int startVertex = i;
            int currentVertex = currentNode->data;
            
            // Verifica se il ciclo è chiuso
            if (isCycleClosed(graph, startVertex, currentVertex)) {
                count++;
            }
            
            currentNode = currentNode->next;
        }
    }
    
    return count;
}

// Funzione ausiliaria per verificare se un ciclo è chiuso
int isCycleClosed(Graph* graph, int startVertex, int currentVertex) {
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    
    visited[currentVertex] = 1;
    
    return isCycleClosedUtil(graph, startVertex, currentVertex, visited);
}

// Funzione ausiliaria ricorsiva per verificare se un ciclo è chiuso
int isCycleClosedUtil(Graph* graph, int startVertex, int currentVertex, int visited[]) {
    Node* currentNode = graph->adjacencyList[currentVertex];
    while (currentNode != NULL) {
        int nextVertex = currentNode->data;
        
        // Se il prossimo vertice è il vertice di partenza, il ciclo è chiuso
        if (nextVertex == startVertex) {
            return 1;
        }
        
        // Se il prossimo vertice non è stato visitato, continua la ricorsione
        if (!visited[nextVertex]) {
            visited[nextVertex] = 1;
            if (isCycleClosedUtil(graph, startVertex, nextVertex, visited)) {
                return 1;
            }
        }
        
        currentNode = currentNode->next;
    }
    
    return 0;
}

// Soluzione
void pugilato (FILE *in_file, FILE *out_file) {
    int N, M;
    int v1, v2;
    Graph* graph;
    fscanf(in_file, "%d %d", &N, &M);
    if (N < 2)
        fprintf(out_file, "FALSE");
    else {
        graph = createGraph(M);
        for (int i = 0; i < M; i ++) {
            fscanf(in_file, "%d %d", &v1, &v2);
            connectVertices(graph, v1, v2);
        }
        for (int i = 0; i < M; i ++)
            printf("%d ", graph->adjacencyList[i]->data);
        if (countCycles(graph) % 2 != 0)
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