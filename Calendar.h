#pragma once

//headers
#include <iostream>// I/O library (cin, cout)
#include <iomanip> // I/O manipulation (fixed, setprecision())
#include <string> // String library for manipulating strings of any character type.

using namespace std;// avoid ::std for cin and cout

class DateInitialization // Class for initalizing the first day of the calendar in the programs as default.
{
public:
	DateInitialization();
	void stringToInt(int &, int &, int &);


protected:
	string date;
};

class DateToInt : public DateInitialization //Funtion for setting the first day before the user input any day
{
public:
	DateToInt(int, int, int); // Function for fonverting the date (string) into integers.
	int day;
	int month;
	int year;
};

