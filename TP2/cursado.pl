cursa(calculo, juan).
cursa(calculo, pedro).
cursa(calculo, maria).
cursa(algebra, juan).
cursa(algebra, patricia).
cursa(estadistica, lucas).
cursa(elementos, pedro).
cursa(elementos, luisa).
cursa(elementos, ana).



alumnoRegular(X):- cursa(Z1, X), cursa(Z2, X), Z1 \= Z2.

companieros(X, Y):- cursa(Z, X), cursa(Z, Y).