#include"Fighter.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

int Fighter::getAttackDamage() const {
    return 100;
}

int Fighter::getHealPower() const {
    return 0;
}

int Fighter::getMaxHP() const {
    return 400;
}

std::vector<Goal> Fighter::getGoalPriorityList() {
    vector<Goal> v;
    v.push_back(ATTACK);
    v.push_back(TO_ENEMY);
    v.push_back(CHEST);
    return v;
}

const std::string Fighter::getClassAbbreviation() const {
    if(team==BARBARIANS) return "FI";
    else return "fi";
}

std::vector<Coordinate> Fighter::getAttackableCoordinates() {
    vector<Coordinate> v;
    int x=this->getCoord().x;
    int y=this->getCoord().y;
    v.emplace_back(Coordinate(x,y+1));
    v.emplace_back(Coordinate(x,y-1));
    v.emplace_back(Coordinate(x+1,y));
    v.emplace_back(Coordinate(x-1,y));
    return v;
}

std::vector<Coordinate> Fighter::getMoveableCoordinates() {
    return getAttackableCoordinates();
}

std::vector<Coordinate> Fighter::getHealableCoordinates() {
    return std::vector<Coordinate>();
}

Fighter::Fighter(unsigned int id, int x, int y, Team team) : Player(id,x,y,team){
    HP=400;
}









