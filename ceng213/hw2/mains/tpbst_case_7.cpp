#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "tpbst.hpp"

/*
 * Case 7 : Empty tree, insert single item, print by primary key.
 */
int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.insert("ceng213", "sec1", 31)
            .print("ceng213");

    return 0;
}
