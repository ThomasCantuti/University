-- foldl = folding a sinistra
foldl :: (b -> a -> b) -> b -> [a] -> b

sumList :: [Int] -> Int
sumList = foldl (\acc x -> acc + x) 0
-- Il primo argomento è una funzione binaria che accetta un accumulatore 
-- e un elemento della lista e restituisce un nuovo accumulatore.
-- Il secondo argomento è il valore iniziale dell'accumulatore.
-- Il terzo argomento è la lista da piegare.
result :: Int
result = sumList [1, 2, 3, 4]  -- Restituirà 10

-- foldr = folding a destra
foldr :: (a -> b -> b) -> b -> [a] -> b

concatList :: [String] -> String
concatList = foldr (\x acc -> x ++ acc) ""

result :: String
result = concatList ["a", "b", "c"]  -- Restituirà "abc"