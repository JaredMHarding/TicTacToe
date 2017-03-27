class TicTacToe{

	TicTacToe(){
		//Default Constructor
	}

	int getStatus() const; //According to the rule of
	//TicTacToe, return 0 if the game is a tie; return
	//1 if the first player has won the game; return 2
	//if the second player has won the game; return 3 otherwise.
	bool placeMark1(int row, int col, int p); // Return false if
	// the location is already fixed; otherwise, place a mark
	// at the grid location (row,col) for player “p”, i.e.,
	// invoking setNumber(row, col, p) of the nested Grid object
	// return true.
	void placeMark2(int row, int col, int p); //Use some algorithm
	// such as “minimax” to place a mark on an empty location for player “p”.

	/*

	Add other methods in order to play game with computer

	*/


	~TicTacToe(){
		//Deconstructor
	}
};
