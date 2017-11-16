#include "Matrix.h"

MatrixOp::MatrixOp(int r, int c)
{
	rows = r;
	columns = c;
}

MatrixOp MatrixOp::add(MatrixOp mTwo)
{
	MatrixOp temp(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp.matrix[i][j] = matrix[i][j] + mTwo.matrix[i][j];
		}
	}
	return temp;
}
void MatrixOp::readMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void MatrixOp::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
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
			int x = 1;
			for (int z = 0; z < n; z++)
			{
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
				return false;
			}
		}
	}
	return true;
}