#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>

#include "Person.h"
#include "EMonitor.h"

#define DOWN -1
#define IDLE 0
#define UP 1

using namespace std;

EMonitor EM;

int direction = IDLE;
float currCapacity = 0;
int currPeople = 0;
int currFloor = 0;
int noServed = 0;
bool requestCame = false;
vector<int> destQ;
vector<Person*> people;
vector<int> enterFloors;
vector<int> leaveFloors;
int noFloors;
int noPeople;
float weightCap;
int personCap;
float travelTime;
float idleTime;
float IOTime;
float weight;
int init, dest;
int priority;


void printElevatorInfo(){
    cout << "Elevator (";
    switch(direction){
        case DOWN:
            cout << "Moving-down, ";
            break;
        case UP:
            cout << "Moving-up, ";
            break;
        case IDLE:
            cout << "Idle, ";
            break;
    }
    cout << (int) currCapacity << ", " << currPeople << ", " 
        << currFloor << " ->";
    int destSize = destQ.size();
    if(destSize) cout << " ";
    for(int i=0; i<destSize; i++){
        cout << destQ[i];
        if(i!=destSize-1) cout << ",";
    }
    cout << ")" <<endl;
    return;
}

void addInit(Person* p){
    if(find(destQ.begin(), destQ.end(), p->getInit())==destQ.end() && p->getInit()!=currFloor){
        destQ.push_back(p->getInit());
    }
    sort(destQ.begin(), destQ.end());
    return;
}

void addDest(Person* p){
    if(find(destQ.begin(), destQ.end(), p->getDest())==destQ.end() && p->getDest()!=currFloor){
        destQ.push_back(p->getDest());
    }
    sort(destQ.begin(), destQ.end());
    return;
}

void changeDirection(int d){
    direction=d;
    switch(d){
        case UP: 
            EM.upSignal(); 
            direction=UP;
            break;
        case DOWN: 
            EM.downSignal(); 
            direction=DOWN;
            break;
        default: 
            EM.inIdle(noServed, noPeople); 
            direction=IDLE;
    }
    return;
}

void enter(Person* p){
    //cout << "test 14" << endl;
    cout << "Person (" << p->getID() << ", ";
    switch (p->getPriority()){
        case HP:
            cout << "hp, ";
            break;
        case LP:
            cout << "lp, ";
            break;
    }
    cout << p->getInit() << " -> " << p->getDest() << ", "
        << p->getWeight() << ") entered the elevator" << endl;
    
    currPeople++;
    currCapacity+=p->getWeight();

    p->setInside(true);
    int personDir = IDLE;

    if(init<dest) personDir=UP;
    else personDir=DOWN;

    if(direction==IDLE) changeDirection(personDir);
    
    addDest(p);
    printElevatorInfo();
    return;
}

void makeRequest(Person* p){
    //cout << "beginning of request" << endl;
    
    EM.writeWait();
    if(p->getCompleted()){
        return;
    }
    cout << "Person (" << p->getID() << ", ";
    switch (p->getPriority()){
        case HP:
            cout << "hp, ";
            break;
        case LP:
            cout << "lp, ";
            break;
    }
    cout << p->getInit() << " -> " << p->getDest() << ", "
        << p->getWeight() << ") made a request" << endl;

    int personDir = IDLE;

    if(init<dest) personDir=UP;
    else personDir=DOWN;

    if(direction==IDLE) changeDirection(personDir);
    
    int init = p->getInit();
    addInit(p);

    if(destQ.size()){
        if(destQ[0]<currFloor){
        direction = (DOWN);
    }
    else if(destQ[0]>currFloor){
        direction = (UP);
    }
    }
    printElevatorInfo();
    if(init==currFloor && currCapacity+p->getWeight()<=weightCap) enter(p);
    
    EM.writeSignal();
    requestCame = true;
    return;
}

void* personT(void* p){
    Person* person = (Person *) p;
    int personDir = IDLE;
    int init = person->getInit();
    int dest = person->getDest();
    int pri = person->getPriority();

    if(init<dest) personDir=UP;
    else personDir=DOWN;
    
    while(!person->getCompleted()){
            switch(personDir){
                case UP:
                    EM.upWait();
                    if(direction==IDLE){
                        if(!person->getInside() && !person->getCompleted()){
                            makeRequest(person);
                        }
                    }
                    else{
                        if(init>=currFloor && !person->getInside() && !person->getCompleted()) makeRequest(person);
                    }
                    break;
                case DOWN:
                    EM.downWait();
                    if(direction==IDLE){
                        if(!person->getInside() && !person->getCompleted()){
                            makeRequest(person);
                        }
                    }
                    else{
                        //cout << "test7" << person->getID()<< endl;
                        if(init<=currFloor && !person->getInside() && !person->getCompleted()) makeRequest(person);
                    }
            }
         //cout << "test8" << person->getID()<< endl;
    }
    
    noServed++;
    return 0;
}

