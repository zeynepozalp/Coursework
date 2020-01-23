class Clause:
    def __init__(self, lst, gflag):
        self.explst = lst
        self.gflag = gflag
    def __repr__(self):
        s = str(self.explst[0])
        for i in range(1,len(self.explst)):
            s = s + "+" + str(self.explst[i])
        return s

class Expr:
    def __init__(self, pred, neg, arglst):
        self.pred = pred
        self.neg = neg
        self.arglst = arglst
    def negate(self):
        if(self.neg):
            return Expr(self.pred, 0, self.arglst)
        else:
            return Expr(self.pred, 1, self.arglst)
    def __repr__(self):
        flag=0
        s=self.pred+"("
        for arg in self.arglst:
            if flag == 1:
                s=s+","+str(arg)
            else:
                s=s+str(arg)
            flag=1
        s=s+")"
        if (self.neg == 1):
            s="~"+s
        return s
    def __eq__(self, other):
        l1 = len(self.arglst)
        l2 = len(other.arglst)
        if self.pred == other.pred and self.neg==other.neg and l1==l2:
            for i in range(l1):
                if not self.arglst[i]==other.arglst[i]:
                    return False
            return True
        else:
            return False

def makeExpr(s):
    neg = 0
    pred = ""
    arglst = []
    if s[0] == "~":
        neg = 1
    for i in range(1, len(s)):
        if (s[i] == "("):
            pred = s[neg:i]
            argstr = s[i+1:len(s)-1]
            arglst = argstr.split(",")
            break
    return Expr(pred, neg, arglst)

def stringToClause(s):
    closed=True
    level=0
    clauses=[]
    start_idx=0
    end_idx=0
    for c in s:
        if c == "(":
            closed=False
            level=level+1
        elif c == ")":
            level=level-1
            if level == 0:
                closed=True
        if (closed and c == "+"):
            clauses=clauses+[makeExpr(s[start_idx:end_idx])]
            start_idx=end_idx+1
        elif (closed and end_idx+1 == len(s)):
            clauses=clauses+[makeExpr(s[start_idx:end_idx+1])]
            start_idx=end_idx
        end_idx=end_idx+1
    return clauses

def isConst(s):
    if isinstance(s, Expr):
        return False
    return s[0].isupper()

def isVar(s):
    if isinstance(s,Expr):
        return False
    if s[0].islower() and ("(" not in s and ")" not in s):
        return True
    else:
        return False

def isFunct(s):
    return not(isConst(s) or isVar(s))

def addClauses(c1,c2):
    newexps=list(set(c1.explst+c2.explst))
    if(c1.gflag or c2.gflag):
        return Clause(newexps, 1)
    else:
        return Clause(newexps, 0)


def unify(exp1, exp2, subs):
    if subs==None:
        return None
    elif exp1.pred==exp2.pred and exp1.neg==exp2.neg and len(exp1.arglst)==len(exp2.arglst):
        for i in range(0,len(exp1.arglst)):
            arg1 = exp1.arglst[i]
            arg2 = exp2.arglst[i]
            if isConst(arg1) and isConst(arg2):
                if arg1==arg2:
                    subs[arg1]=arg2
            elif isVar(arg1):
                if isConst(arg2) or isVar(arg2) or isFunct(arg2):
                    subs[arg1]=arg2
            elif isVar(arg2):
                if isConst(arg1) or isFunct(arg1):
                    subs[arg2]=arg1
            elif isinstance(arg1, Expr) and isinstance(arg2,Expr):
                unify(arg1, arg2, subs)
                if subs == None:
                    return None
            else:
                return None
    else:
        return None

def applySubsExpr(exp, subs):
    myargs=[]
    for arg in exp.arglst:
        if isinstance(arg, Expr):
            arg=applySubsExpr(arg, subs)
            myargs.append(arg)
        elif isVar(arg) and (arg in subs):
            arg=subs[arg]
            myargs.append(arg)
        else:
            myargs.append(arg)
    return Expr(exp.pred, exp.neg, myargs)


def applySubs(c1, subs):
    if subs=={}:
        return
    c1newexp = []
    for exp in c1.explst:
        newargs = []
        for arg in exp.arglst:
            if isVar(arg) and (arg in subs):
                arg=subs[arg]
                newargs.append(arg)
            elif isinstance(arg, Expr):
                arg = applySubsExpr(arg, subs)
                newargs.append(arg)
            else:
                newargs.append(arg)
        exp = Expr(exp.pred, exp.neg, newargs)
        c1newexp.append(exp)
    return c1newexp

def isTaut(c):
    exps = c.explst
    n = len(exps)
    pairs = [(exps[i], exps[j]) for i in range(n) for j in range(i+1,n)]
    for (e1, e2) in pairs:
        if e1.pred == e2.pred and e1.neg!=e2.neg and e1.arglst == e2.arglst:
            return True
    return False

def elimTaut(KB):
    for c in KB:
        if(isTaut(c)):
            KB.remove(c)
    return KB

def isSubset(c1, c2):
    l = len(c1.explst)
    count = 0
    for exp1 in c1.explst:
        for exp2 in c2.explst:
            if exp1==exp2:
                count+=1
    if count==l:
        return True
    else:
        return False

def elimSubs(KB):
    #c1 subsumes c2 if there exists a subst. list S s.t. c1S is subset of c2. Delete c2.
    n = len(KB)
    pairs=[(KB[i], KB[j]) for i in range(n) for j in range(i+1, n)]
    for (c1, c2) in pairs:
        for exp1 in c1.explst:
            for exp2 in c2.explst:
                subs={}
                unify(exp1, exp2, subs)
                if subs != {}:
                    c1.explst = applySubs(c1, subs)
                    c2.explst = applySubs(c2, subs)
                    if isSubset(c1, c2):
                        KB.remove(c2)
                        break
                    elif isSubset(c2, c1):
                        KB.remove(c1)
    return KB

