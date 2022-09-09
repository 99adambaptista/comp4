CC = g++
CFLAGS = -std=c++11 -c -g -Wall -Werror# -pedantic
LIBS = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window

all: GuitarHero

GuitarHero: RingBuffer.o GuitarString.o GuitarHero.o
	$(CC) RingBuffer.o GuitarString.o GuitarHero.o -o GuitarHero $(LIBS)

GuitarHero.o: RingBuffer.hpp GuitarString.hpp GuitarHero.cpp
	$(CC) GuitarHero.cpp $(CFLAGS)

GuitarString.o: RingBuffer.hpp GuitarString.hpp GuitarString.cpp
	$(CC) GuitarString.cpp $(CFLAGS)

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) RingBuffer.cpp RingBuffer.hpp $(CFLAGS)

clean:
	rm *.o GuitarHero *.gch
