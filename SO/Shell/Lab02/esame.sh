#!/bin/sh

# verifica numero di parametri
if test $# != 3
    then
        echo "Uso: sh esame.sh .estensione <nomedir1> <nomedir2>"
        exit 1
fi

# verifico se estensione è estensione
estensione="$1"
case "$estensione" in
    .*)
        ;;
    *)
        echo ""$estensione" non è estensione"
        exit 2;;
esac

# verifico se dir1 e dir2 sono directory assolute
dir1="$2"
dir2="$3"
case "$dir1" in
    /*)
        ;;
    *)
        echo ""$dir1" non è dir assoluta"
        exit 3;;
esac

case "$dir2" in
    /*)
        ;;
    *)
        echo ""$dir2" non è dir assoluta"
        exit 4;;
esac

# verifico se dir1 e dir2 sono directory
if test ! -d "$dir1" -a ! -d "$dir2"
    then 
        echo "No directory"
        exit 5
fi

# ricerca
PATH=$PATH:`pwd`
export PATH

echo "Copiati `esame_rec.sh $estensione $dir1 $dir2 | wc -l` file"