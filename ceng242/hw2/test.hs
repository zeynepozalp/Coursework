import Hw2


help = putStrLn "try \"test 1\" for isNumber, \"test 2\" for eagerEvaluation and \"test 3\" for normalEvaluation. \n\
\try \"test 29\" for eagerEvaluation with erroneous inputs, and \"test 39\" for normalEvaluation with erroneous inputs."


checker' :: ([Bool], [Bool], Int) -> String

checker'' :: ([ASTResult], [ASTResult], Int) -> String




checker' (l1, l2, x) | x == (length l1) = ""




checker' (l1, l2, x) | (length l1) /= (length l2) = "ERROR: input and output numbers don't match!"
                     | (length l1) == 0 = "nothing to test"
                     | x == (length l1) = ""
                     | (l1!!x == l2!!x) = "test case " ++ (show x) ++ " passed :D \n"  ++ checker' (l1, l2, (x+1))
                     | (l1!!x /= l2!!x) = "test case " ++ (show x) ++ " failed :( \n" ++ checker' (l1, l2, (x+1))

checker'' (l1, l2, x) | (length l1) /= (length l2) = "ERROR: input and output numbers don't match!"
                      | (length l1) == 0 = "nothing to test"
                      | x == (length l1) = ""
                      | ((show (l1!!x)) == (show (l2!!x))) = "test case " ++ (show x) ++ " passed :D \n"  ++ checker'' (l1, l2, (x+1))
                      | ((show (l1!!x)) /= (show (l2!!x))) = "test case " ++ (show x) ++ " failed :( \n" ++ checker'' (l1, l2, (x+1))


--you may manually add or remove test cases here
isNumIn = ["", "123", "abc", "123a456", "-123", "123-", "123.4", " 12", "12 ", "0x1b"]
isNumOut = [False, True, False, False, True, False, False, False, False, False]

eagerEvalIn = [
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST)))),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "1") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "len") (ASTNode (ASTSimpleDatum "cat") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "CE") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "NG") EmptyAST EmptyAST) EmptyAST)) EmptyAST)) EmptyAST) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST)))),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTLetDatum "y") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST)))) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTLetDatum "z") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "z") EmptyAST EmptyAST))))),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "13") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST)),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "15") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "17") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST)),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "15") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "20") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTLetDatum "y") (ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "14") EmptyAST EmptyAST) EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST))) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))),
               (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "15") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "12") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "27") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))))]
eagerEvalOut = [
                (ASTJust ("14","num",2)),
                (ASTJust ("8","num",2)),
                (ASTJust ("288","num",7)),
                (ASTJust ("88","num",5)),
                (ASTJust ("13","num",0)),
                (ASTJust ("3","num",1)),
                (ASTJust ("20","num",0)),
                (ASTJust ("-156","num",4)),
                (ASTJust ("54","num",2))]

normalEvalIn = [
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))),
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST)))),
                 (ASTNode (ASTLetDatum "x") ((ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "1") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "len") (ASTNode (ASTSimpleDatum "cat") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "CE") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "NG") EmptyAST EmptyAST) EmptyAST)) EmptyAST)) EmptyAST)) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST)))),
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTLetDatum "y") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST)))) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTLetDatum "z") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "z") EmptyAST EmptyAST))))),
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "13") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST)),
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "15") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "17") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST)),
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "15") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "20") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))),
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTLetDatum "y") (ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "14") EmptyAST EmptyAST) EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST))) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))),
                 (ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "15") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "12") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "27") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))))]
normalEvalOut = [
                 (ASTJust ("14","num",3)),
                 (ASTJust ("8","num",1)),
                 (ASTJust ("288","num",17)),
                 (ASTJust ("88","num",9)),
                 (ASTJust ("13","num",0)),
                 (ASTJust ("3","num",0)),
                 (ASTJust ("20","num",0)),
                 (ASTJust ("-156","num",5)),
                 (ASTJust ("54","num",2))]

--eager and normal evaluation must have same outputs for errors, as stated in error_handling.txt
funErrIn = [
            (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "") EmptyAST EmptyAST) EmptyAST),
            (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "CENG242") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "test") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "abc") EmptyAST EmptyAST) EmptyAST),
            (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123a456") EmptyAST EmptyAST) EmptyAST),
            (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "abc") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123a456") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "123") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "456") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "123") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "456") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "456") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "cat") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "456") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "cat") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "abc") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "13") EmptyAST EmptyAST) EmptyAST)),
            (ASTNode (ASTSimpleDatum "len") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123") EmptyAST EmptyAST) EmptyAST) EmptyAST),
            (ASTNode (ASTSimpleDatum "len") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123x") EmptyAST EmptyAST) EmptyAST) EmptyAST),
            (ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "123x") EmptyAST EmptyAST) EmptyAST) EmptyAST),
            ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTLetDatum "y") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "a") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST))),
            (ASTNode (ASTSimpleDatum "negate") (ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "123x") EmptyAST EmptyAST) EmptyAST) EmptyAST)
            ]

funErrOut = [
             (ASTError "the value '' is not a number!"),
             (ASTError "the value 'CENG242' is not a number!"),
             (ASTError "the value 'abc' is not a number!"),
             (ASTError "the value '123a456' is not a number!"),
             (ASTError "the value 'abc' is not a number!"),
             (ASTError "the value '123a456' is not a number!"),
             (ASTError "plus operation is not defined between str and num!"),
             (ASTError "plus operation is not defined between str and str!"),
             (ASTError "times operation is not defined between num and str!"),
             (ASTError "cat operation is not defined between num and str!"),
             (ASTError "cat operation is not defined between str and num!"),
             (ASTError "len operation is not defined on num!"),
             (ASTError "the value '123x' is not a number!"),
             (ASTError "the value '123x' is not a number!"),
             (ASTError "plus operation is not defined between num and str!"),
             (ASTError "negate operation is not defined on str!")
             ]


test 1 = putStrLn $ "testing isNumber.."
         ++"\n"++  checker' (isNumOut, (map isNumber isNumIn), 0)

test 2 = putStrLn $ "testing eagerEvaluation.."
         ++"\n"++  checker'' (eagerEvalOut, (map eagerEvaluation eagerEvalIn), 0)

test 3 = putStrLn $ "testing normalEvaluation.."
         ++"\n"++  checker'' (normalEvalOut, (map normalEvaluation normalEvalIn), 0)

test 29 = putStrLn $ "testing eagerEvaluation with erroneous inputs.."
          ++"\n"++  checker'' (funErrOut, (map eagerEvaluation funErrIn), 0)

test 39 = putStrLn $ "testing normalEvaluation with erroneous inputs.."
          ++"\n"++  checker'' (funErrOut, (map normalEvaluation funErrIn), 0)

test _ = help
