#!/bin/sh

# verifica arg
if test $# -ne 1
then
    echo Numero non corretto di argomenti
    echo Uso: sh cancella_verisioni_preliminari.sh dir
    exit 1
fi

# verifico se dir relativa
case "$1" in
    /*) echo "$1" è dir assoluta
        exit 2 ;;
    *) ;;
esac

# verifico se dir è una dir
if test ! -d "$1" -o ! -x "$1"
then
    echo "$1" non è una dir o non ho diritti di accesso
    exit 3
fi

PATH=$PATH:`pwd`
export PATH

echo '0' > /tmp/.max_counter.tmp # valore iniziale = 0, max num file cancellati
> /tmp/.max_dirname.tmp # nome dir con max file cancellati

cancella_verisioni_preliminari_aux.sh "`pwd`"/"$1"

echo `cat /tmp/.max_dirname.tmp` è dir con più file cancellati

rm -f /tmp/.max_counter.tmp
rm -f /tmp/.max_dirname.tmp