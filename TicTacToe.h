#include "GridGame.h"
class TicTacToe : public GridGame {
public:
  static const int gridSize = 3;
	TicTacToe() : GridGame(gridSize) {
	}

	int getStatus() const {
    //According to the rule of
  	//TicTacToe, return 0 if the game is a tie; return
  	//1 if the first player has won the game; return 2
  	//if the second player has won the game; return 3 otherwise.
    return 0;
  }

  void placeMark(int player) {
    //TODO
  }

	bool placeMark(int row, int col, int p){ // Return false if
	  // the location is already fixed; otherwise, place a mark
	  // at the grid location (row,col) for player “p”, i.e.,
	  // invoking setNumber(row, col, p) of the nested Grid object
	  // return true.
    return false;
  }
	/*
	Add other methods in order to play game with computer
	*/

	~TicTacToe(){
		//Deconstructor
	}
};
