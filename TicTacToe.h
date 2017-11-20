#pragma once

#include <iostream>	// I/O library (cin, cout)
#include <iomanip>	// I/O manipulation (fixed, setprecision())
#include <string>	// String library for manipulating strings of any character type.

using namespace std;

const int maxRows = 3;
const int maxColumns = 3;
const int maxTurns = 9;

class ticTacToe
{
	private:

		int ticTacToeArray[maxRows][maxColumns];

	public:

		int rowPosition, columnPosition;
		void readTicTacToe(int c);
		void printTicTacToe();
		int checkWhoWinsTicTacTOe();
		ticTacToe();
};
