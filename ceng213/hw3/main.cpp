#include "hw3.h"

using namespace std;

void inp1() {
    AccessControl ac1(1, 1);
    cout << "User Add: Sarah " << ac1.addUser("Sarah", "pass123") << endl;
    cout << "User Add: Sarah " << ac1.addUser("Sarah", "pass123") << endl;
    cout << "User Add: Sarah " << ac1.addUser("Sarah", "pass1234") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac1.printPasswords();

    cout << "\nUser Add: Morgan " << ac1.addUser("Morgan", "morP4ssw0rd") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac1.printPasswords();

    cout << "\nUser Add: BigMike " << ac1.addUser("BigMike", "mikesPassword") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac1.printPasswords();

    cout << "\nUser Add: Jeff " << ac1.addUser("Jeff", "jeffsspassword") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac1.printPasswords();

    cout << "\nUser Add: Lester " << ac1.addUser("Lester", "Lestersspassword") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac1.printPasswords();


    AccessControl ac2(4, 4);
    cout << "\nUser Add: Sarah " << ac2.addUser("Sarah", "Sarahspass") << endl;
    cout << "User Add: Sarah " << ac2.addUser("Sarah", "pass1234") << endl;
    cout << "User Add: Morgan " << ac2.addUser("Morgan", "morganspass") << endl;
    cout << "User Add: Ellie " << ac2.addUser("Ellie", "elspassword") << endl;
    cout << "User Add: Vicky " << ac2.addUser("Vicky", "vickypass") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac2.printPasswords();

    cout << "\nUser Add: Casey " << ac2.addUser("Casey", "caseysspassword") << endl;
    cout << "User Add: Casey " << ac2.addUser("Casey", "caseyssp4ssw0rd") << endl;
    cout << "User Add: Vale " << ac2.addUser("Vale", "valespass") << endl;
    cout << "User Add: Devon " << ac2.addUser("Devon", "devonspass") << endl;
    cout << "User Add: Chuck " << ac2.addUser("Chuck", "chuckspass") << endl;
    cout << "User Add: Orion " << ac2.addUser("Orion", "orionspass") << endl;
    cout << "User Add: Chuck " << ac2.addUser("Chuck", "chuckspass") << endl;
    cout << "User Add: Chuck " << ac2.addUser("Chuck", "chuckspass") << endl;
    cout << "User Add: Devon " << ac2.addUser("Devon", "devonspass") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac2.printPasswords();

    AccessControl ac3(3, 1);
    cout << "\nUser Add: Sarah " << ac3.addUser("Sarah", "Sarahspass") << endl;
    cout << "User Add: Sarah " << ac3.addUser("Sarah", "sarspass") << endl;
    cout << "---------" << endl << "Passwords" << endl;
    ac3.printPasswords();
}

void inp2() {
    AccessControl ac(20, 3);
    cout << "\nUser Add: Sarah " << ac.addUser("Sarah", "Sarahspass") << endl;
    cout << "User Add: Morgan " << ac.addUser("Morgan", "morganspass") << endl;
    cout << "User Add: Ellie " << ac.addUser("Ellie", "elspassword") << endl;
    cout << "User Add: Vicky " << ac.addUser("Vicky", "vickypass") << endl;
    cout << "User Add: Casey " << ac.addUser("Casey", "caseysspassword") << endl;
    cout << "User Add: Vale " << ac.addUser("Vale", "valespass") << endl;
    cout << "User Add: Devon " << ac.addUser("Devon", "devonspass") << endl;
    cout << "User Add: Chuck " << ac.addUser("Chuck", "chuckspass") << endl;
    cout << "User Add: Orion " << ac.addUser("Orion", "orionspass") << endl;
    cout << "User Add: BigMike " << ac.addUser("BigMike", "mikesPassword") << endl;
    cout << "User Add: Jeff " << ac.addUser("Jeff", "jeffsspassword") << endl;
    cout << "User Add: Lester " << ac.addUser("Lester", "Lestersspassword") << endl;

    cout << "Login: Chuck " << ac.login("Chuck", "chuckspass") << endl;
    cout << "Login: Chuck " << ac.login("Chuck", "wrong") << endl;
    cout << "Login: Morgan " << ac.login("Morgan", "wrong") << endl;
    cout << "Login: Morgan " << ac.login("Morgan", "morganspass") << endl;
    cout << "Login: Morgan " << ac.login("Morgan", "pass123") << endl;
    cout << "Login: Sarah " << ac.login("Sarah", "wrongpass") << endl;

    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();
    cout << endl;

    cout << "Login: Sarah " << ac.login("Sarah", "Sarahspass") << endl;
    cout << "Login: Sarah " << ac.login("Sarah", "Sarahspass") << endl;
    cout << "Login: Casey " << ac.login("Casey", "caseysspassword") << endl;
    cout << "Login: Orion " << ac.login("Orion", "orionspass") << endl;
    cout << "Login: Jefster " << ac.login("Jefster", "None") << endl;
    cout << "Login: BigMike " << ac.login("BigMike", "mikesPassword") << endl;
    cout << "Login: Jeff " << ac.login("Jeff", "jeffsspassword") << endl;
    cout << "Login: Lester " << ac.login("Lester", "Lestersspassword") << endl;

    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();
}

