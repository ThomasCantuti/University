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
Notazione: ρ<sub>nuovoNome</sub>(R)  
Esempio: trovare nome, cognome e stpendio dei dipendenti che lavorano nel dipartimento 5  
senza rename: π<sub>FName, LName, Salary</sub>(σ<sub>DNO=5</sub>(DIPENDENTE))  
con rename:  
DEP5_EMPS $\leftarrow$ σ<sub>DNO=5</sub>(DIPENDENTE)  
RESULT $\leftarrow$ π<sub>FName, LName, Salary</sub>(DEP5_EMPS)  

![alt text](image/06_02.png)

### Operazioni insiemistiche
**Operazione di unione (UNION)**: unisce due relazioni in una unica con tutte le tuple di una e dell'altra (rimuove eventuali duplicati)  
Notazione: R ∪ S  
Compatibilità dell'unione:
- R e S devono avere lo stesso numero di attributi e il dominio di ogni attributo di R deve essere lo stesso di quello di S
- la relazione risultante ha gli stessi nomi di attributi di R

**Operazione di intersezione (INTERSECTION)**: restituisce una relazione con le tuple presenti in entrambe le relazioni  
Notazione: R ∩ S  
Compatibilità dell'intersezione: stessa compatibilità dell'unione

**Operazione di differenza (MINUS)**: restituisce una relazione con le tuple presenti in R ma non in S  
Notazione: R - S  
Compatibilità della differenza: stessa compatibilità dell'unione

![alt text](image/06_03.png)

Proprietà delle operazioni UNION, INTERSECTION e MINUS:
- UNION e INTERSECTION sono commutative: R ∪ S = S ∪ R, R ∩ S = S ∩ R
- UNION e INTERSECTION sono associative: R ∪ (S ∪ T) = (R ∪ S) ∪ T, R ∩ (S ∩ T) = (R ∩ S) ∩ T
- MINUS non è commutativa: R - S ≠ S - R

**Operazione di prodotto cartesiano (prodotto incrociato)**: restituisce una relazione con tutti gli attributi di R e S e tutte le possibili combinazioni di tuple di R e S (R e S non devono essere compatibii all'unione)  
Notazione: |R x S| ha n x m tuple (n = numero di tuple di R, m = numero di tuple di S)  
Esempio:  
FEMALE_EMPS $\leftarrow$ σ<sub>SEX=F</sub>(EMPLOYEE)  
EMPNAMES $\leftarrow$ π<sub>FName, LName, SSN</sub>(FEMALE_EMPS)  
EMP_DEPENDENTS $\leftarrow$ EMPNAMES x DEPENDENT

![alt text](image/06_04.png)

### Operazioni relazionali binarie
**Operazione di JOIN**: restituisce una relazione data da un prodotto cartesiano seguito da una selezione  
Notazione: R ⨝<sub>condizione</sub> S  
Esempio: trovare i nomi dei manager di ciascun dipartimento  
DIP_MGR $\leftarrow$ DIPARTIMENTO ⨝<sub>MGRSSN=SSN</sub> DIPENDENTE

**THETA JOIN**: JOIN con condizione arbitraria  
Notazione: R ⨝<sub>cond AND cond AND ... AND cond</sub> S

**EQUI-JOIN**: JOIN con unica operazione, quella di uguaglianza, e si ha come risultato una o più coppie di attributi con gli stessi valori in ogni tupla

**NATURAL JOIN**: JOIN (indicata con *) che non include i duplicati in una condizione di uguaglianza. Se due relazioni hanno attributi con lo stesso nome, la condizione di JOIN diventa una ridenominazione

![alt text](image/06_05.png)
