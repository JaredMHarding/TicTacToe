#ifndef GRID_H
#define GRID_H
class Grid {

private:
    int **board;
    int size;

    bool isValid(int row, int col) const {
        if (row < 0 || col < 0 || row >= size || col >= size) {
            std::cout << "INVALID MOVE! Row and column choices must be less than " << size << ". Try again..." << '\n';
            return false;
        }
        return true;
    }

public:
	Grid(int n){
        //Constructor that creates an empty grid where n denotes the
		//number of rows (and the number of columns)
        size = n;
        board = new int*[size];
        for (int i = 0; i < size; i++) {
            board[i] = new int[size];
            for (int j = 0; j < size; j++) {
                board[i][j] = 0;
            }
        }
	}

    // default constructor
    Grid() {}

	Grid(const Grid& obj){
		//Copy constructor that creates a grid with an object
		//of Grid (do a deep copy).
        size = obj.size;
        board = new int*[size];
        for (int i = 0; i < size; i++) {
            board[i] = new int[size];
            for (int j = 0; j < size; j++) {
                board[i][j] = obj.board[i][j];
            }
        }
	}

	Grid(Grid&& obj){
		//Move constructor that creates a grid with an object of
		// Grid (do a shallow copy)
        size = obj.size;
        board = obj.board;
        obj.board = nullptr;
	}

	int getNumber(int row, int col) const {
		//Read number at grid location (row,col).
        if (isValid(row, col)) {
            return board[row][col];
        }
        return -1;
	}

	bool setNumber(int row, int col, int num) {
		// Set number at grid location (row, col) to "num"
        //std::cout << "in setNumber()"
        if (isValid(row, col)) {
            // this is for the ai, so it can clear it
            if (num == 0) {
                board[row][col] = num;
                return true;
            }
            if (isFixed(row, col)) { // if not empty...
                if (num == 1) {
                    std::cout << "INVALID MOVE! That location is taken...try again!" << '\n';
                }
                return false;
            }
            board[row][col] = num;
            return true;
        }
        return false;
	}

	bool isFixed(int row, int col) const {
		// Return true if the grid location (row, col) is fixed, i.e., not empty
            return board[row][col] != 0;

	}

	void clearGrid() {
		// Clear all values to 0 in all locations
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = 0;
            }
        }
	}

    int getSize() {
        return size;
    }

	~Grid(){
		//Destructor that does the memeory deallocation
        for (int i = 0; i < size; i++) {
            delete[] board[i];
        }
        delete[] board;
	}
};
#endif
