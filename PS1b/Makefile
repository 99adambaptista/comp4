CC = g++
CFLAGS = -std=c++11 -c -g -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic $(LIBS)

PhotoMagic.o: PhotoMagic.cpp LFSR.cpp
	$(CC) -c PhotoMagic.cpp LFSR.cpp

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) $(CFLAGS) LFSR.cpp -o LFSR.o

clean:
	rm *.o PhotoMagic