# before resolve, check if either c1.gflag=1 or c2.gflag=1
def resolve(c1, c2, opList): #c1=[~r(a)] c2=[~q(y),r(y)]
    subs={}
    operation=""
    r=""
    resolvents=[]
    for e1 in c1.explst: #e1=~r(a)
        for e2 in c2.explst: #e2=r(y)
            unify(e1, e2.negate(), subs)
            if subs:
                operation = str(c1)+"$"+str(c2)+"$"
                c1.explst.remove(e1)
                c2.explst.remove(e2)
                c1.explst = applySubs(c1, subs)
                c2.explst=applySubs(c2, subs)
                if c1.explst == [] and c2.explst == []:
                    r="empty"
                    c="empty"
                elif c1.explst == []:
                    if(c1.gflag):
                        c2.gflag=1
                    c=c2
                    r=str(c)
                elif c2.explst == []:
                    if (c2.gflag):
                        c1.gflag=1
                    c=c1
                    r=str(c)
                else:
                    c=addClauses(c1,c2)
                    r=str(c)
                resolvents.append(c)
    operation+=r
    if operation!="":
        opList.append(operation)
    return resolvents

def resolution(clauses, opList):
    newClauses=[]
    new=set()
    while True:
        clauses = elimSubs(clauses)
        clauses = elimTaut(clauses)
        clauses.sort(key=lambda x: x.gflag, reverse=True)
        n=len(clauses)
        pairs=[(clauses[i], clauses[j]) for i in range(n) for j in range(i+1, n)]
        for (ci, cj) in pairs:
            newClauses=resolve(ci, cj, opList)
            if "empty" in newClauses: return True
            new=new.union(set(newClauses))
            if(newClauses!=[]):
                break
        clauses=[c for c in clauses if not c.explst==[]]
        if new==set(clauses):
            return False
        if new.issubset(set(clauses)) and newClauses==[]:
            return False
        for cl in new:
            if cl not in clauses: clauses.append(cl)


def theorem_prover(KB, G):
    KBClauses = []
    GClauses = []
    for s in KB:
        cls = stringToClause(s)
        KBClauses.append(Clause(cls, 0))
    for s in G:
        cls = stringToClause(s)
        GClauses.append(Clause(cls, 1))
    clauses = KBClauses + GClauses
    for cls in clauses:
        for exp in cls.explst:
            newarglst=[]
            for arg in exp.arglst:
                if isFunct(arg):
                    arg = makeExpr(arg)
                newarglst.append(arg)
            exp.arglst = newarglst

    opList=[]
    result = resolution(clauses, opList)
    if result:
        return ("yes", opList)
    else:
        return ("no", [])

def tester():
    tests=[]
    sols=[]

    test1 = ["p(A,f(t))", "q(z)+~p(z,f(B))", "~q(y)+r(y)"], ["~r(A)"]
    solution1 = ('yes', ['~r(A)$~q(y)+r(y)$~q(A)', '~q(A)$q(z)+~p(z,f(B))$~p(A,f(B))', '~p(A,f(B))$p(A,f(t))$empty'])
    tests.append(test1)
    sols.append(solution1)

    test2 = ["p(A,f(t))", "q(z)+~p(z,f(B))", "q(y)+r(y)"], ["~r(A)"]
    solution2 = ('no', [])
    tests.append(test2)
    sols.append(solution2)

    test3 = ["p(z)+~q(z)", "~p(A)"], ["q(y)"]
    solution3 = ("yes", ["q(y)$p(z)+~q(z)$p(z)", "p(z)$~p(A)$empty"])
    tests.append(test3)
    sols.append(solution3)

    test4=["p(A,f(t))", "q(z)+~p(z,f(B))", "~q(y)+r(y)", "~t(x)+t(x)"], ["~r(A)"]
    solution4=('yes', ['~r(A)$~q(y)+r(y)$~q(A)', '~q(A)$q(z)+~p(z,f(B))$~p(A,f(B))', '~p(A,f(B))$p(A,f(t))$empty'])
    tests.append(test4)
    sols.append(solution4)

    test5=["p(A,f(t))", "q(z)+~p(z,f(B))", "~q(y)+r(y)", "p(x,f(t))"], ["~r(A)"]
    solution5=('yes', ['~r(A)$~q(y)+r(y)$~q(A)', '~q(A)$q(z)+~p(z,f(B))$~p(A,f(B))', '~p(A,f(B))$p(A,f(t))$empty'])
    tests.append(test5)
    sols.append(solution5)

    test6=["~p(x,y)+~p(y,z)+g(x,z)", "p(f(w),w)"], ["~g(u,v)"]
    solution6=('yes', ["~g(u,v)$~p(x,y)+~p(y,z)+g(x,z)$~p(u,y)+~p(y,v)", "~p(u,y)+~p(y,v)$p(f(w),w)$~p(u,f(v))", "~p(u,f(v))$p(f(w),w)$empty"])
    tests.append(test6)
    sols.append(solution6)

    noOfTests=len(tests)

    print "Testing..."
    for i in range(noOfTests):
        test = tests[i]
        sol = sols[i]
        result=theorem_prover(test[0], test[1])
        print "---------------------------------"
        if result==sol:
            print "Test " + str(i) + " is correct!"
        else:
            print "Test " + str(i) + " is not correct."
            print "Correct solution is: "
            print sol
            print "Your solution is :"
            print result

tester()