LDFLAGS=-std=c++11

all: ; g++ $(LDFLAGS) main.cpp Laptime.cpp Car.cpp Race.cpp Championship.cpp -o Practice;
run: ; ./Practice 
valgrind: ; valgrind --leak-check=full ./Practice
clean: ; rm -rf Practice;