import sys
import random

class ValueIteration:
    def __init__(self, grid, normalReward, obstacleReward, pitfallReward, goalReward, theta, gamma):
        self.grid=grid
        self.normalReward=normalReward
        self.obstacleReward=obstacleReward
        self.pitfallReward=pitfallReward
        self.goalReward=goalReward
        self.theta=theta
        self.gamma=gamma
    def updateStates(self, valueList, actionList):
        if valueList==[] or actionList==[]:
            return
        i=0
        for s in self.grid.stateList:
            s.value=valueList[i]
            s.action=actionList[i]
            i+=1

class QLearning:
    def __init__(self, grid, normalReward, obstacleReward, pitfallReward, goalReward, noEp, alpha, gamma, epsilon):
        self.grid=grid
        self.normalReward=normalReward
        self.obstacleReward=obstacleReward
        self.pitfallReward=pitfallReward
        self.goalReward=goalReward
        self.noEp = noEp
        self.alpha=alpha
        self.gamma=gamma
        self.epsilon=epsilon

class Grid:
    def __init__(self, xDim=0, yDim=0, stateList=[], normalStates=[], goal=None):
        self.xDim=xDim
        self.yDim=yDim
        self.stateList=stateList
        self.normalStates=normalStates
        self.goal=goal
    def findState(self, x, y):
        for state in self.stateList:
            if(state.x==x and state.y==y):
                return state
        return None
    def printGridValues(self):
        print " ",
        for i in range(self.xDim):
            print i+1,
        print "\n",
        for i in range(self.xDim-1, -1, -1):
            print i+1,
            for j in range(self.yDim):
                print self.stateList[self.yDim*j+i].value,
            print "\n",
    def printGridActions(self):
        print " ",
        for i in range(self.xDim):
            print i+1,
        print "\n",
        for i in range(self.xDim-1, -1, -1):
            print i+1,
            for j in range(self.yDim):
                print self.stateList[self.yDim*j+i].action,
            print "\n",

class State:
    def __init__(self, x=0, y=0, type="normal", value=0, action=0, reward=0):
        self.x=x
        self.y=y
        self.type=type
        self.value=value
        self.action=action
        self.reward=reward

valueIteration=None
qLearning=None


def readInput():
    global valueIteration, qLearning
    with open(sys.argv[1], 'r') as f:
        if f.readline() == "V\n":
            theta=float(f.readline().strip())
            gamma=float(f.readline().strip())

            gridSize = f.readline().strip().split(" ")
            xDim, yDim = int(gridSize[0]), int(gridSize[1])
            grid = Grid(xDim, yDim)

            noOfObstacles = int(f.readline().strip())
            obstacleCoords = []
            for i in range(noOfObstacles):
                coord=f.readline().strip().split(" ")
                x, y=int(coord[0]), int(coord[1])
                obstacleCoords.append((x,y))

            noOfPitfalls = int(f.readline().strip())
            pitfallCoords = []
            for i in range(noOfPitfalls):
                coord=f.readline().strip().split(" ")
                x, y=int(coord[0]), int(coord[1])
                pitfallCoords.append((x, y))

            goalCoord=f.readline().strip().split(" ")
            goalX, goalY=int(goalCoord[0]), int(goalCoord[1])

            rewards = f.readline().strip().split(" ")
            normalReward = int(rewards[0])
            obstacleReward = int(rewards[1])
            pitfallReward = int(rewards[2])
            goalReward = int(rewards[3])

            for i in range(1,xDim+1):
                for j in range(1,yDim+1):
                    newState=State(i, j)
                    if (i,j) in obstacleCoords:
                        newState.type="obstacle"
                        newState.reward=obstacleReward
                    elif (i,j) in pitfallCoords:
                        newState.type="pitfall"
                        newState.reward=pitfallReward
                    elif (i,j) == (goalX, goalY):
                        newState.type="goal"
                        newState.reward=goalReward
                        grid.goal=newState
                    else:
                        newState.reward=normalReward
                    grid.stateList.append(newState)
            valueIteration=ValueIteration(grid, normalReward, obstacleReward, pitfallReward, goalReward, theta, gamma)

        else:
            noOfEpisodes = int(f.readline().strip())
            alpha=float(f.readline().strip())
            gamma=float(f.readline().strip())
            epsilon=float(f.readline().strip())

            gridSize=f.readline().strip().split(" ")
            xDim, yDim=int(gridSize[0]), int(gridSize[1])
            grid=Grid(xDim, yDim)

            noOfObstacles=int(f.readline().strip())
            obstacleCoords=[]
            for i in range(noOfObstacles):
                coord=f.readline().strip().split(" ")
                x, y=int(coord[0]), int(coord[1])
                obstacleCoords.append((x, y))

            noOfPitfalls=int(f.readline().strip())
            pitfallCoords=[]
            for i in range(noOfPitfalls):
                coord=f.readline().strip().split(" ")
                x, y=int(coord[0]), int(coord[1])
                pitfallCoords.append((x, y))

            goalCoord=f.readline().strip().split(" ")
            goalX, goalY=int(goalCoord[0]), int(goalCoord[1])

            rewards=f.readline().strip().split(" ")
            normalReward=int(rewards[0])
            obstacleReward=int(rewards[1])
            pitfallReward=int(rewards[2])
            goalReward=int(rewards[3])

            for i in range(1, xDim+1):
                for j in range(1, yDim+1):
                    newState=State(i, j)
                    if (i, j) in obstacleCoords:
                        newState.type="obstacle"
                        newState.reward=obstacleReward
                    elif (i, j) in pitfallCoords:
                        newState.type="pitfall"
                        newState.reward=pitfallReward
                    elif (i, j) == (goalX, goalY):
                        newState.type="goal"
                        newState.reward=goalReward
                        grid.goal=newState
                    else:
                        grid.normalStates.append(newState)
                        newState.reward=normalReward
                    grid.stateList.append(newState)
            qLearning=QLearning(grid, normalReward, obstacleReward, pitfallReward, goalReward, noOfEpisodes, alpha, gamma, epsilon)
        f.close()


