# Ricorrenze

ogni T(n) esplicita ha un'ordine di grandezza

per trasformare una ricorrenza in una funzione da implicita a esplicita si possono usare 3 metodi:
- albero di ricorsione (o sviluppo in serie)
- Master Theorem
- metodo di sostituzione (o induzione)

si sviluppa la ricorrenza per cercare di estrarne il comportamento

Esempio:
$T(n) = T(frazione\ di\ n) + f(n)$

Osservazione: la chiamata più piccola possibile è T(1) = 1 (somma di casi base o parti non ricorsive)

Formula generale per le ricorrenze:

$T(n) = a*T(\frac{n}{b}) + f(n)$

## Soluzione di ricorrenze: Master Theorem
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