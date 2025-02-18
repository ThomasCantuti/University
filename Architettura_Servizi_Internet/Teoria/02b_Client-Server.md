# Modello Client-Server
Il modello Client/Server prevede due entità:
- **Server**: fornisce un servizio
- **Client**: richiede un servizio

parte **Client** del servizio:
- processo lanciato dall'utente
- contatta attivamente il Server
- non richiede dispositivi dedicati o SO sofisticati

parte **Server** del servizio:
- processo specializzato all'erogazione di un servizio
- può servire molti client contemporaneamente
- è avviato al boot della macchina
- eseguito su un calcolatore "condiviso"
- attende passivamente le richieste del client
- accetta richieste da molti client ma ne esegue solo una

**modello Client/Server** --> modello di comunicazione diretta e asimmetrica, molti a uno (server sempre in attesa)

![alt text](<imgs/Screenshot 2025-02-17 alle 18.54.35.png>)

![alt text](<imgs/Screenshot 2025-02-17 alle 18.58.24.png>)

## Identificare i servizi
- i Client specificano il servizio desiderato
- i Server registrano il servizio
- i Client reperiscono l'identificatore del servizio poi lo usano per contattare il Server ed usufruire del servizio

## Progetto Client/Server
Il Server deve:
- accedere alle risorse del sistema
    - problemi autenticazione utenti
    - autorizzazione all'accesso
    - integrità dei dati
    - protezione della privacy
- gestire le richieste contemporanee da molti client (server concorrente)

## Tipi di interazione tra Client e Server
Due tipi di interazioni:
- **connection oriented**: stabilito un canale di comunicazione virtuale prima di iniziare lo scambio dei dati (es. servizio telefonico)
- **connectionless**: i messaggi sono inviati senza stabilire un canale di comunicazione virtuale (es. sistema postale)

Due tipi di comportamenti:
- **modello pull**: il Client richiede (pull) un servizio al Server e attende la risposta (Server-driven e sincrono (bloccante))
- **modello push**: il Client manda al Server un segnale di interesse, poi fa altro. Il Server invia (push) al Client la risposta quando è pronta (Client-driven e asincrono (non bloccante))

## Stato dell'interazione tra Client e Server
**stato** --> sintesi di come l'attuale sessione di servizio sta procedendo, memorizzate da una delle due parti

Durante la **gestione di richieste multiple di servizio**, possono esserci due tipi di interazioni:
- **stateless**:
    - non si tiene traccia dello stato (ogni richiesta è indipendente dalle altre)
    - migliore efficienza del Server (dimensione messaggio minore e migliore velocità)
    - Server semplificato, Client e infrastruttura di rete più complessi
    - usato **SOLO** se il protocollo applicativo è progettato con operazioni idempotenti (producono sempre lo stesso risultato)
- **stateful**:
    - si tiene traccia dello stato (ogni richiesta dipende dalle precedenti)
    - migliore affidabilità del Server in caso di malfunzionamenti (sopprattutto quelli di rete)
    - Server più complesso (deve mantenere lo stato per ogni client)

### Servizi Stateless
ogni messaggio contiene tutte le informazioni (anche lo stato) per svolgere il servizio richiesto (messaggi autocontenuti --> più robusti)

![alt text](<imgs/Screenshot 2025-02-17 alle 23.26.07.png>)

### Servizi Stateful
mantenuta l'informazione dello stato in modo locale su un database da client e server (ad ogni messaggio, la parte conosce lo stato di partenza --> meno risorse consumate)

![alt text](<imgs/Screenshot 2025-02-17 alle 23.32.20.png>)

### Gestione stato
Non è necessario gestire lo stato a livello di protocollo applicativo