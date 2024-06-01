# Tassonomia
- **statica o dinamica**:
    - **statica**: se la dimensione è fissata a priori
    - **dinamica**: se la dimensione può variare durante l'esecuzione (a runtime)
- **compatta o sparsa**:
    - **sparse**: gli elementi sono virtualmente vicini, ma fisicamente non sappiamo dove si trovano
  - **compatta**: gli elementi si trovano in posizioni fisiche di memoria contigue
- **basate o non basate su ordinamento di chiavi**:
    - **basate su ordinamento**: se gli elementi sono ordinati secondo una chiave
    - **non basate su ordinamento**: se non c'è alcuna relazione con una chiave

# Liste
Struttura dati dinamica, sparsa, non basata sull'ordinamento

```pseudocode
typedef struct {
    int key;
    struct elemLista *succ;
    struct elemLista *prec;
} elemLista;


typedef struct {
    struct elemLista *head;
    int numel;
} List;


List *L;
L.head = nil;
L.numel = 0;
```

# Pile
Struttura dati dinamica, non basata sull'ordinamento, sparsa (basata su liste) o compatta (basata su array)

## Pile basate su array
```pseudocode
typedef struct {
    int key;
} elemPila;
```

## Pile basate su liste
```pseudocode
typedef struct {
    int key;
    struct elemPila *next;
} elemPila;
```

# Code
Struttura dati dinamica, non basata sull'ordinamento, sparsa (basata su liste) o compatta (basata su array)

## Code basate su array
```pseudocode
typedef struct {
    int key;
} elemCoda;
```

## Code basate su liste
```pseudocode
typedef struct {
    int key;
    struct elemCoda *next;
} elemCoda;
```

# Heap
Struttura dati astratta statica o dinamica, compatta, parzialmente basata sull'ordinamento (mantiene le chiavi semi-ordinate)

```pseudocode
typedef struct {
    int H[..];
    int length;
    int heapsize;
} Heap
```

# Code di priorità
Struttura dati astratta statica o dinamica, compatta, basata sull'ordinamento

## Code di priorità su heap binarie
```pseudocode
typedef struct {
    int Q[..];
    int length;
    int heapsize;
    int priority;
} Queue
```

## Code di priorità su array
```pseudocode
typedef struct {
    int Q[..];
    int index;
    int priority;
    bool flag_empty;
} Queue
```

# Tabella Hash
Struttura dati astratta, dinamica, parzialmente compatta e non basata sull'ordinamento

## Tabella Hash con Chaining
```pseudocode
typedef struct {
    int key;
    int value;
    struct Nodo *next;
} Nodo;

typedef struct {
    Nodo *T[];
    int capacity;
} HashTable
```

## Tabella Hash con Open Hashing
```pseudocode
typedef struct {
    int key
    int value
    bool isOccupied
} Entry;

typedef struct {
    Entry *T[];
    int capacity; // Dimensione array
    int size; // Numero attuale di elementi
} HashTable
```

# Insiemi disgiunti

## Insiemi disgiunti con liste

## Insiemi disgiunti con liste e unione pesata

## Insiemi disgiunti con alberi

# Alberi

## Alberi binari di ricerca (BST)

## Alberi Red-Black (RBT)

## Alberi bilanciati (BT)

# Grafi

## Grafi per BFS

## Grafi per DFS

## Grafi per copertura minima

## Grafi per cammini minimi con sorgente singola

## Grafi per cammini minimi con sorgente multipla