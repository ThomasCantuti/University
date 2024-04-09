#!/bin/sh

# verifico numero arg
if test $# -ne 3
then
    echo Uso: esame.sh genere tipo anno
    exit 1
fi

# verifico se anno è una directory assoluta
case "$3" in
    /*) ;;
    *)  echo "$3" non è una dir assoluta;
        exit 2 ;;
esac

# verifico se anno è una dir
if test ! -d "$3"
then
    echo "$3" non è una directory
    exit 3
fi

# verifico se anno è accessibile
if test ! -x "$3"
then
    echo "$3" non è accessibile
    exit 4
fi

PATH=$PATH:`pwd`
export PATH

echo "" > $HOME/risultati.txt
> /tmp/.mese.tmp
echo 0 > /tmp/.countTitle.tmp

esame_ric.sh "$1" "$2" "$3"

# stampa file risultati in ordine di voto recensione
cat $HOME/risultati.txt | sort -gr

# stampa del mese con più titoli
echo `cat /tmp/.mese.tmp`

rm -f /tmp/.mese.tmp
rm -f /tmp/.countTitle.tmp