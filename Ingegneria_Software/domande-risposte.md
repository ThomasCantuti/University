# Capitolo 1: Ingegneria Software Introduzione

## 1. Quali sono gli attributi per un software di qualità?

**Qualità** di un software valutata in base a **caratteristiche**:

- **interne**: scelte implementative non visibili all'utente
- **esterne**: funzionalità fornite dal sistema e visibili all'utente finale

Le caratteristiche sono collegate: no buone qualità interne --> no buone qulità esterne

**Attributi essenziali** di un software:

- **Maintainability**: software scritto in modo da poter evolvere secondo le modifiche dei requisiti (i requisiti possono spesso cambiare durante il processo)
- **Dependability (e Security)**: software che non causa danni fisici o economici in caso di guasti e software sicuro da accessi o danneggiamenti da malintenzionati
- **Efficiency**: software che non spreca risorse (tempo di elaborazione, uso di memoria, ...)
- **Acceptability**: software accettabile dagli utenti per cui è stato sviluppato (comprensibile, usabile, compatibile con altri sistemi utilizzati)

**Triangolo di McCall** altre qualità importanti, divise in 3 tipi di operazioni sul prodotto:

- **Product Operation**: correttezza, affidabilità, usabilità, efficienza, integrità
- **Product Revision**: mantenibilità, flessibilità, testabilità
- **Product Transition**: portabilità, riusabilità, interoperabilità

modulo = parte funzionale di un sistema, reso indipendente

Attributi legati alla mantainability, durante la progettazione:

- **Coesione**: misura quanto gli elementi all'interno di un modulo sono strettamente correlati all'esecuzione di una funzione comune (obiettivo --> alta coesione)  
  ![alt text](<imgs/Screenshot 2025-06-25 alle 16.13.48.png>)
- **Coupling**: misura il livello di interconnessione tra moduli (obiettivo --> basso accoppiamento)  
  ![alt text](<imgs/Screenshot 2025-06-25 alle 16.15.10.png>)
- **Adattabilità**: se progetto ha componenti debolmente accoppiate, ben documentate e ha una forte coesione
- **Comprensibilità**: legata a coesione, nomi significativi, documentazione e bassa complessità

# Capitolo 3a: Modelli di processo di sviluppo di software

## 2. Descrivere il modello di sviluppo a Cascata (Wateerfall model)

![alt text](<imgs/Screenshot 2025-06-25 alle 16.28.50.png>)

Modello di processo semplice che passa alla fase successiva solo quando la precedente è terminata e ha prodotto un documento.

**Fasi**:

1. Definizione dei Requisiti
2. Progettazione del Sistema e del Software
3. Implementazione e testing delle singole unità
4. Integrazione e testing di Sistema
5. Installazione e Manutenzione

**Uso**: quando i requisiti sono chiari dall'inizio e non si modificheranno

**Vantaggi**:

- buona visibilità del processo (ogni attività produce un documento)
- basso rischio di problemi se si acquisisce familiarità con il progetto

**Svantaggi**:

- difficoltà nel fare cambiamenti durante il processo
- interazione con il cliente mancante
- alto rischio per i sistemi nuovi

## 3. Descrivere il modello di sviluppo a spirale (Spiral Model)

![alt text](<imgs/Screenshot 2025-06-25 alle 16.41.23.png>)

**Obiettivo**: minimizzazione dei rischi

Rappresentato da una spirale dove ogni ciclo è una fase di processo.  
Al termine di ogni "giro" si ottiene un progetto, un prototipo, un sistema funzionante o un prodotto software completo.  
No fasi predefinite, vengono definite dal management del progetto.

**Spirale divisa in spicchi**:

- comunicazione con il cliente
- pianificazione (scadenze e/o risorse)
- analisi dei rischi
- strutturazione
- costruzione e rilascio
- feedback dal cliente

**Uso**: per progetti di grandi dimensioni

**Vantaggi**:

- riutilizzo ed eliminazione di errori
- valutazione dei rischi
- interazione con cliente ad ogni giro di spirale
- buona visibilità del processo

**Svantaggi**:

- richiede esperienza per valutare i rischi
- errori nella valutazione dei rischi --> si ripercuotono nelle fasi successive

## 4. Descrivere il modello di sviluppo evolutivo (o di prototipazione)

![alt text](<imgs/Screenshot 2025-06-25 alle 16.55.42.png>)

Due tipi di modelli:

- **prototipazione di tipo evolutivo**: lavorare con il cliente ed evolvere il sistema finale partendo da una specifica di massima
- **prototipazione di tipo usa e getta**: capire i requisiti del sistema poi scriverne di migliori ed il prototipo sperimenta le parti del sistema non ancora ben comprese

**Uso**:

- per sistemi interattivi di piccola o media dimensione
- per parti di sistemi (es. UI)
- per sistemi con vita corta
- per prototipi

**Vantaggi**:

- basso rischio per nuovi problemi

**Svantaggi**:

