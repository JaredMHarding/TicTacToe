#ifndef GRIDGAME_H
#define GRIDGAME_H
#include "Grid.h"
class GridGame {
protected:
        Grid *grid;
public:
	GridGame(int n) {
		// Constructor
        grid = new Grid(n);
	}

	virtual int getStatus() const = 0; // A virtual function for checking the game status
	virtual bool placeMark(int row, int col, int p) = 0; // A virtual function for placing mark
	virtual void placeMark(int player) = 0; // A virtual function for placing mark


    // this will be called on every move
    void drawGrid() const {
        int size = grid->getSize();
        int i, j;
        int move;
        for(i = 0; i < size; i++) {
            for(j = 0; j < size-1; j++) {
                move = grid->getNumber(i, j);
                printMove(move);
                std::cout << '|';
            }
            move = grid->getNumber(i, j);
            printMove(move);
            std::cout << '\n';
        }
        std::cout << '\n';
    }

	void restart() {
        //Restart the game by clearing all values in all cells
        grid->clearGrid();
    }

    void printMove(int move) const {
        switch (move) {
            case 1: std::cout << 'X';
                break;
            case 2: std::cout << 'O';
                break;
            default: std::cout << ' ';
                break;
        }
    }

	~GridGame() {
		// Deconstructor
        grid->~Grid();
	}
};
#endif
