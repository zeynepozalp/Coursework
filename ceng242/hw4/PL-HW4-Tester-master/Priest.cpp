#include"Priest.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

int Priest::getAttackDamage() const {
    return 0;
}

int Priest::getHealPower() const {
    return 50;
}

int Priest::getMaxHP() const {
    return 150;
}

std::vector<Goal> Priest::getGoalPriorityList() {
    vector<Goal> v;
    v.push_back(HEAL);
    v.push_back(TO_ALLY);
    v.push_back(CHEST);
    return v;
}

const std::string Priest::getClassAbbreviation() const {
    if(team==BARBARIANS) return "PR";
    else return "pr";
}

std::vector<Coordinate> Priest::getAttackableCoordinates() {
    return std::vector<Coordinate>();
}

std::vector<Coordinate> Priest::getMoveableCoordinates() {
    vector<Coordinate> v;
    int x=this->getCoord().x;
    int y=this->getCoord().y;
    v.push_back(Coordinate(x,y+1));
    v.push_back(Coordinate(x,y-1));
    v.push_back(Coordinate(x+1,y));
    v.push_back(Coordinate(x-1,y));
    v.push_back(Coordinate(x+1,y+1));
    v.push_back(Coordinate(x-1,y-1));
    v.push_back(Coordinate(x+1,y-1));
    v.push_back(Coordinate(x-1,y+1));
    return v;
}

std::vector<Coordinate> Priest::getHealableCoordinates() {
    return getMoveableCoordinates();
}

Priest::Priest(unsigned int id, int x, int y, Team team) : Player(id, x, y, team) {
    HP=150;
}
