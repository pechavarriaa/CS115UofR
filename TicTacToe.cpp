#include "TicTacToe.h"

void ticTacToe::readTicTacToe(int c)//Function for reading from the users
{
	rowPosition = columnPosition = 0;//
	cout << "Player" << c << " move:";//Printing turn on the display
	while (!(rowPosition > 0 && rowPosition < 4 && columnPosition > 0 && columnPosition < 4))//Defining limits inside the matrix
	{
		cin >> rowPosition >> columnPosition;//Player input

		if (!(rowPosition > 0 && rowPosition < 4 && columnPosition > 0 && columnPosition < 4))//If goes in, it was a invalid move
		{
			cout << "Please enter a valid position of the grid\n";
			continue;
		}
		if (ticTacToeArray[rowPosition - 1][columnPosition - 1] != 0)//For knowing wich if the position was alredy taken
		{
			cout << rowPosition << " " << columnPosition << "is used. ";
			cout << "Please choose another move: ";
			rowPosition = 0;
		}
	}

	ticTacToeArray[rowPosition - 1][columnPosition - 1] = c;//If it makes it throgh here, it assigns the value into the matrix
	cout << endl;
}

void ticTacToe::printTicTacToe()//Function for printing the matrix each time the player moves
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << ticTacToeArray[i][j] << " ";
		cout << endl;
	}
}

int ticTacToe::checkWhoWinsTicTacTOe()//Determining which player wins of if it is tied
{
	ticTacToeArray[i][j];

	bool d1 = true, d2 = true;//Variables for telling if all the numbers in the diagonal are the same
	int dg1 = ticTacToeArray[0][0], dg2 = ticTacToeArray[0][maxColumns - 1];//Initializing variables for checking the diagonals of the matrix
	for (int i = 0; i < maxColumns; i++)
	{
		int j = 0;//Initializing j here so that the next variables can be used with j
		int colValue = ticTacToeArray[j][i];//Getting the first value to check the columns (seed)
		int rowValue = ticTacToeArray[i][j];//Getting the first value to check the rows (seed) 
		bool c = true, r = true;
		for (; j < maxRows; j++)//Navigating throgh the matrix
		{
			if (i == j && ticTacToeArray[i][j] != dg1)//Checking diagonal from left to right
				d1 = false;
			if (i + j == maxColumns - 1 && ticTacToeArray[i][j] != dg2)//Checking diagonal from right to left
				d2 = false;
			if (ticTacToeArray[j][i] != colValue)//Checking columns
				c = false;
			if (ticTacToeArray[i][j] != rowValue)//Checking rows
				r = false;
		}
		if (c == true) // -> check winner in column
			return ticTacToeArray[0][i];
		if (r == true) //-> check winner in row
			return ticTacToeArray[i][0];
	}
	if (d1 == true) // -> check winner in d1
		return ticTacToeArray[0][0];
	if (d2 == true) // -> check winner in d2
		return ticTacToeArray[maxColumns - 1][0];
	return 0;//If return 0 the game is tied, or it has not finish yet
}

ticTacToe::ticTacToe()//Initialing matrix with constructor
{
	for (int i = 0; i < maxRows; i++)
		for (int j = 0; j < maxColumns; j++)
			ticTacToeArray[i][j] = 0;//Filling array with zeros
}
