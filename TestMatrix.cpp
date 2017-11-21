#include "Matrix.h"
//include header
using namespace std;
int main()
{
	//declare variables to initialize object with constructor
	int rows;
	int columns;
	int n;
	//ask user for values
	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << "Enter the number of columns:";
	cin >> columns;
//create two objects of type MatrixOp with user input
	MatrixOp mOne(rows, columns);
	MatrixOp mTwo(rows, columns);

//call function in both objects to read matrices
	cout << "Enter the elements of matrix 1 row by row:\n";
	mOne.readMatrix();

	cout << "Enter the elements of matrix 2 row by row:\n";
	mTwo.readMatrix();


	cout << "matrix 1 == matrix 2?\n";
	//check if both matrices are equal by overloading == operator
	if (mOne == mTwo)
		cout << "Yes\n";
	else
		cout << "No\n";

//create object by adding both matrices to print the resulting matrix
	cout << "matrix 1 + matrix 2:\n";
	MatrixOp obj = mOne.add(mTwo);
	obj.print();

//ask for n and elevate each value of the matrix to the power of n
	cout << "matrix 1 power n. Enter n: ";
	cin >> n;
	//call function
	mOne.power(n);
	mOne.print();

	return 0;
}

/*
1 0 3
5 1 2

1 1 2
1 0 4
*/
