#include"Player.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

void Player::incrementHP(int hp) {
    this->HP+=hp;
}

void Player::decrementHP(int hp) {
    this->HP-=hp;
}

void Player::setCoordinate(Coordinate c) {
    coordinate=c;
}

void Player::setHP(int hp) {
    this->HP=hp;
}

Player::Player(unsigned int id,int x, int y, Team team) : id(id), coordinate(Coordinate(x,y)){
    this->team=team;
}

unsigned int Player::getID() const{
    return id;
}

const Coordinate& Player::getCoord() const{
    return coordinate;
}

int Player::getHP() const{
    return HP;
}

Team Player::getTeam() const{
    return team;
}

std::string Player::getBoardID(){
    if(id<10) return ("0"+to_string(id));
    else return to_string(id);
}

bool Player::attack(Player *enemy) {
    enemy->decrementHP(this->getAttackDamage());
    cout<<"Player "<<this->getBoardID()<<" attacked Player "<<enemy->getBoardID()<<" ("<<this->getAttackDamage()<<")"<<endl;
    return enemy->getHP() <= 0;
}

void Player::heal(Player *ally) {
    ally->incrementHP(this->getHealPower());
    if(ally->getHP()>ally->getMaxHP()) ally->setHP(ally->getMaxHP());
    cout<<"Player "<<this->getBoardID()<<" healed Player "<<ally->getBoardID()<<endl;
}

void Player::movePlayerToCoordinate(Coordinate c) {
    cout<<"Player "<<this->getBoardID()<<" moved from "<<this->coordinate<<" to "<<c<<endl;
    this->setCoordinate(c);
}

bool Player::isDead() const {
    return HP<=0;
}






