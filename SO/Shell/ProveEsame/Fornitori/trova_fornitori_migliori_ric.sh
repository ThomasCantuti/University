#!/bin/sh

dir="$1"
cod_parte="$2"
num="$3"

cd "$dir"
numPartiMax=0

# cerca
for file in `ls *.txt 2>/dev/null`
do
    if test -f "$file" -a -r "$file"
    then
        numParti=`cut -f 4 -d "," "$file"`
        if test `cut -f 2 -d "," "$file"` = "$cod_parte" -a $num -lt $numParti 2>/dev/null
        then
            if test $numParti -gt $numPartiMax
            then
                echo $numParti > /tmp/.numeroPezziMax.tmp
                echo `cut -f 1 -d "," "$file"` > /tmp/.nomeFornitore.tmp
                numPartiMax=$numParti
            fi
        fi
    fi
done

# ricorsione
for i in *
do
    if test -d "$i" -a -x "$i"
    then
        trova_fornitori_migliori_ric.sh "`pwd`/$i" "$cod_parte" "$num"
    fi
done