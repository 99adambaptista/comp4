CC = g++
CFLAGS = -std=c++11 -c -g -Wall -Werror# -pedantic

all: ps5a

ps5a: test.o RingBuffer.o
	$(CC) test.o -o ps5a $(LIBS)

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) -c $(CFLAGS) RingBuffer.cpp RingBuffer.hpp

clean:
	rm *.o ps5a *.gch
