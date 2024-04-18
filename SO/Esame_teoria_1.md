# Risposte alle Domande

## Paginazione su richiesta
Di solito la memoria virtuale è realizzata mediante tecniche di paginazione su richiesta: tutte le pagine di ogni processo risiedono in memoria di massa; durante l'esecuzione alcune di esse vengono trasferite, all'occorrenza, in memoria centrale tramite un modulo chiamato "Pager". La paginazione su richiesta (o "su domanda") prevede che il pager trasferisca in memoria centrale una pagina soltanto se ritenuta necessaria, seguendo una politica "lazy".

## Modalità Scheduling
I sistemi operativi svolgono tre tipi di scheduling:
- **Scheduling a breve termine (o di CPU)**: seleziona il prossimo processo pronto da eseguire sulla CPU
- **Scheduling a medio termine (swapper)**: effettua lo swap dei processi tra memoria e disco per gestire il multiprogrammazione
- **Scheduling a lungo termine**: determina quali nuovi processi ammettere nel sistema

## System Calls / System call in C
Le system call permettono ad un programma utente di richiedere servizi dal sistema operativo. Alcune system call in C:
- `fork()`: crea un nuovo processo figlio
- `exit()`: termina l'esecuzione di un processo 
- `wait()`: sospende un processo padre in attesa della terminazione dei figli
- `exec()`: sostituisce il codice di un processo con un nuovo programma

## Segnali: cosa sono, come gestirli
Un segnale è un'interruzione software inviata a un processo per notificare un particolare evento. Un processo può gestire un segnale in tre modi:
1) Ignorarlo
2) Eseguire l'azione di default predefinita 
3) Installare una funzione handler per gestirlo

## Gestione dei segnali a valle della fork e a valle dell'exec
- Dopo una `fork()`, il processo figlio eredita dal padre le impostazioni per la gestione dei segnali
- Dopo una `exec()`, il nuovo programma eredita solo i segnali ignorati o a default, perdendo le precedenti funzioni handler

## Segnale SIGCHLD
Il segnale SIGCHLD viene inviato dal kernel a un processo padre quando uno dei suoi figli termina. Questo permette al padre di non dover attendere esplicitamente la terminazione usando `wait()`.

## Bit di protezione del file (Shell)
I permessi di un file vengono regolati tramite 12 bit di protezione:
- 9 bit per leggere/scrivere/eseguire per user/group/altri
- 3 bit per le impostazioni SUID, SGID e Sticky bit

## Differenze tra Signal e Sigaction
`signal()` ha una semantica variabile e non sempre affidabile, i segnali vanno reinstallati ad ogni ricezione.
`sigaction()` è sempre affidabile, con una semantica ben definita in tutte le versioni Unix/Linux, e non richiede reinstallazione.

## Storia dei SO in generale (evoluzione)
- **Sistemi batch semplici**: codice/dati su schede perforate, programmi eseguiti in batch sequenziali 
- **Batch multiprogrammati**: pool di job caricati in memoria ed eseguiti in parallelo per migliorare l'utilizzo della CPU
- **Sistemi time-sharing**: l'attività della CPU è dedicata ciclicamente a diversi job, fornendo l'illusione di macchine dedicate agli utenti

## Cosa succede quando viene aperto un file
- In generale: inserimento nella tabella dei file aperti, eventuale copia in memoria (memory mapping)
- In Unix: viene inserito un nuovo file descriptor nella tabella dei file aperti del processo e copiato il relativo i-node

## Context switch
È l'operazione di trasferimento del controllo della CPU da un processo/thread ad un altro. Include il salvataggio dello stato del processo corrente e il ripristino di quello del processo selezionato per l'esecuzione.

## Cosa succede se diminuiamo l'intervallo di tempo
Variare l'intervallo di tempo può influenzare:
- Lo scheduling dei processi
- La gestione delle risorse 
- I timeout per la gestione degli eventi

## Pager
Il Pager è un modulo del SO che realizza i trasferimenti di pagine da/verso memoria secondaria e centrale per la paginazione su richiesta o il pre-fetching delle pagine prima dello swap-in.