void inp3() {
    AccessControl ac(1, 1);
    cout << ac.addUsers("input.txt") << endl;
    ac.printPasswords();
}

void inp4() {
    AccessControl ac(20, 3);
    cout << "User Add: Sarah " << ac.addUser("Sarah", "Sarahspass") << endl;
    cout << "User Add: Morgan " << ac.addUser("Morgan", "morganspass") << endl;
    cout << "User Add: Ellie " << ac.addUser("Ellie", "elspassword") << endl;
    cout << "User Add: Vicky " << ac.addUser("Vicky", "vickypass") << endl;
    cout << "User Add: Casey " << ac.addUser("Casey", "caseysspassword") << endl;
    cout << "User Add: Vale " << ac.addUser("Vale", "valespass") << endl;
    cout << "User Add: Devon " << ac.addUser("Devon", "devonspass") << endl;
    cout << "User Add: Chuck " << ac.addUser("Chuck", "chuckspass") << endl;
    cout << "User Add: Orion " << ac.addUser("Orion", "orionspass") << endl;
    cout << "User Add: BigMike " << ac.addUser("BigMike", "mikesPassword") << endl;
    cout << "User Add: Jeff " << ac.addUser("Jeff", "jeffsspassword") << endl;
    cout << "User Add: Lester " << ac.addUser("Lester", "Lestersspassword") << endl;

    cout << "Login: Chuck " << ac.login("Chuck", "chuckspass") << endl;
    cout << "Logout: Chuck " << ac.logout("Chuck") << endl;
    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();

    cout << "Login: Chuck " << ac.login("Chuck", "chuckspass") << endl;
    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();

    cout << "Login: Morgan " << ac.login("Morgan", "morganspass") << endl;
    cout << "Login: Sarah " << ac.login("Sarah", "Sarahspass") << endl;
    cout << "Logout: Sarah " << ac.logout("Sarah") << endl;
    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();

    cout << "Logout: Chuck " << ac.logout("Chuck") << endl;
    cout << "Logout: Chuck " << ac.logout("Chuck") << endl;
    cout << "Logout: Morgan " << ac.logout("Morgan") << endl;
    cout << "Logout: Morgan " << ac.logout("Morgan") << endl;

    cout << "Login: Sarah " << ac.login("Sarah", "Sarahspass") << endl;
    cout << "Login: Casey " << ac.login("Casey", "caseysspassword") << endl;
    cout << "Login: Vicky " << ac.login("Vicky", "vickypass") << endl;
    cout << "Login: Vale " << ac.login("Vale", "valespass") << endl;
    cout << "Login: Orion " << ac.login("Orion", "orionspass") << endl;
    cout << "Login: Jefster " << ac.login("Jefster", "None") << endl;
    cout << "Login: BigMike " << ac.login("BigMike", "mikesPassword") << endl;
    cout << "Login: Jeff " << ac.login("Jeff", "jeffsspassword") << endl;
    cout << "Login: Lester " << ac.login("Lester", "Lestersspassword") << endl;
    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();

    cout << "Logout: Sarah " << ac.logout("Sarah") << endl;
    cout << "Logout: Casey " << ac.logout("Casey") << endl;
    cout << "Logout: Sarah " << ac.logout("Sarah") << endl;
    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();

    cout << "Logout: Orion " << ac.logout("Orion") << endl;
    cout << "Logout: Jefster " << ac.logout("Jefster") << endl;
    cout << "Logout: BigMike " << ac.logout("BigMike") << endl;
    cout << "Logout: Jeff " << ac.logout("Jeff") << endl;
    cout << "Logout: Lester " << ac.logout("Lester") << endl;
    cout << "Logout: Vicky " << ac.logout("Vicky") << endl;
    cout << "Logout: Vale " << ac.logout("Vale") << endl;

    cout << "Login: BigMike " << ac.login("BigMike", "mikesPassword") << endl;
    cout << "Login: Jeff " << ac.login("Jeff", "jeffsspassword") << endl;
    cout << "Login: Lester " << ac.login("Lester", "Lestersspassword") << endl;

    cout << "Logout: BigMike " << ac.logout("BigMike") << endl;
    cout << "Logout: Jeff " << ac.logout("Jeff") << endl;
    cout << "Logout: Lester " << ac.logout("Lester") << endl;
    cout << "---------" << endl << "Active Users" << endl;
    ac.printActiveUsers();

}

