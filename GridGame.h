class GridGame {
	GridGame(){
		// Constructor
	}
	virtual int getStatus() const = 0; // A virtual function for checking the game status
	virtual bool placeMark(int row, int col, int p); // A virtual function for placing mark
	virtual void placeMark(int player)	; // A virtual function for placing mark
	void drawGrid() const; //Output the grid onto the screen
	void restart(); //Restart the game by clearing all values in all cells

	~GridGame(){
		// Deconstructor
	}
};
