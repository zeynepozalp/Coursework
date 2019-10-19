#include <iostream>
#include <cstdio>
#include <cctype>
#include <unistd.h>
#include <termios.h>

#include "phonebook.hpp"

using namespace std;

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

void mainLoop(PhoneBook& pb)
{
    while (1)
    {
        cout << "(n: insert new contact, r: remove contact, c: call contact, p: print phone book, s: save phone book, l: load phone book, q: quit)" << endl;
        cout << "> " << flush;

        char key = tolower(getch());

        string name, number;
        switch (key)
        {
            case 'n':
                cout << endl << "Name: " << flush;
                cin >> name;

                cout << "Number: " << flush;
                cin >> number;

                pb.insert(name, number);

                break;

            case 'r':
                cout << endl << "Name: " << flush;
                cin >> name;

                pb.remove(name);

                break;

            case 'c':
                cout << endl << "Name: " << flush;
                cin >> name;

                pb.call(name);

                break;

            case 'p':
                pb.print();

                break;

            case 's':
                cout << endl << "Filename: " << flush;
                cin >> name;

                pb.save(name);

                break;

            case 'l':
                cout << endl << "Filename: " << flush;
                cin >> name;

                pb.load(name);

                break;

            case 'q':
                return;

                break;

            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

}

int main()
{
    PhoneBook phoneBook;

    mainLoop(phoneBook);

    return 0;
}
