#include <iostream>
#include "NewGame.h"
#include "TicTacToe.h"

int main(int argc, char* argv[]) {
	TicTacToe* g = new TicTacToe();
  g->startGame();
	return 0;
}
