# Diagrammi di sequenza

**Diagramma di sequenza** -> tipo di diagrmma per modellare il comportamento dinamico di un sistema  
**Scopo**: rappresentare l'interazione tra gli oggetti in un sistema durante il tempo di esecuzione

**Caratteristiche**:
- **modellazione del comportamento**: interazioni dinamiche tra oggetti (non solo strutture statiche)
- **diagrammi di interazione**: interzioni tra istanze di oggetti (non sulle classi stesse)
- **rappresentazione temporale**:
    - **asse Y**: rappresenta il tempo (sequenza cronologica degli eventi)
    - **asse X**: rappresenta gli oggetti coinvolti e le interazione tra essi
- **interazioni tra oggetti**: interazioni avvengono tramite chiamate a metodi o operazioni degli oggetti coinvolti

**Utilizzi per descrivere**:
- **casi d'uso**: visualizzare come gli attori interagiscono con il sistema
- **comportamento del sistema**: fornire dettagli su operazioni e messaggi scambiati tra oggetti

**Elementi fondamentali**
- **oggetti**:
    - istanze delle classi che interagiscono tra di loro
    - rappresentati da rettangoli con identificazione : `nomeOggetto : nomeClasse`
    - disposti lungo l'asse X
- **messaggi (metodi delle classi)**:
    - gli oggetti si comunicano inviando messaggi
    - la punta della freccia "chiama" un metodo contenuto nell'oggetto "chiamato"
    - possono essere sincroni o asincroni
        - **sincroni**: il mittente attende la risposta del destinatario prima di continuare
        - **asincroni**: il mittente non attende la risposta del destinatario per continuare
    - rappresentati da frecce tra oggetti:
        - **frecce piene**: messaggi sincroni
        - **frecce tratteggiate**: messaggi asincroni
- **restituzioni**:
    - dopo l'elaborazione di un messaggio, un oggetto può restituire un valore o una risposta
    - frecce tratteggiate che tornano al mittente
- **timeline**:
    - interazione che avviene lungo una timeline verticale
    - rappresenta la sequenza temporale degli eventi


![alt text](<images/Screenshot 2024-12-02 alle 13.08.22.png>)

![alt text](<images/Screenshot 2024-12-02 alle 14.26.27.png>)

![alt text](<images/Screenshot 2024-12-02 alle 14.30.15.png>)

## Modellazione di sequenza
Descritto come un modello iterativo suddiviso in 2 fasi:

1. **fase preliminare (modellazione informale)**:
    - messaggi tra oggetti scritti in linguaggio naturale (per capire il comportamento)
    - esempio: `stabilire i dati dl libro` o `esaminare una condizione`
2. **fase dettagliata (modellazione formale)**:
    - messaggi tra oggetti scritti in linguaggio formale (nomi di metodi specifici, parametri, tipi associati alle classi)
    - esempio:
        - `stabilire i dati dl libro` -> `set_data(isbn, titolo)`
        - `stabilire i dati dl libro` -> `1.1: scoprire(isbn)`


**Modello informale**:

![alt text](<images/Screenshot 2024-12-02 alle 14.08.31.png>)

**Modello formale**:

![alt text](<images/Screenshot 2024-12-02 alle 14.09.22.png>)


## Strutture di controllo
Modellano comportamenti condizionali, iterativi e opzionali.

- **strutture di controllo**:
    - `opt`(optional): rappresenta una sequenza che può essere eseguita oppure no, in base a una condizione specifica (come if ma senza else)
        - esempio: condizione vera -> esecuzione messaggio 3
    
    ![alt text](<images/Screenshot 2024-12-02 alle 14.37.55.png>)

    - `alt`(alternative): consente di rappresentare scelte condizionali tra due o più percorsi (come if-else)
        - esempio: if valore < 5 allora setNivel(rojo); else if valore > 8 allora setNivel(verde) else setNivel(amarillo)
        
    ![alt text](<images/Screenshot 2024-12-02 alle 14.42.28.png>)

    - `loop` (iterative): rappresenta un ciclo iterativo (come while)
        - esempio: for 1 to 20 do ...
    
    ![alt text](<images/Screenshot 2024-12-03 alle 01.13.36.png>)

    - `break`: rappresenta l'interruzione di un ciclo iterativo quando una condizione è soddisfatta
        - esempio: con condizione nel for o con un if-else
    
    ![alt text](<images/Screenshot 2024-12-03 alle 01.30.20.png>)

    ![alt text](<images/Screenshot 2024-12-03 alle 01.31.10.png>)

    - strutture di controllo annidate: combinazione di più strutture di controllo
        - esempio: if cond1 then if cond2 then for ...
    ![alt text](<images/Screenshot 2024-12-03 alle 01.35.19.png>)

## Tempi nei diagrammi di sequenza
Gestire i tempi e le restrizioni temporali durante l'interazione tra oggetti.

1. **rappresentazione temporale**:
    - **asse temporale verticale**: rappresenta il tempo dall'alto verso il basso (sequenza cronologica degli eventi)
    - **durata delle operazioni**: indicata con una linea verticale sopra l'oggetto coinvolto
    
![alt text](<images/Screenshot 2024-12-03 alle 01.46.36.png>)

2. **restrizioni temporali**: possibilità di aggiungere vincoli temporali specifici per indicare i tempi entro i quali deve verificarsi un'operazione

![alt text](<images/Screenshot 2024-12-03 alle 01.47.04.png>)

3. **sincronizzazione degli eventi**: rappresentare l’allineamento e la sincronizzazione degli eventi tra diversi oggetti

![alt text](<images/Screenshot 2024-12-03 alle 01.47.24.png>)

4. **impostazioni di tempi complessi**:
    - **delay**: ritardo intenzionali tra due eventi
    - **timeout**: limite di tempo entro il quale un'operazione deve essere completata

![alt text](<images/Screenshot 2024-12-03 alle 01.49.08.png>)