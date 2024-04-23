# Algoritmi di ordinamento

## Insertion Sort
```pseudocode
proc InsertionSort (A) {
    for (j = 2 to A.length) {
        key = A[j]
        i = j − 1
        while ((i > 0) and (A[i] > key)) {
            A[i + 1] = A[i]
            i = i − 1
        }
        A[i + 1] = key
    }
}
```

- **utilizzo**: Quando si ha un piccolo numero di elementi da ordinare o quando l'array è già quasi ordinato
- **complessità**: 
    - **caso migliore**: $\Theta(n)$
    - **caso peggiore**: $\Theta(n^2)$
    - **caso medio**: $\Theta(n^2)$

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

- **utilizzo**: Quando si ha un piccolo numero di elementi da ordinare
- **complessità**: 
    - **caso migliore**: $O(n^2)$
    - **caso peggiore**: $O(n^2)$
    - **caso medio**: $O(n^2)$

## MergeSort
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

- **complessità**: $\Theta(n)$

```pseudocode
proc MergeSort (A, p, r) {
    if (p < r) {
        then
        q = [(p + r ) / 2]
        MergeSort(A, p, q)
        MergeSort(A, q + 1, r)
        Merge(A, p, q, r)
    }
}
```

- **utilizzo**: Quando si ha un grande numero di elementi da ordinare e si vuole un algoritmo stabile grazie al suo approccio "divide et conquer"
- **complessità**: $\Theta(n \cdot \log_2(n))$

## QuickSort
```pseudocode
proc Partition (A, p, r) {
    x = A[r]
    i = p − 1
    for (j = p to r − 1) {
        if (A[j] ≤ x) {
            then
            i = i + 1
            SwapValue(A, i, j)
        }
    }
    SwapValue(A, i + 1, r )
    return i + 1
}
```

- **complessità**: $\Theta(n)$

```pseudocode
proc QuickSort (A, p, r) {
    if (p < r) {
        then
        q = Partition(A, p, r)
        QuickSort(A, p, q − 1)
        QuickSort(A, q + 1, r)
    }
}
```

- **utilizzo**: Quando si ha un grande numero di elementi da ordinare e non si ha bisogno di un algoritmo stabile
- **complessità**: 
    - **caso migliore**: $\Theta(n \cdot \log_2(n))$ -> partizione bilanciata (quando si sceglie un pivot che ad ogni passo genera due sottoproblemi di dimensione n/2)
    - **caso peggiore**: $\Theta(n^2)$ -> partizione sbilanciata (quando si sceglie un pivot che ad ogni passo genera due sottoproblemi: uno di dimensione 0 e uno di dimensione n-1)
    - **caso medio**: $O(n \cdot \log_2(n))$

## RandomizedQuickSort
```pseudocode
proc RandomizedPartition (A, p, r) {
    s = p ≤ Random() ≤ r
    SwapValue(A, s, r)
    x = A[r]
    i = p − 1
    for (j = p to r − 1) {
        if (A[j] ≤ x) {
            then
            i = i + 1
            SwapValue(A, i, j)
        }
    }
    SwapValue(A, i + 1, r )
    return i + 1
}
```

- **complessità**: $\Theta(n)$

```pseudocode
proc RandomizedQuickSort (A, p, r) {
    if (p < r) {
        then
        q = RandomizedPartition(A, p, r)
        RandomizedQuickSort(A, p, q − 1)
        RandomizedQuickSort(A, q + 1, r)
    }
}
```

- **utilizzo**: Quando si ha un grande numero di elementi da ordinare e non si ha bisogno di un algoritmo stabile, ma si vuole evitare il caso peggiore di QuickSort
- **complessità**: $O(n \cdot \log_2(n))$

## CountingSort
```pseudocodice
proc CountingSort (A, B, k) {
    let C[0, . . . , k] new array
    for (i = 0 to k) C[i] = 0
    for (j = 1 to A.length) C[A[j]] = C[A[j]] + 1
    for (i = 1 to k) C[i] = C[i] + C[i − 1]
    for (j = A.length downto 1)

    B[C[A[j]]] = A[j]
    C[A[j]] = C[A[j]] − 1
}
```

- **utilizzo**: Quando gli elementi da ordinare sono interi positivi con un range limitato
- **complessità**: $\Theta(n + k)$ con il simbolo $+$ che indica il massimo tra $n$ e $k$

Dove $k$ è il valore massimo dell'array A

## RadixSort
```pseudocodice
proc RadixSort (A, d)
    for (i = 1 to d) AnyStableSort(A) on digit i
```

- **utilizzo**: Sfrutta le singole cifre degli elementi da ordinare ed è efficiente per ordinare interi o stringhe con chiavi di lunghezza fissa
- **complessità**: 
    - **caso peggiore**: $O(d \cdot f(n))$ con $f(n)$ complessità nel caso peggiore dell'algoritmo AnyStableSort
    - **caso medio**: $\Theta(d \cdot (n + k))$

Dove $d$ è il numero di cifre e $k$ è il valore massimo dell'array A

# Algoritmi di ricerca

## Analisi algoritmica
```pseudocode
proc RecursiveBinarySearch (A, low, high, k) {
    if (low > high)
        then return nil
    mid = (high + low)/2
    if (A[mid] = k)
        then return mid
    if (A[mid] < k)
        then return RecursiveBinarySearch(A, mid + 1, high, k)
    if (A[mid] > k)
        then return RecursiveBinarySearch(A, low, mid − 1, k)
}
```

- **utilizzo**: per trovare l'indice dell'elemento $k$ richiesto in un array ordinato, con high e low indici di inizio e fine array
- **complessità**: 
    - **caso migliore**: $\Theta(1)$
    - **caso peggiore**: $\Theta(\log_2(n))$
    - **caso medio**: $\Theta(\log_2(n))$

# Algoritmi per liste, pile e code
## Liste

```pseudocode
proc ListInsert (L, x) {
    x.next = L.head
    if (L.head != nil) {
        L.head.prev = x
    }
    L.head = x
    x.prev = nil
}
```

```pseudocode
proc ListSearch (L, k) {
    x = L.head
    while (x != nil and x.key != k) {
        x = x.next
    }
    return x
}
```

```pseudocode
proc ListDelete (L, x) {
    if (x.prev != nil) {
        x.prev.next = x.next
    } else {
        L.head = x.next
    }
    if (x.next != nil) {
        x.next.prev = x.prev
    }
}
```