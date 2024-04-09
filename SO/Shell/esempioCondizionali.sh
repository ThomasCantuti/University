# risponde "si" se invocato con "si" e un numero <= 24
if test $1 = si -a $2 -le 24
    then echo si
    else echo no
fi