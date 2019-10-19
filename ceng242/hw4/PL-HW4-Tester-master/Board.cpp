#include"Board.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

Board::Board(unsigned int _size, std::vector<Player *> *_players, Coordinate _chest) : chest(_chest){
    size=_size;
    players=_players;
}

Board::~Board(){}

bool Board::isCoordinateInBoard(const Coordinate &c) {
    return !(c.x < 0 || c.y < 0 || c.x > size-1 || c.y > size-1);
}

bool Board::isPlayerOnCoordinate(const Coordinate &c) {
    for(int i=0; i<(*players).size(); i++){
        int x = (*players)[i]->getCoord().x;
        int y = (*players)[i]->getCoord().y;
        if(x==c.x && y==c.y) return true;
    }
    return false;
}

Player *Board::operator[](const Coordinate &c) {
    for(int i=0; i<(*players).size(); i++){
        int x = (*players)[i]->getCoord().x;
        int y = (*players)[i]->getCoord().y;
        if(x==c.x && y==c.y) return (*players)[i];
    }
    return NULL;
}

Coordinate Board::getChestCoordinates() {
    return chest;
}

void Board::printBoardwithID() {
    for(int i=0;i<size;i++){
        for(int j=0; j<size; j++){
            Coordinate c=Coordinate(j,i);
            Player *p=this->operator[](c);
            if(p) cout<<p->getBoardID()<<" ";
            else if(chest.x==c.x && chest.y==c.y) cout<<"Ch ";
            else cout<<"__ ";
        }
        cout<<endl;
    }
}

void Board::printBoardwithClass() {
    for(int i=0;i<size;i++){
        for(int j=0; j<size; j++){
            Coordinate c=Coordinate(j,i);
            Player *p=this->operator[](c);
            if(p) cout<<p->getClassAbbreviation()<<" ";
            else if(chest.x==c.x && chest.y==c.y) cout<<"Ch ";
            else cout<<"__ ";
        }
        cout<<endl;
    }
}
