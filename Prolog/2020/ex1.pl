magicNumber(7).
magicNumber(X) :- 10 < X, X < 20.
magicNumber(X) :- between(100, 120, X).

nearby(X,Y) :- X = Y.
nearby(X,Y) :- X is Y+1.
nearby(X,Y) :- X is Y-1.

count(Lower, Upper) :- Upper < Lower, !, false.
count(Lower, Upper) :- Upper = Lower, writeln(Lower), !.
count(Lower, Upper) :- Upper \= Lower, writeln(Lower), Next is Lower + 1, count(Next, Upper).

smartCount(Lower, Upper) :- forall(between(Lower, Upper, X), writeln(X)).
