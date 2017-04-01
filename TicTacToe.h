#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
#include "GridGame.h"
class TicTacToe : public GridGame {
public:
    static const int gridSize = 3;
    static const int empty = 0;
    static const int human_X = 1;
    static const int AI_O = 2;
//    static const int inf = 1<<20;

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

    bool placeMark(int row, int col, int player) {
        if (grid->setNumber(row, col, player)) {
            return true;
        }
        return false;
    }

    void placeMark(int player) {
        aiChoose();
    }

    void gameOver(int endState) {
        std::string playAgain;
        std::string winner = (endState == 1) ? "The human" : "The computer";
        std::cout << "Game over!" << "\n";
        if (endState == 0) {
            std::cout << "It is a tie!" << "\n";
        } else {
            std::cout << winner << " won!" << "\n";
        }
        std::cout << "Would you like to play again? Enter 'y' or 'n'\n";
        std::cin >> playAgain;
        if (playAgain.compare("y") == 0) {
            grid->clearGrid();
            startGame();
        } else {
            std::cout << "Thanks for playing! GOODBYE\n";
            exit(0);
        }
    }

    void startGame() {
        char row;
        char col;
        int winner;
        std::cout << "Welcome to TicTacToe!" << '\n';
        while(true) {
            drawGrid();
            std::cout << "Enter your desired row number (0 based): " << '\n';
            std::cin >> row;
            std::cout << "Enter your desired column number(0 based): " << '\n';
            std::cin >> col;
            // human move
            while (!placeMark(row, col, human_X)) {
                std::cout << "Enter your desired row number (0 based): " << '\n';
                std::cin >> row;
                std::cout << "Enter your desired column number(0 based): " << '\n';
                std::cin >> col;
            }
            // human move
            if ((winner = getStatus()) != 3) {
                break;
            }
            // AI move
            placeMark(AI_O);
            if ((winner = getStatus()) != 3) {
                break;
            }
        }
        drawGrid();
        gameOver(winner);
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
// This is a faulty minimax algorithm we tried to implement
/*
    int aiChoose(int player, int n, int* row, int* col) {
        int result;
        int max = -inf;
        int min = inf;

        int status = getStatus();
        if (status != 3) {
            return status;
        }
        for (int i = 0;i < gridSize;i++) {
            for (int j = 0;j < gridSize;j++) {
                if (!grid->isFixed(i,j)) {
                    if (player == AI_O) {
                        placeMark(i,j,AI_O);
                        result = aiChoose(human_X,n+1,row,col);
                        placeMark(i,j,empty);
                        if (result < min) {
                            min = result;
                            if (n == 0) {
                                *row = i;
                                *col = j;
                            }
                        }
                    }
                    else if (player == human_X) {
                        placeMark(i,j,human_X);
                        result = aiChoose(AI_O,n+1,row,col);
                        placeMark(i,j,empty);
                        if (result > max) {
                            max = result;
                            if (n == 0) {
                                *row = i;
                                *col = j;
                            }
                        }
                    }
                }
            }
        }
        if (player == human_X) {
            return max;
        }
        else {
            return min;
        }
    }
*/
    void aiChoose() {
        if (getStatus() == 3) {
            for (int i = 0;i < gridSize;i++) {
                for (int j = 0;j < gridSize;j++) {
                    if (!grid->isFixed(i,j)) {
                        placeMark(i,j,AI_O);
                        if (getStatus() != 3) {
                            return;
                        }
                        placeMark(i,j,empty);
                        placeMark(i,j,human_X);
                        if (getStatus() != 3) {
                            // don't actually put X
                            // it was just to see if the human could win
                            placeMark(i,j,empty);
                            placeMark(i,j,AI_O);
                            return;
                        }
                        placeMark(i,j,empty);
                    }
                }
            }
            // if it couldn't win or block, pick a random slot
            int randRow;
            int randCol;
            srand(time(0));
            do {
                randRow = rand() % gridSize;
                randCol = rand() % gridSize;
            } while(!placeMark(randRow,randCol,AI_O));
        }
    }
};