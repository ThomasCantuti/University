# Algebra e Calcolo Relazionale

Esempio di Applicazione con Database Azienda

![alt text](image/06_00.png)

## Algebra Relazionale
Algebra relazionale -> insieme di operazioni per il modello relazionale che consentono all'utente di specificare le interrogazioni fondamentali

Risultato interrogazione -> nuova relazione (può essere stata formata da una o più relazioni)

Espressione dell'algebra relazionale -> sequenza di operazioni dell'algebra relazionale, con risultato un'altra relazione che rappresenta il risultato di un'interrogazione del database

### Operazioni relazionali unarie
**Operazione di selezione (SELECT)**: per selezionare un sottoinsieme di tuple che soddisfano una condizione (filtro orizzontale)  
Notazione: σ<sub>condizione</sub>(R)  
Esempio: σ<sub>Età>30</sub>(DIPENDENTE) -> seleziona i dipendenti con età maggiore di 30 anni  
Proprietà:
- SELECT σ<sub>condizione</sub>(R) produce una relazione con lo stesso schema di R
- SELECT è commutativa: σ<sub>cond1</sub>(σ<sub>cond2</sub>(R)) = σ<sub>cond2</sub>(σ<sub>cond1</sub>(R))
- SELECT in cascata possono essere eseguite in qualunque ordine per la proprietà commutativa
- SELECT in cascata si possono sostituire con una SELECT che combina le condizioni con un operatore logico AND: σ<sub>cond1</sub>(σ<sub>cond2</sub>(R)) = σ<sub>cond1 AND cond2</sub>(R)

**Operazione di proiezione (PROJECT)**: per selezionare alcuni attributi (colonne) da una relazione (tabella) scartando gli altri (filtro verticale), quest'operazione elimina eventuali duplicati delle tuple  
Notazione: π<sub>attributi</sub>(R)  
Esempio: π<sub>Nome, Cognome</sub>(DIPENDENTE) -> seleziona solo i campi Nome e Cognome dalla tabella DIPENDENTE  
Proprietà:
- il numero di tuple risultanti è sempre minore o uguale al numero di tuple della relazione originale R
- se nell'elenco di tuple c'è una chiave di R allora il numero di tuple risultanti è uguale al numero di tuple della relazione originale R
- π<sub>attributi1</sub>(π<sub>attributi2</sub>(R)) = π<sub>attributi1</sub>(R) se attributi1 è contenuto in attributi2

![alt text](image/06_01.png)

**Operazione di ridenominazione (RENAME)**: da la possibilità di applicare un'operazione alla volta e creare relazioni con risultati intermedi con nomi diversi  
Esempio senza rename:  
π<sub>FName, LName, Salary</sub>(σ<sub>DNO=5</sub>(DIPENDENTE))
## Calcolo Relazionale