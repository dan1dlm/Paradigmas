eliminarIgualesX [] _ = []
eliminarIgualesX (x:xs) a
    |x == a =  eliminarIgualesX xs a
    |otherwise = x : eliminarIgualesX xs a

diferencia a b = [c | c <- a,  c `notElem` b]

sublista1 z n = [x | x <- z, x `notElem`[1 .. n]]

f x = x*2

transformar z = [f x | x <- z]

verificar predicado z = [c | c <- z, predicado c]