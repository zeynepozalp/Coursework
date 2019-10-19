#include "hw3.h"

using namespace std;

/*
    This input file tests the basic working
    pipeline of the expanding.

    Need to expand table 2 times.

    Also checks the addUser function.
*/

int main()
{
  AccessControl ac(3, 3);
  // register users
  std::cout << "User Add: Sarah "   << ac.addUser("Sarah", "Sarahspass")        << std::endl;
  // Shouldn't add it
  std::cout << "User Add: Sarah "   << ac.addUser("Sarah", "Anypass")           << std::endl;
  // Without Expand
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  cout << endl;

  std::cout << "User Add: Morgan "  << ac.addUser("Morgan", "morganspass")      << std::endl;
  // Check expand
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  cout << endl;
  
  std::cout << "User Add: Casey "   << ac.addUser("Casey", "caseysspassword")   << std::endl;
  std::cout << "User Add: Vale "    << ac.addUser("Vale", "valespass")          << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  cout << endl;

  std::cout << "User Add: Devon "   << ac.addUser("Devon", "devonspass")        << std::endl;
  // Check expand
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  cout << endl;
  return 0;
}