void printVector(vector<Person*> enterPeople){
    int n=enterPeople.size();
    for(int i=0; i<n; i++){
        cout << (enterPeople[i])->getID() << " ";
    }
    cout<<endl;
    return;
}

struct less_than_key{
    inline bool operator() (const Person* struct1, const Person* struct2)
    {
        return (struct1->getPriority() < struct2->getPriority());
    }
};

bool entersCurrFloor(){
    bool b = false;
    vector<Person*> enterPeople;
    for(int i=0; i<noPeople; i++){
        Person* p = people[i];
        if(p->getInit()==currFloor && !p->getCompleted()){
            enterPeople.push_back(p);
        }
    }
    int n = enterPeople.size();

    sort(enterPeople.begin(), enterPeople.end(), less_than_key());

    for(int i=0; i<n; i++){
        Person* newp = enterPeople[i];
        
        if(currPeople<personCap && currCapacity+newp->getWeight()<=weightCap){
            enter(newp);
            b = true;
        }
    }
    return b;
}

void leave(Person* p){
    p->setCompleted(true);
    p->setInside(false);
    cout << "Person (" << p->getID() << ", ";
    switch (p->getPriority()){
        case HP:
            cout << "hp, ";
            break;
        case LP:
            cout << "lp, ";
            break;
    }
    cout << p->getInit() << " -> " << p->getDest() << ", "
        << p->getWeight() << ") has left the elevator" << endl;

    currPeople--;
    if(!currPeople){
        changeDirection(IDLE);
    }

    currCapacity-=p->getWeight();
    printElevatorInfo();
    return;
}

bool leavesCurrFloor(){
    bool b = false;
    for(int i=0; i<noPeople; i++){
        Person* p = people[i];
        if(p->getDest()==currFloor && !p->getCompleted() && p->getInside()){
            leave(p);
            b=true;
        }
    }
    return b;
}

void moveUp(){
    usleep(travelTime);
    changeDirection(UP);
    currFloor++;
    vector<int>::iterator it = find(destQ.begin(), destQ.end(), currFloor);
    if(it!=destQ.end()){
       destQ.erase(it);
    }
    if(destQ.size()==0) changeDirection(IDLE);
    printElevatorInfo();
    return;
}

void moveDown(){
    usleep(travelTime);
    changeDirection(DOWN);
    currFloor--;
    vector<int>::iterator it = find(destQ.begin(), destQ.end(), currFloor);
    if(it!=destQ.end()){
       destQ.erase(it);
    }
    if(destQ.size()==0) changeDirection(IDLE);
    printElevatorInfo();
    return;
}

int main(int argc, char* argv[]){
    //cout << "test1" << endl;
    fstream file;
    file.open(argv[1]);

        file >> noFloors >> noPeople >> weightCap >> personCap >> travelTime
            >> idleTime
            >> IOTime; 

        for(int i=0; i<noPeople; i++){
            file >> weight >> init >> dest >> priority;
            Person* newPerson = new Person(i, weight, init, dest, priority);
            people.push_back(newPerson);
        }

        file.close();

    pthread_t personTids[noPeople];

    //cout << "test2" << endl;
    for(int i=0; i<noPeople; i++){
        pthread_create(personTids+i, NULL, personT, (void*) people[i]);
    }
    //cout << "test3" << endl;
    EM.inIdle(noServed, noPeople);
    //int i=0;
    while(noServed!=noPeople){
        //i++;
        //cout << "test4" << endl;
        if(direction==IDLE){
            EM.inIdle(noServed, noPeople);
            //cout << "test5" << endl;

            while(!requestCame){
                if(noServed==noPeople) break;
                //cout << "test6" << endl;
                EM.writeSignal();
                usleep(idleTime);
            }
            
            requestCame=false;
        } 
        
        int destFloor = *destQ.begin();
        if(destFloor>currFloor){
            //cout << "test11" << endl;
            moveUp();
        }
        if(destFloor<currFloor){
            //cout << "test12" << endl;
            moveDown();
        }
        if(entersCurrFloor()){
            //cout << "test8" << endl;
            usleep(IOTime);
        }
        if(leavesCurrFloor()){
            //cout << "test9" << endl;
            usleep(IOTime);
        }
        //cout << "test10" << endl;
        //if(i==5) break;
    }

    //cout << "test13" << endl;

    for(int i=0; i<noPeople; i++){
        pthread_join(personTids[i], NULL);
    }

    return 0;
}