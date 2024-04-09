#!/bin/bash
# Thomas Cantuti 187390
PATH=$PATH:`pwd`
export PATH

# verifico se ci sono almeno 2 argomenti
if test $# -le 1
    then
        echo "Inserire almeno 2 argomenti"
        exit 1
fi

# file in variabile
file=$1

if test ! -f "$file"
    then
        echo "Il primo parametro deve essere un file"
        exit 2
fi

# verifico se ho diritti di lettura poi apro file
if test -r "$file"
    then
        shift 1
        echo "Apertura file processi..."
        for i in $*
        do
            n=`grep "$i" "$file" | wc -l`
            #n=`grep -c "$i" "$file"`
            echo "Parametro: $i - Ricorrenze: $n"
        done

    else
        echo "Non hai diritti di lettura"
        exit 3
fi