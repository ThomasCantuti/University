#!/bin/sh

est="$1"
dir1="$2"
dir2="$3"

cd "$dir1"

# cerca file
for i in *$est
do
    if test -f "$i" -a ! -f "$dir2/$i"
        then
            cp "$i" "$dir2/$i"
            echo "Copia di $i"
    fi
done

# ricerca ricorsiva
for i in *
do
    # controllando permesso di esecuzione evito loop
    if test -d "$i" -a -x "$i"
        then
            esame_rec.sh "$est" "$dir1/$i" "$dir2"
    fi
done