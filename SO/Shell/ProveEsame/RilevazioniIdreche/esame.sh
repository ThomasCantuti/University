#!/bin/sh

# verifico numero argomenti
if test $# -ne 2
then
    echo Uso: esame.sh nome anno
    exit 1
fi

# verifico se anno è dir assoluta
case "$2" in
    /*) ;;
    *)  echo "$2" non è dir assoluta;
        exit 2 ;;
esac

# verifico se anno è una dir
if test ! -d "$2"
then
    echo "$2" non è una directory
    exit 3
fi

# verifico se anno è una dir accessibile
if test ! -x "$2"
then
    echo "$2" non è accessibile
    exit 4
fi

# esportazione percorso
PATH=$PATH:`pwd`
export PATH

> $HOME/fiumilog.txt
> /tmp/.giorno.tmp
echo "100000" > /tmp/.countMin.tmp

esame_ric.sh "$1" "$2"

# stampa contenuto fiumilog
cat $HOME/fiumilog.txt

# stampa giorno con livello più basso
echo `cat /tmp/.giorno.tmp` giorno con liv idrometrico più basso

rm -f /tmp/.giorno.tmp
rm -f /tmp/.countMin.tmp