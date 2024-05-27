# Grafi: percorsi minimi tra tutte le coppie di vertici
Grafo G = (V, E, W) pesato, diretto e connesso  
Obiettivo: trovare il percorso minimo per ogni coppia di vertici (nel caso in cui fossimo obbligati ad usare Bellman-Ford)

Rappresentazione: utilizzo della matrice delle distanze del grafo

Grazie a questa rappresentazione il grafo è rappresentato solo dalla matrice W di pesi

Risultato:
- matrice dei pesi -> `D`
- matrice dei predecessori (indicazione sul percorso minimo) -> `π`

Esempio: 


Programmazione dinamica: risolve in maniera efficiente un problema di ottimizzazione suddividendo dei problemi in sottoproblemi comuni  
Caratteristica della programmazione dinamica: tutta la complessità di progettazione si accumula nella progettazione iniziale

## Algoritmo della moltiplicazione di matrici
IMPORTANTE Caratterizzazione della sottotruttura ottima basata su archi:  
$L^m_{i j}$ = peso del cammino minimo tra il vertice `i` e il vertice `j` che si puó costruire usando al piú `m` archi  
$L^m_{i j} = min(L^{m-1}_{i j}, min_k(L^m_{i k} + W_{kj})) = min_k(L^m_{i k} + W_{kj})$

i ----> k ----> j  
secondo min = soluzione più conveniente usando k come ultimo predecessore  
Esempio: il modo migliore per andare da `i` a `j` con al massimo due archi si trova cercando il modo migliore per andare da `i` a qualsiasi `k` e da `k` a `j` usando un solo arco (moltiplicazione tra una riga e una colonna)

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
```

```pseudocode
proc SlowAllPairsShortestPaths (W) {
    n = W.rows
    let L(1) = W
    for m = 2 to n - 1
        L(m) = ExtendShortestPaths(L(m-1), W)
    return L(n-1)
}
```

**Complessità**: $\Theta(|V|^4)$

```pseudocode
proc FasterAllPairsShortestPaths (W) {
    n = W.rows
    L(1) = W
    m = 1
    while m < n - 1
        L(2m) = ExtendShortestPaths(L(m), L(m))
        m = 2m
    return L(m)
}
```

**Complessità**: $\Theta(|V|^3 \cdot \log(|V|))$

## Algoritmo di Floyd-Warshall
IMPORTANTE Caratterizzazione della sottotruttura ottima basata su vertici: dati due vertici `i` e `j` e un insieme di vertici diversi da `i` e `j`, sul cammino minimo tra `i` e `j` potrebbero esserci altri vertici, detti intermediari

Nel cambiare il focus da numero di archi usabili a quali intermideiari:
- mi ricordo che i vertici sono ordinati 1, 2, ..., n
- caratterizzo il risultato parziale con "usando fino al vertice `k`-esimo"

i ---> k ---> l ---> u ---> j  
k, l, u sono intermediari

Notazione: i ⇝1 j oppure i ⇝2 j -> cammino minimo passando, se serve, per i vertici 1 o 2

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

Osservazione:
- il cammino minimo da `i` a `k` e quello da `k` a `j` non usano `k` come intermediario
- il numero dei vertici è minore al numero di archi quindi l'utilizzo di Floyd-Warshall è più efficiente perchè usa come sottostruttura ottima i vertici

**Complessità**: $\Theta(|V|^3)$