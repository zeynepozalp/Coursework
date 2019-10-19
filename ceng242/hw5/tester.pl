:- module(tester, [test_hw5/0]).
:- [hw5].

% ===== READ ME =====
% 1. Call this file with the following:
% 	swipl -S4096m -q -s tester.pl -t "test_hw5"
%
% 2. In order to make Prolog print the whole list when a long list is returned with dots, call the following:
% 	set_prolog_flag(answer_write_options,[max_depth(0)]).



% === Helper functions ===
isSubset([],_).
isSubset([H | T], Y) :- member(H, Y), select(H, Y, Z), isSubset(T, Z).
equal(X, Y) :- isSubset(X, Y), isSubset(Y, X), !.


% === Test cases for catomic_number/2 ===
% Test case 1: catomic_number(cobalt, CATOMIC_NUMBER)
% Test case 2: catomic_number(NAME, 12)
% Test case 3: catomic_number(carbon, 6)
% Test case 4: catomic_number(oxygen, 8)
% Test case 5: catomic_number(bromine, 35)

test_case_CN1 :- (catomic_number(cobalt, CATOMIC_NUMBER), !, CATOMIC_NUMBER == 28) -> write('- Test case 1 is successful.\n'); write('- Test case 1 is failed.\n').
test_case_CN2 :- (catomic_number(NAME, 12), !, NAME == magnesium) -> write('- Test case 2 is successful.\n'); write('- Test case 2 is failed.\n').
test_case_CN3 :- (catomic_number(carbon, 6)) -> write('- Test case 3 is successful.\n'); write('- Test case 3 is failed.\n').
test_case_CN4 :- (catomic_number(oxygen, 8)) -> write('- Test case 4 is successful.\n'); write('- Test case 4 is failed.\n').
test_case_CN5 :- (catomic_number(bromine, 35)) -> write('- Test case 5 is successful.\n'); write('- Test case 5 is failed.\n').

test_catomic_number :-
    not(current_predicate(catomic_number/2)), 
    !,
	write('- Predicate catomic_number/2 is not found.\n').

test_catomic_number :-
	write('Testing catomic_number/2 predicate...\n'),
	TimeLimit is 10,
	catch(call_with_time_limit(TimeLimit, test_case_CN1), _, (write('- Test case 1 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_CN2), _, (write('- Test case 2 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_CN3), _, (write('- Test case 3 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_CN4), _, (write('- Test case 4 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_CN5), _, (write('- Test case 5 timed out.\n'))).


% === Test cases for ion/2 ===
% Test case 1: ion(boron, CHARGE)
% Test case 2: ion(NAME, 2)
% Test case 3: ion(NAME, -2)
% Test case 4: ion(carbon, 4)
% Test case 5: not(ion(carbon, -4))

test_case_I1 :- (ion(boron, CHARGE), !, CHARGE == 3) -> write('- Test case 1 is successful.\n'); write('- Test case 1 is failed.\n').
test_case_I2 :- (findall(NAME, ion(NAME, 2), ALL_NAMES), 
			equal(ALL_NAMES, [iron, manganese, magnesium, calcium]) )
			-> write('- Test case 2 is successful.\n'); write('- Test case 2 is failed.\n').
test_case_I3 :- (findall(NAME, ion(NAME, -2), ALL_NAMES), 
			equal(ALL_NAMES, [cobalt, oxygen]) )
			-> write('- Test case 3 is successful.\n'); write('- Test case 3 is failed.\n').
test_case_I4 :- (ion(carbon, 4)) -> write('- Test case 4 is successful.\n'); write('- Test case 4 is failed.\n').
test_case_I5 :- (not(ion(carbon, -4))) -> write('- Test case 5 is successful.\n'); write('- Test case 5 is failed.\n').

test_ion :-
    not(current_predicate(ion/2)), 
    !,
	write('- Predicate ion/2 is not found.\n').

test_ion :-
	write('Testing ion/2 predicate...\n'),
	TimeLimit is 10,
	catch(call_with_time_limit(TimeLimit, test_case_I1), _, (write('- Test case 1 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_I2), _, (write('- Test case 2 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_I3), _, (write('- Test case 3 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_I4), _, (write('- Test case 4 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_I5), _, (write('- Test case 5 timed out.\n'))).


% === Test cases for molecule/2 ===
% Test case 1: molecule(CATOM_LIST, 20)
% Test case 2: not(molecule(_, 30))
% Test case 3: molecule(CATOM_LIST, 32)
% Test case 4: molecule(CATOM_LIST, 62)
% Test case 5: molecule([oxygen,oxygen,calcium,iron], 62)
% Test case 6: molecule(CATOM_LIST, 180) (for efficiency testing)

test_case_M1 :- (molecule(CATOM_LIST, 20), !, CATOM_LIST == [oxygen, magnesium]) -> write('- Test case 1 is successful.\n'); write('- Test case 1 is failed.\n').
test_case_M2 :- (not(molecule(_, 30))) -> write('- Test case 2 is successful.\n'); write('- Test case 2 is failed.\n').
test_case_M3 :- (findall(CATOM_LIST, molecule(CATOM_LIST, 32), CATOM_LISTS), 
			equal(CATOM_LISTS, [[carbon, nitrogen, nitrogen, magnesium], [boron, nitrogen, oxygen, magnesium]]) )
			-> write('- Test case 3 is successful.\n'); write('- Test case 3 is failed.\n').
test_case_M4 :- (findall(CATOM_LIST, molecule(CATOM_LIST, 62), CATOM_LISTS), 
			equal(CATOM_LISTS, [[oxygen,oxygen,calcium,iron],[boron,nitrogen,nitrogen,nitrogen,magnesium,magnesium,magnesium],[carbon,oxygen,oxygen,oxygen,oxygen,magnesium,magnesium],[carbon,carbon,nitrogen,nitrogen,oxygen,oxygen,calcium],[boron,carbon,nitrogen,oxygen,oxygen,oxygen,calcium],[boron,boron,oxygen,oxygen,oxygen,oxygen,calcium],[carbon,oxygen,oxygen,magnesium,cobalt],[carbon,cobalt,cobalt]]) )
			-> write('- Test case 4 is successful.\n'); write('- Test case 4 is failed.\n').
test_case_M5 :- (molecule([oxygen,oxygen,calcium,iron], 62)) -> write('- Test case 5 is successful.\n'); write('- Test case 5 is failed.\n').
test_case_M6 :- (findall(CATOM_LIST, molecule(CATOM_LIST, 180), _))
			-> write('- Test case 6 is successful.\n'); write('- Test case 6 is failed.\n').

test_molecule :-
    not(current_predicate(molecule/2)), 
    !,
	write('- Predicate molecule/2 is not found.\n').

test_molecule :-
	write('Testing molecule/2 predicate...\n'),
	TimeLimit is 60,
	catch(call_with_time_limit(TimeLimit, test_case_M1), _, (write('- Test case 1 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_M2), _, (write('- Test case 2 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_M3), _, (write('- Test case 3 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_M4), _, (write('- Test case 4 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_M5), _, (write('- Test case 5 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_M6), _, (write('- Test case 6 timed out.\n'))).

test_hw5 :-
	test_catomic_number,
	test_ion,
	test_molecule.


