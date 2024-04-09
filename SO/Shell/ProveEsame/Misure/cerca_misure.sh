#!/bin/sh

# verifico numero argomenti
if test $# -ne 2
then
    echo Uso: cerca_misure.sh dir header
    exit 1
fi

# verifico se dir è assoluta
case "$1" in
    /*) ;;
    *)  echo "$1" non è una directory assoluta;
        exit 2;;
esac

# verifico se dir è una directory ed è accessibile
if test ! -d "$1"
then
    echo "$1" non è una directory
    exit 3
fi

if test ! -x "$1"
then
    echo "$1" non è accessibile
fi

# verifico esistenza e creazione di misure.txt
if test ! -f misure.txt
then
    > $HOME/misure.txt
fi

PATH=$PATH:`pwd`
export PATH

> /tmp/.dirMaxNumFile.tmp
echo 0 > /tmp/.countFile.tmp

cerca_misure_ric.sh "$1" "$2"

echo `cat /tmp/.dirMaxNumFile.tmp` ha maggior numero di file

rm -f /tmp/.dirMaxNumFile.tmp
rm -f /tmp/.countFile.tmp