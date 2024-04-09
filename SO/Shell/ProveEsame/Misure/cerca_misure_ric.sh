#!/bin/sh

dir="$1"
header="$2"

cd "$dir"

count=0

# cerca
for file in `ls *.log 2>/dev/null`
do
    if test -f "$file" -a -r "$file" -a -w "$file"
    then
        if test "$header" = `head -n 1 "$file"`
        then
            echo `pwd` "$file" >> $HOME/misure.txt
            count=`expr $count + 1`
            if test $count -gt `cat /tmp/.countFile.tmp`
            then
                echo "$dir" > /tmp/.dirMaxNumFile.tmp
                echo $count > /tmp/.countFile.tmp
            fi
        fi
    fi
done

# ricorsione
for d in *
do
    if test -d "$d" -a -x "$d"
    then
        cerca_misure_ric.sh "`pwd`/$d" "$header"
    fi
done