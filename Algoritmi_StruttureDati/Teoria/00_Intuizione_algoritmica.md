# Intuizione algoritmica

## Definizione di algoritmo
Algoritmo fino all'epoca moderna -> metodo per risoluzione simbolica di numeri  
Algoritmo oggi -> qualsiasi procedura che da un input produce un output

Problema -> ciò che dobbiamo risolvere  
Problema risolvibile -> esiste un algoritmo che lo risolve  
Istanza -> input di un problema  
Soluzione -> output di un problema

## Epoca moderna dell'informatica (con Turing)
Computabilità -> caratteristica del problema e non dell'algoritmo che lo risolve  
Complessità -> caratteristica di entrambi, il problema e l'algoritmo che lo risolve

## Scrivere algoritmi
3 aspetti di un linguaggio:
- **sintassi** -> come strutturo una frase
- **semantica** -> cosa significa una frase
- **pragmatica** -> miglior modo di esprimere un concetto, fissata la sintassi e la semantica

Ogni linguaggio è sufficientemente espressivo per esprimere qualsiasi algoritmo pertanto si usa lo pseudo codice

```pseudocode
proc MyFunction (MyArg1, Myarg2, ...) {
    for (i = Something to SomethingElse) {
        ...
    }
    while (Condition) {
        ...
    }
    if (Condition) {
        ...
    }
    MyOtherFunction (MyArg3, MyArg4, ...)
    return Something
}
```

**Dimensione dell'input** -> numero di bit che l'input occupa  
**Tempo di computazione** -> numero di passi elementari che si impiegano e tiene conto di costanti che nascondono dettagli implementativi  
**Indici array** -> iniziano da 1 (da 0 solo se specificato)  
**Complessità** -> tempo e spazio (di memoria)
