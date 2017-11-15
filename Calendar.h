
//headers
#include <iostream>// I/O library (cin, cout)
#include <iomanip> // I/O manipulation (fixed, setprecision())
#include <string> // String library for manipulating strings of any character type.
#include <sstream>//to convert int to string in c++ 98

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
//definition to convert int to string with sstream
		
using namespace std;// avoid ::std for cin and cout

// Class for initalizing the first day of the calendar in the programs as default
class DateInitialization
{
public:

	DateInitialization();
	void setDate(string);

	string date;
};

//Funtion for setting the first day before the user input any day
class FullDate : public DateInitialization
{
public:
	FullDate(int, int, int);	// Function for fonverting the date (string) into integers.
	string toString();	//Funtion for converting the integers of the date into string type by name of the month and ordinal number
	void stringToInt();	//Function for converting the string that the user input into three integers for month, day and year
	bool check();	//Checks that the format of the string is the correct
	int endOfMonth();	//Checks for each month which is its last day of the month
	FullDate nextDate();	//Calculates the next day for the first day that the user input
	FullDate operator ++ (int);	//Operator overloading for adding one day to the first that that the user input
	string compareDates(FullDate);	//Comparison of dates between the first and the second input of the user
	int month;
	int day;
	int year;
};

bool checkInput(string, FullDate &);	//Checks if the input is typed correctly
void processInput(string, FullDate &,bool);	//If the input is not correct it asks for type the date again
