#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "phonebook.hpp"

using namespace std;

void PhoneBook::insert(const string& name, const string& number)
{
    // TODO: IMPLEMENT THIS FUNCTION

}

void PhoneBook::remove(const string& name)
{
    // TODO: IMPLEMENT THIS FUNCTION

}

void PhoneBook::call(const string& name)
{
    // TODO: IMPLEMENT THIS FUNCTION

}

void PhoneBook::print() const
{
    const Node<Contact>* p = data.first();
    cout << endl;
    while (p){
        cout << p->getElement().toString() << endl;
        p = p->getNext();
    }
}

void PhoneBook::save(const string& filename) const
{
    // TODO: IMPLEMENT THIS FUNCTION

}

void PhoneBook::load(const string& filename)
{
    // TODO: IMPLEMENT THIS FUNCTION

}
