#include "Matrix.h"

using namespace std;

int main()
{
	MatrixOp Obj;

	cout << "Enter the number of rows: ";
	cin >> Obj.rows;
	cout << "Enter the number of columns:";
	cin >> Obj.columns;

	cout << "Enter the elements of matrix 1 row by row:" << endl;
	Obj.readMatrix(Obj.rows, Obj.columns, Obj.matrixOne);

	cout << "Enter the elements of matrix 2 row by row:" << endl;
	Obj.readMatrix(Obj.rows, Obj.columns, Obj.matrixTwo);
	cout << "Add" << "\n";
	Obj.add(Obj.rows, Obj.columns, Obj.matrixOne, Obj.matrixTwo, Obj.addMatrix);
	Obj.print(Obj.rows, Obj.columns, Obj.addMatrix);
	int n = 2; //It is needed to change this, the user has to input the value.
	Obj.power(Obj.rows, Obj.columns, n, Obj.matrixOne, Obj.powerMatrix);
	cout << "Power" << "\n";
	Obj.print(Obj.rows, Obj.columns, Obj.powerMatrix);

	Obj.operator==(Obj.matrixTwo);
}

/*
1 0 3
5 1 2

1 1 2
1 0 4
*/