list = [1,2,3,4,5] 
- 
se modifico una lista essa rimane uguale
anche se viene mostrata a schermo modificata
-
-- prendere primo elemento:
head list

-- prendere ultimo elemento:
last list -- == head( reverse list )

-- rimuovere primo elemento:
tail list

-- rimuovere ultimo elemento:
init list -- == take( length list - 1 ) list == reverse( tail( reverse list ) )

-- selezionare n-esimo elemento (indici partono da 0):
list !! n

-- seleziona n elementi:
take n list

-- rimuovere i primi n elementi:
drop n list

-- lunghezza lista:
length list

-- somma di una lista:
sum list

-- prodotto di una lista:
product list

-- inverti lista:
reverse list

-- verifica se lista vuota:
null list

