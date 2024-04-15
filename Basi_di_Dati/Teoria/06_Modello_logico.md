# Da modello concettuale a modello logico

## ER - Relazionale
### Entità
- per ogni entità E si crea una relazione R con tutti gli attributi semplici di E
- si sceglie uno degli attributi chiave di E come chiave primaria di R (se è composta l'insieme degli attributi formeranno la chiave primaria)

### Entità deboli
- per ogni entità debola W si crea una relazione R con tutti gli attributi semplici di W
- chiave esterna di R -> si includono gli attributi chiave primaria della relazione corrispondente all'entità proprietaria E
- chiave primaria di R -> combinazione della chiave primaria dell'entità proprietaria E e della chiave parziale dell'entità debole W

### Associazioni binarie

#### Associazioni 1:1
per ogni associazione A 1:1 si identificano le relazioni S e T:
1. Chiave esterna -> si sceglie una delle relazioni (es. S) e si include come chiave esterna la chiave primaria dell'altra relazione (es. T)
2. Unica relazione -> si uniscono le due entità e l'associazione in una singola relazione
3. Relazione associazione -> si crea una terza relazione R per avere un riferimento per le due relazioni S e T

#### Associazioni 1:N
per ogni associazione A 1:N si identificano le relazioni S (lato N) e T (lato 1):
- si include nella chiave esterna in S la chiave primaria di T
- si includono tutti gli attributi di A in S

#### Associazioni N:M
per ogni associazione A N:M si crea una relazione S che rappresenti A:
- si includono come chiavi esterne in S le chiavi primarie delle due relazioni coinvolte in A
- si includono tutti gli attributi di A in S

### Attributi multivalore
per ogni attributo multivalore A si crea una nuova relazione R dove questa avrà un attributo corrispondente ad A e l'attributo K corrispodente alla chiave primaria di A

### Associazioni N-arie
per ogni associazione A n-aria si crea una relazione S per rappresentare A:
- si includono come chiavi esterne in S le chiavi primarie delle relazioni che rappresentano le n entità coinvolte in A
- si includono tutti gli attributi di A in S

image slide 12

## EER - Relazionale
### Specializzazioni e Generalizzazione

#### opzione A

#### opzione B

#### opzione C

#### opzione D