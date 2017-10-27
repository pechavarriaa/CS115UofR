////  ========================================================================== 
//// | Assignment Three : CALENDAR PROJECT
//// |
//// | Author : PABLO ECHAVARRIA
//// | Language : C++
//// | Instructor : MUSTAKIM AL HELAL
//// | Due Date : WEDNESDAY, NOVEMBER, 1, 2017 AT 11:59PM
////  +--------------------------------------------------------------------------
//// | Description :  Develop in C++ a class date to represent a calendar.The class should provide the following
//// |				operations :
//// |							-A default constructor that initializes a date object to 01 - 01 - 1900.
//// |							-A class constructor that initializes a date object to a correct value 
//// |							 using three integer parameters corresponding to the desired month, day and year.
//// |							 The function toString() that returns the string version of a date object.For example,
//// |							 applying toString() to the date 12 - 01 - 2000 produces "December 1st, 2000".
//// |							 The function nextDate() that returns the successive date i.e.the new value of the
//// |							 date object.For example, applying nextDate() to the date 12 - 31 - 2000 produces a
//// |							 new date: 01 - 01 - 2001. You should take into account if the year is a leap year or not.
//// |							 A leap year is : (1) divisible by 400 or (2) divisible by 4 and not divisible by 100.
//// |							 The function compareDates() that checks if the date of interest is before, after or
//// |							 equal to the argument date.
//// |
//// |			A simple run of the driver program follows.
//// |		Enter the first date using the format mm - dd - yyyy: 12 - 32 - 2000
//// |		Incorrect day!
//// |		Enter the first date using the format mm - dd - yyyy : 12 - 31 - 2000
//// |		The string version of the date is : December 31st, 2000
//// |		The next date in string version is : January 1st, 2001
//// |		Enter the second date using the format mm - dd - yyyy : 12 - 01 - 2001
//// |		The first date comes before the second one.
//// |		Another run :
//// |		Enter the first date using the format mm - dd - yyyy : 02 - 28 - 2005
//// |		The string version of the date is : February 28th, 2005
//// |		The next date in string version is : March 1st, 2005
//// |		Enter the second date using the format mm - dd - yyyy : 01 - 10 - 2005
//// |		The first date comes after the second one.
//// |
////  ============================================================================

//headers
#include <iostream>// I/O library (cin, cout)
#include <iomanip> // I/O manipulation (fixed, setprecision())

using namespace std;// avoid ::std for cin and cout

class DateInitialization
{
public:
		DateInitialization();
		void stringToInt(int &, int &, int &);

protected:
	string date;
};

class DateToInt : public DateInitialization
{
public:
	DateToInt(int, int, int);
	int day;
	int month;
	int year;
};
int main()
{
	int month;
	int day;
	int year=0;

	DateInitialization dateInitalization;
	dateInitalization.stringToInt(month, day, year);
	DateToInt dateToInt( month,  day, year);

}
void  DateInitialization::stringToInt(int& month, int& day, int& year)
{
	month = (date[0] - '0') * 10 + (date[1] - '0');
	day = (date[3] - '0') * 10 + (date[4] - '0');
	for (int i = 6; i < 10; i++)
		year = year * 10 + (date[i] - '0');

}
DateToInt::DateToInt(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}
DateInitialization::DateInitialization(void)
{
	date = "01-01-1900";
}
