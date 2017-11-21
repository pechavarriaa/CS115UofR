#pragma once

#include <iostream>	// I/O library (cin, cout)
#include <iomanip>	// I/O manipulation (fixed, setprecision())
#include <string>	// String library for manipulating strings of any character type.

using namespace std;

const int maxRows = 3;
const int maxColumns = 3;
const int maxTurns = 9;
//Class for playing tic tac toe
class ticTacToe
{
private:

	int ticTacToeArray[maxRows][maxColumns];

public:
	int i, j; //Variables for navigating through the matrix
	int rowPosition, columnPosition; //Variables for determining if the position that the player move is correct or not taken
	void readTicTacToe(int c); //Variable for input position for the next player
	void printTicTacToe(); //Print scoreboard
	int checkWhoWinsTicTacTOe(); //Variable to tell which one won or if the game is tide
	ticTacToe(); //Constructor
};
