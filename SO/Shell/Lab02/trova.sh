#!/bin/sh
# Thomas Cantuti 187390

# verifico se ci sono 2 parametri
if test $# != 2
    then
        echo "Uso: sh trova.sh <nomedir> <nomefile>"
        exit 1
fi

# verifico se il primo arg è dir assoluta
dir="$1"
case "$dir" in 
    /*) ;;
    *)  echo "Il primo argomento deve essere una directory assoluta"
        exit 2;;
esac

# verifico se dir è una directory
if test ! -d "$dir"
    then
        echo "$dir non è una directory"
        exit 3
fi

# ricerca file
file="$2"
PATH=$PATH:`pwd` # aggiunge directory script corrente al PATH
export PATH

# verifico se ho i permessi per entrare nella directory
if test -x "$dir" 
    then
        cd "$dir"
        for i in *
        do
            if test -d "$i"
                then
                    # ricorsione
                    trova.sh "`pwd`"/"$i" "$file"
                else
                    if test -f "$i" -a "$i" = "$file"
                        then
                            echo trovato $i in `pwd`
                    fi
            fi
        done
fi