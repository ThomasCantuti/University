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