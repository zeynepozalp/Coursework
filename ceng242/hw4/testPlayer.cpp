//
//#include<iostream>
//#include"Player.h"
//#include"Archer.h"
//#include"Fighter.h"
//#include"Scout.h"
//#include"Priest.h"
//#include"Tank.h"
//#include"Constants.h"
//
//int main(){
//  /*
//   * Since there is no board object here, attack, move and heal methods are executed
//   * regardless of the ability of the class actually being able to execute that move.
//   *
//   */
//  Player *archer = new Archer(0,1,2,BARBARIANS);
//  Player *fighter = new Fighter(1,2,2,BARBARIANS);
//  Player *scout = new Scout(2,3,2,BARBARIANS);
//  Player *priest = new Priest(3,4,1,KNIGHTS);
//  Player *tank = new Tank(4,6,3,KNIGHTS);
//
//  // Shared methods
//
//  std::cout << "Archer ID: " << archer -> getID() << std::endl;
//  std::cout << "Tank Board ID: " << tank -> getBoardID() << std::endl;
//  std::cout << "Scout position: " << scout->getCoord() << std::endl;
//  std::cout << "Priest team: " << (priest->getTeam()==BARBARIANS?"BARBARIANS":"KNIGHTS") << std::endl;
//  std::cout << "Fighter HP: " << fighter -> getHP() << std::endl;
//  std::cout << "Archer Dead? " << (archer -> isDead()?"YES" : "NO") << std::endl;
//
//
//
//  // Virtual methods
//
//  std::cout << "Scout AD: " << scout -> getAttackDamage() << std::endl;
//  std::cout << "Archer AD: " << archer -> getAttackDamage() << std::endl;
//  std::cout << "Priest Heal: " << priest -> getHealPower() << std::endl;
//  std::cout << "Tank Max HP: " << tank -> getMaxHP() << std::endl;
//  std::cout << "Fighter Max HP: " << fighter -> getMaxHP() << std::endl;
//
//  // Some interactions
//
//  scout -> attack(priest);
//  priest -> movePlayerToCoordinate(Coordinate(3,4));
//  archer -> attack(scout);
//  fighter -> attack(tank);
//  priest -> heal(tank);
//  archer -> attack(priest);
//  archer -> attack(priest);
//  tank -> attack(fighter);
//  scout -> movePlayerToCoordinate(Coordinate(0,0));
//
//  std::vector<Coordinate> coor;
//  coor = scout -> getAttackableCoordinates();
//  std::cout << "Scout attackable coordinates: {" ;
//  for (auto& c : coor){
//    std::cout << c << " ";
//  }
//  std::cout << "}" << std::endl;
//
//  std::cout << "Archer Dead? " << (archer -> isDead()?"YES" : "NO") << std::endl;
//  std::cout << "Priest HP: " << priest->getHP() << std::endl;
//
//  archer -> attack(priest);
//  std::cout << "Priest Dead? " << (priest -> isDead()?"YES" : "NO") << std::endl;
//
//  std::cout << "Priest Coordinate: " << priest -> getCoord() << std::endl;
//
//  delete archer;
//
//
//
//
//
//
//}
