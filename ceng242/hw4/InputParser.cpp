#include"InputParser.h"
#include <sstream>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

using namespace std;

Game *InputParser::parseGame() {
    unsigned int size;
    int x;
    int y;
    unsigned int turns;

    std::cin >> size;
    std::cin >> x;
    std::cin >> y;
    std::cin >> turns;

    Coordinate chest(x, y);

    Game *game = new Game (turns, size, chest);

    unsigned int playerNumber;
    std::cin >> playerNumber;

    for(int i=0; i<playerNumber; i++){
        unsigned int id;
        string cls;
        string team;
        int x;
        int y;
        cin >> id;
        cin >> cls;
        cin >> team;
        cin >> x;
        cin >> y;
        if(team=="BARBARIAN") game->addPlayer(id, x, y, BARBARIANS, cls);
        else game->addPlayer(id, x, y, KNIGHTS, cls);
    }
    return game;
}
