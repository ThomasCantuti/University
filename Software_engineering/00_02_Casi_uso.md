# Modellazione di Casi d'uso
<img src="images/00_02_00.png" alt="descrizione" width="450" height="300">

## Modellazione dei casi d'uso
- **Obiettivo**: Descrivere **cosa** fa un sistema senza specificare **come**.
- **Finalità**:
    - Raccogliere e organizzare i **requisiti** del sistema.
    - Definire le **interazioni** tra **attori** (utenti o sistemi esterni) e il **sistema**.
- **Capacità del sistema**:
    - Mostrare come le funzionalità del sistema sono realizzate **dagli attori**.
    - Delineare il **confine** tra sistema e ambiente esterno.
- **Strumenti di rappresentazione**:
    - **Diagrammi di casi di uso**: Visualizzano graficamente le funzionalità principali.
    - **Descrizioni testuali**: Supportate da diagrammi comportamentali per chiarire il flusso operativo.
- **Vantaggi**:
    - Chiarisce le esigenze degli attori.
    - Definisce le funzionalità chiave del sistema.

## Elementi di un Diagramma di Casi d'uso
<img src="images/00_02_01.png" alt="descrizione" width="500" height="300">

- **Attore**:  
  - **Definizione**: Rappresenta un utente o un sistema esterno che interagisce con il sistema.  
  - **Esempi**: Cliente, banca, personale di vendita.

- **Caso d'uso**:  
  - **Definizione**: Sequenza di azioni che il sistema esegue con l'interazione di un attore.  
  - **Esempio**: Login (inserimento credenziali, verifica, accesso).

- **Sistema**:  
  - **Definizione**: Rappresenta il confine tra ciò che è all'interno del sistema e ciò che è esterno.  
  - **Ruolo**: Determina i limiti del sistema, delimitando le interazioni possibili con gli attori.

- **Relazioni**:  
    - **Associazione**:  
        - **Definizione**: Connessione tra un **attore** e un **caso di uso**.
        - **Ruolo**: Rappresenta le azioni principali che un attore compie con il sistema.
        - **Esempio**: Un cliente (attore) che esegue l’azione di "effettuare un acquisto" (caso di uso).

    - **Include**:  
        - **Definizione**: Relazione che indica che un **caso di uso** include sempre il comportamento di un altro caso di uso.
        - **Ruolo**: Il comportamento dell’altro caso è **obbligatorio** e viene eseguito ogni volta che si verifica il primo.
        - **Esempio**: L’acquisto di un prodotto include il caso di uso "verifica disponibilità".

    - **Extend**:  
        - **Definizione**: Relazione che permette a un **caso di uso** di estendere il comportamento di un altro caso di uso.
        - **Ruolo**: Il comportamento aggiuntivo è **opzionale** e viene attivato solo in condizioni specifiche.
        - **Esempio**: Il caso di uso "pagamento" può estendere con "inserimento sconto" in caso di promozioni.

    - **Generalizzazione/Specializzazione (eredità)**:  
        - **Definizione**: Relazione "è_un" tra **casi di uso** o **attori**.
        - **Ruolo**: Un attore o caso di uso più specifico eredita il comportamento o le caratteristiche di uno più generale.
        - **Esempio**: Un "cliente premium" è_un "cliente", quindi eredita le stesse azioni di base con funzionalità aggiuntive.

**Relazioni tra attori e casi d'uso:**

<img src="images/00_02_02.png" alt="descrizione" width="500" height="300">

I diagrammi dei casi d'uso servono nei processi iniziali di ingegneria dei requisiti per identificare e raccogliere i requisiti del sistema.  
Strumenti come VP4UML consentono un'analisi testuale delle specifiche preliminari, che aiuta a ottenere le prime approssimazioni dei diagrammi dei casi d'uso (diagrammi preliminari).

Esempi di diagrammi dei casi d'uso:

<img src="images/00_02_03.png" alt="descrizione" width="550" height="300">
<img src="images/00_02_04.png" alt="descrizione" width="550" height="300">

**Casi d'uso di base**: quando il caso d'uso è direttamente collegato all'attore (il primo esempio ha 3 casi d'uso di base e il secondo ne ha 2)

**Casi d'uso condiviso**: quando due o più attori intervengono contemporaneamente sul caso d'uso per soddisfare il requisito (la funzionalità)

<img src="images/00_02_05.png" alt="descrizione" width="550" height="400">
<img src="images/00_02_07.png" alt="descrizione" width="600" height="350">

**Ereditarietà tra attori**: per organizzare la semantica della specificazione

<img src="images/00_02_06.png" alt="descrizione" width="600" height="300">

Elaborazione di un diagramma dei casi d'uso:
1. familiarizzare con il dominio del problema da risolvere
2. individuare e sottolineare i verbi e i nomi o i sostantivi rilevanti (indicazioni delle possibili funzioni future del sistema e degli attori)
3. partendo dagli elementi individuati si crea uno schema, individuando i casi d'uso di base e la struttura organizzativa dei casi d'uso interni
4. si fa un primo rapido schizzo a partire dallo schema poi si risolve ogni attore separatamente e poi li si unisce in un diagramma unico
5. si analizza il diagramma per verificare gli aspetti sintattici e semantici (vincoli imposti, risoluzioni per specializzazione, ereditarietà degli attori)