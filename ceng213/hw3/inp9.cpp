#include "hw3.h"

using namespace std;

/*
    This input file tests the basic working
    pipeline of the login and logout.
*/


int main()
{
  AccessControl ac(20, 3);
  // register users
  std::cout << "User Add: Sarah "   << ac.addUser("Sarah", "Sarahspass")        << std::endl;
  std::cout << "User Add: Morgan "  << ac.addUser("Morgan", "morganspass")      << std::endl;
  std::cout << "User Add: Ellie "   << ac.addUser("Ellie", "elspassword")       << std::endl;
  std::cout << "User Add: Vicky "   << ac.addUser("Vicky", "vickypass")         << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  std::cout << std::endl;

  // Cannot login or logout (No entry named Chuck)
  std::cout << "Login: Chuck "    << ac.login("Chuck", "chuckspass")      << std::endl;
  std::cout << "Logout: Chuck "   << ac.logout("Chuck")                   << std::endl;
  // Shouldn't login either (wrong pass)
  std::cout << "Login: Ellie "   << ac.login("Ellie", "wrongpass")       << std::endl;
  // Should login
  std::cout << "Login: Ellie "   << ac.login("Ellie", "elspassword")       << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  std::cout << std::endl;

  std::cout << "Logout: Ellie "   << ac.logout("Ellie")                   << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  std::cout << std::endl;

  std::cout << "Change Pass: Sarah "   << ac.changePass("Sarah", "Sarahspass", "Sarahsnewpass")  << std::endl;
  // Shouldn't login either (wrong pass)
  std::cout << "Login: Sarah "   << ac.login("Sarah", "Sarahspass")       << std::endl;
  // Should login
  std::cout << "Login: Sarah "   << ac.login("Sarah", "Sarahsnewpass")       << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  std::cout << std::endl;

  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  std::cout << std::endl;

  return 0;
}
