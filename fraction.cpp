#include <iostream>
#include <string>
using namespace std;

void scan_data(int &, int &, char &, int &, int &);
void do_next_op(int &, int &, char &, int &, int &, int &, int &);
void addition(int &, int &, int &, int &, int &, int &);
void subtraction(int &, int &, int &, int &, int &, int &);
void multiplication(int &, int &, int &, int &, int &, int &);
void division(int &, int &, int &, int &, int &, int &);

void lowerCase(string & answer)
{
	for (int index = 0; index < answer.size(); index++)
	{
		if (answer[index] >= 'A' && answer[index] <= 'Z')
			answer[index] = 'a' + answer[index] - 'A';
	}
}

int gcdr(int a, int b)
{
	if (a == 0) return b;
	return gcdr(b % a, a);
}

void main()
{
	string continueProgram;
	bool nextOperation = true;
	int leftTop = 0, leftBottom = 0, rightTop = 0, rightBottom = 0, numeratorResult = 0, denominatorResult = 0;
	char operation = 0;
	do
	{
		scan_data(leftTop, leftBottom, operation, rightTop, rightBottom);
		do_next_op(leftTop, leftBottom, operation, rightTop, rightBottom, numeratorResult, denominatorResult);
		if (denominatorResult == 0) {
			cout << "Error division by 0\n";
		}
		else if(denominatorResult != -1)
		{
			int gcd = 0;
			gcd = gcdr(numeratorResult, denominatorResult);
			cout << numeratorResult / gcd << '/' << denominatorResult / gcd << '\n';
		}
		bool readOk = true;
		while (readOk)
		{
			cout << "Continue: Yes/No?\n";
			cin >> continueProgram;
			lowerCase(continueProgram);
			if (continueProgram.compare("yes") == 0)
			{
				nextOperation = true;
				readOk = false;
			}
			else if (continueProgram.compare("no") == 0)
			{
				nextOperation = false;
				readOk = false;
			}
			else
				cout << "That is not an answer\n"; // I don't now what happens here when you dont use yes or no, just another word.
		}
	} while (nextOperation);
}

void scan_data(int & leftNumerator, int & leftDenominator, char & operant, int & rightNumerator, int & rightDenominator)
{
	char fractionCharacter = 0;
	cin >> leftNumerator >> fractionCharacter >> leftDenominator >> operant >> rightNumerator >> fractionCharacter >> rightDenominator;

}

void do_next_op(int & leftNumerator, int & leftDenominator, char & operant, int & rightNumerator, int & rightDenominator, int & numerator, int & denominator)
{
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
		cout << "The operations available are \"+\", \"-\", \"*\", \"/\"\n";
		denominator = -1;
	}
}

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