def writeOutput():
    global valueIteration, qLearning
    if valueIteration!=None:
        with open(sys.argv[2], 'w') as f:
            for state in valueIteration.grid.stateList:
                f.write(str(state.x)+" ")
                f.write(str(state.y)+" ")
                f.write(str(state.action)+"\n")
        f.close()
    else:
        with open(sys.argv[2], 'w') as f:
            for state in qLearning.grid.stateList:
                f.write(str(state.x)+" ")
                f.write(str(state.y)+" ")
                f.write(str(state.action)+"\n")
        f.close()

########################################################
#        0 : 'N' , 1 : 'E ' , 2 : 'S ' , 3 : 'W'       #
########################################################

def findAction(state, grid):
    list=[]
    x=state.x
    y=state.y
    if x+1<grid.xDim+1:
        list.append([grid.findState(x+1, y), 1])
    if y+1<grid.yDim+1:
        list.append([grid.findState(x, y+1), 0])
    if x-1>0:
        list.append([grid.findState(x-1, y), 3])
    if y-1>0:
        list.append([grid.findState(x, y-1), 2])
    return list

def maxActionValue(state):
    actions = findAction(state, valueIteration.grid)
    maxaction=None
    maxvalue=None
    for tuple in actions:
        s=tuple[0]
        a=tuple[1]
        if s.value>maxvalue:
            maxvalue=s.value
            maxaction=a
    return maxvalue, maxaction

def solveValue():
    gamma = valueIteration.gamma
    theta = valueIteration.theta
    valueList=[]
    actionList=[]
    while(True):
        sigma=0.0
        valueIteration.updateStates(valueList, actionList)
        #print "Values:"
        #valueIteration.grid.printGridValues()
        #print "Actions:"
        #valueIteration.grid.printGridActions()
        valueList=[]
        actionList=[]
        for state in valueIteration.grid.stateList:
            value, action = maxActionValue(state)
            newvalue=state.reward+gamma*value
            valueList.append(newvalue)
            actionList.append(action)
            if newvalue-state.value > sigma:
                sigma=newvalue-state.value
        if theta*(1-gamma)/gamma > sigma:
            break
    valueIteration.updateStates(valueList, actionList)

def findAllAction(state, grid):
    list=[]
    x=state.x
    y=state.y
    list.append([grid.findState(x+1, y), 1])
    list.append([grid.findState(x, y+1), 0])
    list.append([grid.findState(x-1, y), 3])
    list.append([grid.findState(x, y-1), 2])
    return list

def maxActionValue2(actions):
    maxaction=None
    maxvalue=None
    maxstate=None
    for tuple in actions:
        s=tuple[0]
        a=tuple[1]
        if s!=None and s.value>maxvalue:
            maxvalue=s.value
            maxaction=a
            maxstate=s
    return maxstate, maxvalue, maxaction

def episode(state):
    alpha=qLearning.alpha #learning rate
    gamma=qLearning.gamma #discount factor
    epsilon=qLearning.epsilon #epsilon greedy approach
    grid=qLearning.grid
    # with prob. epsilon -> randomly select an action
    # with prob. 1-epsilon -> greedy selection
    # Q(s,b) = (1-a) * Q(s,b) + a * (r(s') + gamma * V(s'))
    # V(s') = max Q(s',b) where b is an action
    qMatrix=[[0 for x in range(4)] for y in range(grid.xDim*grid.yDim)]
    while state.type!="goal":
        actions=findAllAction(state, grid)
        maxstate, maxvalue, maxaction=maxActionValue2(actions)
        p=random.uniform(0, 1)
        if p < epsilon:
            #newstate, newaction = random.choice(filter(lambda (x, y): y!=maxaction, actions))
            newstate, newaction=random.choice(actions)
        else:
            newstate, newaction = maxstate, maxaction
        x=state.x-1
        y=state.y-1
        stateindex=y*grid.xDim+x
        if newstate==None: #wall
            qMatrix[stateindex][newaction]=(1-alpha) * qMatrix[stateindex][newaction]+alpha * qLearning.obstacleReward
        else:
            qMatrix[stateindex][newaction]=(1-alpha) * qMatrix[stateindex][newaction]+alpha * (newstate.reward+gamma * newstate.value)
            if qMatrix[stateindex][newaction]>state.value:
                state.value=qMatrix[stateindex][newaction]
                state.action=newaction
            if newstate.type!="obstacle":
                state=newstate

def solveQ():
    noEp=qLearning.noEp
    for count in range(noEp):
        qLearning.grid.goal.value=qLearning.goalReward
        initialState = random.choice(qLearning.grid.normalStates)
        episode(initialState)
    #print "Values:"
    #qLearning.grid.printGridValues()
    #print "Actions:"
    #qLearning.grid.printGridActions()

def solve():
    readInput()
    if valueIteration!=None:
        solveValue()
    else:
        solveQ()
    writeOutput()

solve()