#!/bin/sh

# verifico quantità argomenti
if test $# -ne 2
then
    echo Uso: sh riordina_foto.sh dirSorg dirDest
    exit 1
fi

# verifico dirSorg e dirDest non siano assolute
case "$1" in
    /*) echo Errore: dirSorg è assoluta
        exit 2;;
    *) ;;
esac

case "$2" in
    /*) echo Errore: dirDest è assoluta
        exit 3;;
    *) ;;
esac

# verifico che le dir siano dir
if test ! -d $1
then
    echo dirSorg non è una directory
    exit 4
fi

if test ! -d $2
then
    echo dirDest non è una directory
    exit 5
fi

# verifico e creo dirDest/Duplicati
if ! test -d $2/Duplicati
then
    mkdir `pwd`/"$2"/Duplicati
fi

# esportazione e cambio PATH
PATH=$PATH:`pwd`
export PATH

> /tmp/.fileCopiati.tmp

riordina_foto_ric.sh "$1" `pwd`/"$2"

echo Totale: `wc -l < /tmp/.fileCopiati.tmp` file copiati

rm -f /tmp/.fileCopiati.tmp