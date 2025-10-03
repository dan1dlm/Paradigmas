-- ============================================================================
-- PARADIGMAS DE PROGRAMACION - 2025
-- Solucion-TP3-2025.hs
-- ============================================================================

-- -----------------------------------------------------------------------------------------------------------------------------------------------
--  Ejercicio 1
-- -----------------------------------------------------------------------------------------------------------------------------------------------
  
misterio1  n
   |  n == 0   =  1
   |  n == 1   =  3
   | otherwise =  9 * misterio1 (n - 2)

{-- La función misterio1 devuelve el valor de 3 elevado a la n --}

misterio2 0 = 1
misterio2 n = (mod n 10) * misterio2 (div n 10)

{-- La función misterio2 devuelve el producto de los digitos de un numero natural n --}


-- -----------------------------------------------------------------------------------------------------------------------------------------------
--  Ejercicio 2
-- -----------------------------------------------------------------------------------------------------------------------------------------------

{-- a. productoPorSumasSucesivas que reciba dos números naturales y realice el producto entre dichos números mediante sumas sucesivas --}

-- Version Guards
productoPorSumasSucesivasG x y
   | y==0 = 0
   | otherwise = x + productoPorSumasSucesivasG x (y-1)

-- Version Pattern Matching
productoPorSumasSucesivasPM x 0 = 0
productoPorSumasSucesivasPM x y = x + productoPorSumasSucesivasPM x (y-1)

-- Version List Comprehension
productoPorSumasSucesivasLC x y = sum[x | w <-[1..y]]


{-- b.	sumaDigitosPares que reciba un número positivo y devuelva la suma de los dígitos pares que contiene --}

sumarDigitosParesG n
   | n == 0 = 0
   | mod n 2 == 0 = (mod n 10) + sumarDigitosParesG (div n 10) 
   | otherwise = sumarDigitosParesG (div n 10)
   
sumarDigitosParesPM 0 = 0
sumarDigitosParesPM n = (if (mod n 2) ==0 then mod n 10 else 0 ) + sumarDigitosParesPM (div n 10)

{-- c.	contarMenores que dada una lista de números enteros cuente cuantos elementos de la lista son menores que 10 --}
{-- i.	Realice una versión con Guards --}

contarMenoresG xs 
   | null xs = 0
   | (head xs) < 10 = 1 + contarMenoresG (tail xs)
   | otherwise = contarMenoresG (tail xs)
   

{-- ii.	Realice una versión con Pattern Matching --}

contarMenoresPM []  = 0
contarMenoresPM (y:ys) = (if y < 10 then 1 else 0 ) + contarMenoresPM ys

{-- iii. Realice una versión con List Comprehension --}

contarMenoresLC ys = sum[1 | y <- ys, y < 10]

{-- d.	eliminarIgualesX que reciba una lista y un número X y elimine de la lista todos los elementos iguales a X. --}
{-- i.	Realice una versión con Guards --}

eliminarIgualesXG ys x  
   | null ys = []
   | (head ys) == x = eliminarIgualesXG (tail ys) x
   | otherwise =  (head ys) : eliminarIgualesXG (tail ys) x
   

{-- ii.	Realice una versión con Pattern Matching --}

eliminarIgualesXPM [] _ = []
eliminarIgualesXPM (y:ys) x = (if y == x then [] else [y] ) ++ eliminarIgualesXPM ys x

{-- iii. Realice una versión con List Comprehension --}

eliminarIgualesXLC ys x = [ y | y <- ys, not (y == x)]


{-- e.	diferencia que reciba dos listas y devuelva los elementos de la primer lista que no se encuentran en la segunda lista --}
-- Version Guards
diferenciaG xs ys
   | null xs || null ys = xs
   | elem (head xs) ys = diferenciaG (tail xs) ys
   | otherwise = (head xs) : diferenciaG (tail xs) ys

-- Version Pattern Matching
diferenciaPM [] ys = []
diferenciaPM xs [] = xs
diferenciaPM (x:xs) (y:ys) = (if  elem x (y:ys) then [] else [x] ) ++ diferenciaPM xs (y:ys)

-- Version List Comprehension

diferenciaLC xs ys = [x | x <- xs, not(elem x ys)]


{-- f.	subLista1 que reciba una lista y un número natural n y retorne una lista sin los primeros n elementos de la lista dada. No utilice drop --}
-- Version Guards

subLista1G xs n
   | null xs = []
   | n==0 = xs
   | otherwise = subLista1G (tail xs) (n-1)

-- Version Pattern Matching

subLista1PM [] _ = [] 
subLista1PM (x:xs) 0 = (x:xs)
subLista1PM (x:xs) n = subLista1PM xs (n-1)

-- Version List Comprehension

subLista1LC xs n = [xs !! (a-1)| a <- [1..(length xs)], a > n]
subLista1LC2 xs n = [x | (x,a) <- (zip xs [1..(length xs)]), a > n]


