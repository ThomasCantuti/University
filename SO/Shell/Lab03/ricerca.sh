#!/bin/sh

num="$1"
dirSorg="$2"
dirDest="$3"
est="$4"

cd "$dirSorg"
for i in "$est"
do
    for j in *$est
    do
        if test -f $j -a -r $j
            then
                # echo prova $j
                righeFile=`wc -l < $j` # ridirezione < perchè wc normalmente stampa "num nomefile.est" e a me interessa solo num
                # echo prova2 $righeFile $num
                if test $righeFile -gt $num
                    then
                        # continue
                        echo $j >> /tmp/counter.tmp
                        cp $j "$dirDest/$j"
                fi
        fi
    done
done

# ricerca 
for i in *
do
    if test -d "$i" -a -x "$i"
        then
            ricerca.sh "$num" "$dirSorg/$i" "$dirDest" "$est"
    fi
done