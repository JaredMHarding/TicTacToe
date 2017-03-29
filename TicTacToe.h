#include "GridGame.h"
class TicTacToe : public GridGame {
public:
  static const int gridSize = 3;

	TicTacToe() : GridGame(gridSize) {}

	int getStatus() const {
    //return 0 if the game is a tie;
    //return 1 if the first player has won the game; return 2
  	//if the second player has won the game; return 3 otherwise.
    int vert = checkWinsVert();
    int hor = checkWinsHor();
    int NWSE = checkWinsNWSE();
    int NESW = checkWinsNESW();
    if (vert == 1 || hor == 1 || NWSE == 1 || NESW == 1) return 1;
    if (vert == 2 || hor == 2 || NWSE == 2 || NESW == 2) return 2;

    if (vert == -1 && hor == -1 && NWSE == -1 && NESW == -1) {
      for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
          // if there is a 0 still in board, return 3 to keep playing
          if (!grid->isFixed(i, j)) return 3;
        }
      }
    }
    // a tie!
    return 0;
  }

  void placeMark(int player) {
    //TODO this is call virtual bool placeMark to make sure that its valid
    // also do stdin to take move from player
    std::cout << "";
  }

  virtual bool placeMark(int row, int col, int player) {
    if (grid->setNumber(row, col, player)) {
      return true;
    }
    return false;
  }

  void startGame() {
    std::cout << "Welcome to TicTacToe!" << '\n';
    std::cout << "Please enter you " << '\n';
  }

	~TicTacToe() {}

private:
  int checkWinsHor() const {
    int first, second, third;
    for (int i = 0; i < gridSize; i++) {
      first = grid->getNumber(i, 0);
      second = grid->getNumber(i, 1);
      third = grid->getNumber(i, 2);
      if (first == second && second == third && first != 0) {
        return first;
      }
    }
    return -1;
  }

  int checkWinsVert() const {
    int first, second, third;
    for (int i = 0; i < gridSize; i++) {
      first = grid->getNumber(0, i);
      second = grid->getNumber(1, i);
      third = grid->getNumber(2, i);
      if (first == second && second == third && first != 0) {
        return first;
      }
    }
    return -1;
  }

  int checkWinsNWSE() const {
    int first, second, third;
    first = grid->getNumber(0, 0);
    second = grid->getNumber(1, 1);
    third = grid->getNumber(2, 2);
    if (first == second && second == third && first != 0) {
      return first;
    }
    return -1;
  }

  int checkWinsNESW() const {
    int first, second, third;
    first = grid->getNumber(0, 2);
    second = grid->getNumber(1, 1);
    third = grid->getNumber(2, 0);
    if (first == second && second == third && first != 0) {
      return first;
    }
    return -1;
  }
};
