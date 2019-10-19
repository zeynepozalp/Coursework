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

//    string line;
//    int x, y;
//    int i=0;
//    unsigned int size, nturn, pos;
//    unsigned int nplayer=0;
//    Game *game=NULL;
//
//    for(int i=0; i<playerNumber;i++){
//        getline(cin, line);
//        if(i==0){
//            size=stoi(line);
//        }
//        else if(i==1){
//            pos=line.find(' ');
//            x=stoi(line.substr(0,pos));
//            y=stoi(line.substr(pos+1));
//        }
//        else if(i==2){
//            nturn=stoi(line);
//        }
//        else if(i==3){
//            nplayer=stoi(line);
//            game = new Game(nturn, size, Coordinate(x, y));
//        }
//        else{
//            pos = line.find(' ');
//            istringstream iss(line);
//            unsigned int id;
//            iss>>id;
//            line.erase(0, pos+1); pos = line.find(' ');
//            string cls = line.substr(0, pos);
//            line.erase(0, pos+1); pos = line.find(' ');
//            string team = line.substr(0, pos);
//            line.erase(0, pos+1); pos = line.find(' ');
//            x=stoi(line.substr(0,pos));
//            y=stoi(line.substr(pos+1));
//            if(team=="BARBARIAN") game->addPlayer(id, x, y, BARBARIANS, cls);
//            else game->addPlayer(id, x, y, KNIGHTS, cls);
//        }
//    }
    return game;
}
