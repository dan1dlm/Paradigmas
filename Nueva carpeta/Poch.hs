import GHC.Base (divInt)

-- inciso a) Pattern Matching
predicadoEsPar :: Int -> Bool
predicadoEsPar = even

aceptados :: Int -> (Int -> Bool) -> [Int]
aceptados n p = if n < 10 then (if p n then [n] else []) else 
                (if p (mod n 10) then (mod n 10) : aceptados (div n 10) p else aceptados (div n 10) p)

-- inciso b) List Comprehension
comunes :: Eq a => [a] -> [a] -> (a -> Bool) -> [a]
comunes xs ys p = [a | a <- xs, a `elem` ys, p a]

-- inciso c) Guards
subLista :: Eq a => [a] -> Int -> Int -> [a]
subLista (x:xs) n c
    | null (x:xs) = []
    | c == 0 = []
    | n == 1 = x : subLista xs n (c - 1)
    | otherwise = (x:xs) !! (n - 1) : subLista xs n (c - 1)

main :: IO()
main = do
    let n = 123456
    let l1 = [2, 5, 7]
    let l2 = [3, 5, 8]
    let l3 = [1, 2, 3, 4, 5, 6, 7, 8]
    print(aceptados n predicadoEsPar)
    print(comunes l1 l2 predicadoEsPar)
    print(subLista l3 2 3)
    return()
