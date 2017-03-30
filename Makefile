#OPTIMIZE=-03 -DNDEBUG
DEBUGGABLE = -g
CFLAGS = -std=c++11 -Wall -pedantic $(OPTIMIZE) -c -g
Games: main.o
	g++ main.o -o Games
main.o: main.cpp GridGame.h TicTacToe.h NewGame.h Grid.h
	g++ $(CFLAGS) main.cpp
clean:
	rm -f Games *.o
