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

## HeapSort
```pseudocode
proc HeapSort(H) {
    BuildMaxHeap(H) // oppure BuildMinHeap(H)
    for (i = H.length downto 2) {
        SwapValue(H, i, 1)
        H.heapsize = H.heapsize - 1
        MaxHeapify(H, 1) // oppure MinHeapify(H, 1)
    }
}
```

- **utilizzo**: Ordina una Min/Max-Heap in modo instable e inplace
- **complessità**: $\Theta(n \cdot \log(n))$

# Algoritmi di ricerca

## Recursive Binary Search
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

- **utilizzo**: Per trovare l'indice dell'elemento $k$ richiesto in un array ordinato, con high e low indici di inizio e fine array
- **complessità**: 
    - **caso migliore**: $\Theta(1)$
    - **caso peggiore**: $\Theta(\log_2(n))$
    - **caso medio**: $\Theta(\log_2(n))$

# Algoritmi per Liste

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

- **utilizzo**: Per inserire un elemento in testa ad una lista
- **complessità**: $\Theta(1)$

```pseudocode
proc ListSearch (L, k) {
    x = L.head
    while (x != nil and x.key != k) {
        x = x.next
    }
    return x
}
```

- **utilizzo**: Per cercare in ogni nodo della lista se la chiave $k$ è presente e restituirla in caso positivo
- **complessità**: $\Theta(n)$

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

- **utilizzo**: Per eliminare l'elemento x dalla lista, dove x punta all'elemento da eliminare
- **complessità**: $\Theta(1)$

# Algoritmi per Pile
## Pile basate su array
```pseudocode
proc Empty (S) {
    if (S.top == 0)
        then return true
    return false
}
```

- **utilizzo**: Verifica se la pila è vuota
- **complessità**: $\Theta(1)$

```pseudocode
proc Push (S, x) {
    if (S.top == S.max) 
        then error "overflow"
    S.top = S.top + 1
    S[S.top] = x
}
```

- **utilizzo**: Inserisce x in cima alla pila
- **complessità**: $\Theta(1)$

```pseudocode
proc Pop (S) {
    if (Empty(S)) 
        then error "underflow"
    S.top = S.top - 1
    return S[S.top + 1]
}
```

- **utilizzo**: Estrae l'elemento in cima alla pila
- **complessità**: $\Theta(1)$

## Pile basate su liste
Utilizzi e complessità uguali alle pile basate su array

```pseudocode
proc Empty (S) {
    if (S.head == nil)
        then return true
    return false
}
```

```pseudocode
proc Push (S, x) {
    ListInsert(S, x)
}
```

```pseudocode
proc Pop (S) {
    if (Empty(S)) 
        then error "underflow"
    x = S.head
    ListDelete(S, x)
    return x.key
}
```

# Algoritmi per Code
## Code basate su array
```pseudocode
proc Enqueue (Q, x) {
    if (Q.dim == Q.length)
        then error "overflow"
    Q[Q.tail] = x
    if (Q.tail == Q.length)
        then Q.tail = 1
        else Q.tail = Q.tail + 1
    Q.dim = Q.dim + 1
}
```

- **utilizzo**: Inserisce x in coda alla coda
- **complessità**: $\Theta(1)$

```pseudocode
proc Dequeue (Q) {
    if (Q.dim == 0)
        then error "underflow"
    x = Q[Q.head]
    if (Q.head == Q.length)
        then Q.head = 1
        else Q.head = Q.head + 1
    Q.dim = Q.dim - 1
    return x
}
```

- **utilizzo**: Estrae l'elemento in testa alla coda
- **complessità**: $\Theta(1)$

## Code basate su liste
Utilizzi e complessità uguali alle code basate su array

```pseudocode
proc Empty (Q) {
    if (Q.head == nil)
        then return true
    return false
}
```

```pseudocode
proc Enqueue (Q, x) {
    ListInsert(Q, x)
}
```

```pseudocode
proc Dequeue (Q) {
    if (Empty(Q))
        then error "underflow"
    x = Q.tail
    Q.tail = x.prev
    ListDelete(Q, x)
    return x.key
}
```

# Algoritmi per Heap

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

- **utilizzo**: Per trovare l'indice del genitore, del figlio sinistro e del figlio destro di un nodo
- **complessità**: $\Theta(1)$

```pseudocode
proc MinHeapify (H, i) {
    l = Left(i) --> l = i*2
    r = Right(i) --> i*2 + 1
    smallest = i
    if ((l ≤ H.heapsize) and (H[l] < H[i]))
        then smallest = l
    if ((r ≤ H.heapsize) and (H[r] < H[smallest]))
        then smallest = r
    if smallest ≠ i {
        then
        SwapValue(H, i, smallest)
        MinHeapify(H, smallest)
    }
}
```

