select risposta in pippo pluto paperino;
do
    echo "hai scelto $risposta"
done

echo "Scegli quale file cancellare"
select i in 'ls *.bak'
do
    echo "Selezionato: $i"
    rm -f $i
done