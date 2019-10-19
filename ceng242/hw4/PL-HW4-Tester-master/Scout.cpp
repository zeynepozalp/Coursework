#include"Scout.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

Scout::Scout(unsigned int id, int x, int y, Team team) : Player(id, x, y, team) {
    HP=125;
}

int Scout::getAttackDamage() const {
    return 25;
}

int Scout::getHealPower() const {
    return 0;
}

int Scout::getMaxHP() const {
    return 125;
}

std::vector<Goal> Scout::getGoalPriorityList() {
    vector<Goal> v;
    v.push_back(CHEST);
    v.push_back(TO_ALLY);
    v.push_back(ATTACK);
    return v;
}

const std::string Scout::getClassAbbreviation() const {
    if(team==BARBARIANS) return "SC";
    else return "sc";
}

std::vector<Coordinate> Scout::getAttackableCoordinates() {
    vector<Coordinate> v;
    int x=this->getCoord().x;
    int y=this->getCoord().y;
    v.emplace_back(Coordinate(x,y+1));
    v.emplace_back(Coordinate(x,y-1));
    v.emplace_back(Coordinate(x+1,y));
    v.emplace_back(Coordinate(x-1,y));
    v.emplace_back(Coordinate(x+1,y+1));
    v.emplace_back(Coordinate(x-1,y-1));
    v.emplace_back(Coordinate(x+1,y-1));
    v.emplace_back(Coordinate(x-1,y+1));
    return v;
}

std::vector<Coordinate> Scout::getMoveableCoordinates() {
    return getAttackableCoordinates();
}

std::vector<Coordinate> Scout::getHealableCoordinates() {
    return std::vector<Coordinate>();
}


