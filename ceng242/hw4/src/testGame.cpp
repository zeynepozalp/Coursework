#include"Game.h"
#include"InputParser.h"
#include<iostream>


int main(){

  Game *game = InputParser::parseGame();
  Board *board = game->getBoard();
  std::cout << "Board with ID" << std::endl;
  board->printBoardwithClass();
  std::cout << "Board with ID" << std::endl;
  board->printBoardwithID();
  while(!game->isGameEnded()){
    game->playTurn();
    board->printBoardwithClass();
    std::cout << "--------------" << std::endl;
    board->printBoardwithID();
  }
}
