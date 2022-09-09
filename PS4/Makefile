CC = g++
CFLAGS = -std=c++11 -c -g -Wall -Werror -pedantic
LIBS = -lsfml-system

all: ED

ED: main.o ED.o
	$(CC) main.o -o ED $(LIBS)

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp

planets.o: ED.cpp ED.hpp
	$(CC) -c $(CFLAGS) ED.cpp ED.hpp

clean:
	rm *.o ED massif*