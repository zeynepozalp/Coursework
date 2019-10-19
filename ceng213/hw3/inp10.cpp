#include "hw3.h"

using namespace std;

/*
    This input file tests the basic working
    pipeline of the delete user.
*/

void delUser(AccessControl& ac, string username) {
  vector<string> oldPasswords;
  cout << "User Del: " << username << " " << ac.delUser(username, oldPasswords) << endl;
  cout << "Passwords of " << username << ": ";
  for (int i=0; i<oldPasswords.size(); i++)
    cout << oldPasswords[i] << " ";
  cout << endl; cout << endl;
}

int main()
{
  AccessControl ac1(3, 3);

  // register users
  std::cout << "User Add: Sarah "   << ac1.addUser("Sarah", "Sarahspass")        << std::endl;
  std::cout << "User Add: Morgan "  << ac1.addUser("Morgan", "morganspass")      << std::endl;
  std::cout << "User Add: Ellie "   << ac1.addUser("Ellie", "elspassword")       << std::endl;
  std::cout << "User Add: Vicky "   << ac1.addUser("Vicky", "vickypass")         << std::endl;

  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac1.printPasswords();
  cout << endl;

  // Cannot delete
  delUser(ac1, "Bob");
  // Should delete
  delUser(ac1, "Vicky");

  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac1.printPasswords();
  cout << endl;

  std::cout << "Change Pass: Sarah "   << ac1.changePass("Sarah", "Sarahspass", "Sarahsnewpass")  << std::endl;

  std::cout << "Change Pass: Sarah "   << ac1.changePass("Sarah", "Sarahsnewpass", "Sarahsnewerpass")  << std::endl;

  std::cout << "Change Pass: Sarah "   << ac1.changePass("Sarah", "Sarahsnewerpass", "Sarahsnewestpass") << std::endl;

  // Should delete
  delUser(ac1, "Sarah");

  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac1.printPasswords();
  cout << endl;

  delUser(ac1, "Morgan");
  delUser(ac1, "Ellie");

  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac1.printPasswords();
  cout << endl;

  return 0;
}
