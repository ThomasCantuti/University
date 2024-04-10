-- Espressioni lambda: specificano argomenti e corpo della funzione senza nome
\x -> x + x
-- \ rappresenta lambda
map (\x -> x + x*0.2) [10, 100, 50] -- map applica la lambda expr a tutti gli arg della lista

-- (x #) \y -> x # y   con x già prefissato
(1 +) \y -> 1 + y

-- (# y) \x -> x # y   con y già prefissato
(/ 2) \x -> x / 2