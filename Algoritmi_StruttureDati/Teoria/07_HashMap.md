# Tabelle Hash
Le tabelle hash (o dizionari) sono strutture dati astratte, dinamiche, parzialmente dinamiche e non basate sull'ordinamento  
Sono usate per inserimento, cancellazione e ricerca di chiavi o valori ad accesso diretto (complessità $\Theta(1)$ o $\Theta(n)$)

Condizioni di utilizzo di una tabella Hash:
- universo grande
- sottoinsieme utilizzando dell'universo relativamente piccolo, ma non assolutamente piccolo

-> quindi non posso allocare tutto in forma compatta e non posso dire che l'accesso lineare è efficiente

Esempio Universo $U$:
![alt text](<Screenshot 2024-04-11 alle 14.29.13.png>)

## Funzione di Hash
Permette di mappare tanti oggetti in poche posizioni per indirizzare l'elemento alla posizione h(k)  
h: $U \rightarrow {1, ..., m}$  
conflitto -> quando $k_1$ ≠ $k_2$ ma $h(k_1) = h(k_2)$

La funzione di hash può sistemare:
- crittografia
    - sia resistente alla pre-immagine
    - uniforme (che distribuisca bene)
    - che fosse resistente ai conflitti
- non crittografica
    - uniforme (che distribuisca bene)
    - che fosse resistente ai conflitti

Obiettivo: trovare una funzione di hash che minimizzi i conflitti e una strategia per risolverli -> chaining

## Tabelle hash con Chaining
Tecnica che risolve i conflitti di una tabella hash usando una lista doppiamente collegata con la testa memorizzata in T[h(k)] e quando è vuoto contiene nil (array di puntatori che punta a teste di lista)

image slide 9

questa soluzione occupa un po' più di m parole di memoria, ma molte meno di $|U|$

```pseudocode
proc HashInsert (T, k) {
    let x be a new node with key k
    i = h(k)
    ListInsert(T[i], x)
}
```
complessità: nel caso peggio ->  $\Theta(1)$

```pseudocode
proc HashSearch (T, k) {
    i = h(k)
    return ListSearch(T[i], k)
}
```
complessità: nel caso peggiore -> $\Theta(n)$

```pseudocode
proc HashDelete (T, k) {
    i = h(k)
    x = ListSearch(T[i], k)
    ListDelete(T[i], x)
}
```
complessità: nel caso peggiore -> $\Theta(n)$

I casi peggiori si hanno quando non si trova la chiave nella lista e bisogna scorrerla tutta

Nel cercare le chiavi $k_i$ devo cercare tutte le chiavi di tipo $k_j$ con j > i e tali che $h(k_j) = h(k_i)$ (cercare gli elementi inseriti dopo)

### Complessità ricerca
valore atteso = ...
risoluzione...
risultato = $\Theta(1 + \frac{n}{m})$

## Funzioni di hash per il chaining
- metodo della divisione: garantisce uniforme semplicità quando m è primo (h(k) = k mod m+1)
- metodo della moltiplicazione: garantisce uniformità quando m è una potenza di 2 (h(k) = floor(m(k*A - floor(k*A) ))+1)
- metodo dell'addizione: quando le chiavi sono stringhe (conversione in ASCII e somma dei valori)
- mid square: h(k) = le R cifre centrali del numero $k^2$

```pseudocode
proc HashComputeModulo (w, B, m) {
    let d = |w|
    z[0] = 0
    for (i = 1 to d) z[i+1] = ((z[i] * B) a[i]) mod m
    return z[d] + 1
}
```

## Open hashing
Tecnica che elimina le liste quindi il chaining  
- sequenza di probing -> provare più di una posizione sulla tabella finchè non si trova una posizione libera o la tabella è piena
hashing uniforme -> tutte le posizioni della tabella devono essere provate

### Operazioni
```pseudocode
proc OaHashInsert (T, k) {
    i = 0
    repeat {
        j = h(k, i)
        if T[j] = nil {
            then
            T[j] = k
            return j
        }
        else i = i + 1
    } until (i = m)
    return “overflow”
}
```

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
