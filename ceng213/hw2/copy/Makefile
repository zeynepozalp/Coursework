CC=g++
CFLAGS=-c -ansi -Wall -pedantic-errors -O0

all: tpbst webstore

webstore: main_webstore.o photo.o stock_photo_webstore.o
	$(CC) main_webstore.o photo.o stock_photo_webstore.o -o webstore

tpbst: main_tpbst.o
	$(CC) main_tpbst.o -o tpbst

main_webstore.o: main_webstore.cpp
	$(CC) $(CFLAGS) main_webstore.cpp -o main_webstore.o

main_tpbst.o: main_tpbst.cpp
	$(CC) $(CFLAGS) main_tpbst.cpp -o main_tpbst.o

photo.o: photo.cpp photo.hpp
	$(CC) $(CFLAGS) photo.cpp

stock_photo_webstore.o: stock_photo_webstore.cpp stock_photo_webstore.hpp tpbst.hpp photo.hpp
	$(CC) $(CFLAGS) stock_photo_webstore.cpp

clean:
	rm *o
	rm tpbst
	rm webstore
