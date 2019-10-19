#include"Game.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

static int barbarians;
static int knights;
static int flag;
static int deadFlag;

Game::Game(unsigned int max, unsigned int boardSize, Coordinate chest) : board(Board(boardSize, &players, chest)) {
    maxTurnNumber=max;
    turnNumber=1;
    barbarians=0;
    knights=0;
}

Game::~Game() {
    for(auto & player : players){
        delete player;
    }
    players.clear();
}

void Game::addPlayer(int id, int x, int y, Team team, std::string cls) {
    if(cls=="ARCHER"){
        players.push_back(new Archer(id,x,y,team));
    }
    else if(cls=="FIGHTER"){
        players.push_back(new Fighter(id,x,y,team));
    }
    else if(cls=="SCOUT"){
        players.push_back(new Scout(id,x,y,team));
    }
    else if(cls=="PRIEST"){
        players.push_back(new Priest(id,x,y,team));
    }
    else if(cls=="TANK"){
        players.push_back(new Tank(id,x,y,team));
    }
    if(team==BARBARIANS) barbarians++;
    if(team==KNIGHTS) knights++;
}

bool Game::isGameEnded() {
    if(barbarians==0){
        cout<<"Game ended at turn "<<--turnNumber<<". All barbarians dead. Knight victory."<<endl;
        return true;
    }
    else if(knights==0){
        cout<<"Game ended at turn "<<--turnNumber<<". All knights dead. Barbarian victory."<<endl;
        return true;
    }
    else if(flag==1){
        cout<<"Game ended at turn "<<--turnNumber<<". Chest captured. Barbarian victory."<<endl;
        return true;
    }
    else if(turnNumber==maxTurnNumber+1){
        cout<<"Game ended at turn "<<--turnNumber<<". Maximum turn number reached. Knight victory."<<endl;
        return true;
    }
    else return false;
}

void Game::playTurn() {
    sortPlayers();
    cout<<"Turn "<<turnNumber<<" has started."<<endl;
    for(int i=0; i<players.size();i++){
        playTurnForPlayer(players[i]);
        if(deadFlag){
            i--;
            deadFlag=0;
        }
    }
    turnNumber++;
}

