#include "Matrix.h"//include header

MatrixOp::MatrixOp(int r, int c)//Constructor
{
	rows = r; //r and c from input
	columns = c;
}

MatrixOp MatrixOp::add(MatrixOp mTwo)//Adding the two matrices of type MatrixOp
{
	MatrixOp temp(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp.matrix[i][j] = matrix[i][j] + mTwo.matrix[i][j];
			//add in temp the values from both matrices
		}
	}
	return temp; //Returning matrix
}
void MatrixOp::readMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
			//read each value
		}
	}
}
void MatrixOp::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//print each value from matrix
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void MatrixOp::power(int n)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int x = 1;//initialize to 1 to multiply and get the value
			for (int z = 0; z < n; z++)
			{
				// each value to power of n
				x *= matrix[i][j];
			}
			matrix[i][j] = x;
		}
	}

}

bool MatrixOp::operator== (MatrixOp mTwo)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] != mTwo.matrix[i][j])
			{
				//if at any point they are different return false
				return false;
			}
		}
	}
	//if they always were equal return true
	return true;
}
