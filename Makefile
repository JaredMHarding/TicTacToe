#OPTIMIZE=-03 -DNDEBUG
DEBUGGABLE = -g
CFLAGS = -std=c++11 -Wall -pedantic $(OPTIMIZE) -c -g
TicTacToe: main.o
    g++ main.o -o TicTacToe
main.o: main.cpp GridGame.h TicTacToe.h NewGame.h Grid.h
    g++ $(CFLAGS) main.cpp
clean:
    rm -f TicTacToe *.o
