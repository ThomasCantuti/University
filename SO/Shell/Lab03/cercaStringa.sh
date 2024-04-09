#!bin/sh

stringa="$1"
dir="$2"
num="$3"

cd "$dir"

> /tmp/.counter.tmp

# conta
for file in `ls *.txt 2>/dev/null`
do
    if test -f "$file" -a -r "$file" -a `grep -c "$stringa" "$file"` -gt "$num"
    then
        echo "$file" >> /tmp/.counter.tmp
    fi
done

# aggiornamento
if test `wc -l < /tmp/.counter.tmp` -gt `wc -l < /tmp/.max_counter.tmp`
then
    echo "`wc -l < /tmp/.counter.tmp`" > /tmp/.max_counter.tmp
    echo `pwd` > /tmp/.max_dirname.tmp
fi

rm -f /tmp/.counter.tmp

# ricorsività
for i in *
do
    if test -d "$i" -a -x "$i"
    then
        cercaStringa.sh "$stringa" "$i" "$num"
    fi
done