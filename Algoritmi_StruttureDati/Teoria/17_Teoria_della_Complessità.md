# Teoria della complessità: accenni ed esempi
Si considerano solo dei **problemi decisionali** (se output è {si; no}) e non generali.

## Classe P
In questo contesto esiste un insieme dei problemi:  
$P = \{problemi\space che\space possono\space essere\space risolti\space in\space tempo\space polinomiale\}$

Appartengono però tutti i problemi alla classe P?  
Si considera un grafo indiretto non pesato G = (V, E) e k-clique un sottoinsieme di vertici di cardinaltà k t.c. per ogni coppia di vertici esiste un arco che li collega.  
Si può dunque definire il problema di trovare la massima clique.

```pseudocode
proc kClique (G, k) {
    for (A in G.V, |A| = k) {
        Clique = true
        for (u, v in A) {
            if ((u, v) not in G.E)
                Clique = false
        }
        if (Clique = true)
            return true
    }
    return false
}
```

**Complessità**: $O(2^{|V|})$

Il problema della k-clique probabilmente non appartiene alla classe P.

## Classe NP
Dato un grago G con un insieme di vertici, sarebbe difficile stabilire se si tratta di una k-clique?  
$NP = \{problemi\space la\space cui\space soluzione\space può\space essere\space verificata\space in\space tempo\space polinomiale\}$

```pseudocode
proc kCliqueCheck (G, A, k) {
    if (|A| != k)
        return false
    Clique = true
    for (u, v in A) {
        if ((u, v) not in G.E)
            Clique = false
    }
    if (Clique = true)
        return true
    return false
}
```

**Complessità**: $O(k^2)$

Sono infitamente di più i problemi che non appartengono alla classe NP di quelli che vi appartengono.  
Un problema in particolare che non appartiene alla classe NP è il problema della geografia generalizzata.

### Problema della geografia generalizzata
spiegazione problema

```pseudocode
proc HasIWinningStrategy (G, p, v)
```

**Complessità**: $O(2^{|V|})$

## Classe PSPACE
$PSPACE = \{problemi\space che\space possono\space essere\space risolti/verificati\space in\space spazio\space polinomiale\}$