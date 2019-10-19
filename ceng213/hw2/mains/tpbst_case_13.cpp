#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "tpbst.hpp"

/*
 * Case 13 : Empty tree, insert single item, remove it, insert another with same primary key, print.
 */
int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.insert("ceng213", "sec1", 31)
            .remove("ceng213", "sec1")
            .insert("ceng213", "sec2", 32)
            .print();

    return 0;
}
