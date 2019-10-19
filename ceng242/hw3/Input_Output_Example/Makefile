LDFLAGS=-std=c++11

all: ; g++ $(LDFLAGS) main.cpp Laptime.cpp Car.cpp Race.cpp Championship.cpp -o Practice;
laptime: ; g++ $(LDFLAGS) main.cpp Laptime.cpp -o laptime;
car: ; g++ $(LDFLAGS) main.cpp Laptime.cpp Car.cpp -o car;
champ: ; g++ $(LDFLAGS) main.cpp Laptime.cpp Car.cpp Race.cpp Championship.cpp -o champ;
run: ; ./Practice
valgrind: ; valgrind --leak-check=full ./Practice
clean: ; rm -rf Practice;