{-- g.	transformar que reciba como parámetros una función f (de un argumento) y una lista y devuelva como resultado la lista recibida en la que cada uno de sus elementos haya sido transformado con la función f --}
-- transformar :: (a -> b) -> [a] -> [b]

-- Version Guards
transformarG f xs
   | null xs = []
   | otherwise = f (head xs) : transformarG f (tail xs)

-- Version Pattern Matching

transformarPM _ [] = []
transformarPM f (x:xs) = f x : transformarPM f xs

-- Version List Comprehension
transformarLC f xs = [f x | x <- xs]

-- Funciones auxiliares de un argumento
-- fcionAux::  (Num a)=> a -> a
fcionAux1 x = 2 * x
fcionAux2 x = x - 1

{-- h.	tablaDePares que, dado un número natural n, construya una lista que contenga los números pares que se encuentran en el intervalo [ 0,n]. Use List Comprehension --}

tablaDePares n = [x | x <- [0..n], (mod x 2) == 0]

{-- i.	paresOrdenados que construya una lista con todos los pares ordenados (x,y) posibles teniendo en cuenta que x corresponde a todos los números pares e y a los números impares entre 0 y 5 donde se cumple la condición que  x+y es menor a un valor Z dado. Use List Comprehension --}

paresOrdenados1 z = [(a, b) | a <- [0..5], b <- [0..5] , mod a 2 ==0, mod b 2 ==1, (a + b) < z]
paresOrdenados2 z = [(x, y) | x <- [0,2..5], y <- [1,3..5], (x + y) < z]

{-- j.	verificar que recibe un predicado p (un predicado es una función que devuelve un valor booleano) y una lista de elementos xs y devuelve True si todos los elementos de la lista satisfacen el predicado, caso contrario retorna False --}

{-- i.	Realice una versión con Guards --}
verificarG p xs
   | null xs = True
   | otherwise = p (head xs) && verificarG p (tail xs)

{-- ii.	Realice una versión con Pattern Matching --}
verificarPM _ [] = True
verificarPM p (x:xs) = p x && verificarPM p xs

{-- iii. Realice una versión con List Comprehension --}

verificarLC p xs = and [ p x | x <- xs ]

-- Predicados auxiliares de un argumento
predAux1 x = x > 0
predAux2 x = mod x 2

{-- k.	combinar que reciba una función f y dos listas y retorne una nueva lista que resulta de la combinación las listas aplicando la función f. La función f debe recibir como parámetro un elemento de cada lista a combinar por vez. Utilice la siguiente definición de tipo para su función:
combinar :: (a -> b -> c) -> [a] -> [b] -> [c]
--}
{-- i.	Realice una versión con Guards --}
combinarG f xs ys
   | null xs = []
   | null ys = []
   | otherwise = f (head xs) (head ys) : combinarG f (tail xs) (tail ys)
   

{--	ii.	Realice una versión con Pattern Matching --}
combinarPM _ [] [] = []
combinarPM _ _ [] = []
combinarPM _ [] _ = []
combinarPM f (x:xs)(y:ys) = f x y : combinarPM f xs ys

{--	iii.	Realice una versión con List Comprehension --}
combinarLC f xs ys = [ f x y | (x, y) <- (zip xs ys)]

-- Funciones auxiliares con dos argumentos
fcionAux3 x y = x+y
fcionAux4 x y = (x,y)

{-- l.	filtrarLista que reciba un predicado y una lista y luego regresa la lista de elementos que satisfacen el predicado. La signatura de la función debería ser: 
filtrarLista :: (a -> Bool)  -> [a] -> [a]
--}
{-- i.	Realice una versión con guards --}

filtrarListaG p xs 
   | null xs = []
   | p (head xs) = (head xs) : filtrarListaG p (tail xs)
   | otherwise = filtrarListaG p (tail xs)
   
{-- ii.	Realice una versión con list comprehension --}
filtrarListaLC p xs = [ x | x <- xs, p x]


{-- m.	subLista2 que reciba una lista, un elemento x y un número natural n y retorne una lista sin los primeros n elementos de la lista dada que sean mayores que x. Utilice Pattern Matching --}

subLista2 [] _ _ = []
subLista2(y:ys) x 0 = (y:ys)
subLista2 (y:ys) x n = if y > x then subLista2 ys x (n-1) else y : subLista2 ys x n


{-- n.	insertarLista: función que recibe dos listas y un número natural n y retorna la primer lista a la que se le agregaron los elementos de la segunda lista a partir de la posición n. Utilice Guards --}

insertarLista xs ys n
   | null xs = ys
   | n==0 = ys ++ xs
   | otherwise = head xs : insertarLista (tail xs) ys (n-1)
   

-- -----------------------------------------------------------------------------------------------------------------------------------------------
--  Ejercicio 3
-- -----------------------------------------------------------------------------------------------------------------------------------------------

foldlGV f a xs
    | null xs = a
    | otherwise = foldlGV f ( f a (head xs) ) (tail xs)

































































































































