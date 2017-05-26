//This file is created by Abir Razzak for CS172 Assignment 3
//This file implements the tBoard object
#include <vector>
#include <iostream>
#include <string>
#include "symbol.h"
#include "tic.h"
using namespace std;

	//Default Constructor
	//Makes a board with all blank spaces
	tBoard::tBoard() {
		matrix.resize(3, vector<symbol>(3, BLANK));
	}
	//Makes a move on the board
	//X is the row and y is the column
	//m is the symbol to place (either X or O)
	//It returns true if the move was made
	//If the move is illegal, return false and do not change the table
	bool tBoard::move(symbol m, int x, int y) {
		try {
			matrix.at(x).at(y);
			if (matrix[x][y] == BLANK) {
				matrix[x][y] = m;
				return true;
			}
			else return false;
		}
		catch (const std::out_of_range & e) {
			return false;
		}
	}
	//Returns true if the game is over
	//This could be because of a winner or because of a tie
	bool tBoard::game_over() {

		//If a winner is declared, then the game is over
		if (winner() != BLANK) return true;
		
		//If there are any blank spaces, game is not over
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (matrix[i][j] == BLANK) return false;
			}
		}

		//If there is no winner and no blank spaces, then game over
		return true;

	}
	//Returns who won X or O.
	//If the game was a tie, return  BLANK
	symbol tBoard::winner() {

		for (int i = 0; i < 3; i++) {
			//Check if entire column is the same symbol (not BLANK)
			if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][1] != BLANK) return matrix[i][0];
			
			//Check if entire row is the same symbol (not BLANK)
			if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[1][i] != BLANK) return matrix[i][0];
		}

		//Check diagonals
		if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != BLANK) return matrix[0][0];
		if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2] && matrix[1][1] != BLANK) return matrix[2][0];

		//No winners? Then tie
		return BLANK;
	}
	//Added in by: Abir Razzak
	//Returns the symbol in position (x,y)
	symbol tBoard::get_symbol(int x, int y) const {
		return matrix[x][y];
	}
//Overload the output operator
ostream & operator<<(ostream& os, const tBoard& myTable) {
	os << " |  0  |  1  |  2  |" << endl
		<< " +-----------------+" << endl
		<< "0|  " << myTable.get_symbol(0, 0) << "  "
		<< "|  " << myTable.get_symbol(0, 1) << "  "
		<< "|  " << myTable.get_symbol(0, 2) << "  |" << endl
		<< " +-----------------+" << endl
		<< "1|  " << myTable.get_symbol(1, 0) << "  "
		<< "|  " << myTable.get_symbol(1, 1) << "  "
		<< "|  " << myTable.get_symbol(1, 2) << "  |" << endl
		<< " +-----------------+" << endl
		<< "2|  " << myTable.get_symbol(2, 0) << "  "
		<< "|  " << myTable.get_symbol(2, 1) << "  "
		<< "|  " << myTable.get_symbol(2, 2) << "  |" << endl
		<< " +-----------------+" << endl;
	return os; //actually check this tho
}