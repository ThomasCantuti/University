#!/bin/sh
# Thomas Cantuti 187390
PATH=$PATH:`pwd`
export PATH
while test "$nome" != fine
do
    # lettura pattern
    echo "Scrivi il nome del file ("fine" termina il programma): "
    read nome
    if test "$nome" = fine
        then continue
        else
            # Ricerca pattern
            if test -f "$nome"
                then echo $nome è un file
                else
                    if test -d "$nome"
                        then echo $nome è una directory
                        else echo $nome non esiste
                    fi
            fi
    fi
done