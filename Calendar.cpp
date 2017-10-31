/*//  ==========================================================================
// | Assignment Three : CALENDAR PROJECT
// |
// | Author : PABLO ECHAVARRIA
// | Language : C++
// | Instructor : MUSTAKIM AL HELAL
// | Due Date : WEDNESDAY, NOVEMBER, 1, 2017 AT 11:59PM
//  +--------------------------------------------------------------------------
// | Description :  Develop in C++ a class date to represent a calendar.The class should provide the following
// |				operations :
// |							-A default constructor that initializes a date object to 01 - 01 - 1900.
// |							-A class constructor that initializes a date object to a correct value
// |							 using three integer parameters corresponding to the desired month, day and year.
// |							 The function toString() that returns the string version of a date object.For example,
// |							 applying toString() to the date 12 - 01 - 2000 produces "December 1st, 2000".
// |							 The function nextDate() that returns the successive date i.e.the new value of the
// |							 date object.For example, applying nextDate() to the date 12 - 31 - 2000 produces a
// |							 new date: 01 - 01 - 2001. You should take into account if the year is a leap year or not.
// |							 A leap year is : (1) divisible by 400 or (2) divisible by 4 and not divisible by 100.
// |							 The function compareDates() that checks if the date of interest is before, after or
// |							 equal to the argument date.
// |
// |			A simple run of the driver program follows.
// |		Enter the first date using the format mm - dd - yyyy: 12-32-2000
// |		Incorrect day!
// |		Enter the first date using the format mm - dd - yyyy : 12-31-2000
// |		The string version of the date is : December 31st, 2000
// |		The next date in string version is : January 1st, 2001
// |		Enter the second date using the format mm - dd - yyyy : 12-01-2001
// |		The first date comes before the second one.
// |		Another run :
// |		Enter the first date using the format mm - dd - yyyy : 02-28-2005
// |		The string version of the date is : February 28th, 2005
// |		The next date in string version is : March 1st, 2005
// |		Enter the second date using the format mm - dd - yyyy : 01-10-2005
// |		The first date comes after the second one.
// |
//  ============================================================================*/

// http://www.cs.uregina.ca/Links/class-info/115/08-overloading/

#include "Calendar.h" // Header for including headers and function prototypes

int main()
{
	int month = 0;	//Declaration of month for the object constructor in the function toString()
	int day = 0;	//Declaration of day for the object constructor in the function toString()
	int year = 0;	//Declaration of year for the object constructor in the function toString()
	string date;	//Declaration of the string date for inputing into the function processInput()

	// First date
	FullDate dateObj(month, day, year);	//Created for 01-01-1900 running two constructors
	dateObj.stringToInt();	//Passing values from the string date converting them to three variables int for manipulation
	cout << "Enter the first date using the format mm-dd-yyyy : ";	//Console user instructions
	getline(cin, date);	//Reading string of date of format mm-dd-yyyy
	processInput(date, dateObj, true);	//Function for checking that the user gave the correct information in the same format as asked
	cout << "The string version of the date is : ";
	cout << dateObj.toString() << endl;	//Printing the date with the name of the month and the ordinal number
	cout << "The next date in string version is :";
	FullDate nextDay = dateObj.nextDate();	//Generating the next day from the one that the user input
	cout << nextDay.toString() << endl;	//Printing the next day from the one that the user input

	// Second date
	cout << "Enter the second date using the format mm-dd-yyyy : ";
	FullDate secondDateObj(month, day, year);
	getline(cin, date); //Reading string of date of format mm-dd-yyyy
	processInput(date, secondDateObj, false);	//Function for checking that the user gave the correct information in the same format as asked
	cout << dateObj.compareDates(secondDateObj) << endl;	//Funtion for comparing the dates, it tells the user which one goes after the other one
}