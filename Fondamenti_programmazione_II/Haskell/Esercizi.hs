-- Inversa di una lista data una lista (reverse)
inversa [] = []
inversa (x:xs) = (inversa xs) ++ [x]
-- oppure
inversa1 xs = inv xs []
inv [] ys = ys
inv (x:xs) ys = inv xs (x:ys)

-- Lista di coppie date le due liste (zip)
coppie (x:xs) (y:ys) = (x,y):coppie xs ys
coppie _ _ = []

-- Restituisce la lista senza i primi n elementi (simile a drop)
eliminaPrimi xs 0 = xs
eliminaPrimi (x:xs) n = eliminaPrimi xs (n-1)

-- Concatenare due liste senza ++
concatena [] ys = ys
concatena (x:xs) ys = x:(concatena xs ys)

-- Lista di n volte v
rep 0 x = []
rep n x = x:rep(n - 1) x

-- Fondere due liste in una ordinata
merge (x:xs) (y:ys)
    | x < y = x:merge (y:ys) xs
    | otherwise = y:merge (x:xs) ys
merge [] ys = ys
merge xs [] = xs

-- Lista ordinata (lista divisa in due metà, ordinate le due liste, riunite le due liste)
msort [] = []
msort [x] = [x]
msort xs = merge (msort (take (div (length xs) 2) xs)) (msort (drop (div (length xs) 2) xs))

-- Lista che toglie gli elementi divisibili per 3
div3 n = (n `mod` 3) == 0
filterDiv3 xs = filter div3 xs

-- Fattoriale di un numero
factorial1 0 = 1
factorial1 n = n * factorial1(n - 1)
-- oppure
factorial n = foldr (*) 1 [1..n]

-- foldr -> applicato a destra
-- foldl -> applicato a sinistra

-- Modulo di un numero
even n = n `mod` 2 == 0

-- Dividere una lista in n elementi
splitAt n xs = (take n xs, drop n xs)

-- Dividere una lista in due metà
halve xs = (take ((length xs) `div` 2) xs, drop ((length xs) - ((length xs) `div` 2)) xs)
--halve xs = splitAt ( div (length xs) 2 ) xs

-- Restituzione del terzo elemento di una lista
third1 x = head(tail(tail x))
third2 xs = xs !! 2
third3 (_:_:x:_) = x

-- Somma ricorsiva all'indietro
sumdown 0 = 0
sumdown n = n + sumdown(n - 1)
sumdown1 num = if num > 0 then num + sumdown (num-1) else 0

-- Decide se tutti i valori logici nella lista sono True
and [] = True
and (x:xs) = x && and xs

 -- Concatenare liste di liste
concat [] = True
concat (x:xs) = x ++ concat xs

 -- Selezionare n-esimo elemento della lista (!!)
(x:_) !! 0 = xs
(_:xs) !! n = xs !! (n-1)

 -- Decide se un valore è nella lista
elem _ [] = False
elem x (y:ys) = if x == y then True else elem x ys

 -- Conta le occorenze di ogni valore in una lista
count _ [] = 0
count x (y:ys) = if x == y then 1 + count x ys else count x ys

-- Verifica se una condizione è vera per tutta la lista
all _ [] = True
all cond (x:xs)
    | cond x = all cond xs
    | otherwise = False

-- Verifica se una condizione è vera per alcuni elementi della lista
any _ [] = False
any cond (x:xs)
    | cond x = True
    | otherwise = any cond xs

-- Seleziona elementi dalla lista finchè la condizione è vera
takeWhile _ [] = []
takeWhile cond (x:xs)
    | cond x = x : takeWhile cond xs
    | otherwise = []

-- Rimuove elementi dalla lista finchè la condizione è vera
dropWhile _ [] = []
dropWhile cond (x:xs)
    | cond x = dropWhile cond xs
    | otherwise = x:xs

-- Data una lista di numeri essa viene unita in un numero
dec2int [] = 0
dec2int = foldl (\x y -> 10*x + y) 0

-- Due funzioni si applicano alternativamente alla lista
altMap _ _ [] = []
altMap f1 f2 (x:xs) = f1 x : altMap f2 f1 xs
-- altMap (+10) (+100) [0,1,2,3,4]
-- output = [10,101,12,103,14]