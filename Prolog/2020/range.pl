:- module(loop, [upto/4, downto/4]).

upto(Low,High,_Step,Low) :- Low =< High.
upto(Low,High,Step,Var) :-
    Inc is Low+Step,
    Inc =< High,
    upto(Inc, High, Step, Var).

downto(Low,High,_Step,High) :- Low =< High.
downto(Low,High,Step,Var) :-
    Dec is High-Step,
    Dec >= Low,
    downto(Low, Dec, Step, Var).
