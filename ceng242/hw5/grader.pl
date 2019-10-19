:- module(section1_grader, [runGrader/1]).

% ===== READ ME =====
% 1. Run the grader with the following command;
%		swipl -S4096m -q -s section1_grader.pl -t "runGrader('./lab3.pl')"
% where FILENAME.pl is your code file.
% Note: You may need 4 gbs of memory space to run this command.
% If you don't, remove or change the option "-S4096m".
%
% 2. In order to make Prolog print the whole list when a long list is returned with dots, call the following:
% 		set_prolog_flag(answer_write_options,[max_depth(0)]).

% === Helper functions ===
%write_comment(_).
% Replace the above definition with the below one to see the comments
write_comment(Comment) :- write(Comment).

is_subset([], _).
is_subset([H|T], Y):- member(H, Y), select(H, Y, Z), is_subset(T, Z).
equal(X, Y):- is_subset(X, Y), is_subset(Y, X), !.



% === Test cases for similar_distributions/2 ===
test_case_SD1(G) :- (similar_distributions(c9, c11), not(similar_distributions(c11, _)))
			-> G is 5, write_comment('- Test case 1 is successful.\n'); G is 0, write_comment('- Test case 1 is failed.\n').
test_case_SD2(G) :- (findall(NAME_2, similar_distributions(c9, NAME_2), ALL_NAMES), equal(ALL_NAMES, [c11]) )
			-> G is 2, write_comment('- Test case 2 is successful.\n'); G is 0, write_comment('- Test case 2 is failed.\n').
test_case_SD3(G) :- (not(similar_distributions(_, c83)), not(similar_distributions(c83, _)))
			-> G is 3, write_comment('- Test case 3 is successful.\n'); G is 0, write_comment('- Test case 3 is failed.\n').
test_case_SD4(G) :- (not(similar_distributions(c110, c107)))
			-> G is 2, write_comment('- Test case 4 is successful.\n'); G is 0, write_comment('- Test case 4 is failed.\n').
test_case_SD5(G) :- (similar_distributions(c110, c96), not(similar_distributions(c96, c110)))
			-> G is 2, write_comment('- Test case 5 is successful.\n'); G is 0, write_comment('- Test case 5 is failed.\n').
test_case_SD6(G) :- (similar_distributions(c85, c58), not(similar_distributions(c58, c85)))
			-> G is 2, write_comment('- Test case 6 is successful.\n'); G is 0, write_comment('- Test case 6 is failed.\n').
test_case_SD7(G) :- (findall(NAME_2, similar_distributions(c220, NAME_2), ALL_NAMES), equal(ALL_NAMES, [c239]) )
			-> G is 2, write_comment('- Test case 7 is successful.\n'); G is 0, write_comment('- Test case 7 is failed.\n').
test_case_SD8(G) :- (findall(NAME_1, similar_distributions(NAME_1, _), ALL_NAMES), equal(ALL_NAMES, [c9,c35,c29,c41,c85,c65,c108,c110,c191,c163,c163,c163,c156,c156,c154,c224,c220]) )
			-> G is 5, write_comment('- Test case 8 is successful.\n'); G is 0, write_comment('- Test case 8 is failed.\n').
test_case_SD9(G) :- (similar_distributions(c35, c33), not(similar_distributions(c33, _)))
			-> G is 2, write_comment('- Test case 9 is successful.\n'); G is 0, write_comment('- Test case 9 is failed.\n').
test_case_SD10(G) :- (findall(NAME_2, similar_distributions(_, NAME_2), ALL_NAMES), equal(ALL_NAMES, [c11,c33,c37,c49,c58,c73,c106,c96,c136,c156,c154,c152,c154,c152,c152,c228,c239]) )
			-> G is 5, write_comment('- Test case 10 is successful.\n'); G is 0, write_comment('- Test case 10 is failed.\n').

testSD(0) :-
    not(current_predicate(similar_distributions/2)),
    !,
	write_comment('- Predicate similar_distributions/2 is not found.\n').

