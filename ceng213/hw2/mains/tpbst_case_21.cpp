#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "tpbst.hpp"

/*
 * Case 21 : Empty tree, insert many items, create primary node with empty secondary tree, unsuccessful finds, print.
 */
int main() {
    TwoPhaseBST<int> tpbst;

    tpbst.insert("ceng351", "sec2", 32)
            .insert("ceng351", "sec1", 31)
            .insert("ceng351", "sec3", 33)
            .insert("ceng351", "sec4", 34)
            .insert("ceng213", "sec1", 21)
            .remove("ceng213", "sec1")
            .insert("ceng435", "sec1", 41)
            .insert("ceng435", "sec2", 42)
            .insert("ceng435", "sec4", 44)
            .insert("ceng435", "sec3", 43)
            .insert("ceng477", "sec3", 73)
            .insert("ceng477", "sec4", 74)
            .insert("ceng477", "sec1", 71)
            .insert("ceng477", "sec2", 72)
            .insert("ceng453", "sec1", 91);

    int *temp = NULL;
    if ((temp = tpbst.find("ceng213", "sec1")) != NULL)
        std::cout << *temp << std::endl;
    if ((temp = tpbst.find("ceng351", "sec5")) != NULL)
        std::cout << *temp << std::endl;
    if ((temp = tpbst.find("ceng435", "sec5")) != NULL)
        std::cout << *temp << std::endl;
    if ((temp = tpbst.find("ceng453", "sec1")) != NULL)
        std::cout << *temp << std::endl;
    if ((temp = tpbst.find("ceng477", "sec0")) != NULL)
        std::cout << *temp << std::endl;

    tpbst.print();

    return 0;
}
