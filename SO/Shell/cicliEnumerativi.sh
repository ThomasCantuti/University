# ripetizione ciclo per ogni stringa presente nella lista
for <var> [in <list>] # list = lista di stringhe
do
    <comandi>
done

# itera con valori di i in $*
for i
do
    <comandi>
done

# esegue per tutti i file nella directory
for i in *

for i in 'ls s*'
do <comandi>
done

for i in 'cat file1'
do <comandi per ogni parola del file file1>
done

for i in 0 1 2 3 4 5 6
do
    echo $i
done