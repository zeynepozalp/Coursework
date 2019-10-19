#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "LinkedList.hpp"

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()



using namespace std;

class tmpClass {
public:

    tmpClass(string val1 = "", int val2 = 0) : s_val(val1), i_val(val2) {
    };

    friend ostream &operator<<(ostream &out, const tmpClass& r) {
        out << "[" << r.s_val << ":" << r.i_val << "]";
        return out;
    };

    bool operator==(const tmpClass & rhs) const {
        return (this->s_val == rhs.s_val);
    };

private:
    string s_val;
    int i_val;
};

void test_integer_list() {
    LinkedList<int> a = LinkedList<int>();
    a.print();
    for (int i = 0; i < 100; i++) a.insertNode(a.getHead(), i);
    a.print();
}

void test_insert_delete() {
    LinkedList<tmpClass> list = LinkedList<tmpClass>();
    list.insertNode(list.getHead(), tmpClass("CCCCC", 1));
    list.insertNode(list.getHead(), tmpClass("BBBBB", 1));
    list.insertNode(list.getHead(), tmpClass("AAAAA", 1));
    list.print();
    list.deleteNode(list.getHead());
    list.print();
}

void test_copy_constructor() {
    srand(39);
    LinkedList<tmpClass> list = LinkedList<tmpClass>();
    for (int i = 0; i < 10; ++i) {
        list.insertNode(list.getHead(), tmpClass(SSTR(rand() % 10), rand() % 10));
    }
    list.print();
    {
        LinkedList<tmpClass> list2 = list;
        list.insertNode(list.getHead(), tmpClass(SSTR(rand() % 10), rand() % 10));
        list2.print();
    }
    list.print();
}

int main(int argc, char* argv[]) {
    cout << "test 1" << endl;
    test_integer_list();
    cout << "test 2" << endl;
    test_insert_delete();
    cout<<"test 3"<<endl;
    test_copy_constructor();
    return 0;
} 
