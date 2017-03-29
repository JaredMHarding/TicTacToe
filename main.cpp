#include <iostream>

#include "NewGame.h"
#include "TicTacToe.h"
#include "GridGame.h"
#include "Grid.h"

int main(int argc, char* argv[]) {
	int n = 3;
	GridGame* name = new TicTacToe();
  name->drawGrid();

	return 0;
}
