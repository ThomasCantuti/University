#!/bin/sh

dirSorg="$1"
dirDest="$2"

cd `pwd`/"$dirSorg"

# cerco file .PNG
for file in `ls *.PNG 2>/dev/null`
do
    # verifico se file leggibili
    if test -f "$file" -a -r "$file"
    then
        # verifico se file esistente
        if test -e "$file"
        then
            # file esistente: lo sposto nella directory $dirDest/Duplicati
			count=1
			while test -e "$dirDest/Duplicati/$file-$count"
			do
				count=`expr $count + 1`
			done
			mv $i "$dirDest"/Duplicati
        else
            echo spostamento "$file" in `pwd`/"$dirDest"
            mv $file "$dirDest"
            echo "$file" >> /tmp/.fileCopiati.tmp
        fi
    fi
done

# ricorsione
for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        riordina_foto_ric.sh "$dir" "$dirDest"
    fi
done