testSD(Grade) :-
    TimeLimit is 2,
	catch(call_with_time_limit(TimeLimit, test_case_SD1(G1)), _, (G1 is 0, write_comment('- Test case 1 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD2(G2)), _, (G2 is 0, write_comment('- Test case 2 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD3(G3)), _, (G3 is 0, write_comment('- Test case 3 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD4(G4)), _, (G4 is 0, write_comment('- Test case 4 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD5(G5)), _, (G5 is 0, write_comment('- Test case 5 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD6(G6)), _, (G6 is 0, write_comment('- Test case 6 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD7(G7)), _, (G7 is 0, write_comment('- Test case 7 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD8(G8)), _, (G8 is 0, write_comment('- Test case 8 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD9(G9)), _, (G9 is 0, write_comment('- Test case 9 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_SD10(G10)), _, (G10 is 0, write_comment('- Test case 10 timed out.\n'))),
	Grade is G1 + G2 + G3 + G4 + G5 + G6 + G7 + G8 + G9 + G10.




% === Test cases for proton_ionization/3 ===
test_case_PI1(G) :- (not(proton_ionization(cX, 1, _)))
			-> G is 5, write_comment('- Test case 1 is successful.\n'); G is 0, write_comment('- Test case 1 is failed.\n').
test_case_PI2(G) :- (proton_ionization(c11, 8, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8, 3])
			-> G is 5, write_comment('- Test case 2 is successful.\n'); G is 0, write_comment('- Test case 2 is failed.\n').
test_case_PI3(G) :- (proton_ionization(c9, 1, [4, 5]), not(proton_ionization(c9, 1, [3, 6])))
			-> G is 5, write_comment('- Test case 3 is successful.\n'); G is 0, write_comment('- Test case 3 is failed.\n').
test_case_PI4(G) :- (proton_ionization(c9, 2, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [5, 4])
			-> G is 5, write_comment('- Test case 4 is successful.\n'); G is 0, write_comment('- Test case 4 is failed.\n').
test_case_PI5(G) :- (proton_ionization(c9, 6, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8, 1])
			-> G is 5, write_comment('- Test case 5 is successful.\n'); G is 0, write_comment('- Test case 5 is failed.\n').
test_case_PI6(G) :- (proton_ionization(c58, 6, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8,1,1,4,5,4,6,5,4,3,3,4,4,3,3])
			-> G is 5, write_comment('- Test case 6 is successful.\n'); G is 0, write_comment('- Test case 6 is failed.\n').
test_case_PI7(G) :- (proton_ionization(c58, 16, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8,1,1,4,5,4,6,5,4,3,3,4,4,3,3])
			-> G is 5, write_comment('- Test case 7 is successful.\n'); G is 0, write_comment('- Test case 7 is failed.\n').
test_case_PI8(G) :- (proton_ionization(c220, 6, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8,8,6,5,4,5,5,4,4,3,2,1,1,2,2,3,4,3,4,3,4,4,4,5,5,5,5,4,4,5,4,4,5,4,5,4,5,4,5,4,5,6,5,4,5,4,5,6,5,4,3,2])
			-> G is 5, write_comment('- Test case 8 is successful.\n'); G is 0, write_comment('- Test case 8 is failed.\n').
test_case_PI9(G) :- (proton_ionization(c58, 16, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8,1,1,4,5,4,6,5,4,3,3,4,4,3,3])
			-> G is 5, write_comment('- Test case 9 is successful.\n'); G is 0, write_comment('- Test case 9 is failed.\n').
test_case_PI10(G) :- (proton_ionization(c154, 3, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [7,5,6,5,3,5,4,5,4,5,4,4,3,7,3,4,4,3,3,4,4,2,3,5,4,5,4,5,4,4,5,4,5,6,4])
			-> G is 5, write_comment('- Test case 10 is successful.\n'); G is 0, write_comment('- Test case 10 is failed.\n').
test_case_PI11(G) :- (proton_ionization(c107, 1, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [3,5,1,5,2,6,6,8,6,6,5,4,4,3,6,3,6,5,6,6,7,4])
			-> G is 5, write_comment('- Test case 11 is successful.\n'); G is 0, write_comment('- Test case 11 is failed.\n').
test_case_PI12(G) :- (proton_ionization(c29, 2, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [4,3,4,3,4,3,3,4,1])
			-> G is 5, write_comment('- Test case 12 is successful.\n'); G is 0, write_comment('- Test case 12 is failed.\n').
test_case_PI13(G) :- (proton_ionization(c41, 8, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8,8,8,7,3,7])
			-> G is 5, write_comment('- Test case 13 is successful.\n'); G is 0, write_comment('- Test case 13 is failed.\n').
test_case_PI14(G) :- (proton_ionization(c247, 5, FINAL_ELECTRON_LIST), !, FINAL_ELECTRON_LIST == [8,4,5,5,4,3,5,6,5,1,5,7,6,7,7,6,6,6,2,5,4,5,4,5,7,4,5,6,5,5,7,5,6,6,1,5,6,6,6,5,5,6,1,5,4,5,6,7,2])
			-> G is 5, write_comment('- Test case 14 is successful.\n'); G is 0, write_comment('- Test case 14 is failed.\n').

testPI(0) :-
    not(current_predicate(proton_ionization/3)),
    !,
	write_comment('- Predicate proton_ionization/3 is not found.\n').

testPI(Grade) :-
    TimeLimit is 2,
	catch(call_with_time_limit(TimeLimit, test_case_PI1(G1)), _, (G1 is 0, write_comment('- Test case 1 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI2(G2)), _, (G2 is 0, write_comment('- Test case 2 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI3(G3)), _, (G3 is 0, write_comment('- Test case 3 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI4(G4)), _, (G4 is 0, write_comment('- Test case 4 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI5(G5)), _, (G5 is 0, write_comment('- Test case 5 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI6(G6)), _, (G6 is 0, write_comment('- Test case 6 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI7(G7)), _, (G7 is 0, write_comment('- Test case 7 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI8(G8)), _, (G8 is 0, write_comment('- Test case 8 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI9(G9)), _, (G9 is 0, write_comment('- Test case 9 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI10(G10)), _, (G10 is 0, write_comment('- Test case 10 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI11(G11)), _, (G11 is 0, write_comment('- Test case 11 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI12(G12)), _, (G12 is 0, write_comment('- Test case 12 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI13(G13)), _, (G13 is 0, write_comment('- Test case 13 timed out.\n'))),
	catch(call_with_time_limit(TimeLimit, test_case_PI14(G14)), _, (G14 is 0, write_comment('- Test case 14 timed out.\n'))),
	Grade is G1 + G2 + G3 + G4 + G5 + G6 + G7 + G8 + G9 + G10 + G11 + G12 + G13 + G14.



testLab :-
    write_comment('Testing similar_distributions/2 predicate...\n'),
    testSD(SD_G),
	write_comment('Testing proton_ionization/3 predicate...\n'),
	testPI(PI_G),
    Grade is SD_G + PI_G,
    write(Grade).


runGrader(File) :-
	use_module(File),
	catch(call_with_time_limit(60, testLab), _, _).
