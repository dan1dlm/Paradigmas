concatenar([], X, X).
concatenar([X|T], L, [X|R]):-concatenar(T, L, R).