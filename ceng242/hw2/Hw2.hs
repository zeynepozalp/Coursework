module Hw2 where

data ASTResult = ASTError String | ASTJust (String, String, Int) deriving (Show, Read)
data ASTDatum = ASTSimpleDatum String | ASTLetDatum String deriving (Show, Read)
data AST = EmptyAST | ASTNode ASTDatum AST AST deriving (Show, Read)

isNumber :: String -> Bool
eagerEvaluation :: AST -> ASTResult
normalEvaluation :: AST -> ASTResult
-- DO NOT MODIFY OR DELETE THE LINES ABOVE --
-- IMPLEMENT isNumber, eagerEvaluation and normalEvaluation FUNCTIONS ACCORDING TO GIVEN SIGNATURES --

fstTuple :: (AST, Int, [String]) -> AST
fstTuple (x,_,_) = x
sndTuple :: (AST, Int, [String]) -> Int
sndTuple (_,x,_) = x
trdTuple :: (AST, Int, [String]) -> [String]
trdTuple (_,_,x) = x

isNumber [] = False
isNumber [a]
  | [a]=="0" || [a]=="1" || [a]=="2" || [a]=="3" || [a]=="4" || [a]=="5" || [a]=="6" || [a]=="7" || [a]=="8" || [a]=="9" || [a]=="-" = True
  | otherwise = False
isNumber s
  | isTail (tail s) = False
  | otherwise = isNumber (tail s) && (isNumber [head s])

isTail :: String -> Bool
isTail [] = False
isTail [a]
  | [a]=="-" = True
  | otherwise = False
isTail s = isTail [head s] || isTail (tail s)

isIn :: [String] -> String -> Bool
isIn [] _ = False
isIn [a] b = if (a==b) then True else False
isIn s b = isIn [head s] b || isIn (tail s) b

takeData :: AST -> String
takeData EmptyAST = ""
takeData (ASTNode _ (ASTNode (ASTSimpleDatum x) _ _) _) = x
takeData (ASTNode (ASTSimpleDatum x) EmptyAST EmptyAST) = x

errorCheck :: AST -> String
errorCheck (ASTNode x EmptyAST EmptyAST) = ""
errorCheck (ASTNode (ASTSimpleDatum x) (ASTNode (ASTSimpleDatum l) _ _) EmptyAST)
  | (x=="num") && (not (isNumber l)) = "the value '" ++ l ++ "' is not a number!"
  | (x=="negate") && (l=="str") = "negate operation is not defined on str!"
  | (x=="len") && (l=="num") = "len operation is not defined on num!"
  | otherwise = ""
errorCheck (ASTNode (ASTSimpleDatum x) (ASTNode (ASTSimpleDatum l) _ _) (ASTNode (ASTSimpleDatum r) _ _))
  | (x=="plus" || x=="times") && (l=="str" || r=="str") = x ++ " operation is not defined between " ++ l ++ " and " ++ r ++ "!"
  | (x=="cat") && (l=="num" || r=="num") = x ++ " operation is not defined between " ++ l ++ " and " ++ r ++ "!"
  | otherwise = ""
errorCheck _ = ""

errorC :: AST -> String
errorC ast@(ASTNode x EmptyAST EmptyAST) = errorCheck ast
errorC (ASTNode x l EmptyAST)
  | not (errorCheck l == "") = errorCheck l
  | otherwise = errorCheck (ASTNode x l EmptyAST)
errorC (ASTNode x l r)
  | not (errorCheck l == "") = errorCheck l
  | not (errorCheck r == "") = errorCheck r
  | otherwise = errorCheck (ASTNode x l r)

newAST :: AST -> AST
newAST EmptyAST = EmptyAST
newAST ast@(ASTNode x l r) = case x of
  ASTSimpleDatum s -> ASTNode x (newAST l) (newAST r)
  ASTLetDatum s -> changeAST (newAST l) (newAST r) s

changeAST :: AST -> AST -> String -> AST
changeAST _ EmptyAST _ = EmptyAST
changeAST _ x "" = x
changeAST ast (ASTNode d@(ASTSimpleDatum s) l r) name = if (s==name) then (ast) else (ASTNode d (changeAST ast l name) (changeAST ast r name))

normalEvaluation ast
  | not (e == "") = ASTError e
  | not (e2 == "") = ASTError e2
  | otherwise = ASTJust (takeData (fst a), b , snd a) where
    nast = newAST ast
    a = neve (nast, 0, [])
    b = if isNumber (takeData (fst a)) then "num" else "str"
    e = errorC ast
    e2 = errorC nast

