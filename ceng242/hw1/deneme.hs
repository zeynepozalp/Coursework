module Hw1 where

type Mapping = [(String, String, String)]
data AST = EmptyAST | ASTNode String AST AST deriving (Show, Read)

--writeExpression :: (AST, Mapping) -> String
-- evaluateAST :: (AST, Mapping) -> (AST, String)
-- DO NOT MODIFY OR DELETE THE LINES ABOVE --
-- IMPLEMENT writeExpression and evaluateAST FUNCTION ACCORDING TO GIVEN SIGNATURES --

changeAST :: AST -> Mapping -> AST
changeAST EmptyAST _ = EmptyAST
changeAST ast [] = ast
changeAST (ASTNode x l r) map
  | (x == fstTuple h) = ASTNode (sndTuple h) (ASTNode (trdTuple h) l r) EmptyAST
  | otherwise = newAST (ASTNode x l r) (tail map)
  where h = (head map)

newAST :: AST -> Mapping -> AST
newAST EmptyAST _ = EmptyAST
newAST ast [] = ast
newAST (ASTNode x l r) map
  | (x == (fstTuple h)) = ASTNode (sndTuple h) (ASTNode (trdTuple h) (changeAST l map) (changeAST r map)) EmptyAST
  | otherwise = ASTNode x (changeAST l map) (changeAST r map)
  where h = (head map)
