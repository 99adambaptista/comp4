CC = g++
CFLAGS = -std=c++11 -c -g -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: tree

tree: main.o PTree.o
	$(CC) main.o PTree.o -o tree $(LIBS)

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

PTree.o: PTree.cpp PTree.hpp
	$(CC) -c $(CFLAGS) PTree.cpp PTree.hpp

clean:
	rm *.o *.gch tree