- **utilizzo**: Valuta la posizione del padre e dei due figli per poi modificare eventualmente la posizione di un elemento per farlo diventare min-heap
- **complessità**: $\Theta(\log(n))$

```pseudocode
proc BuildMinHeap (H) {
    H.heapsize = H.length
    for (i = [H.length/2] downto 1)
        MinHeapify(H, i)
}
```

- **utilizzo**: Costruisce un min-heap a partire da un array
- **complessità**: $\Theta(n)$

```pseudocode
proc MaxHeapify (H, i) {
    l = Left(i)
    r = Right(i)
    largest = i
    if ((l ≤ H.heapsize) and (H[l] > H[i]))
        then largest = l
    if ((r ≤ H.heapsize) and (H[r] > H[largest]))
        then largest = r
    if (largest ≠ i) {
        then
        SwapValue(H, i, largest)
        MaxHeapify(H, largest)
    }
}
```

- **utilizzo**: Valuta la posizione del padre e dei due figli per poi modificare eventualmente la posizione di un elemento per farlo diventare max-heap
- **complessità**: $\Theta(\log(n))$

```pseudocode
proc BuildMaxHeap (H) {
    H.heapsize = H.length
    for (i = [H.length/2] downto 1)
        MaxHeapify(H, i)
}
```

- **utilizzo**: Costruisce una max-heap a partire da un array
- **complessità**: $\Theta(n)$

```pseudocode
proc HeapSort(H) {
    BuildMaxHeap(H) // oppure BuildMinHeap(H)
    for (i = H.length downto 2) {
        SwapValue(H, i, 1)
        H.heapsize = H.heapsize - 1
        MaxHeapify(H, 1) // oppure MinHeapify(H, 1)
    }
}
```

- **utilizzo**: Ordina una Min/Max-Heap in modo instable e inplace
- **complessità**: $\Theta(n \cdot \log(n))$

# Algoritmi per Code di priorità

```pseudocode
proc ExtractMin(Q) {
    if (Q.heapsize < 1) {
        then return "underflow"
    }
    min = Q[1]
    Q[1] = Q[Q.heapsize]
    Q.heapsize = Q.heapsize - 1
    MinHeapify(Q, 1)
    return min
}
```

- **utilizzo**: Estrae l'elemento dalla coda Q (min/max-heap) con la chiave minima/massima
- **complessità**: $\Theta(\log(n))$

```pseudocode
proc DecreaseKey(Q, i, priority) {
    if (priority > Q[i]) {
        then return "error"
    }
    Q[i] = priority
    while ((i > 1) and (Q[Parent(i)] > Q[i])) {
        SwapValue(Q, i, Parent(i))
        i = Parent(i)
    }
}
```

- **utilizzo**: Diminuisce la chiave dell'elemento i e lo posiziona correttamente nella coda Q
- **complessità**: $\Theta(\log(n))$

# Algoritmi per Tabelle Hash

## Tabelle Hash con chaining (concatenamento)
```pseudocode
proc HashInsert (T, k) {
    let x be a new node with key k
    i = h(k)
    ListInsert(T[i], x)
}
```

- **utilizzo**: Inserisce un elemento con chiave k nella tabella hash T
- **complessità**: $\Theta(1)$

```pseudocode
proc HashSearch (T, k) {
    i = h(k)
    return ListSearch(T[i], k)
}
```

- **utilizzo**: Cerca un elemento con chiave k nella tabella hash T
- **complessità**: $\Theta(1 + \frac{n}{m})$

```pseudocode
proc HashDelete (T, k) {
    i = h(k)
    x = ListSearch(T[i], k)
    ListDelete(T[i], x)
}
```

- **utilizzo**: Elimina un elemento con chiave k dalla tabella hash T
- **complessità**: $\Theta(n)$

## Funzione di Hash con chaining per metodo dell'addizione

```pseudocode
proc HashComputeModulo (w, B, m) {
    let d = |w|
    z[0] = 0
    for (i = 1 to d) z[i+1] = ((z[i] * B) + a[i]) mod m
    return z[d] + 1
}
```

- w = stringa
- B = cardinalità dell'alfabeto
- m = dimensione della tabella hash

**Ricorda**: scegliere B in maniera che ogni sottoprodotto sia rappresentabile

- **utilizzo**: Calcola la posizione in cui inserire la chiave k nella tabella hash T
- **complessità**: $\Theta(d)$

## Tabelle Hash con Open Hashing (indirizzamento aperto)

```pseudocode
proc OaHashInsert (T, k) {
    i = 0
    repeat {
        j = h(k, i)
        if (T[j] = nil) {
            T[j] = k
            return j
        }
        else i = i + 1
    } until (i = m)
    return “overflow”
}
```

