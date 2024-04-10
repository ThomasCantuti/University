# Modello dei dati relazionali

Modello basato sul concetto di **Relazione** (concetto matematico basato sulla teoria degli insiemi)

## Relazione
La relazione è una tabella di valori:
    - insieme di righe
    - insieme di colonne

Ogni riga rappresenta un'**istanza** di un'entità  
Ogni riga possiede un valore per un elemento o insisme di elementi che la identificano univocamente

## Definizioni formali

### Schema di una relazione
R(A1, A2, ..., An) con R nome della relazione e A1, A2, ..., An attributi della relazione

Esempio:
CLIENTI (ID-Cli, Nome-Cli, Indirizzo, Tel)  
CLIENTI è una relazione definita sui quattro attributi ID-Cli, Nome-Cli, Indirizzo e Tel, ciascuno dei quali possiede un dominio, o insieme di valori validi.  
ID-Cli è un numero di 6 cifre.

### Tuple
Insieme ordinato di valori dove ogni valore è derivato da un dominio  
Le colonne sono gli attributi della relazione

Esempio:
<632895, “Giacomo Piva", "via Saragat 1, 44122, Ferrara", "+39 (0532) 974344"> è una tupla appartenente alla relazione CLIENTI


### Dominio
Ha una definizione logica (es. numeri di telefono -> insieme dei numeri di telefono validi)  
Può avere **un tipo di dati** o un **formato** definito (es. numeri di telefono ha formato +dd (dddd) dddddddd dove d è una cifra decimale)  
Il ruolo del dominio è l'attributo (es. dominio date -> attributo "DataFattura")

### Relazione
Relazione o stato della relazione è formata dal prodotto cartesiano degli insiemi dominio (es. S1 x S2) dove ciascun insieme ha valori provenienti da un dominio (dominio usato per definire il ruolo dell'attributo)

### Esempio formale:
- dato R(A1, A2, ..., An)
- r(R) $\subset$ dom(A1) x dom(A2) x ... x dom(An)
    - R -> schema della relazione
    r di R -> stato della relazione (specifico "valore" o popolazione di R)
    - R -> intensione della relazione
    - r -> estensione della relazione

### Esempio:
- S1 = {0, 1} e S2 = {a, b, c}
- R $\subset$ S1 x S2
- r(R) = {<0, a>, <0, b>, <1, c>} è un possibile stato (o popolazione o intensione) r della relazione R, definita nei domini S1 e S2 con 3 tuple

![alt text](image/05_00.png)

Esempio:
![alt text](image/05_01.png)


## Caratteristiche Relazioni
- Le tuple non si devono considerare ordinate
- L'ordinamento degli attributi esiste ed è R(A1, A2, ..., An) ed i valori in t = <v1, v2, ..., vn>
- una relazione più generale non richiede ordinamento
- tutti i valori in una tupla sono atomici e NULL si usa per valori sconosciuti

### Notazione
valori in una tupla t: t[A_i] = v_i

## Vincoli di Integrità
Condizioni che devono essere rispettate da tutti gli stati di una relazione validi ed esistono 3 vincoli:
- **Vincoli sulla Chiave**
- **Vincoli di integrità dell'Entità**
- **Vincoli di integrità Referenziale**

### Vincoli sulla Chiave
- **Superchiave** di R: insieme di attributi che identificano univocamente una tupla
- **Chiave** di R: superchiave di R che è minimale (se ce ne sono varie se ne sceglie una come chiave primaria)
- **Chiave Primaria** di R: chiave scelta come chiave di riferimento per la relazione

### Vincoli di integrità dell'Entità
Gli **Attributi chiave** non possono essere NULL in nessuna tupla

### Vincoli di integrità Referenziale
Quando si hanno due relazioni e una di queste fa riferimento all'altra per un attributo, il valore dell'attributo deve esistere nell'altra relazione

### Altri Vincoli
- **Vincoli di Integrità Semantica**: vincoli basati sulla semantica dell'applicazione
Esempio: se in una scuola si ha l'attributo età e si vuole che sia compreso tra 18 e 65

## Operazioni sulle Relazioni
- **Inserimento** di una tupla (INSERT)
- **Cancellazione** di una tupla (DELETE)
- **Modifica** di una tupla (MODIFY, UPDATE)
- i vincoli di integrità devono essere rispettati anche dale operazioni di aggiornamento
- una serie di operazioni di aggiornamento possono essere raggruppate insieme (bulk insert)
- le operazioni di aggiornamento possono creare in automatico altri aggiornamenti

Se un'operazione di aggioernamento viola un vincolo di integrità:
- si annulla l'operazione che causa la violazione (REJECT)
- eseguire l'operazione, informando l'utente della violazione
- eseguire altri aggiornamenti per correggere la violazzione (CASCADE, SET NULL)
- eseguire una routine dell'utente pre correggere la violazione