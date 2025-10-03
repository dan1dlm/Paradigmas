-- comentarios
{-
	comentarios de más de una línea
-}
-- COMANDOS HASKELL
-- :t nombreFuncion retorna el tipo de la funcion


--              EJEMPLOS HASKELL
{-
    Función potencia a^b, b>=0. Si b < 0 devuelve 0
-}

-- GUARDS
potencia1 a b
   |b < 0  = 0
   |b==0   = 1
   |otherwise= a* potencia1 a (b-1)
   
-- PATTERN MATCHING
potencia2 a 0 = 1
potencia2 a b = if b < 0 then 0 else a* potencia2 a (b-1)

-- LIST COMPREHENSION
-- potencia3 a b = product [a | x<-[1..b], b>0]
potencia3 a b = if b<0 then 0 else product [a | z<-[1..b], b>0]



{-
    Función pertenece
-}

-- PATTERN MATCHING 
pertenece1 [] y = False
pertenece1 (x:xs) y = if y==x then True else pertenece1 xs y

-- GUARDS
pertenece2 xs y
   | null xs   = False
   | head xs ==y = True
   | otherwise = pertenece2 (tail xs) y
   
-- LIST COMPREHENSION
pertenece3 xs y = or [z==y| z<-xs]






















