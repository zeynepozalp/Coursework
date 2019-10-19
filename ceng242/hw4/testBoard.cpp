//#include"Board.h"
//#include<iostream>
//#include"Player.h"
//#include"Archer.h"
//#include"Fighter.h"
//#include"Scout.h"
//#include"Priest.h"
//#include"Tank.h"
//#include"Constants.h"
//
//
//int main(){
//  std::vector<Player*> players;
//  Board board(6,&players,Coordinate(5,0));
//  std::cout << "Coordinate " << Coordinate(6,2) << "in board? " << board.isCoordinateInBoard(Coordinate(6,2)) << std::endl;
//  std::cout << "Coordinate " << Coordinate(-2,1) << "in board? " << board.isCoordinateInBoard(Coordinate(-2,1)) << std::endl;
//  std::cout << "Coordinate " << Coordinate(6,-2) << "in board? " << board.isCoordinateInBoard(Coordinate(6,-2)) << std::endl;
//  std::cout << "Coordinate " << Coordinate(2,3) << "in board? " << board.isCoordinateInBoard(Coordinate(2,3)) << std::endl;
//
//  Player *archer = new Archer(0,1,4,BARBARIANS);
//  Player *fighter = new Fighter(1,1,5,BARBARIANS);
//  Player *scout = new Scout(2,2,4,BARBARIANS);
//  Player *priest = new Priest(3,4,4,KNIGHTS);
//  Player *tank = new Tank(4,5,3,KNIGHTS);
//
//  players.push_back(archer );
//  players.push_back(fighter );
//  players.push_back(scout );
//  players.push_back( priest );
//  players.push_back(tank );
//
//  std::cout << "Player on coordinate " << Coordinate(5,3) << "? " << board.isPlayerOnCoordinate(Coordinate(5,3)) << std::endl;
//  std::cout << "Player on coordinate " << Coordinate(3,3) << "? " << board.isPlayerOnCoordinate(Coordinate(3,3)) << std::endl;
//
//  std::cout << "ID of player on coordinate " << Coordinate(4,4) << " " << board[Coordinate(4,4)] -> getID() << std::endl;
//  std::cout << "Printing with ID" << std::endl << std::endl;
//  board.printBoardwithID();
//
//  std::cout << "Printing with class" << std::endl << std::endl;
//  board.printBoardwithClass();
//
//}
