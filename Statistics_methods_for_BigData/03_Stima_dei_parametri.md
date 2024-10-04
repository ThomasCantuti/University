# Stima dei parametri
- L'informazione sul parametro sconosciuto è contenuta nella distribuzione a posteriori
- Esistono più modi per ottenere dalla distribuzione a posteriori una stima del parametro per alcuni dati osservati
- Bisogna definire un criterio oggettivo che consenta di scegliere gli stimatori ottimali in base a tale criterio

## Funzione di perdita e di rischio
- si consideri un modello parametrico bayesiano $(X, f(x | \theta), \pi(\theta))$

- si consideri un campione $X = (X_1, X_2, \ldots, X_n)$ e uno stimatore di $\theta, \hat{\theta}(X_1, ..., X_n)$

- **Funzione di perdita**: è una funzione non negativa $L : D \times \Theta \rightarrow \mathbb{R}$ che misura il costo di stimare $\theta$ con $\hat{\theta}$ quando il vero valore del parametro è $\theta$ ($D$ è lo spazio dei dati, $\Theta$ è lo spazio dei parametri)

- **Rischio**: è la funzione che misura il costo atteso (aspettazione) di stimare $\theta$ con $\hat{\theta}$, $R(\theta, \hat{\theta}) = E_{\theta}[L(\theta, \hat{\theta})] = \int L(d, \theta) \pi(\theta | x_1, ..., x_n) d\theta$ con $d = \hat{\theta}(x_1, ..., x_n)$

- **criterio per costruire gli stimatori** $\rightarrow$ cercare gli stimatori che minimizzano il rischio (si ottengono stimatori diversi a seconda della funzione di perdita utilizzata)

- **Stimatore del minimo rischio**: data una funzione di perdita $L(d, \theta)$, lo stimatore del minimo rischio è $\hat{\theta}(x_1, ..., x_n) = argmin_{d} \int L(d, \theta) \pi(\theta | x_1, ..., x_n) d\theta$

- **Funzione di perdita quadratica**: $L(d, \theta) = (d - \theta)^2$