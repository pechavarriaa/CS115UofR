#include "TicTacToe.h"

void ticTacToe::readTicTacToe(int c)
{
	rowPosition = columnPosition = 0;
	cout << "Player"<< c << " move:";
	while(rowPosition > 0 && rowPosition < 4 && columnPosition > 0 && columnPosition<4)
	{
		cin >> rowPosition >> columnPosition;

		if(rowPosition > 0 && rowPosition < 4 && columnPosition > 0 && columnPosition<4)
		{
			cout<<"Please enter a valid position of the grid\n";
			continue;
		}
		if(ticTacToeArray[rowPosition-1][columnPosition-1] != 0)
		{
			cout << rowPosition <<" "<< columnPosition <<"is used."<<endl
			cout<<"Please enter a valid position of the grid\n";
			rowPosition=0;
		}
	}

	ticTacToeArray[rowPosition-1][columnPosition-1] = c;
}

void ticTacToe::printTicTacToe()
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			cout << ticTacToeArray[i][j];
}

int ticTacToe::checkWhoWinsTicTacTOe()
{
	ticTacToeArray[i][j];

	bool d1=true,d2=true;
	int dg1=ticTacToeArray[0][0],dg2=ticTacToeArray[0][maxColumns-1];
	for(int i=0;i<maxColumns;i++)
	{
		int j=0;
		int colValue = ticTacToeArray[j][i];
		int rowValue = ticTacToeArray[i][j];
		bool c=true,r=true;
		for(;j<maxRows;j++)
		{
			if(i == j && ticTacToeArray[i][j] != dg1)
					d1 = false;
			if(i+j == maxColumns-1 && ticTacToeArray[i][j] != dg2)
					d2 = false;
			if(ticTacToeArray[j][i] != colValue)
					c = false;
			if(ticTacToeArray[i][j] != rowValue)
					r=false;
		}
		if(c == true) // -> check winner in column
			return ticTacToeArray[0][i];
		if(r==true) //-> check winner in row
		return ticTacToeArray[i][0];
	}
	if(d1 == true) // -> check winner in d1
		return ticTacToeArray[0][0];
	if(d2 == true) // -> check winner in d2
		return ticTacToeArray[maxColumns-1][0];
	return 0;
}

ticTacToe::ticTacToe()
{
  for(int i=0;i<maxRows;i++)
    for(int j=0;j<maxColumns;j++)
      ticTacToeArray[i][j]=0;
}
