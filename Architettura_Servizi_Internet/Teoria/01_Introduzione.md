# Reti di Calcolatori
**reti di calcolatori** --> insieme di diversi sistemi che comunicano e cooperano attraverso lo scambio di messaggi per ottenere risultati coordinati

**sistemi distribuiti** --> evoluzione delle reti di calcolatori, dove tutte le operazioni svolte dagli utenti sembrano essere locali anche quando vengono svolte in modo remoto (beneficio della trasparenza)

**Conseguenze**:
- **Concorrenza**: molte attività (processi) possono essere in esecuzione in un qualunque momento ed in diverse località
- **Nessun tempo globale**: non è possibile una perfetta sincronizzazione degli orologi di una moltitudine di macchine in rete
- **Fallimenti indipendenti**: molte cause di fallimento oltre a crash di macchine e problemi di rete

## Motivazioni
- **condivisione di risorse**: condivisione di dati, hardware, software
- **affidabilità**: ridondanza e tolleranza ai guasti
- **applicazioni intrinsecamente distribuite**
- **facile accesso al sistema**
- **scalabilità**: crescita del numero di utenti e delle dimensioni della rete

## Aspetti dello scenario
- **eterogeneità**: diversità di hardware, software, protocolli, sistemi operativi, linguaggi di programmazione
- **apertura**: pubblicazione e documentazione delle interfacce, facilità di estensione e cooperazione con altri componenti
- **sicurezza**: protezione dei dati, controllo degli accessi, autenticazione, integrità, privacy, disponibilità, paternità (problemi complicati dalla condivisione del supporto di comunicazione)
- **mobilità**: mobilità utenti, terminali, applicazioni
- **scalabilità**: efficacia ed efficienza al crescere delle risorse gestite e degli utenti collegati (costi, algoritmi decentralizzati, compatibilità)
    - **scalabilità orizzontale**: aumento il numero di server
    - **scalabilità verticale**: aumento le prestazioni del server

![alt text](<imgs/Screenshot 2025-02-17 alle 10.51.18.png>)

## Principali problemi
- **gestione guasti**: guasti possono essere parziali e distribuiti
- **concorrenza**: applicazioni e servizi concorrenti per rispondere a richieste di molti client contemporaneamente
- **trasparenza**: nascondere la reale distribuzione a utenti e programmatori in varie forme
    - **accesso**: uso di stesse operazioni per accedere risorse locali o remote
    - **locazione**: risorse accedute senza bisogno di sapere dove sono
    - **concorrenza**: molti processi eseguono contemporaneamente senza interferenze
    - **replicazione**: risorse replicate senza conoscenza da parte utente
    - **guasti**: si nascondono alcuni guasti
    - **mobilità**: spostamento risorse o utenti senza alterare la fruizione del servizio
    - **performance**: potenziamento del sistema per migliori prestazioni
- **sicurezza**: molte più vulnerabilità rispetto a un sistema isolato stand-alone

## Principali Trend nello Sviluppo delle Reti di Calcolatori e dei Servizi Internet
1. **Cloud Computing**
2. **Migration to the Cloud**
3. **Cloud Federation**
4. **Edge + Fog + Cloud Computing ---> Compute Continuum**
5. **Containerization and Microservices**
6. **Smart Cities**
7. **Industry 5.0**
8. **AI approaches for optimization of communications**

### Cloud Computing
**Cloud** --> metafora della rete Internet

**Cloud Computing** --> possibilità di utilizzare applicazioni e dati che non risiedono più nella macchina locale, ma che arrivano attraverso la rete Internet

**Applicazioni e dati** --> in server remoti, acceduti via rete

**Paradigmi**:
- **Infrastructure-as-a-Service (IaaS)**
- **Platform-as-a-Service (PaaS)**
- **Software-as-a-Service (SaaS)**
- **Function-as-a-Service (FaaS)**

**Principali fornitori**:
- **Amazon** con Amazon Web Services (AWS)
- **Google** con Google App Engine e tutta la suite Google Apps
- **Microsoft** con la proposta Windows Azure e Office365
- **Salesforce** per prodotti CRM (Customer Relationship Management)

**Evoluzione del Cloud Computing**:
- **Edge Computing**: spostamento della capacità computazionale più vicino agli utilizzatori, senza dover trasferire i dati in Cloud
- **Fog Computing**: estensione del modello Edge Computing che considera anche allocazione e gestione integrata dei servizi di computazione, stoccaggio, e disseminazione dei dati tra i dispositivi Edge e il Cloud
- **Compute Continuum**: integrazione di Edge, Fog e Cloud Computing