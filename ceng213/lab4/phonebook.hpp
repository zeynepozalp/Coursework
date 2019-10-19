#ifndef __phonebook_h__
#define __phonebook_h__

#include <string>
#include <sstream>
#include "list.hpp"

using namespace std;

class Contact
{
    public:
        // Note that we can implement short functions directly
        // inside the class definition. This is called "inlining"
        // functions.
        Contact()
        {
            name = "";
            number = "";
            callCount = 0;
        }

        Contact(string na, string nu, int cc = 0)
        {
            name = na;
            number = nu;
            callCount = cc;
        }

        string toString() const{
            ostringstream sout;
            sout << name << "\t" << number << "\t" << callCount << endl;
            return sout.str();
        }

        void setName(string n){
            name = n;
        }

        void setNumber(string n){
            number = n;
        }

        void setCallCount(int cc){
            callCount = cc;
        }

        void incCallCount(){
            callCount++;
        }

        string getName() const{
            return name;
        }

        string getNumber() const{
            return number;
        }

        int getCallCount() const{
            return callCount;
        }

    private:
        string name;
        string number;
        int callCount;
};

class PhoneBook
{
    public:
        // Insert the given name-number pair into the phone book in sorted order to avoid sorting when print is called.
        void insert(const string& name, const string& number);

        // Remove the first occurance of the given name from
        // the phone book
        void remove(const string& name);

        // Simulate a call to the given name.
        void call(const string& name);

        // Print the entire contents of the phone book
        void print() const;

        // Save the contents of this phone book to the given file
        void save(const string& filename) const;

        // Load the contents from the given file
        void load(const string& filename);

    private:
        List<Contact> data;
};

#endif // __phonebook_h__
