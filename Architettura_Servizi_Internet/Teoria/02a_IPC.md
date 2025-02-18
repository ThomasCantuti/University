# Comunicazione tra processi in una rete di calcolatori
**applicazione distribuita** --> costituita da diversi processi che comunicano e cooperano tra loro attraverso lo scambio di messaggi per ottenere risultati coordinati

**Aspetti principali per la realizzazione di un'applicazione distribuita**:
- Identificazione dei processi (nomi)
- Primitive di comunicazione tra processi
- Sincronizzazione dei processi
- Comunicazioni con/senza connessione
- Affidabilità
- Eterogeneità e formato dei dati
- Modelli di interazione (Client/Server e altri modelli)

## Identificazione dei processi comunicanti (sistema di nomi)
- per ogni processo bisogna definire un **nome globale** univoco
    - esempio: "nome" della macchina + "nome" del processo nella macchina
- problema dei nomi risolto dai protocolli di comunicazione
    - esempio nel caso di Internet con TCP/UDP e IP:
        - nome macchina = indiritto IP
        - nome processo = numero di porta

![alt text](<imgs/Screenshot 2025-02-17 alle 12.00.33.png>)

**macchina** --> identificata univocamente da un indirizzo IP  
**porta** --> identifica univocamente un processo (numeri di 16 bit, strazione fornita da TCP e UDP)  
**messaggi** --> consegnati su una specifica porta, non direttamente ad un processo infatti un processo si **lega** ad una porta per ricevere (o spedire) dei messaggi  
**indirizzo IP + porta** --> endpoint di un canale di comunicazione

## Primitive di comunicazione tra processi
Esistono due soluzioni indipendenti per la comunicazione tra processi:
- designazione dei processi sorgente e destinatario della comunicazione
    - schemi diretti simmetrici
    - schemi diretti asimmetrici
    - schemi indiretti
- tipo di sincronizzazione tra processi comunicanti
    - sincrona
    - asincrona

### Designazione dei processi sorgente e destinatario della comunicazione
---
- **schemi diretti simmetrici**: i processi si nominano esplicitamente (usato nei modelli tipo pipeline)
```pseudocode
send(message) to Pdes
receive(&message) from Psorg
```

- **schemi diretti asimmetrici**: schema **molti-a-uno / molti-a-molti** dove il mittente nomina esplicitamente il destinatario, ma il destinatario non nomina il mittente (modello client/server dove i processi client specificano il destinatario delle richieste)
```pseudocode
Pi (client)  Pj (server)
...
send (msg) to Pj receive (&request, &Pi)
    <esecuzione del servizio>
receive (&ris) from Pj send (response) to Pi
```

- **schemi indiretti**: comunicazione tramite un oggetto mailbox M dove il supporto permette di:
    - creare una mailbox
    - inviare e ricevere messaggi dalla mailbox
    - distruggere la mailbox
```pseudocode
send(message, M)
receive(message, M)
```

### Tipi di sincronizzazione tra processi comunicanti
---
- **sincrona**:
- il processo si blocca in attesa del completamento dell'operazione richiesta:
    - **send sincrono**: il mittente si blocca fino a che il messaggio non è stato consegnato
    - **receive sincrono**: il destinatario si blocca fino a che il messaggio non è stato ricevuto
- il messaggio ricevuto corrisponde allo stato attuale dell'altro processo
- **deadlock**: se due processi si bloccano in attesa l'uno dell'altro, si risolve usando timeout o multithreading
- modalità sincrona usata per soluzioni di alto livello

- **asincrona**:
- il processo continua la sua esecuzione subito dopo che l'operazione viene invocata:
    - **send asincrono**: processo mittente continua esecuzione subito dopo la send (senza sapere se il destinatario ha ricevuto il messaggio)
    - **receive asincrono**: processo destinatario esegue la receive ma nel buffer potrebbe esserci nessun messaggio e quindi si distinguono due soluzioni:
        - **polling**: invocazione periodica della receive
        - **interrupt-driven/gestione a eventi**: il processo destinatario viene interrotto quando arriva un messaggio
- non c'è garanzia che il messaggio sia stato ricevuto
- il messaggio ricevuto non corrisponde allo stato attuale dell'altro processo

Si possono usare send e receive sincrone o asincrone in combinazione tra loro

## Sincronizzazione e Buffering
Per ragioni di perfomance, durante la sincronizzazione, si usa un **buffer** per memorizzare i messaggi in attesa di essere ricevuti

Il buffer compporta un trade-off: migliori performance corrispondenti ad un minore controllo (il mittente non sa quando arriva il messaggio)

![alt text](<imgs/Screenshot 2025-02-17 alle 16.46.57.png>)

## Comunicazione con/senza connessione
- **con connessione**:
    - stabilita una connessione tra i processi chiamante e chiamato (es. sistema telefonico)
    - può essere logica o fisica
    - una volta stabilita la connessione, i dati fluiscono continuamente

- **senza connessione**:
    - non c'è connessione tra i processi
    - ogni messaggio viene indirizzato e consegnato singolarmente al destinatario (es. sistema postale)
    - i messaggi possono essere consegnati in ordine diverso da quello in cui sono stati inviati e possono seguire strade diverse

## Affidabilità della comunicazione
Il support IPC (Inter-Process Communication) deve garantire l'affidabilità nella consegna dei messaggi:
- **comunicazione affidabile**: in caso di perdita di messaggi o guasti, il supporto ritrasmette il messaggio
- **comunicazione non affidabile**: il supporto invia i messaggi senza verificarne la consegna