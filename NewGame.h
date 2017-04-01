#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
#include "GridGame.h"
class NewGame : public GridGame{
public:
	static const int gridSize = 5;
    static const int empty = 0;
    static const int human_X = 1;
    static const int AI_O = 2;

	NewGame() : GridGame(gridSize){}

	int getStatus() const{
		// According to the game you designed,
		// return different values to indicate the game status.
		// return 0 if the game is a tie;
        // return 1 if the first player has won the game; return 2
    	// if the second player has won the game; return 3 otherwise.
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
        aiChoose();
	}

	bool placeMark(int row, int col, int player) {
		if (grid->setNumber(row, col, player)) {
			return true;
		}
		return false;
	}

	void gameOver(int endState) {
		std::string playAgain;
		std::string winner = (endState == 1) ? "The computer" : "The human";
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
		int row;
		int col;
		int winner;
		std::cout << "Welcome to TicTacNo!" << '\n';
		std::cout << "This game is the anti-TicTacToe.\n";
		std::cout << "Try to avoid making 3 in a row on this 5x5 grid.\n";
		std::cout << "Whoever makes 3 in a row first looses!\n";
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
				std::cout << "Enter your desired column number (0 based): " << '\n';
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
	// Deconstructor
	~NewGame() {}

private:
	int checkWinsHor() const {
		int first, second, third;
        for (int i = 0;i < gridSize;i++) {
            for (int j = 0;j < gridSize-2;j++) {
                first = grid->getNumber(i, j);
                second = grid->getNumber(i, j+1);
                third = grid->getNumber(i, j+2);
                if (first == second && second == third && first != 0) {
                    return first;
                }
            }
        }
        return -1;
	}

	int checkWinsVert() const {
        int first, second, third;
        for (int i = 0;i < gridSize-2;i++) {
            for (int j = 0;j < gridSize;j++) {
                first = grid->getNumber(i, j);
                second = grid->getNumber(i+1, j);
                third = grid->getNumber(i+2, j);
                if (first == second && second == third && first != 0) {
                    return first;
                }
            }
        }
        return -1;
	}

	int checkWinsNWSE() const {
        int first, second, third;
        for (int i = 0;i < gridSize-2;i++) {
            for (int j = 0;j < gridSize-2;j++) {
                first = grid->getNumber(i, j);
                second = grid->getNumber(i+1, j+1);
                third = grid->getNumber(i+2, j+2);
                if (first == second && second == third && first != 0) {
                    return first;
                }
            }
        }
        return -1;
	}

	int checkWinsNESW() const {
        int first, second, third;
        for (int i = 0;i < gridSize-2;i++) {
            for (int j = 2;j < gridSize;j++) {
                first = grid->getNumber(i, j);
                second = grid->getNumber(i+1, j-1);
                third = grid->getNumber(i+2, j-2);
                if (first == second && second == third && first != 0) {
                    return first;
                }
            }
        }
        return -1;
	}

    // this isn't the best algorithm, but it seems to work
    void aiChoose() {
        if (getStatus() == 3) {
            // spots where the ai would make 3 in a row
            int aiWin[gridSize*gridSize][2];
            int aiWinNum = 0;
            // spots where the human would make 3 in a row
            int humanWin[gridSize*gridSize][2];
            int humanWinNum = 0;
            // spots that don't make 3 in a row
            int fine[gridSize*gridSize][2];
            int fineNum = 0;
            for (int i = 0;i < gridSize;i++) {
                for (int j = 0;j < gridSize;j++) {
                    // put the pair into either the avoid array
                    // or the fine array if it is empty
                    if (!grid->isFixed(i,j)) {
                        placeMark(i,j,AI_O);
                        // did the AI make 3 in a row?
                        if (getStatus() != 3) {
                            // remove it and add to the avoid array
                            placeMark(i,j,empty);
                            aiWin[aiWinNum][0] = i;
                            aiWin[aiWinNum][1] = j;
                            aiWinNum++;
                            // done with this spot, move on
                            continue;
                        }
                        placeMark(i,j,empty);
                        // now test if the human can make 3 in a row
                        placeMark(i,j,human_X);
                        if (getStatus() != 3) {
                            // remove it and add to the avoid array
                            placeMark(i,j,empty);
                            humanWin[humanWinNum][0] = i;
                            humanWin[humanWinNum][1] = j;
                            humanWinNum++;
                            // done with this spot, move on
                            continue;
                        }
                        placeMark(i,j,empty);
                        // if we got to this point, it is fine
                        fine[fineNum][0] = i;
                        fine[fineNum][1] = j;
                        fineNum++;
                    }
                }
            }
            // are there any fine spots? then pick one of those
            srand(time(0));
            if (fineNum > 0) {
                int randIndex = rand() % fineNum;
                placeMark(fine[randIndex][0],fine[randIndex][1],AI_O);
            }
            // otherwise pick a spot where a human could make 3
            else if (humanWinNum > 0) {
                int randIndex = rand() % humanWinNum;
                placeMark(humanWin[randIndex][0],humanWin[randIndex][1],AI_O);
            }
            // otherwise, just pick one from the aiWin
            // there's no other choice
            else {
                int randIndex = rand() % aiWinNum;
                placeMark(aiWin[randIndex][0],aiWin[randIndex][1],AI_O);
            }
        }
    }
};













