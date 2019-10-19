#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "tpbst.hpp"

/*
 * Case 5 : Empty tree, find, check if structure is broken, print.
 */
int main() {
    TwoPhaseBST<int> tpbst;

    int *temp = NULL;
    if ((temp = tpbst.find("ceng213", "sec1")) != NULL)
        std::cout << *temp << std::endl;

    tpbst.print();

    return 0;
}
