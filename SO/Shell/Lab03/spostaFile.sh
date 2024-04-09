#!/bin/sh

dir="$1"
shift
stringa="$1"
shift

cd "$dir"

# cerca file e sposta
for file in $*
do
    if test -f "$file" -a -r "$file"
    then
        if test `grep -c "$stringa" "$file"` -ge 1
        then
            echo "$file" spostato
            echo "$file" >> /tmp/.counterFileSpostati.tmp
            echo "$stringa" >> /tmp/.counterStringa.tmp
            # mv $file /tmp
        fi
    fi
done

# ricorsione
for i in *
do
    if test -d "$i" -a -x "$i"
    then
        spostaFile.sh "`pwd`/$i" "$stringa" $*
    fi
done