Goal Game::playTurnForPlayer(Player *player) {
    if(players.empty()) return NO_GOAL;
    if(player->isDead()){
        auto i=0;
        for(i=0; i<players.size(); i++){
            if(players[i]==player) break;
        }
        players.erase(players.begin()+i);
        if(player->getTeam()==BARBARIANS) barbarians--;
        else knights--;
        cout<<"Player "<<player->getBoardID()<<" has died."<<endl;
        delete player;
        deadFlag=1;
    }
    else{
            Board *b = this->getBoard();
            vector<Goal> prlist=player->getGoalPriorityList();
            vector<Coordinate> coords;
            for(int i=0; i<prlist.size();i++){
                if(prlist[i]==ATTACK){
                    coords=player->getAttackableCoordinates();
                    auto lowestID=1000;
                    Player *lowest=NULL;
                    for(int j=0;j<coords.size();j++){
                        Coordinate coord=coords[j];
                        if(b->isCoordinateInBoard(coord) && b->isPlayerOnCoordinate(coord)){
                            Player *temp=(*b)[coord];
                            if(temp->getID()<lowestID && temp->getTeam()!=player->getTeam()){
                                lowestID=temp->getID();
                                lowest=temp;
                            }
                        }
                    }
                    if(lowest){
                        player->attack(lowest);
                        return ATTACK;
                    }
                }
                else if(prlist[i]==HEAL){
                    coords=player->getHealableCoordinates();
                    int heal=0;
                    for(int j=0;j<coords.size();j++){
                        Coordinate coord=coords[j];
                        if(b->isCoordinateInBoard(coord) && b->isPlayerOnCoordinate(coord)){
                            Player* temp=(*b)[coord];
                            if(temp->getTeam()==player->getTeam()){
                                player->heal(temp);
                                heal=1;
                            }
                        }
                    }
                    if(heal==1) return HEAL;
                }
                else if(prlist[i]==CHEST){
                    coords=player->getMoveableCoordinates();
                    Coordinate coord=b->getChestCoordinates();
                    if(player->getCoord()==coord) continue;
                    Coordinate nearest(1000,1000);
                    for(int j=0;j<coords.size();j++){
                        if(b->isCoordinateInBoard(coords[j]) && !(b->isPlayerOnCoordinate(coords[j]))){
                            if((coords[j]-coord)<(nearest-coord)){
                                nearest=coords[j];
                            }
                            else if((coords[j]-coord)==(nearest-coord) && (coords[j].y)==(player->getCoord().y)){
                                nearest=coords[j];
                            }
                        }
                    }
                    if(coord==nearest && b->isPlayerOnCoordinate(coord)){
                        continue;
                    }
                    if(nearest!=Coordinate(1000,1000) && !(b->isPlayerOnCoordinate(nearest)) && (nearest-coord)!=player->getCoord()-coord){
                        player->movePlayerToCoordinate(nearest);
                        if(player->getCoord()==b->getChestCoordinates() && (player->getTeam()==BARBARIANS)) flag=1;
                        return CHEST;
                    }
                }
                else if(prlist[i]==TO_ALLY){
                    Team team=player->getTeam();
                    vector<Player*> allies;
                    auto lowestID=1000;
                    Player *lowest;
                    for(auto & temp : players){
                        if(temp->getTeam()==team && player!=temp) allies.push_back(temp);
                    }
                    auto nearestd=1000;
                    Player *nearestp=NULL;
                    Coordinate coord=player->getCoord();
                    for(auto temp : allies){
                        Coordinate enemyc=temp->getCoord();
                        if(enemyc-coord<nearestd){
                            nearestd=enemyc-coord;
                            nearestp=temp;
                        }
                        else if(enemyc-coord==nearestd && temp->getID()<nearestp->getID()){
                            nearestd=enemyc-coord;
                            nearestp=temp;
                        }
                    }
                    coords=player->getMoveableCoordinates();
                    Coordinate nearest(1000,1000);
                    if(nearestp){
                        for(auto & j : coords){
                            Coordinate enemyc=nearestp->getCoord();
                            if(j==enemyc){
                                nearest=j;
                                break;
                            }
                            else if(b->isCoordinateInBoard(j) && !(b->isPlayerOnCoordinate(j))){
                                if((j-enemyc)<(nearest-enemyc)){
                                    nearest=j;
                                }
                                else if((j-enemyc)==(nearest-enemyc) && (j.y)==(player->getCoord().y)){
                                    nearest=j;
                                }
                            }
                        }
                        if(nearest!=Coordinate(1000,1000) && !(b->isPlayerOnCoordinate(nearest))){
                            player->movePlayerToCoordinate(nearest);
                            if(player->getCoord()==b->getChestCoordinates() && (player->getTeam()==BARBARIANS)) flag=1;
                            return TO_ALLY;
                        }
                    }
                }
                else if(prlist[i]==TO_ENEMY){
                    Team team=player->getTeam();
                    vector<Player*> enemies;
                    auto lowestID=1000;
                    Player *lowest;
                    for(auto & temp : players){
                        if(temp->getTeam()!=team && player!=temp) enemies.push_back(temp);
                    }
                    auto nearestd=1000;
                    Player *nearestp=NULL;
                    Coordinate coord=player->getCoord();
                    for(auto temp : enemies){
                        Coordinate enemyc=temp->getCoord();
                        if(enemyc-coord<nearestd){
                            nearestd=enemyc-coord;
                            nearestp=temp;
                        }
                        else if(enemyc-coord==nearestd && temp->getID()<nearestp->getID()){
                            nearestd=enemyc-coord;
                            nearestp=temp;
                        }
                    }
                    coords=player->getMoveableCoordinates();
                    Coordinate nearest(1000,1000);
                    if(nearestp){
                        for(auto & j : coords){
                            Coordinate enemyc=nearestp->getCoord();
                            if(j==enemyc) {
                                nearest=j;
                                break;
                            }
                            else if(b->isCoordinateInBoard(j) && !(b->isPlayerOnCoordinate(j))){
                                if((j-enemyc)<(nearest-enemyc)){
                                    nearest=j;
                                }
                                else if((j-enemyc)==(nearest-enemyc) && (j.y)==(player->getCoord().y)){
                                    nearest=j;
                                }
                            }
                        }
                        if(nearest!=Coordinate(1000,1000)  && !(b->isPlayerOnCoordinate(nearest))){
                            player->movePlayerToCoordinate(nearest);
                            if(player->getCoord()==b->getChestCoordinates() && (player->getTeam()==BARBARIANS)) flag=1;
                            return TO_ENEMY;
                        }
                    }
                }
            }
        }
    return NO_GOAL;
}

void Game::sortPlayers() {
    if(players.empty()) return;
    for(int j=0; j<players.size(); j++){
        for(int i=0; i<players.size()-j-1;i++){
            Player *p1=players[i];
            Player *p2=players[i+1];
            if(p2->getID()<p1->getID()){
                players[i]=p2;
                players[i+1]=p1;
            }
        }
    }
}
