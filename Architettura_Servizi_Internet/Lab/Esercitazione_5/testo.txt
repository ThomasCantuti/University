Si progetti un'applicazione Client/Server che, utilizzando le socket, permetta
a uno sciatore appassionato di consultare il bollettino della neve. Più
precisamente, l'applicazione deve permettere allo sciatore di stampare una
lista delle località turistiche attrezzate per lo sci, ordinandole da quella
con più disponibilità di neve a quella con meno disponibilità di neve sulle
piste.

Il Client deve presentare la seguente interfaccia:

	bollettino_neve    server    porta

dove server è il nome logico del Server e porta il numero di porta del
servizio.

Per prima cosa, il Client si deve interfacciare con l'utente, da cui riceve
(via terminale) il nome della regione e il numero N di località di interesse.
Il Client deve quindi comunicare le informazioni inserite dall'utente al
Server.

A sua volta, il Server dovrà selezionare, all'interno delle località registrate
nella regione richiesta, le N località con la maggiore disponibilità di neve
sulle piste da sci e inviare le relative informazioni al Client. In
particolare, il server dovrà ordinare le informazioni sulle località richieste
in ordine decrescente sulla base del numero di centimetri di neve attualmente
presenti sulle piste. Opzionalmente, in aggiunta alle informazioni richieste il
Server dovrà restituire al Client anche il numero medio di cm di neve per le
località richieste (ovverosia le N località con la maggiore disponibilità di
neve nella regione di interesse).

A tal proposito, si supponga che, sul Server, le informazioni sulla neve siano
salvate in un file per ciascuna regione all'interno della directory
/var/local/bollettino_neve (quindi il file "/var/local/bollettino_neve/piemonte.txt" 
conterrà le informazioni sulle località del Piemonte, il file
"/var/local/bollettino_neve/veneto.txt" quelle sulle località del Veneto,
ecc.). Si supponga inoltre che i file con le informazioni sulla neve contengano
una riga (con numero di centimetri di neve attualmente sulle piste, nome della
località, nome del comprensorio sciistico, ecc.) per ciascuna delle località
registrate nel sistema.

Al termine di ogni richiesta, il Client deve mettersi in attesa della richiesta
successiva, e terminare qualora l'utente inserisca la stringa "fine".

ATTENZIONE: Si realizzino il Client e il Server in C, ma il Client deve anche
essere realizzato in Java.