- **utilizzo**: Inserisce un elemento con chiave k nella tabella hash T
- **complessità**: $\Theta(m)$

```pseudocode
proc OaHashSearch (T, k) {
    i = 0
    repeat {
        j = h(k, i)
        if T[j] = k
            then
            return j
        else i = i + 1
    } until (T[j] = nil or i = m)
    return nil
}
```

- **utilizzo**: Cerca un elemento con chiave k nella tabella hash T
- **complessità**: $\Theta(m)$

# Algoritmi per Insiemi Disgiunti

## Insiemi disgiunti: Liste
```pseudocode
proc MakeSet (calS, S, x, i) {
    calS[i].set = x
    S.head = x
    S.tail = x
}
```

- **utilizzo**: Crea un nuovo oggetto S
- **complessità**: $\Theta(1)$

```pseudocode
proc FindSet (x) {
    return x.head.head
}
```

- **utilizzo**: Dato x, restituisce il rappresentante dell'insieme di x
- **complessità**: $\Theta(1)$

```pseudocode
proc Union (x, y) {
    S1 = x.head
    S2 = y.head
    if (S1 ≠ S2) {
        then
        S1.tail.next = S2.head
        z = S2.head
        while (z ≠ nil) {
            z.head = S1
            z = z.next
        }
        S1.tail = S2.tail
    }
}
```

- **utilizzo**: Unisce due insiemi in uno già esistente ed eliminando l'altro
- **complessità**: $\Theta(n)$

## Insiemi disgiunti: Liste con unione pesata
```pseudocode
proc MakeSet (calS, S, x, i) {
    calS[i].set = x
    S.head = x
    S.tail = x
    S.rank = 1
}
```

- **utilizzo**: Crea un nuovo oggetto S
- **complessità**: $\Theta(1)$

```pseudocode
proc Union (x, y) {
    S1 = x.head
    S2 = y.head
    if (S1 ≠ S2) {
        then
        if (S2.rank > S1.rank) {
            then SwapVariable(S1, S2)
        }
        S1.tail.next = S2.head
        z = S2.head
        while (z ≠ nil) {
            z.head = S1
            z = z.next
        }
        S1.tail = S2.tail
        S1.rank = S1.rank + S2.rank
    }
}
```

- **utilizzo**: Unisce due insiemi in uno già esistente ed eliminando l'altro, l'unione viene fatta sempre sull'insieme con rango maggiore
- **complessità**: $\Theta(\log(n))$

## Insiemi disgiunti: Foreste di alberi
```pseudocode
proc MakeSet (x) {
    x.p = x
    x.rank = 0
}
```

- **utilizzo**: crea un nuovo albero di altezza massima 0 (rank = 0) con il solo nodo x
- **complessità**: $\Theta(1)$

```pseudocode
proc FindSet (x) {
    if (x ≠ x.p) {
        then x.p = FindSet(x.p)
    }
    return x.p
}
```

- **utilizzo**: Scorrendo i puntatori verso l'alto li aggiorna appiattendo il ramo al quale appartiene il rappresentante e lo restituisce
- **complessità**: $\Theta(\log(n))$

```pseudocode
proc Union (x, y) {
    x = FindSet(x)
    y = FindSet(y)
    if (x.rank > y.rank) {
        then y.p = x
    } else {
        x.p = y
        if (x.rank = y.rank) {
            then y.rank = y.rank + 1
        }
    }
}
```

- **utilizzo**: Unisce due alberi in uno solo:
    1. si trovano i rappresentanti degli elementi (x, y) usati come indici
    2. si sceglie l'elemento di rango inferiore e si aggiorna solo il padre (si fa puntare il rappresentante con rango inferiore al rappresentante con rango superiore)
- **complessità**: $O(m)$

# Algoritmi per Alberi

## Visite
```pseudocode
proc TreeInOrderTreeWalk (x) {
    if (x ≠ nil) {
        TreeInOrderTreeWalk(x.left)
        print(x.key)
        TreeInOrderTreeWalk(x.right)
    }
}
```

- **utilizzo**: Visita l'albero in ordine
- **complessità**: $\Theta(n)$

```pseudocode
proc TreePreOrderTreeWalk (x) {
    if (x ≠ nil) {
        print(x.key)
        TreePreOrderTreeWalk(x.left)
        TreePreOrderTreeWalk(x.right)
    }
}
```

- **utilizzo**: Se si volesse valutare un'espressione algebrica bisognerebbe partire dall'alto, tenendo conto che il nodo più in alto è considerato l'operazione più esterna
- **complessità**: $\Theta(n)$

