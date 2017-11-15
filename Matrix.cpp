#include "Matrix.h"

void MatrixOp::add(int &r, int &c, int matrixOne[][maxRows], int matrixTwo[][maxRows], int addMatrix[][maxRows])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			addMatrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];
		}
	}
}
void MatrixOp::readMatrix(int &r, int &c, int fillMatrix[][maxRows])
{
	int temp = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> temp;
			fillMatrix[i][j] = temp;
		}
	}
}

void MatrixOp::print(int &r, int &c, int addMatrix[][maxRows])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << addMatrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void MatrixOp::power(int &r, int &c, int &n, int matrixOne[][maxRows], int powerMatrix[][maxRows])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			powerMatrix[i][j] = 1;
			for (int z = 0; z < n; z++)
			{
				powerMatrix[i][j] *= matrixOne[i][j];
			}
		}
	}

}