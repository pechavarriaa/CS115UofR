//  ========================================================================== 
// | Assignment One : FRACTION
// |
// | Author : PABLO ECHAVARRIA
// | Language : C++
// | Instructor : MUSTAKIM AL HELAL
// | Due Date : SUNDAY, OCTOBER, 1, 2017 AT 11:59PM
//  +--------------------------------------------------------------------------
// | Description :         Write a function that reads a problem involving two common
// |			   fractions such as 2/4 + 5/6. After reading the common fractions 
// |			   problem, call a function to perform the indicated operation 
// |			   (call addFrac for +, call multiplyFrac for *, and so on).
// |			   Pass the numerator and denominator of both fractions to the
// |			   function that performs the operation; the function should return
// |			   the numerator and denominator of the result through its output 
// |			   parameters. Then display the result as a common fraction.
// |			   (Hint: Use functions readFracProblem and getFrac; see Listings 6.3 and 6.4.)
// |
// | Input :     Enter a common fraction problem: 3/4 + 5/6
// |		 Enter a common fraction problem: 3/4 # 5/6
// |		 Enter a common fraction problem: 2/7 * 3/8
// |		 Enter a common fraction problem: 3/0 - 5/6
// |
// | Output :     The result of the addition is 38/24
// |		  Invalid operation!
// |		  The result of the multiplication is 6/56
// |		  Cannot solve this problem!
// |
//  ============================================================================

// headers
#include <iostream> // I/O (cin, cout)
#include <string> // use c++ strings

//avoid using ::std with cin, cout and string
using namespace std;

//function prototypes
void scan_data(int &, int &, char &, int &, int &);//read all input
void do_next_op(int &, int &, char &, int &, int &, int &, int &);//process data
void addition(int &, int &, int &, int &, int &, int &);// add fractions
void subtraction(int &, int &, int &, int &, int &, int &);// substract fractions
void multiplication(int &, int &, int &, int &, int &, int &);// multiply fractios
void division(int &, int &, int &, int &, int &, int &);// divide fractions1
void lowerCase(string &);//lower case to process all ways of writing yes and no
int gcdr(int,int);//greatest common divisor for simplify fractions

int  main()
{
  string continueProgram;//string to read yes or no from input
  bool nextOperation = true;//used to control ending of program
  int leftTop = 0, leftBottom = 0, rightTop = 0, rightBottom = 0, numeratorResult = 0, denominatorResult = 0;// variables for fraction processing
  char operation = 0;// read operation character
  do
    {
      cout<<"Enter a common fraction problem: ";
      scan_data(leftTop, leftBottom, operation, rightTop, rightBottom);//read fractions from user input
      do_next_op(leftTop, leftBottom, operation, rightTop, rightBottom, numeratorResult, denominatorResult);//process input
      if (denominatorResult == 0)
	{
	  cout << "Error division by 0\nCannot solve this problem!\n";
	  // denomitatorResults check if user is dividing by 0
	}
      else if(denominatorResult != -1)// check if user input a proper operation
	{
	  int gcd = 0;
          if(numeratorResult == 0)
	    cout<<numeratorResult<<endl;
	  else
	    {
	      gcd = gcdr(numeratorResult, denominatorResult);//calculate gcd
	      cout << numeratorResult / gcd << '/' << denominatorResult / gcd << '\n';//print simplified result
	    }
	}
      bool readOk = true;//bool to check if user wrote either yes or no correctly
      while (readOk)
	{
	  cout << "Continue: Yes/No?\n";
	  cin >> continueProgram;
	  lowerCase(continueProgram);//use lowercase to compare 
	  if (continueProgram.compare("yes") == 0)
	    {
	      nextOperation = true;
	      readOk = false;
	      cout<<endl;
	    }
	  else if (continueProgram.compare("no") == 0)
	    {
	      nextOperation = false;
	      readOk = false;
	    }
	  else
	    cout << "That is not an answer\n"; // tell user to type correctly
	}
    } while (nextOperation);// exit if user says no

  return 0;
}//end main

void scan_data(int & leftNumerator, int & leftDenominator, char & operant, int & rightNumerator, int & rightDenominator)
{
  char fractionCharacter = 0;
  cin >> leftNumerator >> fractionCharacter >> leftDenominator >> operant >> rightNumerator >> fractionCharacter >> rightDenominator;
  //read all 7 character from user
}

void do_next_op(int & leftNumerator, int & leftDenominator, char & operant, int & rightNumerator, int & rightDenominator, int & numerator, int & denominator)
{
  /*
    do each operation accordingly
    depending on user input
  */
  if (operant == '+')
    addition(leftNumerator, leftDenominator, rightNumerator, rightDenominator, numerator, denominator);
  else if (operant == '-')
    subtraction(leftNumerator, leftDenominator, rightNumerator, rightDenominator, numerator, denominator);
  else if (operant == '*')
    multiplication(leftNumerator, leftDenominator, rightNumerator, rightDenominator, numerator, denominator);
  else if (operant == '/')
    division(leftNumerator, leftDenominator, rightNumerator, rightDenominator, numerator, denominator);
  else
    {
      cout << "Invalid operation!\n";
      cout << "The operations available are \"+\", \"-\", \"*\", \"/\"\n";
      denominator = -1;
      //update variable to check later and tell user to type proper input
    }
}

//functions implementation
void addition(int & leftNumerator, int & leftDenominator, int & rightNumerator, int & rightDenominator, int & numerator, int & denominator)
{
  denominator = leftDenominator * rightDenominator;
  numerator = (rightDenominator*leftNumerator) + (leftDenominator*rightNumerator);
}

void subtraction(int & leftNumerator, int & leftDenominator, int & rightNumerator, int & rightDenominator, int & numerator, int & denominator)
{
  denominator = leftDenominator * rightDenominator;
  numerator = (rightDenominator*leftNumerator) - (leftDenominator*rightNumerator);
}

void multiplication(int & leftNumerator, int & leftDenominator, int & rightNumerator, int & rightDenominator, int & numerator, int & denominator)
{
  denominator = leftDenominator * rightDenominator;
  numerator = leftNumerator * rightNumerator;
}

void division(int & leftNumerator, int & leftDenominator, int & rightNumerator, int & rightDenominator, int & numerator, int & denominator)
{
  denominator = leftDenominator * rightNumerator;
  numerator = leftNumerator * rightDenominator;
}

//function to make lower case all the string
void lowerCase(string & answer)
{
  for (int index = 0; index < answer.size(); index++)
    {
      if (answer[index] >= 'A' && answer[index] <= 'Z')
	answer[index] = 'a' + answer[index] - 'A';
    }
  //each letter is checked and in case is upper case, gets converted to lower case
}

//function to return greatest common divisor
int gcdr(int a, int b)
{
  if (a == 0) return b;
  return gcdr(b % a, a);//return greatest common divisor
  // more of euclidian algorithm on https://en.wikipedia.org/wiki/Euclidean_algorithm
}
