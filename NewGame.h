class NewGame {

	NewGame() {
		//Default constructor
	}

	int getStatus() const; //According to the game you designed,
	// return different values to indicate the game status.

	bool placeMark1(int row, int col, int p) {  //Return false if the
	// location is already fixed; otherwise, place a mark at the grid
	// location (row,col) for player “p”, i.e., invoking
	// setNumber(row, col, p) of the nested Grid object and return true.
		return false;
	}


	void placeMark2(int row, int col, int p); //Use some algorithm such
	// as “minimax” to place a mark on an empty location for player “p”

	/*

	Add other methods needed in order to play computer

	*/

	~NewGame() {
		// Deconstructor
	}

};
