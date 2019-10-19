#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "tpbst.hpp"

/*
 * Case 12 : Empty tree, insert single item, remove it, print by primary key and secondary key.
 */
int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.insert("ceng213", "sec1", 31)
            .remove("ceng213", "sec1")
            .print("ceng213", "sec1");

    return 0;
}
