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
    int *pred;
    Vertex** adjacencyList;
} Graph;

// Inizializza il grafo
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Vertex**)malloc(numVertices * sizeof(Vertex*));
    graph->color = (char*)malloc(numVertices * sizeof(char*));
    graph->pred = (int*)malloc(numVertices * sizeof(int*));
    
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->color[i] = 'B';
        graph->pred[i] = -1;
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

void DepthVisit (Graph *graph, Vertex *vertex, int i) {
    graph->color[i] = 'W';
    for (vertex = graph->adjacencyList[i]; vertex != NULL; vertex = vertex->next) {
        if (graph->color[vertex->data] == 'B') {
            graph->pred[vertex->data] = i;
            if (vertex->next != NULL)
                DepthVisit(graph, vertex, vertex->data);
        }
    }
    if (vertex != NULL)
        graph->color[vertex->data] = 'G';
}

void DepthFirstSearch (Graph *graph) {
    for (int i = 0; i < graph->numVertices; i ++) {
        if (graph->adjacencyList[i] != NULL && graph->color[i] == 'B')
            DepthVisit(graph, graph->adjacencyList[i], i);
    }
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
void initializeColors(Graph* graph, FILE *out_file) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->color[i] == 'B') {
            graph->color[i] = 'W';
            for (Vertex* vertex = graph->adjacencyList[i]; vertex != NULL; vertex = vertex->next) {
                if (graph->color[vertex->data] == 'B' && graph->color[graph->pred[vertex->data]] == 'G')
                    graph->color[vertex->data] = 'W';
                if (graph->color[vertex->data] == 'B' && graph->color[graph->pred[vertex->data]] == 'W')
                    graph->color[vertex->data] = 'G';
            }
        }
        for (Vertex* vertex = graph->adjacencyList[i]; vertex != NULL; vertex = vertex->next)
            fprintf(out_file, "%d %c ", vertex->data, graph->color[vertex->data]);
        fprintf(out_file, "\n");
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
    for (int i = 0; i < graph->numVertices; i++) {
        for (Vertex* vertex = graph->adjacencyList[i]; vertex != NULL; vertex = vertex->next) {
            //if (i == 5905) {
                //for (Vertex* vertexAdj = vertex; vertexAdj != NULL; vertexAdj = vertexAdj->next)
                    //printf("%d %c ", vertexAdj->data, graph->color[vertexAdj->data]);
            if (graph->color[i] == graph->color[graph->adjacencyList[i]->data]) {
                printf("%d %c %d %c", i, graph->color[i], graph->adjacencyList[i]->data, graph->color[graph->adjacencyList[i]->data]);
                return true;
            }
            //}
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
    free(graph->pred);
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

    DepthFirstSearch(graph);

    for (int i = 0; i < graph->numVertices; i ++)
        graph->color[i] = 'B';

    initializeColors(graph, out_file);

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