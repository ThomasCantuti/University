#!/bin/sh

num="$1"
shift
dirSorg="$1"
shift
dirDest="$1"
shift

cd "$dirSorg"

for ext in $*
do
    for file in "`ls *$ext 2>/dev/null`"
    do
        if test -f "$file"
            then
                continue
        fi
    done
done