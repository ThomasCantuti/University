#!/bin/sh

# verifico numero arg
if test $# -ne 1
then
    echo Inserire un argomento
    exit 1
fi

# verifico arg sia dir assoluta
case "$1" in
    /*) ;;
    *) 
        echo "$dir" non è dir assoluta
        exit 2
esac

# verifico se arg è dir
if test ! -d "$1"
then
    echo "$dir" non è una directory
fi

PATH=$PATH:`pwd`
export PATH

> $HOME/errori.txt
> $HOME/warning.txt

cerca_file_log.sh "$1"

