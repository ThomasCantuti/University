#!/bin/sh

dir="$1"

cd "$dir"

echo "$dir"

for i in `ls *.log 2> /dev/null`
do
    continue
done

# ricorsione
for d in *
do
    if test -d "$d" -a -x "$d"
    then
        cerca_file_log.sh "$d/*"
    fi
done