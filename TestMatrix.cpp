#include "Matrix.h"

using namespace std;

int main()
{
	int rows = 0;
	int columns = 0;
	int matrixOne[maxColumns][maxRows] = {};
	int matrixTwo[maxColumns][maxRows] = {};
	int addMatrix[maxColumns][maxRows] = {};
	int powerMatrix[maxColumns][maxRows] = {};

	MatrixOp Obj;
	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << "Enter the number of columns:";
	cin >> columns;

	cout << "Enter the elements of matrix 1 row by row:" << endl;
	Obj.readMatrix(rows, columns, matrixOne);

	cout << "Enter the elements of matrix 2 row by row:" << endl;
	Obj.readMatrix(rows, columns, matrixTwo);
	cout << "Add" << "\n";
	Obj.add(rows, columns, matrixOne, matrixTwo, addMatrix);
	Obj.print(rows, columns, addMatrix);
	int n = 2;
	Obj.power(rows, columns, n, matrixOne, powerMatrix);
	cout << "Power" << "\n";
	Obj.print(rows, columns, powerMatrix);
}

/*
1 0 3
5 1 2

1 1 2
1 0 4
*/