#!bin/sh

# verifica num argomenti
if test $# != 3
    then
        echo "Uso: cercaFile.sh stringa dir num"
        exit 1
fi

# verifica dir assoluta
dir="$2"
case "$dir" in
    /*) ;;
    *) echo "$dir" non è dir assoluta 
        exit 2;;
esac

# verifico se dir assoluta è dir
if test ! -d "$dir"
then
    echo "$dir" non è dir
    exit 3
fi

# verifica num intero
if test "$3" -le 0
then
    echo Non è un numero
    exit 4
fi
num="$3"


> /tmp/.max_counter.tmp # maggior numero di file in dir corrente
> /tmp/.max_dirname.tmp # nome della dir con maggior numero di file

# condizione: file leggibile, file.txt, num presenza stringa > num argomento

PATH=$PATH:`pwd`
export PATH

cercaStringa.sh "$1" "$dir" "$num"

echo "`cat /tmp/.max_dirname.tmp`" contiene il maggior numero di file

rm /tmp/.max_counter.tmp
rm /tmp/.max_dirname.tmp