#!/bin/sh

nome="$1"
dirAnno="$2"

cd "$dirAnno"

rilevazione=0

# info ordine file:
# livelloIdrometrico,nomeCorso,località,sogliaGuardia,timestampRilevazione

# cerca
for file in `ls *.txt 2>/dev/null`
do
    if test -f "$file" -a -r "$file"
    then
        # cerco file di interesse -> nomeCorso
        if test `cut -d "," -f 2 "$file" | grep -c $nome` -ge 1
        then
            # estrazione livIdro, località, timestamp
            grep $nome "$file" | cut -d "," -f 1,3,5 >> $HOME/fiumilog.txt
            # estraggo rilevazione più bassa
            rilevazione=`cut -d "," -f 1 "$file" | sort -n | head -n 1`
            # controllo se è il più basso del minimo attuale
            if test $rilevazione -lt `cat /tmp/.countMin.tmp`
            then
                echo $rilevazione > /tmp/.countMin.tmp
                echo "$file" > /tmp/.giorno.tmp
            fi
        fi
    fi
done


# ricorsione
for d in *
do
    if test -d "$d" -a -x "$d"
    then
        esame_ric.sh "$nome" "`pwd`/$d"
    fi
done