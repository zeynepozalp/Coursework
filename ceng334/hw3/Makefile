EXEC=ext2shell
DIST=hw3.tar.gz
all:
	gcc main.c vfs/*.c ext2_fs/*.c -o $(EXEC) -g -I.

dist:
	tar -czvf $(DIST) Makefile main.c $(wildcard *.h) ext2_fs vfs

clean:
	rm $(DIST) $(EXEC)
