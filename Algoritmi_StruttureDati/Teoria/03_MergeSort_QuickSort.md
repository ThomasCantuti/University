# MergeSort e QuickSort

## Algoritmi elementari
metodi basati sui confronti:

ogni elemento viene spostato verso il/al posto giusto separatamente dagli altri, in maniera iterativa o ricorsiva (es. InsertionSort, SelectionSort, BubbleSort, ...)

## SelectionSort
```pseudocode
proc SelectionSort (A) {
    for (j = 1 to A.length - 1) {
        min = j
        for (i = j + 1 to A.length) {
            if (A[i] < A[min])
                then min = i
        SwapValue(A, min, j)
        }
    }
}
```

dimostrazione

## MergeSort
### Merge
prima si studia un algoritmo che risolve il problema di costruire una sequenza ordinata partendo da due sequenze ordinate

Input -> Array A, indici p,q,r con $p\leq q \leq r$ e A[p, ..., q] e A[q+1, ..., r] sono ordinati
Output -> A[p, ..., r] ordinato

```pseudocode
proc Merge (A, p, q, r) {
    n1 = q − p + 1
    n2 = r − q
    let L[1, . . . , n1] and R[1, . . . , n2] be new array
    for (i = 1 to n1) L[i] = A[p + i − 1]
    for (j = 1 to n2) R[j] = A[q + j]
    i = 1
    j = 1
    for (k = p to r ){
        if (i ≤ n1){
            then
            if (j ≤ n2){ --> L e R non sono ancora finiti
                then
                if (L[i] ≤ R[j]){
                    then CopyFromL(i)
                    else CopyFromR(j)
                }
                else CopyFromL(i) --> L non è ancora finito ma R si
            }
            else CopyFromR(j) --> R non è ancora finito ma L si
        }
    }
}
```

dimostrazione

- **terminazione** -> i primi due cicli for terminano per $i = n_1$ e $j = n_2$ mentre il terzo for ...
- **correttezza** -> 
- **complessità** -> i primi due cicli for sono $\Theta(n_1)$ e $\Theta(n_2)$ quindi uguali a $\Theta(n)$ e il terzo for vale $\Theta(n)$ quindi la complessità vale $\Theta(n)$ e non devo distinguere tra i tre casi

### MergeSort
si usa l'algoritmo Merge come sotto-funzione per un nuovo algoritmo di ordinamento

```pseudocode
proc MergeSort (A, p, r) {
    if (p < r ){
        then
        q = [(p + r )/2]
        MergeSort(A, p, q)
        MergeSort(A, q + 1,r )
        Merge(A, p, q,r )
    }
}
```
image di dimostrazione slide 14

- **terminazione** -> ad ogni chiamata la distanza tra p e r deve diminuire, si effettua la nuova chiamata solo se $p \lt r$
- **correttezza** -> con invariante ricorsiva ovvero dopo ogni chiamata ricorsiva MergeSort(A, p, r), A[p, ..., r] è ordinato
    - caso base -> 
    - caso induttivo -> 
- **complessità** -> $T(n) = 2 * T(\frac{n}{2}) + \Theta(n)$ anche se in realtà sarebbe $T(n) = \Theta(n * \log(n))$ (Master Theorem caso II)