- no visibilità del processo
- sistemi poco strutturati
- richieste capacità particolari

## 5. Descrivere il modello di sviluppo trasformazionale (formale)

![alt text](<imgs/Screenshot 2025-06-25 alle 17.54.35.png>)

**Obiettivo**: trasforma una specifica matematica in un programma eseguibile tramite trasformazioni (passaggio da una rappresentazione formale ad un'altra) che preservano la correttezza

**Uso**: con sistemi critici (sicurezza e/o affidabilità essenziali)

**Svantaggi**:

- richiede conoscienze specializzate e addestramento per essere applicato
- alcune parti sono difficili da specificare formalmente

## 6. Descrivere il modello di sviluppo basato sul riutilizzo (sviluppo a componenti)

![alt text](<imgs/Screenshot 2025-06-25 alle 18.04.49.png>)

Modello, per natura evolutivo, che si basa sul riutilizzo sistematico di componenti off-the-shelf opportunamente integrate

**Fasi**:

- analisi delle componenti
- adattamento dei requisiti
- progettazione del sistema
- integrazione

**Vantaggi**:

- riduzione del ciclo di sviluppo e dei costi di progetto
- maggiore produttività

**Svantaggi**:

- dipende tanto dalla disponibilità di componenti riutilizzabili utili per lo scopo

## 7. Descrivere il modello di sviluppo RAD (Rapid Application Development)

![alt text](<imgs/Screenshot 2025-06-25 alle 18.31.09.png>)

Sviluppo ottenuto mediante il riuso di componenti

**Fasi**:

- comunicazione
- pianificazione
- modellazione
- costruzione
- deployment

**Uso**:

- per un ciclo molto breve
- con requisiti chiari
- con processo di sviluppo ben vincolato
- se facilmente partizionato dall'inizio con ogni fase sviluppata indipendentemente ed in tempi brevi (meno di 3 mesi)

**Limiti**:

- richiesto numero di risorse umane sufficienti per creare il team
- sviluppatori e clienti disponibili per completare il sistema in tempi rapidi
- non adatto se il sistema non può essere modularizzato correttamente

## 8. Descrivere il modello di sviluppo RUP (Rational Unified Process)

![alt text](<imgs/Screenshot 2025-06-25 alle 18.45.22.png>)

Modello ibridido, iterativo ed incrementale, derivato da UML.  
Indivua due prospettive:

- **tecnica**: tratta aspetti qualitativi, ingegneristici e di metodo di progettazione
- **gestionale**: tratta aspetti finanziari, strategici, commerciali

**Fasi** (separate da milestone, superate solo se stato avanzato e analisi rischi valido):

- inception (avvio): comunicazione con cliente e pianificazione
- elaboration: comunicazione con cliente ed elaborazione
- construction: progettazione, programmazione e testing
- transition: sistema spostato da sviluppo a cliente

## 9. Come valutare la gravità di un rischio?

Necessario determinare:

- **probabilità** che si verifichi
- **impatto**
- **conseguenze** (capire cosa si perderebbe)

Utile metterli in ordine di priorità con metodi di classificazione e tracciamento dei rischi (es. da 1 a 5) e assegnare priorità (es. rosso-alto, giallo-medio, verde-basso).

Piano di gestione dei rischi rivisto periodicamente

## 10. Cos'è la visibilità in un modello come quello a cascata?

**visibilità** (in un modello) = monitorare e valutare i progessi nel processo di sviluppo (ottenuta tramite documentazione)

Nel **modello a cascata**:  
**vibilità buona** --> ogni attività produce un deliverable (documento) che può essere esaminato (es. dopo analisi dei requisiti --> studio di fattibilità e documento dei requisiti)

produrre documentazione --> vincola interazione del processo se tempi di approvazione del documento lunghi

questo rende il modello a cascata meno flessibile a cambiamenti rispetto ad altri modelli

## 11. Cos'è UML e a cosa serve?

Linguaggio di modellazione universale (applicabile a sistemi molto diversi) per creare modelli software

**Uso**:

- specificare, costruire, visualizzare e documentare i componenti di un sistema
- chiarire le idee
- semplificare la realtà con l'uso di modelli
- scomporre il problema

## 12. Descrivere il modello di sviluppo Build-and-Fix

![alt text](<imgs/Screenshot 2025-06-25 alle 19.42.28.png>)

prodotto sviluppato senza specifica, cominciando a scivere il programma che viene modificato più volte finchè non va bene al cliente

No specifica, no documentazione (manutenzione molto difficile)

**Uso**: per progetto molto piccolo (~100 linee di codice)

# Capitolo 3b: Modelli di processo di sviluppo di software "moderni"

## 13. Descrivere il modello Agile / SCRUM / XP

Meodologie di sviluppo Agile per:

- problemi complessi
- soluzioni inizialmente non chiare
- requisiti soggetti a cambiamento
- sviluppare programmi in "incrementi"
- necessaria stretta collaboriazione e feedback rapido con stakeholder

**Principi della metodologia Agile**:

- **persone e interazioni** più importanti di processi e strumenti
- **software funzionante** più importante di documentazione completa
- **collaborazione con clienti** più importante di negoziazione contrattuale
- **pronti a rispondere ai cambiamenti** più importante di seguire un piano prestabilito

**Cose comuni nei metodi Agili**:

- rilasci frequenti del prodotto
- collaborazione continua del team con il cliente
- documentazione di sviluppo ridotta
- continua e sistematica valutazione dei valori e rischi dei cambiamenti

**MVP (Minimal Viable Product)**: processo iterativo di generazione di idee, prototipazione, presentazione, raccolta dati, analisi e appredimento (massimizza le informazioni apprese dal cliente per creare un prodotto con il più alto ritorno rispetto al rischio)

![alt text](<imgs/Screenshot 2025-06-26 alle 08.46.29.png>)

### XP - Extreme Programming

Approccio che si focalizza sulla velocità e sulla leggerezza (move light and move fast)

Approccio recente:

- codice = prodotto e documentazione
- codifica con un amico (pair programming)
- scrivere codice finchè non si superano casi di prova prefissati
- progetto semplice per superare i test
- inizia con minimo numero di funzioni e migliora il risultato man mano
- meno di 10 persone, nello stesso locale
- cliente o suo vicino per rispondere sempre a domande sui requisiti
- team adatta comportamenti a situazione specifica

**Core practice** (variano nel tempo e a seconda del progetto):

1. planning the game
2. simple design
3. pair programming
4. testing
5. refactor
6. short releases
7. coding standard

**User stories**:

- scritte dai clienti (no documenti di specifica dei requisiti)
- storia = max un paio di frasi
- utile per stimare costi e tempi di rilascio

**Problemi tipici**:

- no testing completo del codice e pochi test utili
- cliente non partecipa a testare il sistema
- test non funzionanti prima dell'integrazione
- test troppo lenti
- storie troppo complicate
- team sovraccarico di compiti

### SCRUM

Processo iterativo ed incrementale dove un insieme di persone si muovono contemporaneamente per raggiungere un obiettivo predeterminato.  
Fornisce un set di funzionalità potenzialmente rilasciabili alla fine di ogni iterazione.

**Fasi**: non c'è una fase alla volta, il team fa un po' di tutto durante uno sprint (requisiti, design, codice, testing)  
![alt text](<imgs/Screenshot 2025-06-26 alle 09.35.52.png>)

**3 fasi**:

- **Fase 1 (pre-game)**:
  - **pianificare le sotto fasi** --> definizione del sistema che deve essere sviluppato, contiene i requisiti conosciuti fino a quel momento
  - **strutturare le sotto fasi** --> pianificato un design di alto livello del sistema
- **Fase 2 (development game)**:
  - sviluppare il sistema attraverso degli **sprint**
    - cicli iterativi dove vengono sviluppati o migliorati funzionalità
    - ogni sprint --> sviluppo del sw
    - architettura evolve durante lo sprint
    - sprint dura da una a quattro settimane
- **Fase 3 (post-game)**:
  - chiusura definitiva della release

![alt text](<imgs/Screenshot 2025-06-26 alle 09.49.08.png>)

**Ruoli**:
- **Product Owner**:
  - persona a cui fanno riferimento tutti i soggetti interessati al progetto, anche il cliente
  - scrive il product backlog (lista con feature e priorità)
  - decide quando il progetto è finito
  - effettua stime, aggiusta processi che presentano problemi, gestisce l'intero procedimento secondo la pianificazione fatta all'inizio
  - accetta o rifiuta i risultati di un lavoro
  - termina uno sprint se necessario

- **Membro del team**:
  - **responsabilità** --> costruiscono il prodotto e decisono cosa fare in ogni sprint
  - **caratteristiche** --> cross-functional, team organizzati indipendentemente, no project/team manager, ognuno fa una cosa alla volta full-time (no multitasking), sviluppatori allo stesso livello
  - **team** --> 7 (± 2) persone che non cambiano durante lo sprint
  - **autogestione**

- **Scrum Master**:
    - supporta il team garantendo condizioni ambientali e motivazioni necessarie per eseguire al meglio il lavoro
    - serve il team, non lo dirige
    - responsabile dei **rituali** dello SCRUM:
        - product owner --> cosa bisogna fare
        - scrum master --> come lo stiamo facendo
        - aggiorna stato di progresso di lavoro --> così tutto il team sa come sta andando il progetto
    - non partecipa come programmatore


**Rituali** (Meetings):
- **Sprint planning**: iniziale pianificazione di gruppo (PO, SM, Team) per definire lo Sprint Backlog
- **Daily Scrum (stand-up)**: ogni membro del team spiega cos'ha fatto ieri, cos'ha fatto oggi e gli ostacoli (max 15 min)
- **Sprint Review**: cos'è stato completato o meno del prodotto nello sprint (max 4 ore)
- **Sprint Retrospective**: cos'è andato bene e quali ostacoli ci sono stati (max 3 ore)

**Fail Fast Technique**: SCRUM incoraggia a "fallire in fretta" per far emergere i problemi subito, imparare da essi e ridurre i costi (fail fast, learn, iterate)

**Problemi tipici**:
- ignorare valori Agile o SCRUM
- backlog non pronto
- no facilitazione dello Scrum Master
- no supporto dai manager o stakeholder

### Confronto XP e SCRUM

![alt text](<imgs/Screenshot 2025-06-26 alle 10.55.23.png>)

## 14. Differenze tra modelli tradizionali e moderni
Differenze principali riguardano l'approccio ai requisiti, la flessibilità, il coinvolgimento del cliente, la documentazione e la gestione del processo.

### Modelli Tradizionali
- derivano da modelli ingegneristici consolidati
- obiettivo --> pianificazione e controlli rigidi
- attività identificati e organizzate in anticipo
- requisiti definiti e compresi all'inizio --> difficoltà nell'effettuare cambiamenti durante il processo
- fasi sequenziali e distinte, si passa alla fase successiva solo se la precedente è terminata
- produzione di documenti formali a ogni fase (buona visibilità del processo)
- limitato coinvolgimento del cliente durante il processo
- bassa flessibilità (si sta al piano iniziale)
- alto rischio per sistemi nuovi
- adatto per progetti con requisiti ben compresi e stabili o di piccole dimensioni

### Modelli Moderni (Agile)
- accolgono i requisiti anche in fase di sviluppo
- fasi iterative ed incrementali con cicli di sviluppo brevi
- privilegiato software funzionante rispetto a documentazioni
- stretta collaborazione con il cliente
- alta flessibilità (rispondere prontamente ai cambiamenti)
- far emergere subito i rischi
- adatto per progetti con requisiti complessi o incerti ed è necessari una stretta collaborazione e costante feedback dal cliente

# Capitolo 4 Lab: Design Pattern & Application Framework
## 15. Cosa sono i Design Pattern?
**Design Pattern** --> soluzione progettuale convalidata per il suo utilizzo con successo in più progetti per un problema ricorrente in un determinato contesto
- riuso dell'esperienza di progettazione
- portano a sistemi più contenibili
- aumentano la produttività
- linguaggio comune per comunicare scelte progettuali

## 16. Ereditarietà vs Composizione
Utilizzati nella OO per riusare codice e strutturare le relazioni tra le classi.

### Ereditarietà ("is-a" relationship)
- **Vantaggi**:
    - **code reuse** --> classi derivate possono ereditare metodi e attributi dalla superclasse, evitando di riscrivere lo stesso codice
    - usata nei **pattern strutturali di classi** per comporre interfacce o implementazioni
    - **Factory Method** --> creazione di oggetti delegata ad una sottoclasse che implementa il factory method per creare gli oggetti specifici (così una classe rimanda l'instanziazione alle sue sottoclassi)
- **Svantaggi e Limiti**:
    - complicazioni nella manutenzione
    - rigidità (gerarchia statica)
    - class explosion (aggiungere responsabilità può portare ad un'esplosione di classi)
    - coupling (crea accoppiamento forte tra le classi --> difficili modifiche)
    - necessità di ereditarietà multipla

### Composizione ("has-a" relationship)
- **Vantaggi**:
    - **principio di design**
    - **separazione di preoccupazioni** --> identifica aspetti che variano e li separa da quelli che variano
    - **delega del comportamento** --> delega il compito di gestire un comportamento ad un oggetto di cui ha un riferimento
    - **flessibilità dinamica** --> modificare il comportamento di un oggetto a runtime
- **Svantaggi**:
    - **overhead di memoria** --> es. se rimangono due oggetti distinti
    - **onerosità all'aggiunta di nuovi prodotti**

## 17. Design Pattern Singleton
Creational design pattern che garantisce che una classe abbia un'unica istanza e fornisce un accesso globale di essa

- costruttore della classe --> privato
- metodo "static" per ottenere unica istanza
- creazione istanza:
    - all'inizializzazione del programma
    - la prima volta che viene richiesta
- istanza può appartenere ad una sottoclasse della classe singleton

![alt text](<imgs/Screenshot 2025-06-26 alle 13.31.50.png>)

## 18. Design Pattern Factory Method
Creational design pattern che definisce come creare oggetti, permettendo alle sottoclassi di cambiare il tipo di oggetti creati

- si incapsula la creazione degli oggetti in un metodo
- metodo può essere:
    - nella stessa classe che deve usare gli oggetti
    - il metodo "static" di una classe diversa
    - "abstract" --> richiedere che una sottoclasse ne definisca l'implementazione di default

![alt text](<imgs/Screenshot 2025-06-26 alle 13.46.22.png>)

## 19. Design Pattern Abstract Factory
Creational design pattern per creare oggetti correlati senza specificare le loro esatte classi

- si definisce:
    - un'interfaccia AbstractFactory con metodi per creare diversi prodotti
    - una o più classi concrete che implementano l'interfaccia AF in riferimento a una singola famiglia di prodotti
- si costruisce a runtime un'istanza di una "concrete factory" --> usata per creare i prodotti

![alt text](<imgs/Screenshot 2025-06-26 alle 14.25.37.png>)

## 20. Design Pattern Adapter
Structural design pattern che cambia l'interfaccia di un oggetto per farlo funzionare con un altro

- classe:
    - si crea una nuova classe Adapter con l'interfaccia target ed eredita l'implementazione della classe Adapted (l'Adapter del target richiama i metodi di Adapted)
- oggetto:
    - si crea una nuova classe Adapter con l'interfaccia target ed un riferimento ad un oggetto della classe Adapted (l'Adapter del target richiama i metodi di Adapted)

![alt text](<imgs/Screenshot 2025-06-26 alle 14.43.03.png>)

## 21. Design Pattern Composite
Structural design pattern che combina oggetti in strutture ad albero che possono essere trattate come un singolo oggetto

- interfaccia che tratta oggetti semplici e complessi in modo uniforme
- **uso**: quando il cliente non ha bisogno di differenziare tra foglie e nodo (cioè stessa funzionalità)

![alt text](<imgs/Screenshot 2025-06-26 alle 14.58.48.png>)

## 22. Design Pattern Observer
Behavioral design pattern che notifica e aggiorna oggetti dipendenti ogni volta che un oggetto cambia lo stato

- si definisce un'interfaccia Observer con un metodo che viene chiamato ad ogni modifica del Subject
- gli oggetti (che implementano Observer) interessati ad un determinato Subject devono essere registrati presso il Subject con un apposito metodo
- ogni volta che il Subject cambia il suo stato chiama il metodo di notifica per tutti gli oggetti Observer registrati

![alt text](<imgs/Screenshot 2025-06-26 alle 15.04.24.png>)

# Capitolo 4: Project Management
## 23. Cosa si intende per cammino critico e come analizzarlo?
**Cammino critico** --> successione di attività legatete allo sviluppo di software in cui un ritardo su una qualsiasi attività provoca un ritardo di consegna

**Analisi dei cammini critici** --> studiare come disporre i compiti all'interno di un progetto per ottimizzarla tramite una ri-scheduling dei compiti tenendo conto del personale a disposizione, delle dipendenze tra le attività e dei tempi di consegna (può portare a ridurre la durata di sviluppo del progetto)

**Diagramma di Pert** --> strumento per lo studio dei cammini critici

L'analisi viene fatta all'inizio del progetto poichè è oneroso farlo con progetto in esecuzione

## 24. Rapporto mese-uomo
Fallimenti di progetti software --> mancanza di tempo sufficiente

**Motivi**:
- tempi stimati non affidabili (non si considerano gli imprevisti)
- confusione tra stima e progressi fatti
- progressi non tracciati in maniera corretta
- ritardo in un punto --> aggiunta di personale --> **peggiora la situazione**

Si misura quindi l'**effort** per evitare o limitare questi fallimenti.

Effort = misurato con mese-uomo --> facilita calcolo dei costi  
Effort = numero_mesi * numero_uomini

Progressi non proporzionali a quest'unità

mesi e uomini interscambiabili solo per compiti senza comunicazione e che possono essere perfettamente partizionati tra i lavoratori

![alt text](<imgs/Screenshot 2025-06-26 alle 15.30.17.png>)

## 25. Differenza tra piano di progetto e piano esecutivo
**Processo** --> descrizione delle attività da svolgere e degli input e output necessari per ogni attività

Questi piani si rappresentano utilizzando diagrammi Gantt o Pert

### Piano di Progetto
indica la sequenza temporale **potenziale** per eseguire le attività in un modello di processo

rappresenta l'ottimizzazione ottimale del progetto (non considera vincoli di tempi, costi e personale)

### Piano Esecutivo
indica la sequenza temporale **reale** per eseguire le attività in un modello di processo

parte dalla pianificazione ottimale (piano di progetto) e la rimodula tenendo conto di vincoli di tempi, costi e personale

## 26. Tipologie di team di sviluppo
- **Democratico Decentralizzato**:
    - no leader permanente
    - consenso di gruppo su soluzioni e organizzazione del lavoro
    - comunnicazione orizzontale
    - **Vantaggi**:
        - cercare presto gli errori
        - funziona bene su problemi difficili
    - **Svantaggi**:
        - difficile da imporre
        - non è scalabile

- **Controllato Decentralizzato**:
    - un leader che coordina
    - risoluzione dei problemi --> fatto in gruppo
    - implementazioni soluzioni --> assegnata dal leader
    - comunicazione orizzontale tra sottogruppi e verticali con il leader

    ![alt text](<imgs/Screenshot 2025-06-27 alle 13.55.45.png>)

- **Controllato Centralizzato**:
    - leader decide su soluzioni e organizzazione
    - comunicazione tra leader e membri

    ![alt text](<imgs/Screenshot 2025-06-27 alle 13.56.27.png>)

## 27. Work Breakdown Structure (WBS)
Applica alla pianificazione il principio di **Divide and Conquer** (problema scomposto in sotto-problemi, si trova la soluzione di questi poi si uniscono le soluzioni)

Definisce:
- le attività da eseguire
- i rapporti gerarchici tra le attività

Grazie alla decomposizione in attività più semplici, facilita la stima di:
- tempi di realizzazione
- costi di realizzazione
- scopi realizzabili

![alt text](<imgs/Screenshot 2025-06-27 alle 13.58.55.png>)

# Capitolo 5: Ingegneria dei Requisiti
## 28. Problemi nella raccolta requisiti: scope, comprensione, volatilità
Raccolta dei requisiti molto importante poichè impatta le fasi successive

- **Problemi di Scope**:
    - limiti del sistema mal definiti
    - dettagli tecnici del cliente non necessari --> confondono invece di chiarire

- **Problemi di Comprensione** con il cliente:
    - non sa cosa vuole
    - vaga idea di limiti e possibilità
    - non da informazioni che ritiene ovvie

- **Problemi di Volontà**:
    - cambiano i requisiti nel corso del tempo

## 29. Descrivere requisiti funzionali e non funzionali con esempi
### Requisiti Funzionali
Definiscono specifiche funzioni che un sistema deve eseguire (**cosa fa** il sistema).  
Spesso vengono dai requisiti del cliente

**Esempi**:
- utente deve poter accedere al sistema inserendo nome utente e password
- utente deve poter cercare prodotti nel cataolo tramite una barra di ricerca
- il sistema deve permettere all'utente di usa carta di credito per un acquisto online

### Requisiti non funzionali
Definiscono aspetti tecnici, proprietà e vincoli del sistema (limiti, qualità, prestazioni, interfacce esterne, manutenzione, sicurezza, affidabilità, capacità di memoria, ... --> **come deve essere** il sistema)

**Esempi**:
- il sistema deve rispondere ad ogni richiesta dell'utente entro 2 secondi
- sistema disponibile il 99.9% del tempo durante l'anno
- UI comprensibile e utilizzabile da un nuovo utente senza formazione in 10 minuti

## 30. Cos’è un caso d’uso e perché è importante?
**Use Cases (Casi d'uso)** --> insieme di informazioni raccolte dall'analista per descrivere una funzionalità dal punto di vista di chi la usa:
- **Attori**: utenti o altra entità che interagisce col sistema (chi comunica col sistema ma ne è esterno)
- **Casi d'uso**: descrivono l'interazione tra attori e sistema (non la logica interna del sistema)

**Importanza dei casi d'uso**:
- comprendere e specificare i bisogni del cliente
- facilitano la comunicazione tra sviluppatori e clienti
- utili per stimare tempi e costi (es. metodo XP)
- utili per mostrare come l'utente svolge specifiche operazioni (UI)

# Capitolo 06: Analisi dei requisiti
## 31. A cosa serve la negoziazione durante l’analisi dei requisiti?
Due motivi per dover negoziare:
- requisiti in conflitto
- come far combaciare richieste e risorse

Compromessi tra:
- funzionalità, prestazioni, altre caratteristiche e ...
- costi, tempi di uscita sul mercato

**Scopo** --> sviluppare un piano di progetto con i bisogni del cliente ma con i vincoli del mondo reale

**Trucco/Soluzione** --> provare ad ottenere vantaggi da entrambe le parti

## 32. Processo di analisi dei requisiti
1. **Comprensione del dominio**: analisti devono "padroneggiare" il dominio (es. se sistema = gestione di una carrozzeria --> analisti devono diventare "esperti" nell'argomento)
2. **Raccolta dei requisiti**: interagire con stakeholders per capire i bisogni
3. **Classificazione**: riorganizzazione in modo strutturato dei requisiti
4. **Risoluzione dei conflitti**: più stakeholders coinvolti possono portare a conflitti che vanno individuati e risolti
5. **Assegnazione delle priorità**: alcuni requisiti più importanti di altri --> stabilire le priorità da subito
6. **Validazione dei requisiti**: ricontrollare i requisiti per verificare se sono completi e coerenti con le necessità degli stakeholders

![alt text](<imgs/Screenshot 2025-06-27 alle 15.55.03.png>)

# Capitolo 07: Progettazione
## 33. Modularizzazione del problema: criteri di Meyer
**Criteri di Meyer** --> valutano un metodo di progettazione sw in base alle loro capicità di creare in modo efficiente dei sistemi modulari

**Criteri**:
- **Scomponibilità**: scomporre il problema in sottoproblemi riduce la complessità
- **Componibilità**: assemblare componenti preesistenti migliora la produttività
- **Comprensibilità**: modulo le cui interfacce con altri moduli sono minime --> semplice costruzione e modificabilità
- **Continuità**: modifiche dei requisiti comportano modifiche ai singoli moduli --> facile controllo
- **Protezione**: anomalie in un modulo non si propagano --> migliora la mantenibilità

## 34. Metodologie progettazione: top-down, bottom-up, sandwich
**Top-Down** --> si parte dall'idea generale del sistema, suddividendolo ricorsivamente in componenti più piccole e dettagliate

**Bottom-Up** --> si parte dai singoli componenti già disponibili e li si integra progressivamente per costruire il sistema

**Sandwich (mista)** --> combinazione tra top-down e bottom-up, lavora contemporaneamente dall'alto e dal basso, integrando poi al centro

![alt text](<imgs/Screenshot 2025-06-27 alle 16.51.04.png>)

# Capitolo 08: Progettazione architetturale
## 35. Cosa significa scomposizione modulare? Esempi?
**Scomposizione modulare** --> sottosistemi scomposti in moduli (ulteriore scomposizione a livello strutturale)
- **sottosistemi**: sistema composto da moduli ed interfacce (interfacce usate per comunicare con altri sottosistemi)
- **moduli**: componente del sottosistema e fornisce uno o più servizi ad altri moduli o usa servizi di altri moduli (non è indipendente)

Esempi di modelli di scomposizione:
- **modello ad oggetti**: sistema scomposto in oggetti che interagiscono
- **modello data-flow**: sistema scomposto in modelli funzionali che trasformano input in output (modelli pipeline)

## 36. Tipi di modelli architetturali e differenze
### Architettura basata sui dati (a repository)
- sistema centrato su un archivio di dati
- componenti accedono all'archivio e operano in modo indipendente
- archivio può essere:
    - attivo --> archivio notifica ai client le variazioni nei dati
    - passivo --> tutte le operazioni sono in mano ai client
- vantaggio --> indipendenza tra i moduli
- possibilità di accoppiare le componenti tramite blackboard

![alt text](<imgs/Screenshot 2025-06-27 alle 17.55.01.png>)

### Architettura client-server
Modello per sistemi distribuiti --> mostra come dati e processi sono distribuiti su un insieme di componenti
- insieme di server autonomi che offrono servizi specifici
- insieme di client che richiedono questi servizi
- una rete di comunicazione che permette ai clienti di accedere ai server

![alt text](<imgs/Screenshot 2025-06-27 alle 18.02.11.png>)

**Strati funzionali**:
- **Presentation layer**: presentari i dati all'utente e gestire input dell'utente
- **Application processing layer**: offre funzionalità specifiche dell'applicazione
- **Data management layer**: gestisce comunicazione con il DBMS

![alt text](<imgs/Screenshot 2025-06-27 alle 18.10.29.png>)

### Architettura a flusso di dati (pipe-and-filter)
- sistema modellato sul flusso di dati, dall'input al'output
- moduli = filtri connessi da pipe di dati
- filtro vuole in input dati in un certo formato e produce in un formato prefissato
- ogni filtro lavora in autonomia (non si preoccupa di cosa lo precede/segue)
- filtro batch sequenziale --> se flusso di dati in un'unica catena di filtri

![alt text](<imgs/Screenshot 2025-06-27 alle 18.11.49.png>)

### Architettura a macchina astratta (a livelli / a strati)
- per modellare l'interfaccia tra sottosistemi
- organizza il sistema in insieme di strati
- ogni strato offre un insieme di servizi
- se interfaccia di un livello cambia --> affetta solo i livelli adiacenti

![alt text](<imgs/Screenshot 2025-06-27 alle 18.19.04.png>)

# Capitolo 09: Progettazione orientata ad oggetti
## 37. Progettazione orientata agli oggetti: fasi
**Progettazione software** --> insieme di oggetti che interagiscono

**OOD (object oriented design)** --> traduce **OOA (object oriented analysis)** in un modello specifico di implementazione --> codificato in un linguaggio **OOP (object oriented programming)**

**Metodo OOD**:
- trovare oggetti, attributi e metodi
- organizzare oggetti in gerarchia di ereditarietà
- organizzare oggetti in gerarchia di aggregazioni
- creare diagrammi per mostrare come i metodi di oggetti sono usati da altri oggetti
- specificare le interfacce degli oggetti

**OOD metodo Coad & Yourdon**:
1. Componenti del dominio
2. Componenti di interazione con l'utente
3. Componenti di gestione delle mansioni
4. Componenti di gestione dei dati

**OOD Metodo Rambaugh OMT (object modeling technique)**:
1. Realizza la progettazione globale del sistema
2. Progetta i singoli oggetti
3. Progetta i meccanismi di controllo
4. Rivedi la struttura gerarchica delle classi per rendere più stretti i meccanismi di ereditarietà
5. Progetta il passaggio di messaggi per implementare le relazioni tra oggetti
6. “Impacchetta” le classi in moduli

# Capitolo 10: Progettazione Interfaccia Utente
## 38. Le 3 regole della UI
1. **Controllo nelle mani dell'utente**:
    - l'utente vuole controllare il computer
    - interazione semplice, flessibile ed adattabile alle sue preferenze (no azioni inutili o forzate)
    - modalità d'uso abbreviate per utenti esperti
    - nascondere i dettagli tecnici
2. **Limita l'uso della memoria dell'utente**: 
    - non fare affidamento sulla memoria dell'utente (possibili errori)
    - ridurre necessità di memoria a breve termine
    - definire scorciatoie
    - UI metafora del mondo reale
3. **UI uniforme per tutta l'applicazione**:
    - informazioni visuali secondo uno standard che deve essere mantenuto
    - contesto evidente in ogni istante
    - mentenere uniformità in una famiglia di applicazioni

## 39. Cosa significa ridurre il ricorso alla memoria a breve termine nelle UI?
**Ridurro uso di memoria a breve termine** --> minimizzare la quantità di informazioni che l'utente deve ricordare da un passaggio all'altro durante l'interazione con il sistema

Qui si parla della memoria dell'utente poichè le perosne ricordano pochi elementi per un tempo molto breve --> far ricodare molti passaggi all'utente rallenta l'interazione e genera frustrazione

**Good practice**:
- mostrare le opzioni a schermo
- riempire automaticamente i campi noti
- menu di navigazione persistente
- comandi contestuali visibili

# Capitolo 11: Verifica e Validazione
## 40. Qual è la differenza tra verifica e validazione?
**Verifica** --> verificare che si sta costruendo il prodotto **nel modo giusto** (sw *che si comporta* com'era previsto)

**Validazione** --> verificare che si sta costruendo il prodotto **giusto** (sw *implementato* com'era previsto)

V & V stabilisce con abbastanza confidenza che il sw è adeguato allo scopo del progetto.  
**Non** vuol dire **completamente privo di difetti** ma sufficientemente buono per lo scopo previsto.

## 41. Differenza tra revisione e walkthrough
**Revisione** --> riunioni pianificate in cui si esamina il codice secondo una checklist di errori comuni (checklist dipende dal linguaggio di programmazione usato)

**Walkthrough** --> processo più lento di una revisione, consiste nella lettura critica del codice provando a percorrere il codice simulandone l'esecuzione

## 42. Back-to-back testing
Usato se ci sono più versioni diverse dello stesso sistema
- verifica l'output di queste versioni dato lo stesso input
    - se output diverso --> errori
- confronto degli output può essere automatizzato --> costo ridotto
- usato quando prototipo disponibile, se ci sono più versioni di un progetto o per upgrade o nuove release

![alt text](<imgs/Screenshot 2025-06-27 alle 21.50.43.png>)

## 43. Tipi di collaudo: White-Box e Black-Box
**White-Box** --> richiede conoscienze del funzionamento interno di un software, verifica diverse parti del codice, mira a coprire tutti i possibili casi e le alternative

**Black-Box** --> verifica il software fornendo input e osservando l'output senza conoscienze interne del codice

![alt text](<imgs/Screenshot 2025-06-27 alle 21.47.24.png>)

# Capitolo 12: Affidabilità
## 44. Descrivere l’affidabilità di un sistema software e come migliorarla
**Affidabilità** --> probabilità che il sistema funzioni senza errori per un certo tempo, in un certo ambiente, per un certo scopo (vuol dire diverse cose in base a sistema, ambiente, scopo)

**Migliorare l'affidabilità** --> rimuovendo i fault che compaiono nelle parte più usate del sistema (importante rimuovere i difetti che causano le conseguenze più serie)

## 45. Fallimento vs. Fault
**Fallimento** --> comportamento inaspettato (ed errato) a runtime osservato da un utente

**Fault** --> caratteristica statica del software che causa il fallimento (non sempre causano fallimenti --> solo se usata la componente errata del sistema)

## 46. TMR (Triple-Modular Redundancy)
3 uguali componenti che ricevono gli stessi input e devono generare gli stessi output.  
Se uno degli output è diverso dagli altri due --> ignorato, componente che l'ha prodotto è guasta.

Funziona perchè:
- hw fallisce causa usura, non perchè progettata male (assunzione)
- improbabile che più componenti falliscano contemporaneamente (assunzione)

![alt text](<imgs/Screenshot 2025-06-27 alle 23.09.57.png>)

## 47. Diversità tra i problemi HW e SW e come posso risolverli
**Problemi**:
- **Hardware** --> generalmente dovuti da usura fisica o guasti di componenti
- **Software** --> errori di progettazione o implementazione o fault

**Risoluzioni**:
- **Hardware** --> riparazione o sostituzione fisica delle componenti difettose
- **Software**:
    - fault avoidance --> progettazione rigorosa per evitare errori
    - fault detection --> test e revisione per trovare errori prima della consegna
    - fault tolerance --> sistema funzionante nonostante gli errori