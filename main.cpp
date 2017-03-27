#include <iostream>

#include "NewGame.h"
#include "TicTacToe.h"
#include "GridGame.h"
#include "Grid.h"

void doStuff(Grid* name){

}

int main(int argc, char* argv[]){

	std::cout << "Hello World\n";

	int n = 3;

	Grid* name = new Grid(n);

	doStuff(name);


	return 0;
}
