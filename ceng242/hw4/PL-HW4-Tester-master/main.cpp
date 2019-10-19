#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "InputParser.h"
#include "Game.h"

#include"Archer.h"
#include"Tank.h"
#include"Priest.h"
#include"Fighter.h"
#include"Scout.h"

#define LOG(x) std::cout << (x) << std::endl;


/*                 COMPARE FILES                */
bool compare_files(const std::string& filename1, const std::string& filename2)
{
	std::ifstream file1(filename1, std::ifstream::ate | std::ifstream::binary);
	std::ifstream file2(filename2, std::ifstream::ate | std::ifstream::binary);
	const std::ifstream::pos_type fileSize = file1.tellg();

	if (fileSize != file2.tellg()) {
		return false;
	}

	file1.seekg(0);	
	file2.seekg(0);

	std::istreambuf_iterator<char> begin1(file1);
	std::istreambuf_iterator<char> begin2(file2);

	return std::equal(begin1, std::istreambuf_iterator<char>(), begin2);
}

int main(void) {

	/*             GENERATE STREAMS             */
	std::fstream testinp;
	std::fstream test;

	/*               TEST PLAYER                */
	test.open("testCases/yourPlayer.txt");
	std::streambuf *coutBuffer = std::cout.rdbuf();
	std::cout.rdbuf(test.rdbuf());

	Player *archer = new Archer(0, 1, 2, BARBARIANS);
	Player *fighter = new Fighter(1, 2, 2, BARBARIANS);
	Player *scout = new Scout(2, 3, 2, BARBARIANS);
	Player *priest = new Priest(3, 4, 1, KNIGHTS);
	Player *tank = new Tank(4, 6, 3, KNIGHTS);

	// Shared methods
	std::cout << "Archer ID: " << archer->getID() << std::endl;
	std::cout << "Tank Board ID: " << tank->getBoardID() << std::endl;
	std::cout << "Scout position: " << scout->getCoord() << std::endl;
	std::cout << "Priest team: " << (priest->getTeam() == BARBARIANS ? "BARBARIANS" : "KNIGHTS") << std::endl;
	std::cout << "Fighter HP: " << fighter->getHP() << std::endl;
	std::cout << "Archer Dead? " << (archer->isDead() ? "YES" : "NO") << std::endl;

	// Virtual methods
	std::cout << "Scout AD: " << scout->getAttackDamage() << std::endl;
	std::cout << "Archer AD: " << archer->getAttackDamage() << std::endl;
	std::cout << "Priest Heal: " << priest->getHealPower() << std::endl;
	std::cout << "Tank Max HP: " << tank->getMaxHP() << std::endl;
	std::cout << "Fighter Max HP: " << fighter->getMaxHP() << std::endl;

	// Some interactions
	scout->attack(priest);
	priest->movePlayerToCoordinate(Coordinate(3, 4));
	archer->attack(scout);
	fighter->attack(tank);
	priest->heal(tank);
	archer->attack(priest);
	archer->attack(priest);
	tank->attack(fighter);
	scout->movePlayerToCoordinate(Coordinate(0, 0));

	std::vector<Coordinate> coor;
	coor = scout->getAttackableCoordinates();
	std::cout << "Scout attackable coordinates: {";
	for (auto& c : coor) {
		std::cout << c << " ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Archer Dead? " << (archer->isDead() ? "YES" : "NO") << std::endl;
	std::cout << "Priest HP: " << priest->getHP() << std::endl;
	archer->attack(priest);
	std::cout << "Priest Dead? " << (priest->isDead() ? "YES" : "NO") << std::endl;
	std::cout << "Priest Coordinate: " << priest->getCoord() << std::endl;

	delete archer;
	delete fighter;
	delete scout;
	delete priest;
	delete tank;

	test.close();
	std::cout.rdbuf(coutBuffer);

	LOG("------------testPlayer------------");
	if (compare_files("testCases/yourPlayer.txt", "testCases/testPlayer.txt")) {
		LOG("PASSED.\n");
	}
	else {
		LOG("FAILED.\n");
	}

	/*                TEST BOARD                */
	test.open("testCases/yourBoard.txt");
	coutBuffer = std::cout.rdbuf();
	std::cout.rdbuf(test.rdbuf());

	std::vector<Player*> players;
	Board board(6, &players, Coordinate(5, 0));
	std::cout << "Coordinate " << Coordinate(6, 2) << "in board? " << board.isCoordinateInBoard(Coordinate(6, 2)) << std::endl;
	std::cout << "Coordinate " << Coordinate(-2, 1) << "in board? " << board.isCoordinateInBoard(Coordinate(-2, 1)) << std::endl;
	std::cout << "Coordinate " << Coordinate(6, -2) << "in board? " << board.isCoordinateInBoard(Coordinate(6, -2)) << std::endl;
	std::cout << "Coordinate " << Coordinate(2, 3) << "in board? " << board.isCoordinateInBoard(Coordinate(2, 3)) << std::endl;

	archer = new Archer(0, 1, 4, BARBARIANS);
	fighter = new Fighter(1, 1, 5, BARBARIANS);
	scout = new Scout(2, 2, 4, BARBARIANS);
	priest = new Priest(3, 4, 4, KNIGHTS);
	tank = new Tank(4, 5, 3, KNIGHTS);

	players.push_back(archer);
	players.push_back(fighter);
	players.push_back(scout);
	players.push_back(priest);
	players.push_back(tank);

	std::cout << "Player on coordinate " << Coordinate(5, 3) << "? " << board.isPlayerOnCoordinate(Coordinate(5, 3)) << std::endl;
	std::cout << "Player on coordinate " << Coordinate(3, 3) << "? " << board.isPlayerOnCoordinate(Coordinate(3, 3)) << std::endl;

	std::cout << "ID of player on coordinate " << Coordinate(4, 4) << " " << board[Coordinate(4, 4)]->getID() << std::endl;
	std::cout << "Printing with ID" << std::endl << std::endl;
	board.printBoardwithID();

	std::cout << "Printing with class" << std::endl << std::endl;
	board.printBoardwithClass();

	for (auto x : players)
		delete x;

	test.close();
	std::cout.rdbuf(coutBuffer);

	LOG("-------------testBoard------------");
	if (compare_files("testCases/yourBoard.txt", "testCases/testBoard.txt")) {
		LOG("PASSED.\n");
	}
	else {
		LOG("FAILED.\n");
	}

	LOG("-------------testCases------------");

	/*           HOW MANY TEST CASES?           */
	int tC = 9;

	/*              CREATE OUTPUTS              */
	for (int i = 0; i < tC; i++) {
		testinp.open("testCases/input" + std::to_string(i) + ".txt");
		test.open("testCases/yourOutput" + std::to_string(i) + ".txt");

		std::streambuf *cinBuffer = std::cin.rdbuf();
		std::streambuf *coutBuffer = std::cout.rdbuf();

		std::cin.rdbuf(testinp.rdbuf());
		std::cout.rdbuf(test.rdbuf());

		Game *game = InputParser::parseGame();
		Board *board = game->getBoard();
		std::cout << "Board with ID" << std::endl;
		board->printBoardwithClass();
		std::cout << "Board with ID" << std::endl;
		board->printBoardwithID();
		while (!game->isGameEnded()) {
			game->playTurn();
			board->printBoardwithClass();
			std::cout << "--------------" << std::endl;
			board->printBoardwithID();
		}

		testinp.close();
		test.close();

		delete game;

		std::cin.rdbuf(cinBuffer);
		std::cout.rdbuf(coutBuffer);
	}

	/*              CHECK OUTPUTS               */
	for(int i = 0; i < tC; i++) {
		std::cout << "Testcase " << i << ": ";
		if (compare_files("testCases/yourOutput" + std::to_string(i) + ".txt", "testCases/output" + std::to_string(i) + ".txt")) {
			LOG("PASSED.");
		}
		else {
			LOG("FAILED.");
		}
	}

	LOG("--------------showOff-------------");

		testinp.open("testCases/input9.txt");
		test.open("testCases/yourOutput9.txt");

		std::streambuf *cinBuffer = std::cin.rdbuf();
		coutBuffer = std::cout.rdbuf();

		std::cin.rdbuf(testinp.rdbuf());
		std::cout.rdbuf(test.rdbuf());

		Game *game = InputParser::parseGame();
		while (!game->isGameEnded()) {
			game->playTurn();
			std::cout << "--------------" << std::endl;
		}

		delete game;

		testinp.close();
		test.close();

		std::cin.rdbuf(cinBuffer);
		std::cout.rdbuf(coutBuffer);

		if (compare_files("testCases/yourOutput9.txt", "testCases/output9.txt")) {
			LOG("PASSED.");
		}
		else {
			LOG("FAILED.");
		}

 }
