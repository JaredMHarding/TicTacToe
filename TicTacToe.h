#include "GridGame.h"
class TicTacToe : public GridGame {
public:
  static const int gridSize = 3;
  static const int empty = 0;
  static const int human_X = 1;
  static const int AI_O = 2;

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

  void aiChoose(int* row, int* col) {
    int score = 10;

    for (int i = 0;i < gridSize;i++) {
      for (int j = 0;j < gridSize;j++) {
        if (!grid->isFixed(i,j)) {
          grid->setNumber(i,j,AI_O);
          int tempScore = YMove(i,j);
          grid->setNumber(i,j,empty);
          if (tempScore < score) {
            score = tempScore;
            *row = i;
            *col = j;
          }
        }
      }
    }
  }

  bool placeMark(int row, int col, int player) {
    if (grid->isFixed(row,col)) {
      return false;
    }
    grid->setNumber(row,col,player);
    return true;
  }

  void placeMark(int player) {
    int row, col;
    aiChoose(&row, &col);
    placeMark(row,col,player);
  }

  void startGame() {

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

  int IMove() {
    if (getStatus() != 3) {
      return 10;
    }
    int score = 10;
    for (int i = 0;i < gridSize;i++) {
      for (int j = 0;j < gridSize;j++) {
        if (!grid->isFixed(i,j)) {
          grid->setNumber(i,j,AI_O);
          int tempScore = YMove();
          grid->setNumber(i,j,empty);
          if (tempScore < score) {
            score = tempScore;
          }
        }
      }
    }
  }

  int YMove() {
    if (getStatus() != 3) {
      return -10;
    }
    int score = -10;
    for (int i = 0;i < gridSize;i++) {
      for (int j = 0;j < gridSize;j++) {
        if (!grid->isFixed(i,j)) {
          grid->setNumber(i,j,human_X);
          int tempScore = IMove();
          grid->setNumber(i,j,empty);
          if (tempScore > score) {
            score = tempScore;
          }
        }
      }
    }
  }
};
