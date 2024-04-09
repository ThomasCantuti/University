#!/bin/sh

# verifica numero arg
if test $# -ne 3
then
    echo Uso: trova_fornitori_migliori.sh dir cod_parte num
    exit 1
fi

# verifico dir assoluta
case "$1" in
    /*) ;;
    *)  echo "$1" non è una directory assoluta
        exit 2;;
esac

# verifico se dir è una directory
if test ! -d "$1"
then
    echo "$1" non è una directory
    exit 3
fi

# verifico di avere i permessi di esecuzione su quella directory
if test ! -x $1
then
    echo "Errore: non posso eseguire in $1"
    exit 4
fi

# verifico se num è un numero
num=`expr $3 + 0` 
if test ! $? $num -le 0 2>/dev/null
then
    echo $num non è un numero
    exit 5
fi

#controllo su num
#case $3 in
#    *[!0-9]*)   echo "Errore: num deve essere un numero"; 
#                exit 5;;
#    *);;
#esac

PATH=$PATH:`pwd`
export PATH

> /tmp/.numeroPezziMax.tmp
> /tmp/.nomeFornitore.tmp

trova_fornitori_migliori_ric.sh "$1" "$2" "$num"

if test `wc -l < /tmp/.nomeFornitore.tmp` -eq 0
then
    echo File non trovato o codici parti non trovati o numero pezzi di ogni fornitore troppo bassi
else
    echo `cat /tmp/.nomeFornitore.tmp` ha `cat /tmp/.numeroPezziMax.tmp` parti di ricambio
fi

rm -f /tmp/.numeroPezziMax.tmp
rm -f /tmp/.nomeFornitore.tmp