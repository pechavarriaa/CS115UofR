#pragma once

//headers
#include <iostream>// I/O library (cin, cout)
#include <iomanip> // I/O manipulation (fixed, setprecision())
#include <string> // String library for manipulating strings of any character type.

using namespace std;

const int maxRows = 100; //Maximum of rows
const int maxColumns = 100; //Maximum of columns

class MatrixOp
{
public:
	//Initialization of variables
	int rows = 0;
	int columns = 0;
	int matrix[maxColumns][maxRows] = {};

	MatrixOp(int, int);//Constructor passing values for rows and columns

	MatrixOp add(MatrixOp mTwo);//Adding two objects
	void readMatrix();//Function for reading two matrices
	void print(); //Funtion for printing result of matrices
	void power(int n); //Function for elevate each number of the matrix two the integer n
	
	
	bool operator==(MatrixOp mTwo);	//Operator overloading
};