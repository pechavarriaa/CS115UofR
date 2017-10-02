//  ========================================================================== 
// | Assignment One : CALCULATOR
// |
// | Author : PABLO ECHAVARRIA
// | Language : C++
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
// | Input : + 10
// |         / 0
// |         / 2.0
// |         & 2
// |         ^ 2
// |         q 0
// | 
// | Output : Result so far is 10.0
// |          Result so far is 10.0
// |          Result so far is 5.0
// |          Result so far is 5.0
// |          Result so far is 25.0
// |          Final result is 25.0
// |
//  ============================================================================

//headers
#include <iostream>// I/O library (cin, cout)
#include <iomanip> // I/O manipulation (fixed, setprecision())
using namespace std;// avoid ::std for cin and cout

//consts
const float EPS = 0.0000001;// constant to compare float values

//functions prototypes
void scan_data(char &, float &);//function designed to read the input
void do_next_op(char &, float &, float &);//function to process data
int ipow(int, int);//power function
float Abs(float);//absolute value

int main()
{
  char symbol = 0;//read symbol variable
  float number = 0;//read number variable
  float accumulatedNumber = 0;//storage result variable

  cout << fixed;//all values to have fixed decimal points

  while (symbol != 'q')//exit when user press 'q'
    {
      scan_data(symbol, number);//process info

      if (symbol != 'q')//when user input 'q' there is no need to process or print data
	{
	  do_next_op(symbol, number, accumulatedNumber);//make operation 
	  cout << "result so far is " << setprecision(1) << accumulatedNumber << endl;//print accumulates result
	}
    }

  cout << "final result is " << setprecision(2) << accumulatedNumber << endl;//print final result
}
//function implementation

//read input
void scan_data(char & operant, float & operand)
{
  cin >> operant >> operand;//read symbol and number
}

//process data
void do_next_op(char & operant, float & operand, float & accumulated)
{

  /*
    process depending on each
    mathematical operation
  */
  if (operant == '+')
    accumulated += operand;

  else if (operant == '-')
    accumulated -= operand;

  else if (operant == '*')
    accumulated *= operand;

  else if (operant == '/')
    {
      if (Abs(operand - 0.0) < EPS)//make sure not to do an invalid operation
	cout << "Error: Division by 0" << endl;
      else
	accumulated /= operand;
    }

  else if (operant == '^')
    accumulated = ipow(accumulated, operand);//calculate power using binary exponentiation with custom function
  else
    cout<<"Error: invalid operand\n";
}

//power function
int ipow(int base, int exp)// power function, binary exponentiation used to do faster calculations
{
  int result = 1;//number to be returned
  while (exp>0)//continue until exp is 0
    {
      if (exp & 1)//elevate when the number is odd
	result *= base;
      exp /= 2;//divide exp by two
      base *= base;//base multiplied by itself
    }

  return result;//return value

  //more info on https://en.wikipedia.org/wiki/Exponentiation_by_squaring
}

//absolute value function
float Abs(float a) 
{
  if (a < EPS)// if a less than 0 return -a to be positive, else return same value
    return -a;// -a will return positive, e.g -(-5.5) = 5.5
  else
    return a;
}
