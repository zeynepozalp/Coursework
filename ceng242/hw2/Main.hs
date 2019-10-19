module Main where

import Lib
import Hw2

plusHead = createHead "plus"
timesHead = createHead "times"
negateHead = createHead "negate"
lenHead = createHead "len"
catHead = createHead "cat"

numHead = createHead "num"
strHead = createHead "str"

createHead::String->AST->AST->AST
createHead x = ASTNode (ASTSimpleDatum x)

createLetHead::String->AST-> AST -> AST
createLetHead x = ASTNode (ASTLetDatum x)

createVar::String->AST
createVar x = ASTNode (ASTSimpleDatum x) EmptyAST EmptyAST

createNum::String->AST
createNum x = numHead (createHead x EmptyAST EmptyAST) EmptyAST

createStr::String->AST
createStr x = strHead (createHead x EmptyAST EmptyAST) EmptyAST

circularDef = createLetHead "x" (plusHead (createVar "x") (createNum "1")) (createVar "x")

letNoOp = createLetHead "x" (createNum "13") (createVar "x")
letButNoUse = createLetHead "x" (plusHead (createNum "15") (createNum "17")) (createNum "3")
letUsed = createLetHead "x" (createNum "15") (plusHead (createNum "14") (createVar "x"))
letNotDeclared = plusHead (createNum "14") (createVar "x")
letOverwrite = createLetHead "x" (createNum "15") (createLetHead "x" (createNum "20") (createVar "x"))
letInLet = createLetHead "x" (createLetHead "y" (createNum "15") (createVar "y")) (createVar "x")
letInExp = createLetHead "x" (timesHead (createNum "3") (createNum "4")) (plusHead (createLetHead "y" (negateHead (createNum "14") EmptyAST) (timesHead (createVar "x") (createVar "y"))) (createVar "x"))
a = createLetHead "x" (createNum "3") (createLetHead "y" (createStr "a") (plusHead (createVar "x") (createVar "y")))
b = createNum "3" 

letNoOpError = createLetHead "x" (createNum "ab") (createVar "x")
letButNoUseError = createLetHead "x" (createNum "ab") (createNum "15")
letUsedErrorLeft = createLetHead "x" (plusHead (createNum "14") (createNum "cd")) (createNum "5")
letUsedErrorRight = createLetHead "x" (plusHead (createNum "14") (createNum "13")) (plusHead (createNum "ab") (createVar "x"))
letWrongType = createLetHead "x" (createStr "abc") (plusHead (createNum "15") (createVar "x"))
letNotInScopeError = createLetHead "x" (createNum "15") (plusHead (createVar "x") (createVar "y"))

nestedOpPlus = createLetHead "x" (createNum "15") (plusHead (createNum "12") (plusHead (createNum "27") (createVar "x")))
nestedOpTimes = createLetHead "x" (createNum "2") (timesHead (createVar "3") (timesHead (createVar "x") (createNum "4")))

plusValid = plusHead (createNum "13") (createNum "4")
plusWrongType =  plusHead (createNum "15") (createStr "16")
plusWrongType2 =  plusHead (createStr "15") (createNum "16")
plusNoArgument = plusHead EmptyAST EmptyAST
plusOneArgument = plusHead (createNum "14") EmptyAST
plusOneWrongTypeArgument = plusHead (createStr "13") EmptyAST
plusOneWrongFormArgument = plusHead (createNum "ab") EmptyAST

timesValid = timesHead (createNum "13") (createNum "2")
timesWrongType = timesHead (createNum "13") (createStr "2")
timesWrongType2 = timesHead (createStr "abc") (createNum "2")
timesNoArgument = timesHead EmptyAST EmptyAST
timesOneArgument = timesHead (createNum "13") EmptyAST
timesOneWrongTypeArgument = timesHead (createStr "15") EmptyAST
timesOneWrongFormArgument = timesHead (createNum "abc") EmptyAST

negateValid = negateHead (createNum "-5") EmptyAST
negateWrongType = negateHead (createStr "abc") EmptyAST
negateTwoArguments = negateHead (createNum "3") (createNum "5")
negateNoArgument = negateHead EmptyAST EmptyAST
negateWrongForm = negateHead (createNum "abc") EmptyAST

lenValid = lenHead (createStr "15") EmptyAST
lenWrongType = lenHead (createNum "15") EmptyAST
lenTwoArguments = lenHead (createStr "abc") (createStr "def")
lenNoArgument = lenHead EmptyAST EmptyAST
lenWrongForm = lenHead (createNum "13") EmptyAST

catValid = catHead (createStr "abc") (createStr "def")
catWrongType = catHead (createStr "abc") (createNum "13")
catWrongType2 = catHead (createNum "13") (createStr "abc")
catNoArgument = catHead EmptyAST EmptyAST
catOneArgument = catHead (createStr "abc") EmptyAST
catOneWrongTypeArgument = catHead EmptyAST (createNum "13")
catOneWrongTypeArgument2 = catHead (createNum "13") EmptyAST

main :: IO ()
main = do {
  print (eagerEvaluation letNoOp);
  print (eagerEvaluation letButNoUse);
  print (eagerEvaluation letUsed);
  print (eagerEvaluation letOverwrite);
  print (eagerEvaluation letInLet);
  print (eagerEvaluation letInExp);

  print (normalEvaluation letNoOp);
  print (normalEvaluation letButNoUse);
  print (normalEvaluation letUsed);
  print (normalEvaluation letOverwrite);
  print (normalEvaluation letInLet);
  print (normalEvaluation letInExp);
}
