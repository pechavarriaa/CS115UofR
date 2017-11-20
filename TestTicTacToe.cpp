#include "TicTacToe.h"

int main()
{
	int cont = 1; //To know which if is even or odd.
	int x = 0; // Different number than 0, 1, 2
	ticTacToe obj;//if does not run try -> ticTacToe obj();
	obj.printTicTacToe();
	while (x != 0 && cont <= maxTurns)//It will run forever but we want to run it until the game is over and use break for saying who won.
	{
		obj.readTicTacToe(3-cont%2+1);
		if (cont > 4)
			x = obj.checkWhoWinsTicTacTOe();
		cont++;
	}
	if(x==0)
		cout << "Draw game";
	else if(x == 1)
		cout << "Player1 wins!";
	else
		cout << "Player2 wins!"
}