void inp5(){
  AccessControl ac(1,1);

  cout << "User Add: Sarah " << ac.addUser("Sarah", "Sarahspass") << endl;
  cout << "User Add: Morgan " << ac.addUser("Morgan", "morganspass") << endl;
  cout << "User Add: Ellie " << ac.addUser("Ellie", "elspassword") << endl;
  cout << "User Add: Vicky " << ac.addUser("Vicky", "vickypass") << endl;
  cout << "Change Pass: Sarah " << ac.changePass("Sarah", "wrong", "wrong") << endl;
  cout << "Change Pass: Sarah " << ac.changePass("Sarah", "Sarahspass","Sarahsnewpass") << endl;
  cout << "User Add: Casey " << ac.addUser("Casey", "caseysspassword") << endl;
  cout << "User Add: Vale " << ac.addUser("Vale", "valespass") << endl;
  cout << "---------" << endl << "Passwords" << endl;
  ac.printPasswords();

  cout << "\n"<<"User Add: Devon " << ac.addUser("Devon", "devonspass")<<endl;
  cout << "---------" << endl << "Passwords" << endl;
  ac.printPasswords();

  cout << "Change Pass: Sarah " << ac.changePass("Sarah", "Sarahsnewpass", "Sarahsnewerpass") << endl;
  cout << "User Add: Chuck " << ac.addUser("Chuck", "chuckspass") << endl;
  cout << "User Add: Orion " << ac.addUser("Orion", "orionspass") << endl;
  cout << "Change Pass: Vale " << ac.changePass("Vale", "valespass", "valesnewpass") << endl;
  cout << "Change Pass: Sarah " << ac.changePass("Sarah", "Sarahsnewerpass", "Sarahsnewestpass") << endl;
  cout << "User Add: BigMike " << ac.addUser("BigMike", "mikesPassword") << endl;
  cout << "User Add: Jeff " << ac.addUser("Jeff", "jeffsspassword") << endl;
  cout << "Change Pass: Vale " << ac.changePass("Vale","valesnewpass", "valesnewerpass") << endl;
  cout << "User Add: Lester " << ac.addUser("Lester", "lestersspassword") << endl;
  cout << "User Add: Beckman " << ac.addUser("Beckman", "Generalsspassword") << endl;
  cout << "User Add: Bryce " << ac.addUser("Bryce", "brycespassword") << endl;
  cout << "User Add: Emmet " << ac.addUser("Emmet", "hothothothot") << endl;
  cout << "User Add: Tang " << ac.addUser("Tang", "harrysspassword") << endl;
  cout << "User Add: Alex " << ac.addUser("Alex", "alexsspassword") << endl;
  cout << "Change Pass: Vale " << ac.changePass("Vale","valesnewerpass", "valesnewestpass") << endl;
  cout << "User Add: AnnaWu " << ac.addUser("AnnaWu", "AnnaWusspassword") << endl;
  cout << "Change Pass: Tang " << ac.changePass("Tang","harrysspassword", "harryssnewpassword") << endl;
  cout << "User Add: Roark " << ac.addUser("Roark", "Tedsspassword") << endl;
  cout << "---------" << endl << "Passwords" << endl;
  ac.printPasswords();

}

int main () {
    inp1();
    // inp2();
    // inp3();
    // inp4();
    // inp5();

    return 0;
}
