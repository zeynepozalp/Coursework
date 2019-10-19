module Hw1 where

type Mapping = [(String, String, String)]
data AST = EmptyAST | ASTNode String AST AST deriving (Show, Read)

writeExpression :: (AST, Mapping) -> String
evaluateAST :: (AST, Mapping) -> (AST, String)
-- DO NOT MODIFY OR DELETE THE LINES ABOVE --
-- IMPLEMENT writeExpression and evaluateAST FUNCTION ACCORDING TO GIVEN SIGNATURES --

fstTuple :: (String, String, String) -> String
fstTuple (x,_,_) = x
sndTuple :: (String, String, String) -> String
sndTuple (_,x,_) = x
trdTuple :: (String, String, String) -> String
trdTuple (_,_,x) = x

conMap :: Mapping -> String
conMap [x]
  | sndTuple x == "num" = fstTuple x ++ "=" ++ trdTuple x
  | sndTuple x == "str" = fstTuple x ++ "=\"" ++ trdTuple x ++ "\""
  | otherwise =""
conMap map = conMap [(head map)] ++ ";" ++ conMap (tail map)

writeAST :: String -> String
writeAST x
  | x == "plus" = "+"
  | x == "times" = "*"
  | x == "cat" = "++"
  | otherwise = ""

conAST :: AST -> String
conAST EmptyAST = ""
conAST (ASTNode x EmptyAST EmptyAST) = x
conAST (ASTNode "negate" x EmptyAST) = "(-" ++ conAST x ++ ")"
conAST (ASTNode "len" x EmptyAST) = "(length " ++ conAST x ++ ")"
conAST (ASTNode x (ASTNode y _ _) EmptyAST)
  | x == "num" = y
  | x == "str" = "\"" ++ y ++ "\"" --show y yazabilirim?
  | otherwise = ""
conAST (ASTNode x l r) = "(" ++ conAST l ++ writeAST x ++ conAST r ++ ")"

writeExpression (ast, map) = if map==[] then (conAST ast) else ("let " ++ conMap map ++ " in " ++ conAST ast)

changeAST :: AST -> (String,String,String) -> AST
changeAST EmptyAST _ = EmptyAST
changeAST (ASTNode x l r) (a,b,c)
  | (x==a) = ASTNode b (ASTNode c (changeAST l (a,b,c)) (changeAST r (a,b,c))) EmptyAST
  | otherwise = ASTNode x (changeAST l (a,b,c)) (changeAST r (a,b,c))

newAST :: AST -> Mapping -> AST
newAST ast [] = ast
newAST (ASTNode x l r) map = newAST (changeAST (ASTNode x l r) (head map)) (tail map)

evaluateAST (ast, map) = (nast, (helper nast)) where nast = newAST ast map

helper :: AST -> String
helper (ASTNode x (ASTNode a b c) r)
  | (x=="plus") =  show ((read (helper l)::Int) + (read (helper r)::Int))
  | (x=="times") = show ((read (helper l)::Int) * (read (helper r)::Int))
  | (x=="negate") = show (-(read (helper l)::Int))
  | (x=="cat") = (helper l) ++ (helper r)
  | (x=="len") = show (length (helper l))
  | (x=="num") = show (read a::Int)
  | (x=="str") = a
  | otherwise = ""
  where l=(ASTNode a b c)
