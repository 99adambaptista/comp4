CC = g++
CFLAGS = -std=c++11 -c -g -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: NBody

NBody: main.o planets.o
	$(CC) main.o -o NBody $(LIBS)

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

planets.o: planets.cpp planets.hpp
	$(CC) -c $(CFLAGS) planets.cpp planets.hpp

clean:
	rm *.o NBody *.gch
