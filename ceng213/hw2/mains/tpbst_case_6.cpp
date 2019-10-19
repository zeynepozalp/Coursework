#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "tpbst.hpp"

/*
 * Case 6 : Empty tree, insert single item, print.
 */
int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.insert("ceng213", "sec1", 31)
            .print();

    return 0;
}
