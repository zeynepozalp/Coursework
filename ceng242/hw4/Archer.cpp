#include"Archer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

Archer::Archer(unsigned int id,int x, int y, Team team) : Player(id,x,y,team){
    HP=200;
}

int Archer::getAttackDamage() const {
    return 50;
}

int Archer::getHealPower() const {
    return 0;
}

int Archer::getMaxHP() const {
    return 200;
}

std::vector<Goal> Archer::getGoalPriorityList() {
    vector<Goal> v;
    v.push_back(ATTACK);
    return v;
}

const std::string Archer::getClassAbbreviation() const {
    if(team==BARBARIANS) return "AR";
    else return "ar";
}

std::vector<Coordinate> Archer::getAttackableCoordinates() {
    vector<Coordinate> v;
    int x=this->getCoord().x;
    int y=this->getCoord().y;
    v.reserve(8);
    for(int i=1;i<3;i++){
        v.emplace_back(Coordinate(x,y+i));
        v.emplace_back(Coordinate(x,y-i));
        v.emplace_back(Coordinate(x+i,y));
        v.emplace_back(Coordinate(x-i,y));
    }
    return v;
}

std::vector<Coordinate> Archer::getMoveableCoordinates() {
    vector<Coordinate> v;
    return v;
}

std::vector<Coordinate> Archer::getHealableCoordinates() {
    vector<Coordinate> v;
    return v;
}