```pseudocode
proc TreePostOrderTreeWalk (x) {
    if (x ≠ nil) {
        TreePostOrderTreeWalk(x.left)
        TreePostOrderTreeWalk(x.right)
        print(x.key)
    }
}
```

- **utilizzo**: Se si volesse liberare la memoria si dovrebbe iniziare dai nodi senza figli, quindi dalle foglie
- **complessità**: $\Theta(n)$

## Alberi binari di ricerca
```pseudocode
proc BSTTreeSearch (x, k) {
    if ( (x = nil) or (x.key = k) )
        return x
    if (k ≤ x.key)
        return BSTTreeSearch(x.left, k)
    else
        return BSTTreeSearch(x.right, k)
}
```

- **utilizzo**: Cerca un elemento con chiave k nell'albero (visita in order)
- **complessità**:
    - **caso medio**: $\Theta(\log(n))$
    - **caso peggiore**: $\Theta(n)$

```pseudocode
proc BSTTreeMinimum (x) {
    if (x.left = nil)
        return x
    return BSTTreeMinimum(x.left)
}
```

- **utilizzo**: Restituisce il nodo con chiave minima (foglia più a sinistra)
- **complessità**:
    - **caso medio**: $\Theta(\log(n))$
    - **caso peggiore**: $\Theta(n)$

```pseudocode
proc BSTTreeMaximum (x) {
    if (x.right = nil)
        return x
    return BSTTreeMaximum(x.right)
}
```

- **utilizzo**: Restituisce il nodo con chiave massima (foglia più a destra)
- **complessità**:
    - **caso medio**: $\Theta(\log(n))$
    - **caso peggiore**: $\Theta(n)$

```pseudocode
proc BSTTreeSuccessor (x) {
    if (x.right ≠ nil)
        return BSTTreeMinimum(x.right)
    y = x.p
    while ( (y ≠ nil) and (x = y.right) ) {
        x = y
        y = y.p
    }
    return y
}
```

- **utilizzo**: Restituisce il nodo successore di x
- **complessità**:
    - **caso medio**: $\Theta(\log(n))$
    - **caso peggiore**: $\Theta(n)$

```pseudocode
proc BSTTreePredecessor (x) {
    if (x.left ≠ nil)
        return BSTTreeMaximum(x.left)
    y = x.p
    while ( (y ≠ nil) and (x = y.left) ) {
        x = y
        y = y.p
    }
    return y
}
```

- **utilizzo**: Restituisce il nodo predecessore di x
- **complessità**:
    - **caso medio**: $\Theta(\log(n))$
    - **caso peggiore**: $\Theta(n)$

```pseudocode
proc BSTTreeInsert (T, z) {
    y = nil
    x = T.root
    // scendo lungo l'albero finchè z.key ≤ x.key
    // quando x sarà nil avrò trovato la posizione corretta
    while (x ≠ nil) {
        y = x
        if (z.key ≤ x.key)
            x = x.left
        else
            x = x.right
    }
    // ora si decide se z sarà figlio sx, dx o root
    z.p = y
    if (y = nil)
        T.root = z
    if ( (y ≠ nil ) and (z.key ≤ y.key) )
        y.left = z
    if ( (y ≠ nil ) and (z.key > y.key) )
        y.right = z
}
```

- **utilizzo**: Inserisce un nuovo elemento come foglia nell'albero
- **complessità**:
    - **caso medio**: $\Theta(\log(n))$
    - **caso peggiore**: $\Theta(n)$

```pseudocode
proc BSTTreeDelete (T, z) {
    // caso 1
    if (z.left = nil)
        BSTTreeTransplant(T, z, z.right)
    // caso 2.a o 2.b
    if ( (z.left ≠ nil) and (z.right = nil) )
        BSTTreeTransplant(T, z, z.left)
    // caso 3
    if ( (z.left ≠ nil) and (z.right ≠ nil) ) {
        y = BSTTreeMinimum(z.right)
        if (y.p ≠ z) {
            BSTTreeTransplant(T, y, y.right)
            y.right = z.right
            y.right.p = y
        }
        BSTTreeTransplant(T, z, y)
        y.left = z.left
        y.left.p = y
    }
}

proc BSTTreeTransplant (T, u, v) {
    if (u.p = nil)
        T.root = v
    if ( (u.p ≠ nil) and (u = u.p.left) )
        u.p.left = v
    if ( (u.p ≠ nil) and (u = u.p.right) )
        u.p.right = v
    if (v ≠ nil)
        v.p = u.p
}
```

- **utilizzo**: Eliminazione di un nodo z la quale può essere complessa, si distinguono 3 casi:
1. se z è foglia (non ha figli) -> si elimina z
2. se z ha un solo figlio -> si elimina z facendo puntare il padre di z al figlio di z (come eliminare un nodo in una lista)
3. se z ha due figli -> si cerca il successore di z (es. y) e si scambia z con y, poi si elimina y
- **complessità**:
    - **caso medio**: $\Theta(\log(n))$
    - **caso peggiore**: $\Theta(n)$

