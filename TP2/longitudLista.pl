longitud([], 0).
longitud([_|T], N):-longitud(T, N1), N is N1 + 1.

eliminar(_, [], []).
eliminar(X, [X|T], S) :- eliminar(X, T, S).
eliminar(X, [H|T], [H|S]) :- X \= H, eliminar(X, T, S).