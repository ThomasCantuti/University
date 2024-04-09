# Heap, HeapSort, Code di Priorità

## Heap
Le heap sono strutture dati astratte necessariamente compatte parzialmente basate sull'ordinamento e sono semi-ordinate (basata su array)

Utilizzo: come struttura dati per implementare code di priorità e algoritmi di ordinamento (risolve i problemi di MergeSort, non in place, e QuickSort, tempo quadratico nel caso peggiore)

Applicazioni delle heap:
- HeapSort
- Code di Priorità

## Heap binarie su array
(min/max) heap -> array H visto come un albero binario quasi completo

immagine di un array visto come albero binario quasi completo, completo e pieno
```
    0
   / \
  1   2
 / \ / \
```

Una heap è un array che vedo come albero (binario quasi completo) e ne eredita la terminalogia infatti parlo di **nodi**, di **altezza** e di **radice**
- **altezza**: altezza dell'albero (H.length)
- **radice**: primo elemento dell'array (H[1])
- **nodo**: elemento dell'array (H[i])

```pseudocode
proc Parent(i) {
    return i/2 // divisione intera
}

proc Left(i) {
    return 2*i
}

proc Right(i) {
    return 2*i + 1
}

```

max-heap: ogni nodo è maggiore o uguale ai suoi figli -> H[Parent(i)] >= H[i]  
min-heap: ogni nodo è minore o uguale ai suoi figli -> H[Parent(i)] <= H[i]

Esempio di min-heap:
```
![alt text](<Screenshot 2024-04-08 alle 14.43.08.png>)
```

Relazione tra la cardinalità di una heap e l'altezza:
```
    |    h    |     min     |     max     |
    |---------|-------------|-------------|
    |    0    |      1      |      1      |
    |    1    |      2      |      3      |
    |    2    |      4      |      7      |
    |    .    |      .      |      .      |
    |    .    |      .      |      .      |
    |    .    |      .      |      .      |
    |    h    |     2^h     | 2^(h+1) - 1 |
```
2^h ≤ n ≤ 2 h+1 − 1 ⇒ 2 h ≤ n < 2 h+1 ⇒ h ≤ log(n) < h + 1  
Quindi, dalla prima si ottiene che h ≤ log(n) cioè h = O(log(n)), e dalla
seconda che h > log(n) − 1 cioè h = Ω(log(n)). Pertanto h = Θ(log(n))

```pseudocode
proc MinHeapify (H, i) {
    l = Left(i)
    r = Right(i)
    smallest = i
    if ((l ≤ H.heapsize) and (H[l] < H[i]))
        then smallest = l
    if ((r ≤ H.heapsize) and (H[r] < H[smallest]))
        then smallest = r
    if smallest 6 = i {
        then
        SwapValue(H, i, smallest)
        MinHeapify(H, smallest)
    }
}

```

tail ricorsione di MinHeapify: una funzione è in tail ricorsione se l'ultima operazione è la chiamata ricorsiva (si comportacome un'iterazione)

proprietà di MinHeapify:
- **terminazione**: termina per due motivi: se i non cambia durante un'esecuzione o se è diventato più grande della dimensione della heap
- **correttezza**: se i figli sono heap e l'elemento è minore di entrambi allora l'heap è corretto
- **complessità**: considerazioni costo:
    - costo dipende dall'altezza h del nodo su cui viene chiamata -> O(h)
    - pertanto il costo massimo è O(numero di ) -> $\Theta(log(n))$
    - ma queste considerazioni nascondono la vera struttura
    - voglio comunuqe scrivere il costo in termini di ricorrenza
    - $T(n) = T(\frac{2}{3} n) + O(1)$ -> $\Theta(log(n))$ per Master Theorem caso 2

Costruzione min-heap:
```pseudocode
proc BuildMinHeap(H) {
    H.heapsize = H.length
    for (i = H.length/2 downto 1) MinHeapify(H, i)
}
```
i = H.length/2  -> primo indice dove ha senso chiamare MinHeapify

Proprietà di BuildMinHeap:
- **terminazione**: terminazione ovvia per il ciclo for
- **correttezza**: se i figli sono heap e l'elemento è minore di entrambi allora l'heap è corretto
- **complessità**: almeno $\frac{1}{2}\Theta(n)$

## HeapSort:
```pseudocode
proc HeapSort(H) {
    BuildMinHeap(H)
    for (i = H.length downto 2) {
        SwapValue(H, i, 1)
        H.heapsize = H.heapsize - 1
        MinHeapify(H, 1)
    }
}
```
algoritmo di ordinamento in place non stabile con complessità $\Theta(n \cdot log(n))$

## Code di Priorità:
Struttura dati astratta basata su ordinamento e necessariamente compatta (con allocazione vicina come array) dove viene associata ad ogni elemento una chiave (priorità) ed estrae l'elemento con priorità minima