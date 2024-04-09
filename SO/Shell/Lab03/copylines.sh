#!/bin/sh

# verifico arg
if test $# -le 2
then
    echo Pochi argomenti
    echo Uso: sh copylines.sh dirAssoluta stringa nomefile1 ...
    exit 1
fi

# verifico dir assoluta
case "$1" in
    /*) ;;
    *)  echo "$1" non è dir assoluta
        exit 2 ;;
esac

# verifico dir
if test ! -d "$1"
then
    echo "$1" non è una dir
    exit 3
fi

dir="$1"
stringa="$2"

# verifico che i nomi siano minuscoli
shift 2
for i in $*
do
    case "$i" in
        *[a-z]*) ;;
        # *[!a-z]*) echo errore scrittura nomi; exit 4;;
        *)   echo "$1" scritto in forma non corretta
            exit 4 ;;
    esac
done

> /tmp/.counterFileSpostati.tmp
> /tmp/.counterStringa.tmp

PATH=$PATH:`pwd`
export PATH

spostaFile.sh "$dir" "$stringa" $*

if test `wc -l < /tmp/.counterFileSpostati.tmp` -eq 0
then
    echo Nessun file spostato
    # sleep `expr 60 \* 60`
else
    echo File spostati: `wc -l < /tmp/.counterFileSpostati.tmp`
    cat /tmp/.counterStringa.tmp
fi

rm -f /tmp/.counterFileSpostati.tmp
rm -f /tmp/.counterStringa.tmp