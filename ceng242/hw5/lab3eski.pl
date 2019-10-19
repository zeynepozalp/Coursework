:- module(lab3, [similar_distributions/2, proton_ionization/3]).
:- [catoms].

is_similar([A1|[]], []):- fail.
is_similar([], [A2|[]]):- fail.
is_similar([A1|[]], [A2|[]]).
is_similar([A1|[B1|C1]], [A2|[B2|C2]]):-
  A1<B1,
  A2<B2,
  is_similar([B1|C1], [B2|C2]).
is_similar([A1|[B1|C1]], [A2|[B2|C2]]):-
  A1>B1,
  A2>B2,
  is_similar([B1|C1], [B2|C2]).
is_similar([A1|[B1|C1]], [A2|[B2|C2]]):-
  A1>B1,
  A2>B2,
  is_similar([B1|C1], [B2|C2]).

similar_distributions(Cat1,Cat2) :-
  catom(Cat1, Mass1, _, List1),
  catom(Cat2, Mass2, _, List2),
  not(Cat1==Cat2),
  Mass1<Mass2,
  is_similar(List1, List2).

add_proton([0|[]], [], _).
add_proton([A|[B|C]], Flist, P):-
  P=<B,
  P=<(8-A),
  add_proton([B-P|C], Rest, P),
  Flist is [A+P|Rest].
add_proton([A|[B|C]], Flist, P):-
  P>B,
  P=<(8-A),
  add_proton([0|C], Rest, P),
  Flist is [A+B|Rest].

proton_ionization(Name, 0, Flist):-
  catom(Name, _, _, List),
  Flist is List.
proton_ionization(Name, P, Flist):-
  P>0,
  catom(Name, _, _, List),
  add_proton(List, Flist, P).
