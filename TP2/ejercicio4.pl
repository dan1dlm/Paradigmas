% Escribir dígitos de un número
% Caso base
digitos(N) :-
    N < 10,
    write(N).

% Paso recursivo
digitos(N) :-
    N >= 10,
    N1 is N // 10,
    digitos(N1),
    write('-'),
    D is N mod 10,
    write(D).

% Sumar dígitos
% Caso base
sumaDigitos(N, S) :-
    N < 10,
    S is N.

% Caso recursivo
sumaDigitos(N, S) :-
    N >= 10,
    N1 is N // 10,
    sumaDigitos(N1, S1),
    D is N mod 10,
    S is D + S1.

%auxiliar:
mayor(X, Y, M):- 
    X >= Y,
    M is X.

mayor(X, Y, M) :-
    X < Y,
    M is Y.


%Encontrar el digito con mayor valor
digitoMayor(N, S):-
    N < 10,
    S is N.

digitoMayor(N, S):-
    N>=10,
    N1 is N//10,
    digitoMayor(N1, S1),
    D is N mod 10,
    mayor(D, S1, M),
    S is M.


elementosLista([], N) :- N is 0.
elementosLista([_|T], N):- elementosLista(T, M), N is M + 1.

aparece([], _, N):- N is 0.
aparece([H|T], X, N):- X = H, aparece(T, X, N1), N is N1 + 1.
aparece([H|T], X, N):- X \= H, aparece(T, X, N).

ordenado([]).
ordenado([_]).
ordenado([H|[S|T]]) :- (H < S), ordenado([S | T]).