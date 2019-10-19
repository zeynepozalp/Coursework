#include "hw3.h"

using namespace std;

/*
    This input file tests the basic working
    pipeline of the change password & expanding.
*/

int main()
{
  AccessControl ac(3, 3);
  // register users
  std::cout << "User Add: Sarah "   << ac.addUser("Sarah", "Sarahspass")        << std::endl;
  // Without expand
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  cout << endl;
  
  // Shouldn't change it
  std::cout << "Change Pass: Sarah "   << ac.changePass("Sarah", "wrong", "Sarahsnewpass")  << std::endl;
  // Success & expand table
  std::cout << "Change Pass: Sarah "   << ac.changePass("Sarah", "Sarahspass", "Sarahsnewpass")  << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  cout << endl;

  return 0;
}