## Alberi Red-Black
```pseudocode
proc BSTTreeLeftRotate (T, x) {
    y = x.right
    x.right = y.left
    if (y.left ≠ T.Nil)
        y.left.p = x
    y.p = x.p
    if (x.p = T.Nil)
        T.root = y
    if ( (x.p ≠ T.Nil) and (x = x.p.left) )
        x.p.left = y
    if ( (x.p ≠ T.Nil) and (x = x.p.right) )
        x.p.right = y
    y.left = x
    x.p = y
}
```

- **utilizzo**: Ruota a sinistra l'albero per mantenere le proprietà di un BST quando si fanno le operazioni di inserimento e cancellazione
- **complessità**: $O(1)$

```pseudocode
proc RBTreeInsert (T, z) {
    y = T.Nil
    x = T.root
    while (x ≠ T.Nil) {
        y = x
        if (z.key < x.key)
            x = x.left
        else
            x = x.right
    }
    z.p = y
    if (y = T.Nil)
        T.root = z
    if ( (y ≠ T.Nil) and (z.key < y.key) )
        y.left = z
    if ( (y ≠ T.Nil) and (z.key ≥ y.key) )
        y.right = z
    z.left = T.Nil
    z.right = T.Nil
    z.color = RED
    RBTreeInsertFixup(T, z)
}
```

- **utilizzo**: Inserisce un nuovo nodo nell'albero, mantenendo le proprietà di un albero Red-Black
- **complessità**: $\Theta(\log(n))$

```pseudocode
proc RBTreeInsertFixup (T, z) {
    while (z.p.color = RED) {
        if (z.p = z.p.p.left)
            RBTreeInsertFixUpLeft(T, z)
        else
            RBTreeInsertFixUpRight(T, z)
    }
    T.root.color = BLACK
}
```

- **utilizzo**: Corregge le proprietà di un albero Red-Black dopo l'inserimento di un nodo rosso

```pseudocode
proc RBTreeInsertFixUpLeft (T, z) {
    y = z.p.p.right
    // caso 1
    if (y.color = RED) {
        z.p.color = BLACK
        y.color = BLACK
        z.p.p.color = RED
        z = z.p.p
    } else {
        // caso 3
        if (z = z.p.right) {
            z = z.p
            BSTTreeLeftRotate(T, z)
        }
        // caso 2
        z.p.color = BLACK
        z.p.p.color = RED
        BSTTreeRightRotate(T, z.p.p)
    }
}

proc RBTreeInsertFixUpRight (T, z) {
    y = z.p.p.left
    // caso 1
    if (y.color = RED) {
        z.p.color = BLACK
        y.color = BLACK
        z.p.p.color = RED
        z = z.p.p
    } else {
        // caso 2
        if (z = z.p.left) {
            z = z.p
            BSTTreeRightRotate(T, z)
        }
        // caso 3
        z.p.color = BLACK
        z.p.p.color = RED
        BSTTreeLeftRotate(T, z.p.p)
    }
}
```

- **utilizzo**: Corregge le proprietà di un albero Red-Black dopo l'inserimento di un nodo rosso ed in base alla posizione del nodo z rispetto al padre e al nonno

## Alberi Bilanciati
```pseudocode
proc BTreeSearch(x, k) {
    i = 1
    while ( (i ≤ x.n) and (k > x.key[i]) )
        i = i + 1
    if ( (i ≤ x.n) and (k == x.key[i]) )
        return (x, i)
    if (x.leaf = true)
        return nil
    DiskRead(x.c[i])
    return BTreeSearch(x.c[i], k)
}
```

- **utilizzo**: Cerca un elemento con chiave k nell'albero B
- **complessità**:
    - numero di accessi al disco: $O(h) = O(\log_t(n))$
    - uso di CPU: $\Theta(t \cdot h) = \Theta(t \cdot \log_t(n))$

```pseudocode
proc BTreeCreate(T) {
    x = Allocate()
    x.leaf = true
    x.n = 0
    DiskWrite(x)
    T.root = x
}
```

- **utilizzo**: Crea un nuovo albero B
- **complessità**: $\Theta(1)$

Allocate() -> funzione che crea e occupa uno spazio sufficiente per un nodo in memoria secondaria

