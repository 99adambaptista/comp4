CC = g++
CFLAGS = -c -g -std=c++11
OBJ = main.o
DEPS = 
LIBS = -ansi -pedantic -Wall -Werror -lboost_regex -lboost_date_time
EXE = ps7

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

ps7: main.cpp
	$(CC) $(OBJ) -o

clean:
	rm $(OBJ) $(EXE)
