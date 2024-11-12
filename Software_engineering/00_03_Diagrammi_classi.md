# Diagrammi delle classi
**diagramma di classe** -> rappresentazione grafica di una collezione di classi, interfacce e collaborazioni e delle relazioni tra di esse.

**Utilizzo**:
- modellare basi di dati (modellazione concettuale)
- modellare le interfacce utente (modellazione di interazione)
- modellare processi di business (modellazione di business)
- modellare l’interoperabilità, come nel middleware

![alt text](<images/Screenshot 2024-11-12 alle 19.39.57.png>)

## Attributi
![alt text](<images/Screenshot 2024-11-12 alle 19.41.02.png>)

![alt text](<images/Screenshot 2024-11-12 alle 19.47.58.png>)

## Metodi
![alt text](<images/Screenshot 2024-11-12 alle 19.48.45.png>)

## Enumerazioni
- enumerazione -> insieme di costanti (tipo di dato enumerato)
- enumerazione -> non è una classe
- usa una relazione di dipendenza

![alt text](<images/Screenshot 2024-11-12 alle 19.52.44.png>)

## Relazioni tra classi
**relazioni strutturali fondamentali**:
- **dipendenze**: relazione di utilizzo (es. una classe utilizza un’altra classe per eseguire un’operazione)
- **associazioni**: relazioni tra istanze di classi che rappresentano connessioni strutturali tra esse (es. una stanza è costituita da pareti)
- **ereditarietà**: relazioni tra classi generali e specializzate (es. una classe “Animale” con sottoclassi “Cane” e “Gatto)

### Dipendenze
**quando si usano**:
- come argomento in una dichiarazione di operazione
- come tipo di dato complesso per un attributo
- come tipo di dato enumerato per un attributo

![alt text](<images/Screenshot 2024-11-12 alle 19.59.42.png>)

**uso della freccia**: 
- non è obbligatorio darle un nome (utile con molte dipendenze)
- la freccia indica la direzione della dipendenza (parte dalla classe che utilizza verso la classe utilizzata)

![alt text](<images/Screenshot 2024-11-12 alle 20.04.51.png>)

![alt text](<images/Screenshot 2024-11-12 alle 20.08.07.png>)

### Associazioni
**possono avere attributi** (non obbligatori):
- ruoli (nome del ruolo all’interno della relazione)
- cardinalità (numero di istanze coinvolte)
- navigabilità (direzione della relazione)

![alt text](<images/Screenshot 2024-11-12 alle 20.12.52.png>)

![alt text](<images/Screenshot 2024-11-12 alle 20.14.21.png>)


### Composizione e Aggregazione
- **composizione**: relazione forte tra classi, dove la “parte” non può esistere senza il “tutto” (es. un “Cerchio” composto da “Punti”; se il cerchio viene distrutto, lo stesso accade ai punti)
    - si denota con un **rombo pieno**

![alt text](<images/Screenshot 2024-11-12 alle 20.25.06.png>)

- **aggregazione**: relazione più debole in cui la “parte” può esistere indipendentemente dal “tutto” (es. una “Finestra” contiene oggetti “Figura”, che possono sopravvivere alla distruzione della finestra)
    - si denota con un **rombo vuoto**

![alt text](<images/Screenshot 2024-11-12 alle 20.25.59.png>)

### Ereditarietà
**ereditarietà** -> relazione tra classi generali e specializzate (sottoclasse eredita attributi e metodi dalla superclasse)
    - permette il **polimorfismo** (sottoclassi possono ridefinire operazioni della classe madre)
    - in alcuni casi, è meglio sostituire l’ereditarietà multipla con l’aggregazione

![alt text](<images/Screenshot 2024-11-12 alle 20.32.48.png>)

## Relazioni N-arie e Riflessive
**relazione N-aria**:
- relazione tra più di due classi
- rappresenta situazioni complesse in cui un’associazione richiede più partecipanti per essere rappresentata accuratamente

![alt text](<images/Screenshot 2024-11-12 alle 20.41.49.png>)

**relazione riflessiva**:
- relazione tra una classe e se stessa
- utile per rappresentare situazioni in cui gli oggetti della stessa classe interagiscono tra di loro

**classi di relazione**: aggiungono ulteriori proprietà alle relazioni (es. data di inizio della supervisione)

![alt text](<images/Screenshot 2024-11-12 alle 20.45.00.png>)



## Relazioni Condizionate e Enumerazioni
**relazioni condizionate**: relazioni con vincoli (es. vincolo di età per i partecipanti a un evento)
    - si aggiunge **un’etichetta** o **“stereotipo”** per chiarire il tipo di relazione e il significato degli attributi

**enumerazioni**: insiemi predefiniti di valori per gli attributi (non sono classi)
    - si usa una relazione di dipendenza

![alt text](<images/Screenshot 2024-11-12 alle 20.49.20.png>)

![alt text](<images/Screenshot 2024-11-12 alle 20.50.48.png>)

## Politiche di denominazione
- **classi**: al singolare e con la prima lettera maiuscola
- **ereditarietà**: non viene nominata, né porta cardinalità o nomi di ruolo
- **dipendenza**: non viene nominata, né porta cardinalità o nomi di ruolo
- **ruolo**: si scrive con la prima lettera minuscola e di solito è al plurale
- **generalizzazione (ereditarietà)**: la classe è scritta in corsivo
- **attributi**: si scrivono con la prima lettera minuscola
- **metodi**: si scrivono con la prima lettera minuscola