# funziona finchè il valore di stato dell'ultimo comando della lista è zero (successo)
# quando è diverso da zero esce
while <lista-comandi>
do
    <comandi>
done

# ripete finchè è fallimento (!= 0), quando è successo (= 0) esce
until <lista-comandi>
do
    <comandi>
done