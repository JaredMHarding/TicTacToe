#include <iostream>
#include "NewGame.h"
#include "TicTacToe.h"

int main(int argc, char* argv[]) {
	TicTacToe* g = new TicTacToe();
  g->drawGrid();
  //bool flag = g->placeMark(0, 0, 1);
  g->drawGrid();
  /*g->setNumber(1, 1, 2);
  g->drawGrid();
  g->setNumber(2, 2, 1);
  g->drawGrid();
  */
	return 0;
}
