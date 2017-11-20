#include "TicTacToe.h"

void ticTacToe::readTicTacToe(int c)
{
	cout << "Player"<< c << " move:";
	cin >> rows, columns;
}

void ticTacToe::printTicTacToe()
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			cout << ticTacToeArray[i][j];
}

bool ticTacToe::checkWhoWinsTicTacTOe()
{
	ticTacToeArray[i][j];
}

ticTacToe::ticTacToe()
{
  for(int i=0;i<maxRows;i++)
    for(int j=0;j<maxColumns;j++)
      ticTacToeArray[i][j]=0;
}