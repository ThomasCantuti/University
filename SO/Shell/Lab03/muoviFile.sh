#!/bin/sh
PATH=$PATH:`pwd`
export PATH

# ricerca di file con estensione desiderata
# spostamento dei file

# verifico se almeno 4 argomenti
if test $# -le 3
    then
        echo "Uso: muoviFile num dirSorgente dirDestinazione ext1 ..."
        exit 1
fi

# verifico se arg1 è un numero
num="`expr $1 + 0`"
if test ! $? -le 0
    then
        echo "Il secondo argomento non è un numero"
        exit 2
fi

# verifico se dirSorg e dirDest sono dir assolute
dirSorg="$2"
dirDest="$3"
case "$dirSorg" in
    /*) ;;
    *)  echo ""$dirSorg" non è dir assoluta"
        exit 3 ;;
esac

case "$dirDest" in
    /*) ;;
    *)  echo ""$dirDest" non è dir assoluta"
        exit 4 ;;
esac

# verifico se sono dir
if test ! -d "$dirSorg"
    then
        echo ""$dirSorg" non è una directory"
        exit 5
fi

if test ! -d "$dirDest"
    then
        echo ""$dirDest" non è una directory"
        exit 6
fi

# verifico se le estensioni sono estensioni
shift 3
for i in $*
do
    case $i in
        .*) ;;
        *)  echo ""$i" non è un'estensione"
            exit 7 ;;
    esac
done

# ricerca
> /tmp/counter.tmp
for i in $*
do
    echo $i
    ricerca.sh "$num" "$dirSorg" "$dirDest" "$i"
done

# ricerca.sh "$num" "$dirSorg" "$dirDest" $* -> al posto del ciclo for

echo "File trovati: `wc -l /tmp/counter.tmp`"
# cat counter.tmp
rm /tmp/counter.tmp