```pseudocode
proc BTreeSplitChild(x, i) {
    z = Allocate()
    y = x.c[i]
    z.leaf = y.leaf
    for (j = 1 to t - 1)
        z.key[j] = y.key[j + t]
    if (y.leaf = false)
        for (j = 1 to t)
            z.c[j] = y.c[j + t]
    y.n = t - 1
    for (j = x.n + 1 downto i + 1)
        x.c[j + 1] = x.c[j]
    x.c[i + 1] = z
    for (j = x.n downto i)
        x.key[j + 1] = x.key[j]
    x.key[i] = y.key[t]
    x.n = x.n + 1
    DiskWrite(y)
    DiskWrite(z)
    DiskWrite(x)
}
```

- **utilizzo**: Suddivide un nodo x figlio di un nodo interno in due nodi
- **complessità**:
    - numero di accessi al disco: $\Theta(1)$
    - uso di CPU: $\Theta(t)$

```pseudocode
proc BTreeInsert(T, k) {
    r = T.root
    // se il nodo è pieno
    if (r.n == 2t - 1) {
        s = Allocate()
        T.root = s
        s.leaf = false
        s.n = 0
        s.c[1] = r
        BTreeSplitChild(s, 1)
        BTreeInsertNonFull(s, k)
    }
    else
        BTreeInsertNonFull(r, k)
}
```

- **utilizzo**: Inserisce una chiave k in un nodo x
- **complessità**:
    - numero di accessi al disco: $\Theta(h) = \Theta(\log_t(n))$
    - uso di CPU: $\Theta(t \cdot h) = \Theta(t \cdot \log_t(n))$

```pseudocode
proc BTreeInsertNonFull(x, k) {
    i = x.n
    if (x.leaf = true) {
        // si spostano a dx gli elementi necessari
        // e si inserisce la chiave
        while ( (i ≥ 1) and (k < x.key[i]) ) {
            x.key[i + 1] = x.key[i]
            i = i - 1
        }
        x.key[i + 1] = k
        x.n = x.n + 1
        DiskWrite(x)
    }
    else {
        // trova il sotto-albero in cui inserire la chiave
        while ( (i ≥ 1) and (k < x.key[i]) )
            i = i - 1
        i = i + 1
        DiskRead(x.c[i])
        // se il figlio è pieno -> split
        if (x.c[i].n == 2t - 1) {
            BTreeSplitChild(x, i)
            if (k > x.key[i])
                i = i + 1
        }
        BTreeInsertNonFull(x.c[i], k)
    }
}
```

- **utilizzo**: Inserisce una chiave k in un nodo non pieno

# Algoritmi per Grafi

## Visita in ampiezza: grafi diretti o indiretti, non pesati, sorgente singola
```pseudocode
proc BreadthFirstSearch(G, s) {
    // inizializzazione
    for (u in G.V \ {s}) {
        u.color = WHITE
        u.d = infinity // distanza ancora sconosciuta
        u.π = Nil // predecessore ancora sconosciuto
    }
    s.color = GREY
    s.d = 0
    s.π = Nil
    Q = vuoto
    Enqueue(Q, s)
    // algoritmo di visita
    while (Q != vuoto) {
        u = Dequeue(Q)
        for (v in G.Adj[u]) {
            if (v.color == WHITE) {
                v.color = GREY
                v.d = u.d + 1
                v.π = u
                Enqueue(Q, v)
            }
        }
        u.color = BLACK
    }
}
```

- **utilizzo**: Per conoscere quanti archi sono necessari per raggiungere qualunque altro vertice dalla sorgente s (distanza minima da s a v qualunque in G)
- **complessità**:
    - **grafo connesso**: $\Theta(|V| + |E|)$
    - **grafo non connesso**: $O(|V| + |E|)$ perchè potrebbero non vedersi tutti gli archi
    - **grafo denso**: $\Theta(|V|^2)$ ma si accetta anche $\Theta(|V| + |E|)$

## Visita in profondità: grafi diretti, non pesati, sorgente singola
```pseudocode
proc DepthFirstSearch (G)
    for (u in G.V) {
        u.color = WHITE
        u.π = Nil
    }
    time = 0
    for (u in G.V) {
        if (u.color == WHITE)
            DepthVisit(G, u)
    }

proc DepthVisit (G, u) {
    time = time + 1
    u.d = time
    u.color = GREY
    for (v in G.Adj[u]) {
        if (v.color == WHITE) {
            v.π = u
            DepthVisit(G, v)
        }
    }
    u.color = BLACK
    time = time + 1
    u.f = time
}
```

- **utilizzo**: Per scoprire tutti i vertici raggiungibili da ogni potenziale sorgente s
- **complessità**:
    - `for (u in G.V)` -> $\Theta(|V|)$
    - `for (u in G.V) con DepthVisit(G, u)` -> $\Theta(|V| + |E|)$
    - `for (v in G.Adj[u])` -> $\Theta(|E|)$
    - Complessità totale: $\Theta(|V| + |E|)$