newASTe :: (AST, Int, [String]) -> (AST, Int, [String])
newASTe (EmptyAST, i, lst) = (EmptyAST, i, lst)
newASTe (ast@(ASTNode (ASTLetDatum s) l r), i, lst) = (fstTuple (changeASTe left fn fr s), (i + sndTuple (changeASTe left fn fr s) + sn + sndTuple right + sndTuple left), s:lst) where
        left = (newASTe (l, i, s:lst))
        right = (newASTe (r, i, s:lst))
        fl = fstTuple left
        fr = fstTuple right
        nast = neve (fl, i, s:lst)
        fn = fst nast
        sn = snd nast
newASTe (ast@(ASTNode x@(ASTSimpleDatum s) l r), i, lst) = (ASTNode x fl fr, i + sndTuple right + sndTuple left, lst) where
        left = (newASTe (l, i, s:lst))
        right = (newASTe (r, i, s:lst))
        fl = fstTuple left
        fr = fstTuple right
        nast = neve (fl, i, s:lst)
        fn = fst nast
        sn = snd nast

changeASTe :: (AST, Int, [String]) -> AST -> AST -> String -> (AST, Int, [String])
changeASTe (_, i, lst) _ EmptyAST _ = (EmptyAST, i, lst)
changeASTe (_, i, lst)  _ x "" = (x, i, lst)
changeASTe a@(ast, i, lst) sonuc (ASTNode d@(ASTSimpleDatum s) l r) name = if (s==name) then (sonuc, i, lst) else ((ASTNode d (fstTuple (changeASTe a sonuc l name)) (fstTuple (changeASTe a sonuc r name))), i+(sndTuple (changeASTe a sonuc l name))+(sndTuple (changeASTe a sonuc r name)), lst)

neve :: (AST, Int, [String]) -> (AST, Int)
neve (EmptyAST, i, lst) = (EmptyAST, i)
neve (ast@(ASTNode (ASTSimpleDatum x) l EmptyAST), i, lst)
  | (x=="num" || x=="str") = (ast, i)
  | (x=="negate") = (nastNegate, snl+1+i)
  | (x=="len") = (nastLen, snl+1+i)
  where nl = (neve (l,0,lst))
        snl = snd nl
        nastNegate = ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum (show (-(read (takeData (fst nl))::Int)))) EmptyAST EmptyAST) EmptyAST
        nastLen = ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum (show (length (takeData (fst (neve (l,i+1,lst))))))) EmptyAST EmptyAST) EmptyAST
neve (ast@(ASTNode (ASTSimpleDatum x) l@(ASTNode (ASTSimpleDatum a) b c) r@(ASTNode (ASTSimpleDatum d) e f)), i, lst)
  | (isIn lst a) || (isIn lst d) = (ast, i)
  | (x=="plus") = (nastPlus, snl+snr+1+i)
  | (x=="times") = (nastTimes, snl+snr+1+i)
  | (x=="cat") = (nastCat, snl+snr+1+i)
  | otherwise = (EmptyAST, i)
  where nl = (neve (l,0,lst))
        nr = (neve (r,0,lst))
        snl = snd nl
        snr = snd nr
        nastPlus = ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum (show ((read (takeData (fst nl))::Int) + (read (takeData (fst nr))::Int)))) EmptyAST EmptyAST) EmptyAST
        nastTimes = ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum (show ((read (takeData (fst nl))::Int) * (read (takeData (fst nr))::Int)))) EmptyAST EmptyAST) EmptyAST
        nastCat = ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum ((takeData (fst nl)) ++ (takeData (fst nr)))) EmptyAST EmptyAST) EmptyAST
neve (ast@(ASTNode (ASTSimpleDatum x) EmptyAST EmptyAST), i, lst) = (ast, i)

eagerEvaluation ast
  | not (e == "") = ASTError e
  | not (e2 == "") = ASTError e2
  | otherwise = ASTJust (takeData (fst a), b,  snd a)
  where e = errorC ast
        e2 = errorC (fst nast)
        new = newASTe (ast, 0, [])
        nast = (fstTuple new, sndTuple new)
        a = neve (fst nast, snd nast, [])
        b = if isNumber (takeData (fst a)) then "num" else "str"

a= ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "a") EmptyAST EmptyAST) EmptyAST
