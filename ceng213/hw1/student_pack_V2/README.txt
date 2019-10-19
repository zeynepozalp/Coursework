Testing LinkedList
----------------------
g++ main_LinkedList.cpp -o LinkedList
./LinkedList
./LinkedList > main_LinkedList.out
valgrind ./LinkedList

Testing VideoShare
-----------------------
g++ main_VideoShare.cpp VideoShare.cpp Video.cpp User.cpp  -o VideoShare
./VideoShare
./VideoShare > main_VideoShare.out
valgrind ./VideoShare

