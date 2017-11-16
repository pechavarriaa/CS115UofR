#pragma once

//headers
#include <iostream>// I/O library (cin, cout)
#include <iomanip> // I/O manipulation (fixed, setprecision())
#include <string> // String library for manipulating strings of any character type.

using namespace std;

const int maxRows = 100;
const int maxColumns = 100;

class MatrixOp
{
public:
	int rows = 0;
	int columns = 0;
	int matrix[maxColumns][maxRows] = {};

	MatrixOp(int, int);

	MatrixOp add(MatrixOp mTwo);
	void readMatrix();
	void print();
	void power(int n);
	
	
	bool operator==(MatrixOp mTwo);	
};