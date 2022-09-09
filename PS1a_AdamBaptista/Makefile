all: ps1a 

ps1a: LSFR.o test.o
	g++ LSFR.o test.o -o ps1a

clean:
	rm *.o ps1a

LSFR.o: LSFR.cpp LSFR.hpp
	g++ LSFR.cpp -o LSFR.o -c -Wall -Werror -pedantic

#test.o: test.cpp
#	g++ -c -o -Wall -Werror -pedantic test.cpp test.o
