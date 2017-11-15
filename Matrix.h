#pragma once

//headers
#include <iostream>// I/O library (cin, cout)
#include <iomanip> // I/O manipulation (fixed, setprecision())
#include <string> // String library for manipulating strings of any character type.

using namespace std;

const int maxRows = 10;
const int maxColumns = 10;

class MatrixOp
{
public:
	void add(int &rows, int &columns, int matrixOne[][maxRows], int matrixTwo[][maxRows], int addMatrix[][maxRows]);
	void readMatrix(int &, int &, int fillMatrix[][maxRows]);
	void print(int &, int &, int printMatrix[][maxRows]);
	void power(int &r, int &c, int &n, int matrixOne[][maxRows], int powerMatrix[][maxRows]);
private:
};