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

  void drawGrid() const{
    int size = grid->getSize();
    for(int row = 0; row < size; row++){
      for(int col = 0; col < size; col++){
        //hypothetically should print a bar to the right of the number
        if(grid->getNumber(row, col) == 1){
          std::cout<<" X ";
        }
        else if(grid->getNumber(row, col) == 2){
          std::cout<<" O ";
        }
        else{
          std::cout<<"   ";
        }
        //this->DrawGrid_pipe(col);

      }
      std::cout << std::endl;
      //hypothetically shoudl print a bar for each row
      // if(row < size-1){
      //   std::cout<< std::endl <<<<std::endl;
      // }
      }
  }

	void restart(); //Restart the game by clearing all values in all cells

	~GridGame() {
		// Deconstructor
	}
};
#endif