```pseudocode
proc CycleDet (G) {
    cycle = false
    for (u in G.V)
        u.color = WHITE
    for (u in G.V) {
        if (u.color == WHITE)
            DepthVisitCycle (G, u)
    }
    return cycle
}

proc DepthVisitCycle (G, u) {
    u.color = GREY
    for (v in G.Adj[u]) {
        if (v.color == WHITE)
            DepthVisitCycle(G, v)
        // se nodo nero -> vado avanti
        // se nodo grigio -> ciclo e mi fermo
        if (v.color == GREY)
            cycle = true
    }
    u.color = BLACK
}
```

- **utilizzo**: Per verificare se un grafo contiene almeno un ciclo
- **complessità**: $\Theta(|V| + |E|)$

```pseudocode
proc TopologicalSort (G) {
    for (u in G.V)
        u.color = WHITE
    L = Nil
    time = 0
    for (u in G.V) {
        if (u.color == WHITE)
            DepthVisitTS(G, u)
    }
    return L
}

proc DepthVisitTS (G, u) {
    time = time + 1
    u.d = time
    u.color = GREY
    for (v in G.Adj[u]) {
        if (v.color == WHITE)
            DepthVisitTS(G, v)
    }
    u.color = BLACK
    time = time + 1
    u.f = time
    ListInsert(L, u)
}
```

- **utilizzo**: Per ordinare i vertici di un grafo diretto **aciclico** in modo che se esiste un arco da u a v, allora u appare prima di v
- **complessità**: $\Theta(|V| + |E|)$

```pseudocode
proc StronglyConnectedComponents (G) {
    for (u in G.V) {
        u.color = WHITE
        u.π = Nil
    }
    time = 0
    for (u in G.V) {
        if (u.color == WHITE)
            DepthVisit(G, u)
    }
    time = 0
    L = Nil
    for (u in G^T.V in reverse finish time order -> u.f) {
        if (u.color == WHITE)
            DepthVisit(G^T, u)
        ListInsert(L, u)
    }
    return L
}

proc DepthVisit (G, u) {
    time = time + 1
    u.d = time
    u.color = GREY
    for (v in G.Adj[u]) {
        if (v.color == WHITE) {
            v.π = u
            DepthVisit(G, v)
        }
    }
    u.color = BLACK
    time = time + 1
    u.f = time
}
```

- **utilizzo**: Per trovare i componenti fortemente connessi di un grafo diretto ovvero il sottoinsieme di vertici dove esiste un cammino da u a v e da v a u
- **complessità**: $\Theta(|V| + |E|)$

## Percorsi minimi: grafi (MST) indiretti, pesati, connessi, sorgente singola
```pseudocode
proc MST-Prim (G, w, r) {
    // inizializzazione
    for (v in G.V) {
        v.key = ∞
        v.π = Nil
    }
    r.key = 0
    // costruzione coda
    Q = G.V
    while (Q ≠ vuoto) {
        u = ExtractMin(Q)
        // aggiorna la coda
        for (v in G.Adj[u]) {
            if ( (v in Q) and (w(u, v) < v.key) ) {
                v.π = u
                v.key = w(u, v) // -> DecreaseKey(Q, v)
            }
        }
    }
}
```

- **utilizzo**: Per trovare il percorso minimo tra una sorgente e tutti gli altri vertici, restituendo ogni volta un albero con i soli archi di peso minimo necessari per raggiungere tutti i vertici
- **complessità**:
    - **implementazione con array**: $\Theta(|V|^2)$
    - **implementazione con min-heap**: $\Theta(|E| \cdot \log(|V|))$

```pseudocode
proc MST-Kruskal (G, w) {
    T = vuoto
    for (v in G.V) 
        MakeSet(v)
    // ordina gli archi di G.E in ordine non decrescente di peso
    SortNoDecreasing(G.E)
    for ( (u, v) in G.E - in order) {
        if (FindSet(u) ≠ FindSet(v)) {
            T = T ∪ {(u, v)}
            Union(u, v)
        }
    }
    return T
}
```

- **utilizzo**: Per trovare il percorso minimo tra una sorgente e tutti gli altri vertici, restituendo sicuramente alla fine un albero con i soli archi di peso minimo necessari per raggiungere tutti i vertici
- **complessità**:
    - **grafi densi**: $\Theta(|V|^2 \cdot \log(|V|))$
    - **grafi sparsi**: $\Theta(|E| \cdot \log(|E|))$

## Percorsi minimi: grafi diretti, pesati, connessi, sorgente singola
```pseudocode
proc InizializeSingleSource (G, s) {
    for (v in G.V) {
        v.d = ∞
        v.π = Nil
    }
    s.d = 0
}
```

