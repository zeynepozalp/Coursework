#include"Tank.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

Tank::Tank(unsigned int id, int x, int y, Team team) : Player(id, x, y, team) {
    HP=1000;
}

int Tank::getAttackDamage() const {
    return 25;
}

int Tank::getHealPower() const {
    return 0;
}

int Tank::getMaxHP() const {
    return 1000;
}

std::vector<Goal> Tank::getGoalPriorityList() {
    vector<Goal> v;
    v.push_back(TO_ENEMY);
    v.push_back(ATTACK);
    v.push_back(CHEST);
    return v;
}

const std::string Tank::getClassAbbreviation() const {
    if(team==BARBARIANS) return "TA";
    else return "ta";
}

std::vector<Coordinate> Tank::getAttackableCoordinates() {
    vector<Coordinate> v;
    int x=this->getCoord().x;
    int y=this->getCoord().y;
    v.emplace_back(Coordinate(x,y+1));
    v.emplace_back(Coordinate(x,y-1));
    v.emplace_back(Coordinate(x+1,y));
    v.emplace_back(Coordinate(x-1,y));
    return v;
}

std::vector<Coordinate> Tank::getMoveableCoordinates() {
    return getAttackableCoordinates();
}

std::vector<Coordinate> Tank::getHealableCoordinates() {
    return std::vector<Coordinate>();
}