## Stati di un processo + stati su Unix  
Principali stati di un processo:
- Nuovo/In inizializzazione 
- Pronto
- In esecuzione
- Attesa
- Terminato

In Unix un processo può essere anche in stato "Zombie" se è terminato ma il padre non ne ha ancora rilevato lo stato.

## Immagine del processo (PCB)
Ogni processo è rappresentato da un Process Control Block (PCB) che contiene tutte le informazioni necessarie per la sua gestione:
- Stato 
- Program Counter
- Registri della CPU
- Informazioni per lo scheduling
- Informazioni per la gestione della memoria
- Dati di controllo generali

## Paginazione
Tecnica di gestione della memoria che prevede di suddividere lo spazio di indirizzamento logico in pagine di dimensione fissa e caricare in memoria solo quelle necessarie (su richiesta o per anticipazione).

## Segmentazione
Tecnica di gestione della memoria che prevede di suddividere lo spazio di indirizzamento logico in segmenti di dimensioni variabili, solitamente uno per ogni modulo oggetto del programma.

## Pipe
Canale di comunicazione unidirezionale con capacità limitata che permette lo scambio di dati tra processi della stessa gerarchia seguendo una politica FIFO.

## RAID  
Tecnica per l'utilizzo ridondante di array di dischi indipendenti allo scopo di migliorare prestazioni (striping) e/o affidabilità (mirroring, parità).

## Protezione
Finalizzata a garantire che le risorse di un sistema vengano utilizzate solo da soggetti autorizzati secondo politiche stabilite.

## Scheduling a breve termine e a medio termine (swapper)
- **Breve termine**: sceglie il prossimo processo da eseguire sulla CPU
- **Medio termine (swapper)**: effettua lo swap dei processi tra memoria e disco per bilanciare il grado di multiprogrammazione

## Thread in Java
Java supporta nativamente il multithreading. Per creare nuovi thread:
1) Istanziare `Thread` passando un oggetto che implementa `Runnable`
2) Estendere la classe `Thread` 

## Stati "Thread" (C)  
Con la libreria pthread, i principali stati di un thread sono:
- Creato
- In esecuzione 
- In attesa
- Terminato
- Interrotto

## Come blocchiamo un thread (cosa non possiamo fare, suspend, stop e perché si crea un deadlock)
Non si possono utilizzare `suspend()` e `stop()` perché rappresentano azioni brutali che possono creare deadlock. `suspend()` non rilascia le risorse, `stop()` le rilascia tutte. Un deadlock si crea quando più thread/processi sono in attesa circolare di risorse detenute dagli altri.

## Accesso Hard Disk
Per accedere ai dati su un hard disk vengono eseguite le seguenti operazioni:
1) Seek: posizionamento del braccio di lettura/scrittura 
2) Latency: attesa che il settore desiderato passi sotto il braccio
3) Lettura/scrittura dei dati
4) Trasferimento dei dati in memoria

## Sicurezza
Mentre la protezione previene usi scorretti da utenti legittimi, la sicurezza difende il sistema da attacchi esterni. Gli aspetti principali sono: autenticazione, riservatezza, integrità, disponibilità

## Capability List
Nell'ambito della protezione, per ogni dominio viene indicato l'insieme degli oggetti e dei relativi diritti di accesso (capability list).

Spesso un oggetto è identificato dal suo nome fisico o dal suo indirizzo (capability). Il possesso della capability corrisponde all'autorizzazione a eseguire una certa operazione.

Quando un processo opera in un dominio, chiede di esercitare un diritto di accesso su un oggetto. Se ciò è consentito, il processo entra in possesso di una capability per l'oggetto e può eseguire l'operazione.

La lista delle capability non è direttamente accessibile a un processo in esecuzione in quel dominio. È protetta e gestita dal S.O. Non può migrare in qualsiasi spazio direttamente accessibile a un processo utente (non può essere manipolata dai processi).

## Metodi di accesso ai file in generale e in Unix
- In generale: aprendo un file viene introdotto un nuovo elemento nella tabella dei file aperti e può essere effettuato l'eventuale memory mapping del file (copia in memoria centrale per accessi più veloci)

