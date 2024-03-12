# Modellazione dei Dati mediante il Modello ER (Entity-Relationship o Entità-Associazione)

uso di Database "Azienda" come esempio

## Database Azienda

Richieste sintetiche dell'azienda (analisi requisiti):
- **Dipartimenti** (organizzazione dell'azienda) -> nome, codice, data di creazione, codice responsabile
- **Progetti** (ogni dipartimento controlla un numero di progetti) -> nome, codice, data di inizio, data di fine, budget, codice dipartimento
- **Dipendenti** -> nome, cognome, data di nascita, indirizzo, telefono, codice fiscale, stipendio, data assunzione, codice dipartimento

## Modello ER
Entità e Attributi:
- **Entità** -> oggetto del mondo reale (dipartimento, progetto, dipendente)
- **Istanza** -> singola occorrenza di un'entità (dipartimento "Vendite", progetto "Sviluppo App", dipendente "Mario Rossi")
- **Attributo** -> proprietà per descrivere un'entità (nome, cognome di un dipendente)
- **Attributo chiave** -> attributo che identifica univocamente un'istanza di un'entità (codice fiscale di un dipendente)
- **Valore** -> valore di un attributo per un'istanza (nome = 'Mario', cognome = 'Rossi', data di nascita = '01/01/1990')
- **Tipo di dati** -> insieme di valori per un attributo (stringa, numero (chiedersi se ci si può fare dei conti, se possibile è un numero altrimenti è una stringa))

## Tipi di Attributi
- **Semplici** -> non può essere suddiviso in parti più piccole, solo l'attributo semplice può essere un attributo chiave (nome, cognome, CF, sesso)
- **Composti ()** -> può essere suddiviso in parti più piccole (indirizzo -> via, città, CAP)
- **Multivalore {}** -> può avere più valori (titoli di studio (può averne uno o più))
- **Derivati** -> può essere calcolato da altri attributi (età, data di nascita)
- **Data** -> esiste un'attributo tutto suo (data di nascita, data di assunzione)

## Entità, Istanze e Attributi chiave
Entità (o tipi di entità) -> Istanza -> Attributo (o attributo chiave) -> Valore

Esempio: entità AUTO ed istanze
AUTO: Targa(Provincia, Numero), NumeroTelaio, Marca, Modello, Anno, {Colore}
auto1: ((FE, 541080), TK629, Fiat, Tipo, 1993, {verde met.})
auto2: ((BO, 371166), TD729, Fiat, Panda, 2004, {nero, bianco})

## Notazione ER
![alt text](image/03_00.png)

## Esempio Database Azienda per gestire: Dipartimenti, Progetti e Dipendenti
Entità: Dipartimento, Progetto, Dipendente

## Associazioni
- **Associazione** -> relazione tra due o più entità con un significato (dipendente lavora in un dipartimento, progetto è assegnato a un dipartimento)
- **Istanza di associazione** -> mette in riferimento due o più istanze di entità (Mario Rossi lavora nel dipartimento Vendite)
- **Grado di un'associazione** -> numero di entità coinvolte

## Istanze dell'associazione LAVORA PER
![alt text](image/03_01.png)

## Istanze dell'associazione LAVORA SU
![alt text](image/03_02.png)

## Entità Deboli ed Associazioni Identificative
- **Entità Debole** -> non ha un attributo chiave proprio, ma dipende da un'altra entità (dipendente, auto, figlio)
- **Associazione Identificativa** -> associazione che identifica un'entità debole (dipendente lavora in un dipartimento, auto è di un proprietario, figlio è di un genitore)

## Vincoli sulle Associazioni
- **Cardinalità massima** ->  quanti collegamenti possono esserci tra le entità coinvolte (1:1, 1:N, M:N):
    - 1:1 (uno a uno)
    - 1:N (uno a molti) o N:1 (molti a uno)
    - M:N (molti a molti)
- **Cardinalità minima** -> quanti collegamenti devono almeno esserci tra le entità coinvolte (0, 1):
    - 0 (partecipazione opzionale)
    - 1 o più (partecipazione obbligatorio)

## Associazioni Ricorsive
- **Associazione Ricorsiva** -> un'entità è associata a se stessa (dipendente è comandato (supervisionato) da un altro dipendente)

## Notazione alternativa (min, max)
specifica la quantità minima e massima di istanze delle entità coinvolte in almeno min e al massimo max istanze dell'associazione