# Ricorrenze

## Esempi di forme di ricorrenze
- $T(n) = 2*n^2 + 3*n + 5$ -> forma esplicita e precisa
- $T(n) = a*n^2 + b*n$ -> forma esplicita e generica
- $T(n) = \Theta(n)$ -> forma asintotica

ogni T(n) esplicita ha un'ordine di grandezza

per trasformare una ricorrenza in una funzione da implicita a esplicita si possono usare 3 metodi:
- albero di ricorsione (o sviluppo in serie)
- Master Theorem
- metodo di sostituzione (o induzione)

## Albero di ricorsione
si sviluppa la ricorrenza per cercare di estrarne il comportamento

Esempio:
$T(n) = T(frazione\ di\ n) + f(n)$

Osservazione: la chiamata più piccola possibile è T(1) = 1 (somma di casi base o parti non ricorsive)

## Master Theorem
Formula generale per le ricorrenze:

$T(n) = a*T(\frac{n}{b}) + f(n)$

Sviluppo in serie generale (se n è potenza esatta di b):

$T(n) = \sum_{i=0}^{log_b(n)-1} a^i * f\left(\frac{n}{b^i}\right) + O\left(n^{log_b(a)}\right)$



### $f(n) = O(n^{(\log_a{(b)} - \epsilon)})$
dimostrazione
### $f(n) = \Theta(n^{(\log_a{(b)})})$
dimostrazione
### $f(n) = \Omega(n^{(\log_a{(b)} + \epsilon)})$
dimostrazione

![alt text](images/02_00.png)


## Master Theorem non basta -> Soluzioni
### Metodo di sostituzione
Indovinare il risultato e poi dimostrarlo per induzione

Strategia generale:
1. si prova il Master Theorem
2. se non funziona:
    1. sviluppare in serie