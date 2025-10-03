producto _ 0 = 0
producto x y = x + producto x (y-1)

producto2 x y
    |y==0 = 0
    |x==0 = 0
    |otherwise = x + producto2 x (y-1)

sumaPares x
    |x==0 = 0
    |digito `mod` 2 == 0 = digito + sumaPares (x `div` 10)
    |otherwise = sumaPares (x `div` 10)
    where digito = (x `mod` 10)

contarMenores [] _ = 0
contarMenores (x:xs) y = if x < y then (1 + contarMenores xs y) else contarMenores xs y

contarMenores2 (x:xs) y
    |null (x:xs) = 0
    |x < y = 1 + contarMenores2 xs y
    |otherwise = contarMenores2 xs y

contarMenores3 z y = sum [1 | x <- z, x < y]

diferencia xs ys
    |null xs = []
    |not condicion = (head xs) : diferencia (tail xs) ys
    |otherwise = diferencia (tail xs) ys
    where condicion = (head xs) `elem` ys

diferencia2 [] _ = []
diferencia2 (x:xs) ys = if x `elem` ys then (diferencia xs ys) else (x : diferencia xs ys)

subLista1 xs n
    |null xs = []
    |n <= 0 = xs
    |otherwise = subLista1 (tail xs) (n-1)

subLista2 [] _ = []
subLista2 xs 0 = xs
subLista2 xs n = subLista1 (tail xs) (n-1)

transformar f z = [f x | x <- z]

paresOrdenados n = [x | x <- [1 .. n], (x `mod` 2) == 0]

verificarG p xs 
    |null xs = True
    |otherwise = p (head xs) && verificarG p (tail xs)

verificarP p _ = True
verificarP p (x:xs) = p x && verificarP p xs

verificarL p z = and [p x | x <- z]

combinarLC f xs ys = [ f x y | (x, y) <- (zip xs ys)]

combinarPM f [] _ = []
combinarPM f _ [] = [] 
combinarPM f (x:xs) (y:ys) = (f x y) : combinarPM f xs ys

combinarG f xs ys 
    |null xs || null ys = []
    |otherwise = f xh yh : combinarG f xt yt
    where  
        xh = head xs
        yh = head ys
        xt = tail xs
        yt = tail ys

filtrarL p xs = [x | x <- xs, p x]

filtrarG p xs
    |null xs = []
    |p x = x : filtrarG p (tail xs)
    |otherwise = filtrarG p (tail xs)
    where x = head xs

subLista [] _ _ = []
subLista _ _ 0 = []
subLista xs x n = if (head xs) > x then ((head xs) : subLista (tail xs) x (n-1)) else (subLista (tail xs) x (n-1))

insertarListas xs ys n 
    |null xs || null ys = []
    |n == length ys = xs
    |otherwise = insertarListas (xs ++ [ys !! n]) ys (n + 1)