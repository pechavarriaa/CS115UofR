#include "TicTacToe.h"

int main()
{
	int cont = 1; //To know which player turn is if is even player2, if odd player1.
	int x = 0; //Different number than 0, 1, 2
	ticTacToe obj;//Creating object 
	obj.printTicTacToe(); //Printing on screen the game
	while (x == 0 && cont <= maxTurns)//It will run while maxTurns is less than 9
	{
		obj.readTicTacToe(3 - ((cont % 2) + 1));
		if (cont > 4)//After the 4th move one of the two players can win
			x = obj.checkWhoWinsTicTacTOe(); //The x will tell which player won or 0 if it has not finish
		obj.printTicTacToe();//Printing the game's board
		cont++;//Increasing counter to know the turn of the players
	}
	if (x == 0)//If exited while and is 0, maxTurns was equal to 9 and the game is tied
		cout << "Draw game";
	else if (x == 1)
		cout << "Player1 wins!";
	else
		cout << "Player2 wins!";
}