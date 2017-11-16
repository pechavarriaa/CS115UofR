#include "Matrix.h"

using namespace std;

int main()
{
	int rows;
	int columns;
	int n;
	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << "Enter the number of columns:";
	cin >> columns;

	
	MatrixOp mOne(rows, columns);
	MatrixOp mTwo(rows, columns);
	

	cout << "Enter the elements of matrix 1 row by row:\n";
	mOne.readMatrix();

	cout << "Enter the elements of matrix 2 row by row:\n";
	mTwo.readMatrix();

	cout << "matrix 1 == matrix 2?\n";
	if (mOne == mTwo)
		cout << "Yes\n";
	else
		cout << "No\n";

	cout << "matrix 1 + matrix 2:\n";
	MatrixOp obj = mOne.add(mTwo);
	obj.print();

	cout << "matrix 1 power n. Enter n: ";
	cin >> n;
	mOne.power(n);
	mOne.print();
}

/*
1 0 3
5 1 2

1 1 2
1 0 4
*/