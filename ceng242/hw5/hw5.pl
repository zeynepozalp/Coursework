:- module( hw5 , [ catomic_number/2, ion/2, molecule/2 ] ) .
:- [catoms].

sum_list([], 0).
sum_list([H|T], Sum) :-
   sum_list(T, Rest),
   Sum is H + Rest.

catomic_number(NAME, CATN) :-
  catom(NAME, _, _, LIST),
  sum_list(LIST, CATN).

find_charge([A],Charge) :-
  A>4,
  Charge is -(8-A).
find_charge([A],Charge) :-
  A=<4,
  Charge is A.
find_charge([H|T], Charge) :- find_charge(T,Charge).

ion(NAME, CHARGE) :-
  catom(NAME, _, _, LIST),
  find_charge(LIST, CHARGE).

molecule(LIST, TCATN):-
  helper(LIST, TCATN, -1, 0, 0).

helper([], TCATN, Catn, Ion, _) :-
  Ion=:= 0,
  TCATN =:= (Catn+1).
helper([H|T], Tcatn, Catn, Charges, Prev) :-
  catomic_number(H, Cat),
  Cat>=Prev,
  (Catn+Cat)<Tcatn,
  ion(H, Charge),
  helper(T, Tcatn, Catn+Cat, Charges+Charge, Cat).
