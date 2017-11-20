#include "TicTacToe.h"

int main()
{
	int cont = 1; //To know which if is even or odd. 
	ticTacToe obj;//if does not run try -> ticTacToe obj();
	obj.printTicTacToe();
	while (1)//It will run forever but we want to run it until the game is over and use break for saying who won.
	{
		if (cont % 2 == 0)
			obj.readTicTacToe(2);
		else
			obj.readTicTacToe(1);
		if (cont > 4)
			obj.checkWhoWinsTicTacTOe();
		cont++;
	}
}
