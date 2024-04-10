-- funzione polimorfa overloaded -> se il suo tipo contiene una o più class constraints
(+) :: Num a => a -> a -> a
-- con a che deve essere istanza di Num

-- Classe -> collezione di tipi che supportano certe operazioni:
-- Eq -> eguagliano due tipi (==) e (/=)
-- Ord -> ordine dei tipi (<), (<=), min, max, ...
-- Show -> prende un tipo e la converte in stringa --> show a -> "a"
-- Read -> prende una stringa e la converte in tipo --> read "expr" :: type -> expr
-- Num -> tipi numerici (+),(-),negate, abs,signum
-- Integral -> tipi numerici interi per div, mod
-- Fractional -> tipi numerici in virgola mobile per (/), recip

