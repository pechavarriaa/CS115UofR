//  ========================================================================== 
// | Assignment One : FRACTION
// |
// | Author : PABLO ECHAVARRIA
// | Language : C PLUS PLUS OBJECT ORIENTED
// | To Compile : EXPLAIN HOW TO COMPILE THIS PROGRAM
// | Instructor : MUSTAKIM AL HELAL
// | Due Date : SUNDAY, OCTOBER, 1, 2017 AT 11:59PM
//  +--------------------------------------------------------------------------
// | Description :         Write a program to model a simple calculator. Each data line 
// |			   should consist of the next operation to be performed from the 
// |			   list below and the right operand. Assume the left operand is 
// |			   the accumulator value (initial value of 0). You need a function
// |			   scan_data with two output parameters that returns the operator
// |			   and right operand scanned from a data line. You need a function
// |			   do_next_op that performs the required operation. do_next_op has 
// |			   two input parameters (the operator and operand) and one
// |			   input/output parameter (the accumulator). 
// |			   The valid operators are:
// |			   +	add
// |			   -	subtract
// |			   * 	multiply
// |			   /	divide
// |			   ^	power(raise left operand to power of right operand)
// |
// | Input : 
// | Output : STATE - SPACE REPRESENTATION OF DC MOTOR.
// | Algorithm : OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
// | PROBLEM.
// | Required Features Not Included :
// | Known Bugs :
//  ============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const float EPS = 0.0000001;
void scan_data(char &, float &);
void do_next_op(char &, float &, float &);

int ipow(int base, int exp)
{
	int result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}
float Abs(float a)
{
	if (a < EPS)
		return -a;
	else
		return a;
}
int main()
{
	char symbol = 0;
	float number = 0;
	float accumulatedNumber = 0;

	cout << fixed;

	while (symbol != 'q')
	{
		scan_data(symbol, number);
		do_next_op(symbol, number, accumulatedNumber);

		if (symbol != 'q')
			cout << "result so far is " << setprecision(1) << accumulatedNumber << endl;
	}

	cout << "final result is " << setprecision(2) << accumulatedNumber << endl;
}
void scan_data(char & operant, float & operand)
{
	cin >> operant >> operand;
}
void do_next_op(char & operant, float & operand, float & accumulated)
{
	if (operant == '+')
		accumulated += operand;

	else if (operant == '-')
		accumulated -= operand;

	else if (operant == '*')
		accumulated *= operand;

	else if (operant == '/')
	{
		if (Abs(operand - 0.0) < EPS)
			cout << "Division by 0" << endl;
		else
			accumulated /= operand;
	}

	else if (operant == '^')
		accumulated = ipow(accumulated, operand);

	else if (operant != 'q')
		cout << "Enter a valid operator" << endl;
}