- In Unix: l'apertura di un file provoca:
   - Inserimento di un elemento (file descriptor) nella tabella dei file aperti del processo
   - Inserimento di un nuovo record di attivazione nella tabella dei file aperti di sistema
   - Copia dell'i-node nella tabella dei file attivi (se non già presente)

## Politiche scheduling HDD (FCFS, SSTF ecc)
In un sistema concorrente, molti processi accedono al file system, che si trova quindi a gestire molte richieste, che devono essere schedulate opportunamente per ridurre i tempi di attesa. Le principali politiche di scheduling per gli HDD sono:

- **FCFS (First Come First Served)**
- **SSTF (Shortest Seek Time First)**: viene servita la richiesta che richiede lo spostamento minore del braccio di lettura/scrittura
- **SCAN**: il braccio si sposta prima in una direzione fino all'ultima traccia, servendo le richieste incontrate, poi torna indietro servendo le richieste rimanenti

## File System in UNIX (4 regioni) e metodi di allocazione dei blocchi in memoria secondaria
L'organizzazione fisica del file system in UNIX è divisa in 4 regioni:

1. **Boot Block**: contiene le procedure di inizializzazione del sistema (da eseguire al bootstrap)
2. **Super Block**: fornisce
   - i limiti delle 4 regioni
   - il puntatore a una lista dei blocchi liberi
   - il puntatore a una lista degli i-node liberi
3. **Data Blocks**: area del disco effettivamente disponibile per la memorizzazione dei file. Contiene:
   - i blocchi allocati
   - i blocchi liberi (organizzati in una lista collegata)
4. **i-List**: contiene la lista di tutti i descrittori (i-node) dei file normali, directory e dispositivi presenti nel file system (accesso con l'indice i-number)

I metodi di allocazione dei blocchi in memoria secondaria sono:
- **Allocazione contigua**: si assegna a un file un'area contigua di blocchi che hanno indirizzi contigui
- **Allocazione non contigua (paginazione)**: il file viene suddiviso in pagine che possono essere allocate in modo sparso

## Working set
In alternativa alla paginazione su domanda, esistono tecniche di gestione della memoria basate sulla pre-paginazione: si prevede un set di pagine di cui il processo avrà bisogno per la prossima fase di esecuzione (working set). Il working set può essere individuato in base ai criteri di località temporale.

## Differenza tra Swapper e Pager
- **Swapper** (scheduler a medio termine): gestisce i trasferimenti dei processi interi da memoria centrale a secondaria (swap out) e viceversa (swap in)

- **Pager**: è un modulo del SO che realizza i trasferimenti delle singole pagine da/verso memoria secondaria/centrale ("swapper di pagine"). Viene utilizzato per:
   - Paginazione su richiesta: trasferisce in memoria centrale solo le pagine necessarie
   - Pre-fetching: carica in anticipo le pagine di cui un processo avrà bisogno

## Immagine del processo in Unix
Un processo UNIX è composto da:

- **process structure**: elemento della process table associato al processo (kernel, residente)
- **text**: elemento della text table associato al codice del processo (kernel, residente)  
- **area dati globali di utente**: contiene le variabili globali del programma (user, swappable)
- **stack e heap di utente**: aree dinamiche associate al programma (user, swappable)
- **stack del kernel**: stack di sistema associato al processo per le chiamate a system call (kernel, swappable)
- **user structure**: struttura dati per la gestione del processo quando residente (kernel, swappable)

## Algoritmi di scheduling a breve termine (Capitolo 9)
Lo scheduler a breve termine (o di CPU) gestisce:

- La coda dei processi pronti: contiene i PCB dei processi in stato Ready
- Code di waiting: una per ogni tipo di attesa, contengono i PCB dei processi waiting per quel tipo di evento

Le principali politiche di scheduling a breve termine sono:

- **First Come First Served (FCFS)**
- **Shortest Job First (SJF)**
- **Priority Scheduling**
- **Round Robin**