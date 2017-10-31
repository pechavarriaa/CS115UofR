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
	void setDate(string);

	string date;
};

class FullDate : public DateInitialization //Funtion for setting the first day before the user input any day
{
public:
	FullDate(int, int, int); // Function for fonverting the date (string) into integers.
	string toString();
	void stringToInt();
	bool check();
	void intToString();
	int endOfMonth();
	FullDate nextDate();
	FullDate operator ++ (int);
	string compareDates(FullDate);
	int month;
	int day;
	int year;
};

bool checkInput(string, FullDate &);
void processInput(string, FullDate &,bool);