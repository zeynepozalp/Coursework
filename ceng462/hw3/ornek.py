def clauseparser(st):
    st = st.strip("\n")
    closed = True
    level = 0
    clause = []
    start_idx = 0
    end_idx = 0
    for c in st:
        if c == "(":
            closed = False
            level = level + 1
        elif c == ")":
            level = level - 1
            if level == 0:
                closed = True
        if (closed and c == ","):
            clause = clause + [st[start_idx:end_idx]]
            start_idx = end_idx+1
        elif (closed and end_idx+1 == len(st)):
            clause = clause + [st[start_idx:end_idx+1]]
            start_idx = end_idx
        end_idx = end_idx + 1
    return clause

def extract(st):
    negation = 0
    op = ""
    args = []
    if st[0] == "~":
        negation = 1
    for i in range(1,len(st)):
        if(st[i] == "("):
            op = st[negation:i]
            argstr = st[i+1:len(st)-1]
            args = argstr.split(",")
            break
    return Expr(op, negation, args)

def isVar(st):
    if isinstance(st,Expr):
        return False
    if st[0].islower():
        return ("(" not in st and ")" not in st)

def isConst(st):
    if isinstance(st,Expr):
        return False
    return st[0].isupper()

def isFunct(st):
    return not(isConst(st) or isVar(st))

def expr(st):
    if isVar(st) or isConst(st) or isinstance(st, Expr): # constant or variable
        return st
    else:                # function
        return extract(st)

class Expr:
    def __init__(self, op, negation, args):
        self.op = op                        # Predicate Symbol
        self.args = map(expr, args)  # ['x', 'A', Expr('f',0,['y'])]
        self.negation = negation            # 1 or 0
    def negate(self):
        if self.negation == 1:
            return Expr(self.op,0,self.args)
        else:
            return Expr(self.op,1,self.args)
    def __repr__(self):
        flag = 0
        st = self.op+"("
        for arg in self.args:
            if flag==1:
                st = st + "," + str(arg)
            else:
                st = st + str(arg)
            flag = 1
        st = st + ")"
        if(self.negation == 1):
            st = "~" + st
        return st

class Clause:
    def __init__(self,lst):
        self.explist = lst
    def concat(self,c2):
        newexplist = list(set(self.explist + c2.explist))
        return Clause(newexplist)
    def __repr__(self):
        st = str(self.explist[0])
        for i in range(1,len(self.explist)):
            st = st + "," + str(self.explist[i])
        return st
#--------------------------------------- FOL Functions ---------------------------------------------
def applyTOexp(exp, subs):
    myargs = []
    for arg in exp.args:
        if isinstance(arg, Expr):
            arg = applyTOexp(arg, subs)
            myargs.append(arg)
        elif isVar(arg):
            arg = subs[arg]
            myargs.append(arg)
        else:
            myargs.append(arg)
    return Expr(exp.op,exp.negation,myargs)

def applysubs(ci, cj, subs):
    dilist = []
    for di in ci.explist:
        arglist = []
        for arg in di.args:
            if isinstance(arg, Expr):
                arg = applyTOexp(arg,subs)
                arglist.append(arg)
            elif isVar(arg) and (arg in subs):
                arg = subs[arg]
                arglist.append(arg)
            else:
                arglist.append(arg)
        di = Expr(di.op,di.negation,arglist)
        dilist.append(di)
    ci.explist = dilist
    djlist = []
    for dj in cj.explist:
        arglist = []
        for arg in dj.args:
            if isinstance(arg, Expr):
                arg =applyTOexp(arg,subs)
                arglist.append(arg)
            elif isVar(arg) and (arg in subs):
                arg = subs[arg]
                arglist.append(arg)
            else:
                arglist.append(arg)
        dj = Expr(dj.op,dj.negation,arglist)
        djlist.append(dj)
    cj.explist = djlist

def unify(di, dj, subs):
    if subs == None:
        return None
    elif (di.op == dj.op) and (di.negation == dj.negation) and (len(di.args) == len(dj.args)):
        for i in range(0,len(di.args)):
            if isConst(di.args[i]) and isConst(dj.args[i]):
                if(di.args[i] == dj.args[i]):
                    subs[di.args[i]] = dj.args[i]
                else:
                    return None
            elif isVar(di.args[i]) and isConst(dj.args[i]):
                subs[di.args[i]] = dj.args[i]
            elif isVar(dj.args[i]) and isConst(di.args[i]):
                subs[dj.args[i]] = di.args[i]
            elif isVar(di.args[i]) and isVar(dj.args[i]):
                subs[di.args[i]] = dj.args[i]
            elif isinstance(di.args[i],Expr) and isinstance(dj.args[i],Expr):
                unify(di.args[i],dj.args[i],subs)
                if subs == None:
                    return None
            else:
                return None
    else:
        return None

def resolution(clauses):
    resolvents = []
    new = set()
    while True:
        n = len(clauses)
        pairs = [(clauses[i], clauses[j]) for i in range(n) for j in range(i+1,n)]
        for (ci, cj) in pairs:
            resolvents = resolve(ci, cj)
            if "empty_list" in resolvents: return True
            new = new.union(set(resolvents))
        if new.issubset(set(clauses)): return False
        for cl in new:
            if cl not in clauses: clauses.append(cl)

def resolve(ci, cj):
    resolvents = []
    subs = {}
    for di in ci.explist:
        for dj in cj.explist:
            unify(di,dj.negate(),subs)
            if subs:
                target.write(str(ci)+"$"+str(cj)+"$")
                ci.explist.remove(di)
                cj.explist.remove(dj)
                applysubs(ci,cj,subs)
                if ci.explist == [] and cj.explist == []:
                    c = "empty_list"
                elif ci.explist == []:
                    c = cj
                elif cj.explist == []:
                    c = ci
                else:
                    c = ci.concat(cj)
                if c!="empty_list":
                    target.write(str(c)+"\n")
                else:
                    target.write("empty_clause\n")
                resolvents.append(c)
    return resolvents


########################################### MAIN ###################################################
inputfile = open("ornekinput.txt","r")
target = open("ornekoutput.txt","w")
tasknum = int(inputfile.readline())
print tasknum
for i in range(0,tasknum):
    KB = []
    G = []
    base_clause_num, goal_clause_num = [int(val) for val in inputfile.readline().split()]
    print base_clause_num, goal_clause_num
    for i in range(0,base_clause_num):
        KB = KB + [map(extract,clauseparser(inputfile.readline()))]
    for i in range(0,goal_clause_num):
        G = G +   [map(extract,clauseparser(inputfile.readline()))]

print "KB: ", KB
print "G: ", G
clauses = KB + G
clause_list = []
for c in clauses:
    clause_list.append(Clause(c))

result = resolution(clause_list)
if result:
    print "YES"
    target.write("YES")
else:
    print "NO"
    target.write("NO")