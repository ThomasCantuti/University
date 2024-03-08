# Terminazione, Correttezza, Complessità
come si analizza un algoritmo e come di studia la sua complessità
distinzione tra iterazione e ricorsione
notazione asintotica

## Analizzare gli algoritmi
4 caratteristiche principali di un algoritmo:
- **correttezza**: l'algoritmo restituisce sempre la risposta corretta
- **completezza**: ogni risposta corretta è restituita dall'algoritmo
- **terminazione**: l'algoritmo termina sempre (non entra in loop infiniti)
- **complessità**: l'algoritmo termina in un tempo ragionevole

## Caso iterativo
### Analisi algoritmica
esempio: InsertionSort
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
- **terminazione** -> ciclo for termina quando j < A.length e ciclo while termina quando i <= 0 e A[i] <= key -> terminazione garantita da ciclo esterno e interno
- **correttezza** -> stabilire una proprietà del ciclo principale che sia vera prima, durante e dopo l'esecuzione del ciclo -> tecnica dell'invariante con A[1, ..., j-1] sempre ordinato
- **complessità**:
```pseudocode
proc InsertionSort (A) {
    for (j = 2 to A.length) { --> n * c1
        key = A[j] --> (n-1) * c2
        i = j − 1 --> (n-1) * c3
        while ((i > 0) and (A[i] > key)) { --> c4 * Σ_{j=2}^{n} (t_j)
            A[i + 1] = A[i] --> c5 * Σ_{j=2}^{n} (t_j - 1)
            i = i − 1 --> c6 * Σ_{j=2}^{n} (t_j - 1)
        }
        A[i + 1] = key --> (n-1) * c7
    }
}
```
- c1, c2, c3, c4, c5, c6, c7 sono costanti
- n è la dimensione dell'input
- $t_j$ è il tempo di esecuzione del ciclo while al passo j (va da 2 ad n, nel caso migliore $t_j$ = 1 ovvero input già ordinato, nel caso peggiore $t_j$ = j ovvero input ordinato al contrario)

- **caso migliore**:
$$T(n) = C + c4 * (n - 1)$$
con $C = c1 * n + c2 * (n-1) + c3 * (n-1) c7 * (n-1)$
risulta una funzione lineare (con a,b costanti):
$T(n) = a * n + b$

- **caso peggiore**: $$T(n) = C + c4 * ( (n * (n + 1) / 2) - 1) + c5 * ( (n * (n - 1) / 2) ) + c6 * ( (n * (n - 1) / 2) )$$
risulta una funzione quadratica (con a,b,c costanti):
$T(n) = a * n^2 + b * n + c$

## Caso ricorsivo
### Analisi algoritmica
esempio: RecursiveBinarySearch
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
- **terminazione** -> termina quando low > high
- **correttezza** -> concentrarsi su quello che accade dopo ogni chiamata ricorsiva -> tecnica dell'invariante induttiva
- **complessità**:
$T(n) = T(\frac{n}{2}) + 1$

## Notazione asintotica
### Studiare la complessità
$T(n) = O(f(n))$ se si ottiene da $f(n)$ eliminando tutti i termini di ordine inferiore al maggiore e tutte le sue costanti
esempio: $T(n) = 3n^2 + 2n + 1$ diventa $O(n^2)$

Si confrontano quindi differenti algoritmi in base al loro comportmaneto asintotico nel caso peggiore

La logica di un algoritmo è data dalle operazioni logiche e aritmetiche, non dalle operazioni di assegnamento

Quindi per calolare la complessità di un algoritmo si considerano solo le operazioni logiche e aritmetiche

### Notazione asintotica
$f(n)$ è limitata da (oppure è un "o" grande di) $g(n)$ (scritto: $f(n) = O(g(n))$) $<--> \exists$ una costante $c > 0$ t.c. per tutti gli $n \geq n_0$ : 

0 $\leq f(n) \leq c * g(n)$

$\lim_{n\to\infty} \frac{f(n)}{g(n)} = 0$

$f(n)$ è limitata dal basso da (oppure è un omega grande di) $g(n)$ (scritto: $f(n) = \Omega(g(n))$) $<--> \exists$ una costante $c > 0$ t.c. per tutti gli $n \geq n_0$ : 

0 $\leq c * g(n) \leq f(n)$

$\lim_{n\to\infty} \frac{f(n)}{g(n)} = \infty$

$f(n)$ è dello stesso ordine di $g(n)$ $<--> \exists$ due costanti $c_1, c_2 > 0$ t.c. per tutti gli $n \geq n_0$ :

0 $\leq c_1 * g(n) \leq f(n) \leq c_2 * g(n)$

Quindi l'insieme $O(g(n))$ contiene tutte e sole quelle funzioni $f(n)$ tali che, a partire da un certo momento in poi (per tutti gli $n ≥ n_0$), il valore di $f(n)$ è descritto dal valore $g(n)$ a meno di una costante. Quindi, asintoticamente, $f(n)$ si comporta come $g(n)$

Per confrontare gli ordini di grandezza delle funzioni si usano $\omicron()$ e $\omega()$ (o piccolo e omega piccolo)
