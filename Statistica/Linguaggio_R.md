# Documentazione Funzioni R - Statistica

## Grafici
- `plot(x, y, type = "p")`: grafico con coordinate `x` e `y`, `type` indica il tipo di grafico.
- `lines(x, y, type = "i")`: sovrapposizione di grafici con coordinate `x` e `y`.
- `boxplot(x)`: crea un boxplot dei dati `x`.
- `barplot(x)`: crea un diagramma a barre per i dati `x`.
- `pie(x)`: crea un diagramma a torta per i dati `x`.
- `hist(x)`: istogramma dei dati `x`.
  - `breaks = n`: dimensione delle linee dell'istogramma; un valore piccolo di `n` produce linee più grosse.
  - `freq = TRUE/FALSE`: se `TRUE`, l'asse delle ordinate mostra i valori interi di frequenza; se `FALSE`, mostra i valori percentuali di densità.

## Statistica Descrittiva
- `factorial(n)`: calcola il fattoriale di `n`.
- `choose(n, k)`: calcola il coefficiente binomiale di `n` su `k`.
- `sample(x, size, replace = TRUE)`: genera un campione casuale di dimensione `size` da un vettore `x`, con o senza reimmissione (controllata da `replace`).
- `mean(x)`: calcola la media di `x`.
- `median(x)`: calcola la mediana di `x`.
- `var(x)`: calcola la varianza di `x`.
- `cor(x, y)`: calcola la correlazione tra `x` e `y`.
- `sd(x)`: calcola la deviazione standard di `x`.
- `table(x)`: crea una tabella di distribuzioni di frequenze assolute di `x`.
- `prop.table(x)`: crea una tabella di distribuzioni di frequenze relative di `x`.
- `cumsum(x)`: calcola la funzione cumulativa empirica di `x`.
- `duplicated(y)`: verifica la presenza di duplicati in `y` restituendo un valore TRUE/FALSE.
- `anyDuplicated(y)`: restituisce il numero di elementi duplicati in `y`.
- `sum(x)`: somma gli elementi di un vettore `x`.
- Cicli: 
```r
  for(i in 1:length(x)){ ... }
```

dove `x` è un vettore.

- `seq(N, F, pass)`: crea un vettore da `N` (iniziale) a `F` (finale) con incremento/decremento pari a pass.

## Variabile Aleatoria Binomiale
- `dbinom(Sk, n, p)`: funzione di massa di probabilità (PMF) per una binomiale con supporto `Sk`, dimensione `n` e probabilità `p`.
- `pbinom(Sk, n, p)`: funzione di distribuzione cumulativa (CDF) per una binomiale.
- `rbinom(Sy, n, p)`: genera variabili casuali binomiali.

## Variabile Aleatoria Normale (Gaussiana)
- `dnorm(x, mean, sd, log = FALSE)`: funzione di densità di probabilità (PDF) per una normale con media `mean` e deviazione standard `sd`.
- `pnorm(x, mean, sd, lower.tail = TRUE, log.p = FALSE)`: funzione di distribuzione cumulativa (CDF) per una normale.
  - `lower.tail = TRUE`: calcola `P[X <= x]`, se `FALSE`, calcola `P[X > x]`.
  - `log.p = TRUE`: le probabilità sono restituite in log(p).
- `rnorm(n, mean, sd)`: genera variabili casuali normali.
- `qnorm(p, mean, sd, lower.tail = TRUE, log.p = FALSE)`: dato un valore `p`, calcola il quantile corrispondente.

## Variabile Aleatoria Esponenziale
- `dexp(x, rate, log = FALSE)`: funzione di densità di probabilità (PDF) per una distribuzione esponenziale con tasso `rate`.
- `pexp(x, rate, lower.tail = TRUE, log.p = FALSE)`: funzione di distribuzione cumulativa (CDF) per una esponenziale.
- `rexp(n, rate)`: genera variabili casuali esponenziali.
- `qexp(p, rate, lower.tail = TRUE, log.p = FALSE)`: calcola il quantile per una distribuzione esponenziale.

## Teorema del Limite Centrale
- `matrix(x, nr, nc)`: genera una matrice con dati `x`, numero di righe `nr` e colonne `nc`.
- `rowSums(y)`: somma gli elementi per riga di una matrice `y`.
- `colSums(y)`: somma gli elementi per colonna di una matrice `y`.