#!/bin/sh

dir="$1"

cd "$dir"

echo '0' > /tmp/.counter.tmp

for file in `ls *.txt 2>/dev/null`
do
    if test -f "$file" -a -w "$file"
    then
        # if test `head -n 1 "$file" | grep preliminare`
        if test `head -n 1 "$file" | cut -f 3 -d ','` = preliminare
            then
                echo "`pwd`/$file è preliminare"
                echo "$file" >> /tmp/.counter
                # rm -f "$file"
            else
                echo "`pwd`/$file è definitivo"
        fi
    fi
done

# aggiornamento
if test `wc -l < /tmp/.counter.tmp` -gt `cat /tmp/.max_counter.tmp`
then
    # mv /tmp/.counter.tmp /tmp/.max_counter.tmp
    echo `wc -l < /tmp/.counter.tmp` > /tmp/.max_counter.tmp
    echo `pwd` > /tmp/.max_dirname.tmp
fi

rm /tmp/.counter.tmp # se faccio mv non serve cancellare

# ricorsione
for i in *
do
    if test -d "$i" -a -x "$i"
    then
        cancella_verisioni_preliminari_aux.sh "$i"
    fi
done