-- :type espressione -> tipo dell'espressione (posso usare anche :t)
-- espressione :: tipo  -> esempio: False :: Bool
-- liste -> tanti elementi dello stesso tipo
-- tuple -> tanti elementi di tipo diverso (non si possono definire tuple con 1 elemento)
['a','b'] -> [Char]
('a', 1) -> (Char, Int)
([1,2,3], ('a', 1, True)) -> ([Int], (Char, Int, bool))

-- Funzioni:
add1 :: (Int, Int) -> Int -- == add1 (x,y) = x + y
add2 :: (Int) -> (Int -> Int) -- == add2 x y = x + y  (prende intero e restituisce intero, ...)

insert x xs = xs ++ [x] -- si applica le [] a x per renderlo lista e si concatena con ++ per aggiungerlo alla fine
insert x xs = x : xs -- inserisce x in testa alla lista xs

-- Funzioni polimorfe:
length :: [a] -> Int 
-
per ogni tipo a la funzione length prende una lista di elementi
di tipo a e restituisce un intero
-

fst :: (a, b) -> a -- presi 2 elementi di tipo casuale restituisce il primo
-- fst (1,2) -> 1
