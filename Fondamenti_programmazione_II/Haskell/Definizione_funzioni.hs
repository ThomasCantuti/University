-- Funzioni con IF-THEN-ELSE

-- Definizione valore assoluto:
abs :: Num a => a -> a
abs n = if n >= 0 then n else -n

-- Definizione segno di un numero:
signum :: Num a => a -> a
signum n = if n > 0 then 1 else 
              if n < 0 then -1 else 0


-- Funzioni con guardie

-- Definizione valore assoluto
abs :: Num a => a -> a
abs n
    | n >= 0 = n
    | otherwise = -n

-- Definizione segno di un numero (altro modo di usare le guardie):
signum :: Num a => a -> a
signum n | n > 0 = 1
         | n < 0 = -1
         | otherwise = 0


-- Funzioni con pattern matching

sayInt :: Int -> String
sayInt 1 = "One!"
sayInt 2 = "Two!"
sayInt x = "Not between 1 and 2"

not :: Bool -> Bool
not False = True
not False = True

snd :: (a,b,c) -> b
snd (_,y,_) = y -- uso _ per generalizzare i casi

head :: [a] -> a
head (x:_) = x

describeList :: Show a => [a] -> String
describeList [] = "Empty list"
describeList (x:[]) = "One element in list: " ++ show x  -- (x:[]) == [x]
describeList (x:y:[]) = "Two elements in list: " ++ show x ++ " " ++ show y  -- (x:y:[]) == [x,y]
describeList _ = "List too long"


-- Funzioni con where
-- where è condivisa solo tra le guardie di una definizione
-- non è condivisa con altre definizioni

bmi :: (Fractional a, Ord a) => a -> a -> String
--bmi 0.0 _ = ...
--    where skinny = 18.5
bmi weight height
    | bmi <= skinny = "Underweight"
    | bmi <= normal = "Normal"
    | bmi <= fat = "Fat"
    | otherwise = "Soo big"
    where bmi = weight / height ^ 2
        skinny = 18.5
        normal = 25.0
        fat = 30.0


initials :: String -> String -> String
initials firstname lastname = [f] ++ " " ++ [l]
    where (f:_) = firstname
          (l:_) = lastname