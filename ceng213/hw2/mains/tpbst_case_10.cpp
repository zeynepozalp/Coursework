#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "tpbst.hpp"

/*
 * Case 10 : Empty tree, insert single item, remove it, print.
 */
int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.insert("ceng213", "sec1", 31)
            .remove("ceng213", "sec1")
            .print();

    return 0;
}
