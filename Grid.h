class Grid{

public:
	Grid(int n){
	//Constructor that creates an empty grid where n denotes the
		//number of rows (and the number of columns).
	}
	Grid(const Grid& obj){
		 //Copy constructor that creates a grid with an object
		//of Grid (do a deep copy).
	}
	Grid(Grid&& obj){
		//Move constructor that creates a grid with an object of
		// Grid (do a shallow copy)
	}
	int getNumber(int row, int col) const{
		//Read number at grid location (row,col).
		return 0;
	}
	void setNumber(int row, int col, int num){
		// Set number at grid location (row, col) to "num"
	}
	bool isFixed(int row, int col) const{
		// Return true if the grid location (row, col) is fixed, i.e., not empty
		return false;
	}
	void clearGrid(){
		// Clear all values to 0 in all locations
	}
	~Grid(){
		//Destructor that does the memeory deallocation
	}
};
