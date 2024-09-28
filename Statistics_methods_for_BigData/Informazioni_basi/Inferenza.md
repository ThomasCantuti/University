# Introduzione all'inferenza statistica

## 1. Concetti di base
- **Inferenza statistica:** Processo di estrazione di conclusioni su una popolazione a partire da un campione. 
- **Popolazione:** Insieme completo di elementi da studiare.
- **Campione:** Sottogruppo della popolazione, spesso selezionato casualmente.

## 2. Caratteristiche del campione e distribuzioni
- **Statistiche campionarie:** Misure calcolate dal campione, come la media $\bar{x}$ e la varianza $s^2$.
- **Distribuzioni campionarie:** Descrivono la distribuzione di una statistica (es. la media campionaria) sotto ripetute estrazioni. La media di un campione estratto da una popolazione normale è distribuita normalmente:

$$\bar{X} \sim N\left(\mu, \frac{\sigma^2}{n}\right)$$

dove $\mu$ è la media della popolazione, $\sigma^2$ è la varianza della popolazione, e $n$ è la dimensione del campione.

## 3. Statistiche in popolazioni normali
- Se la popolazione è normalmente distribuita, le statistiche campionarie seguono distribuzioni note, come la distribuzione $t$ di Student per piccoli campioni (con $n < 30$):

$$t = \frac{\bar{X} - \mu}{\frac{s}{\sqrt{n}}}$$

---

# Proprietà delle statistiche e degli stimatori

## 1. Statistiche sufficienti
- **Statistiche sufficienti:** Contengono tutte le informazioni necessarie per stimare un parametro. Se $T(X)$ è una statistica sufficiente per $\theta$, la verosimiglianza può essere scritta come:

$$L(\theta; X) = g(T(X), \theta) h(X)$$

## 2. Statistiche complete
- **Statistiche complete:** Statistiche sufficienti che non possono essere migliorate con ulteriori informazioni.

## 3. Stimatori non distorti di varianza minima uniforme
- **Stimatori non distorti:** $E[\hat{\theta}] = \theta$.
- **Varianza minima:** Un estimatore è detto uniformemente minimo se ha la varianza più bassa tra gli stimatori non distorti.

## 4. Coerenza
- **Coerenza:** Un estimatore è coerente se converge in probabilità al valore vero del parametro. Formalmente:

$$\hat{\theta}_n \xrightarrow{P} \theta$$

dove $\hat{\theta}_n$ è l'estimatore e $n$ è la dimensione del campione.

## 5. Efficienza asintotica
- **Efficienza asintotica:** Riguarda la performance di un estimatore quando la dimensione del campione tende all'infinito. La varianza asintotica di un estimatore è:

$$Var(\hat{\theta}_n) \xrightarrow{n \to \infty} 0$$

---

# Metodi di stima puntuale

## 1. Stima di massima verosimiglianza (MLE)
- **MLE:** Stima i parametri massimizzando la funzione di verosimiglianza:

$$\hat{\theta}_{MLE} = \arg \max_\theta L(\theta; X)$$

## 2. Metodo dei momenti
- **Metodo dei momenti:** Consiste nel calcolare i momenti della popolazione e uguagliarli ai momenti del campione. Per esempio, per un parametro $\theta$:

$$E[X] = \frac{1}{n}\sum_{i=1}^{n} x_i$$

---

# Test parametrici di ipotesi

## 1. Concetti fondamentali
- **Test di ipotesi:** Procedura per verificare un'affermazione riguardante un parametro. Due ipotesi:
  - **Ipotesi nulla (H0):** Ipotesi da testare.
  - **Ipotesi alternativa (H1):** Opposta all'ipotesi nulla.

## 2. Test uniformemente più potenti
- **Test più potenti:** Massimizzano la probabilità di rifiutare l'ipotesi nulla quando è falsa.

## 3. Test per famiglie di rapporti di verosimiglianza monotoni
- Utilizzano la funzione di verosimiglianza per confrontare modelli.

## 4. Test non distorti
- Mantengono costante il livello di significatività.

## 5. Test del rapporto di verosimiglianza
- Confronta la verosimiglianza sotto H0 e H1:

$$\Lambda = \frac{L(H_0)}{L(H_1)}$$

## 6. Test per popolazioni normali e proporzioni
- Usano statistiche come la $z$-statistica per testare medie e proporzioni.

---

# Test non parametrici

## 1. Test di bontà di adattamento
- Verificano se i dati seguono una certa distribuzione, come il test di chi-quadrato:

$$\chi^2 = \sum \frac{(O_i - E_i)^2}{E_i}$$

dove $O_i$ è il valore osservato e $E_i$ è il valore atteso.

## 2. Test di casualità
- Controllano se una sequenza di dati è casuale (es. test di runs).

## 3. Test di posizione e indipendenza
- Testano le relazioni tra variabili usando statistiche come il test di Wilcoxon.

## 4. Test per confrontare due campioni indipendenti
- Utilizzano statistiche come il test di Mann-Whitney.

## 5. Test per confrontare campioni abbinati
- Analizzano dati correlati, come il test di Wilcoxon per dati appaiati.

---

# Intervalli di confidenza

## 1. Concetti di base
- Un intervallo di confidenza stima l'incertezza riguardo a un parametro:

$$IC = \hat{\theta} \pm z \cdot \frac{\sigma}{\sqrt{n}}$$

dove $\hat{\theta}$ è l'estimatore, $z$ è il valore critico della distribuzione normale.

## 2. Metodi di costruzione
- Vari metodi per calcolare intervalli di confidenza per medie e proporzioni.

## 3. Criteri di ottimalità
- Riguardano come scegliere intervalli di confidenza con la migliore copertura.

## 4. Relazione con i test di ipotesi
- Un intervallo di confidenza può essere utilizzato per testare un'ipotesi: se un valore ipotetico non è incluso nell'intervallo, si rifiuta H0.

## 5. Applicazione a popolazioni normali e proporzioni
- Costruzione di intervalli di confidenza per parametri specifici in popolazioni normali e per proporzioni.