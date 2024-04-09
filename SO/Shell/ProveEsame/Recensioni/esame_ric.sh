#!/bin/sh

genere="$1"
tipo="$2"
dirAnno="$3"

cd "$dirAnno"

count=0
# ordine file:
# voto,genere,titolo,produttore,tipo,durata

# cerca
for file in `ls *.txt 2>/dev/null`
do
    if test -f "$file" -a -r "$file"
    then
        if test `cut -f 2 -d "," "$file" | grep -c $genere` -ge 1 -a `cut -f 5 -d "," "$file" | grep -c $tipo` -ge 1
        then
            grep $genere "$file" | grep $tipo | cut -d "," -f 1,3,6 >> $HOME/risultati.txt
            count=`grep $genere "$file" | grep $tipo -c`
            if test $count -gt `cat /tmp/.countTitle.tmp`
            then
                echo $count > /tmp/.countTitle.tmp
                echo `pwd`/"$file" > /tmp/.mese.tmp
            fi
        fi
    fi
done

# ricorsione
for d in *
do
    if test -d "$d" -a -x "$d"
    then
        esame_ric.sh "$genere" "$tipo" "`pwd`/$d"
    fi
done