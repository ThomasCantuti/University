#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define IN_FILE_NAME  "input.txt"
#define OUT_FILE_NAME "output.txt"
 
#define WHITE -1
#define RED 0
#define BLUE 1
 
 
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;
 
 
typedef struct {
    int num_vertices;
    Node **adj_lists;
    int *colors;
} Graph;
 
 
typedef struct {
    int *array;
    int top;
    int max_size;
} Stack;
 
 
Node *create_node(int vertex) {
    Node *new_node = (Node *) malloc(sizeof(Node));
 
    new_node->vertex = vertex;
    new_node->next = NULL;
 
    return new_node;
}
 
 
Graph *create_graph(int vertices) {
    Graph *graph;
 
    graph = (Graph *) malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    graph->adj_lists = (Node **) malloc(vertices * sizeof(Node *));
    graph->colors = (int *) malloc(vertices * sizeof(int));
 
    for (int i = 0; i < vertices; i++) {
        graph->adj_lists[i] = NULL;
        graph->colors[i] = WHITE;
    }
 
    return graph;
}
 
 
void add_edge_graph(Graph *graph, int src, int dest) {
    Node *new_node;
 
    new_node = create_node(dest);
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
 
    new_node = create_node(src);
    new_node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = new_node;
}
 
 
void free_graph(Graph *graph) {
    Node *adj_list, *tmp;
 
    for (int v = 0; v < graph->num_vertices; v++) {
        adj_list = graph->adj_lists[v];
        while (adj_list != NULL) {
            tmp = adj_list;
            adj_list = adj_list->next;
            free(tmp);
        }
    }
 
    free(graph->adj_lists);
    free(graph->colors);
    free(graph);
}
 
 
Stack *create_stack(int max_size) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
 
    stack->array = (int *) malloc(max_size * sizeof(int));
    stack->top = -1;
    stack->max_size = max_size;
 
    return stack;
}
 
 
void push_stack(Stack *stack, int value) {
    stack->array[++stack->top] = value;
}
 
 
int pop_stack(Stack *stack) {
    return stack->array[stack->top--];
}
 
 
bool is_empty_stack(Stack *stack) {
    return stack->top == -1;
}
 
 
void free_stack(Stack *stack) {
    free(stack->array);
    free(stack);
}
 
bool is_bipartite(Graph *graph, Stack *stack, int start_vertex) {
    Node *adj_node;
    int current_vertex, adj_vertex;
 
    push_stack(stack, start_vertex);
    graph->colors[start_vertex] = RED;
 
    while (!is_empty_stack(stack)) {
        current_vertex = pop_stack(stack);
        adj_node = graph->adj_lists[current_vertex];
 
        while (adj_node != NULL) {
            adj_vertex = adj_node->vertex;
 
            if (graph->colors[adj_vertex] == WHITE) {
                graph->colors[adj_vertex] = (graph->colors[current_vertex] == RED) ? BLUE : RED;
                push_stack(stack, adj_vertex);
            } else if (graph->colors[adj_vertex] == graph->colors[current_vertex]) {
                return false;
            }
 
            adj_node = adj_node->next;
        }
    }
 
    return true;
}
 
 
bool can_be_partitioned(Graph *graph) {
    Stack *stack;
 
    stack = create_stack(graph->num_vertices);
 
    for (int node_vertex = 0; node_vertex < graph->num_vertices; node_vertex++) {
        if (graph->colors[node_vertex] == WHITE) {
            if (!is_bipartite(graph, stack, node_vertex)) {
                free_stack(stack);
                return false;
            }
        }
    }
 
    free_stack(stack);
 
    return true;
}
 
 
int main() {
    int n, m;
    int boxer1, boxer2;
 
    Graph *g;
 
    FILE *fp_in, *fp_out;
 
    // Apri file di input/output
    fp_in = fopen(IN_FILE_NAME, "r");
    fp_out = fopen(OUT_FILE_NAME, "w");
 
    // Leggi la prima riga dell'input
    fscanf(fp_in, "%d %d", &n, &m);
 
    // Crea un grafo con n nodi
    g = create_graph(n);
 
    // Leggi dall'input gli archi
    for (int i = 0; i < m; i++) {
        fscanf(fp_in, "%d %d", &boxer1, &boxer2);
        add_edge_graph(g, boxer1, boxer2);
    }
 
    // Stampa se il grafo ha cicli o meno eseguendo DFS
    fprintf(fp_out, (can_be_partitioned(g)) ? "TRUE\n" : "FALSE\n");
 
    // Chiudi i file e dealloca l'array
    free_graph(g);
    fclose(fp_in);
    fclose(fp_out);
 
    return 0;
}