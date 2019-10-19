newAST :: (AST, Integer) -> (AST, Integer)
newAST (EmptyAST, i) = (EmptyAST, i)
newAST (ast@(ASTNode x l r), i) = case x of
  ASTSimpleDatum s -> (ast, i)
  ASTLetDatum s -> ((helper2 (r, i) s a), b)
  where a = fst (helper1 (l, i))
        b = snd (helper1 (l, i))

helper1 :: (AST, Integer) -> (String, Integer)
helper1 (EmptyAST, i) = ("",i)
helper1 (ast@(ASTNode x l@(ASTNode (ASTSimpleDatum s1) l2 l3) r), i) = case x of
  ASTLetDatum s -> helper1 (fst (newAST (ast, i)), i)
  ASTSimpleDatum s
    | (s=="plus") -> (show ((read (fst (helper1 (newAST (l, i))))::Int) + (read (fst (helper1 (newAST (r, i))))::Int)), i+1)
    | (s=="times") -> (show ((read (fst (helper1 (newAST (l, i))))::Int) * (read (fst (helper1 (newAST (r, i))))::Int)), i+1)
    | (s=="negate") -> (show (-(read (fst (helper1 (newAST (l, i))))::Int)), i+1)
    | (s=="cat") -> ((fst (helper1 (newAST (l, i)))) ++ (fst (helper1 (newAST (r, i)))), i+1)
    | (s=="len") -> (show (length (fst (helper1 (newAST (l, i))))), i+1)
    | (s=="num") -> (show (read s1::Int), i)
    | (s=="str") -> (s1, i)
    | otherwise -> ("", 0)

helper2 :: (AST, Integer) -> String -> String -> AST
helper2 (EmptyAST, i) _ _ = (EmptyAST, i)
helper2 (ast@(ASTNode x l@(ASTNode (ASTSimpleDatum s1) l2 l3) r), i) name ev = case x of
  ASTLetDatum s -> helper2 (fst (newAST (ast, i))) name ev
  ASTSimpleDatum s
    | (s=="plus") -> (show ((read (fst (helper1 (newAST (l, i))))::Int) + (read (fst (helper1 (newAST (r, i))))::Int)), i+1)

helper1 :: AST -> (Integer, Integer)
helper1 EmptyAST = (0,0)
helper1 ast@(ASTNode s l@(ASTNode s1 l2 l3) r@(ASTNode s2 l2 r2)) = case x of
  ASTLetDatum s = helper1 (fst (newAST ast))
  ASTSimpleDatum s = case x1 of
    ASTLetDatum s1 = case x2 of
      ASTLetDatum s2 = helper1 (ASTNode x (fst (newAST l)) (fst (newAST r)))
      ASTSimpleDatum s2 = helper1 (ASTNode x (fst (newAST l)) r)
    ASTSimpleDatum s1 = case x2 of
      ASTLetDatum s2 = helper1 (ASTNode x l (fst (newAST r)))
      ASTSimpleDatum s2 =
      | (s=="plus") =

      newASTe :: AST -> AST
      newASTe EmptyAST = EmptyAST
      newASTe ast@(ASTNode x l r) = case x of
        ASTSimpleDatum s -> ASTNode x (newASTe l) (newASTe r)
        ASTLetDatum s -> changeAST nev((newASTe l, 0)) (newASTe r) s

      changeASTe :: (String, Int) -> AST -> String -> (AST, Int)
      changeASTe _ EmptyAST _ = EmptyAST
      changeASTe _ x "" = x
      changeASTe (sonuc, i) (ASTNode d@(ASTSimpleDatum s) l r) name = if (s==name) then (ast) else (ASTNode d (changeASTe ast l name) (changeASTe ast r name)) where
        ast = if isNumber sonuc then ((ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum sonuc) EmptyAST EmptyAST) EmptyAST), i) else ((ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum sonuc) EmptyAST EmptyAST) EmptyAST),i)