- **utilizzo**: Inizializza i valori di distanza e predecessore per ogni vertice
- **complessità**: $\Theta(|V|)$

```pseudocode
proc Relax (u, v, W) {
    if (v.d > u.d + W(u, v)) {
        v.d = u.d + W(u, v)
        v.π = u
    }
}
```

- **utilizzo**: Rilassa l'arco (u, v) se è possibile migliorare il percorso minimo da s a v passando per u
- **complessità**: $\Theta(1)$

```pseudocode
proc BellmanFord (G, s) {
    // algoritmo vero e prorpio
    InizializeSingleSource(G, s)
    for (i = 1 to |G.V| - 1) {
        // rilassamento degli archi |V| - 1 volte
        for ((u, v) in G.E)
            Relax(u, v, W)
    }
    // controllo esistenza cicli negativi
    for ((u, v) in G.E) {
        if (v.d > u.d + W(u, v))
            return false
    }
    return true
}
```

- **utilizzo**: Dati cicli e pesi negativi, l'algoritmo trova il percorso minimo da s a tutti gli altri vertici se non ci sono cicli negativi raggiungibili da s, altrimenti restituisce false
- **complessità**: $\Theta(|V| \cdot |E|) = O(|V|^3)$

```pseudocode
proc DAGShortestPath (G, s) {
    // ordinamento topologico
    TopologicalSort(G)
    InizializeSingleSource(G, s)
    for (u in G.V - in order) {
        for (v in G.Adj[u])
            Relax(u, v, W)
    }
}
```

- **utilizzo**: Dato un grafo **aciclico**, l'algoritmo trova il percorso minimo da s a tutti gli altri vertici
- **complessità**: $\Theta(|V| + |E|)$

```pseudocode
proc Dijkstra (G, s) {
    InizializeSingleSource(G, s)
    // insieme dei vertici per cui la stima è già corretta
    S = ∅
    // coda di priorità (sulla stima di distanza)
    Q = G.V
    while (Q ≠ ∅) {
        u = ExtractMin(Q)
        S = S ∪ {u}
        for (v in G.Adj[u]) {
            if (v in Q)
                Relax(u, v, W) // -> DecreaseKey(Q, v)
        }
    }
}
```

- **utilizzo**: Dato un grafo con pesi **positivi o zero**, l'algoritmo trova il percorso minimo da s a tutti gli altri vertici
- **complessità**:
    - **se grafo denso -> si usa una coda senza struttura**: $\Theta(|V|^2)$
    - **se grafo sparso -> si usa una heap binaria**: $\Theta(|E| \cdot \log(|V|))$

## Percorsi minimi: grafi diretti, pesati, connessi, sorgente multipla
```pseudocode
proc ExtendShortestPaths (L, W) {
    n = L.rows
    let L' be a new matrix
    for (i = 1 to n)
        for (j = 1 to n)
            L'ij = ∞
            for (k = 1 to n)
                L'ij = min{L'ij, Lik + Wkj}
    return L'
}

proc SlowAllPairsMatrix (W) {
    n = L.rows
    L(1) = W
    for m = 2 to n - 1
        L(m) = ExtendShortestPaths(L(m-1), W)
    return L(n-1)
}
```

- **utilizzo**: Guardando il numero di **archi**, l'algoritmo calcola la matrice delle distanze minime tra tutti i vertici per ogni numero di archi
- **complessità**: $\Theta(|V|^4)$

```pseudocode
proc ExtendShortestPaths (L, W) {
    n = L.rows
    let L' be a new matrix
    for (i = 1 to n)
        for (j = 1 to n)
            L'ij = ∞
            for (k = 1 to n)
                L'ij = min{L'ij, Lik + Wkj}
    return L'
}

proc FasterAllPairsMatrix (W) {
    n = L.rows
    L(1) = W
    m = 1
    while (m < n - 1) {
        L(2m) = ExtendShortestPaths(L(m), L(m))
        m = 2m
    }
    return L(m)
}
```

- **utilizzo**: Guardando il numero di **archi**, l'algoritmo calcola la matrice delle distanze minime tra tutti i vertici per ogni potenza di 2
- **complessità**: $\Theta(|V|^3 \cdot \log(|V|))$

```pseudocode
proc FloydWarshall (W) {
    n = W.rows
    let D(0) = W
    for (k = 1 to n)
        let D(k) be a new matrix
        for (i = 1 to n)
            for (j = 1 to n)
                D(k)ij = min{D(k-1)ij, D(k-1)ik + D(k-1)kj}
}
```

- **utilizzo**: Guardando il numero di **vertici**, l'algoritmo calcola la matrice delle distanze minime tra tutti i vertici per ogni vertice intermedio
- **complessità**: $\Theta(|V|^3)$