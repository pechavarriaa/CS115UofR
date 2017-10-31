#include "Calendar.h"	// Header for including headers and function prototypes


// Class constructor for initilizing a date object
FullDate::FullDate(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}

// Function for converting the string date into three integers for the month day and the year
void  FullDate::stringToInt()
{
	month = year = day = 0; // To clear previos date
	month = (date[0] - '0') * 10 + (date[1] - '0');	//For getting the month from the string into the integer month
	day = (date[3] - '0') * 10 + (date[4] - '0');	//For getting the day from the string into the integer day
	for (int i = 6; i < date.size(); i++)
		year = year * 10 + (date[i] - '0');	//For getting the year from the string into the integer year
}

//	Funtion for checking if the date belongs into date in the gregorian calendar
bool FullDate::check()
{
	const int numOfMonths = 12;
	if (month > numOfMonths) //Checking if the month that is inputed is not more than 12
		return false;
	if (day > endOfMonth()) //Checks that the day inputed do not exceed between the end of each month
		return false;
	return true; //If the day is in the boundaries the function returns true;
}

////	Function for converting the date into the string version of 
//void FullDate::intToString()
//{
//	string m;
//	if (month < 10)
//		m = "0" + to_string(month);
//	else
//		m = to_string(month);
//
//	string d;
//	if (day < 10)
//		d = "0" + to_string(day);
//	else
//		d = to_string(day);
//
//	date = m + "-" + d + "-" + to_string(year);
//}

//	Function for converting the integers values of month, day and year into string version with name of the month and the ordinal number of the day
string FullDate::toString()
{
	// Name of the months stored in a string array
	const string monthName[] = { "January", "February", "March", "April", "May", "June",
								 "July", "August", "September", "October", "November", "December" };

	// Ordinal nubers stored in an string array
	const int maxDay = 31; // Maximum day that some of the months have
	string ordinalNumbers[maxDay] = { "1st", "2nd", "3rd" }; //First three numbers stored in the string array
	for (int i = 3; i < 30; i++) // For loop for storing the numbers that finish in th
	{
		if (i + 1 > 20 && i + 1 < 24)
			continue;
		ordinalNumbers[i] = to_string(i + 1) + "th";
	}
	ordinalNumbers[30] = "21st";
	ordinalNumbers[30] = "22nd";
	ordinalNumbers[30] = "23rd";
	ordinalNumbers[30] = "31st";
	string returnedDate = ""; // String declaration
	returnedDate = monthName[month - 1] + " " + ordinalNumbers[day - 1] + ", " + to_string(year); // String concatenation for result
	return returnedDate; // Returning the date with month name and ordinal number type as a string
}

// Function that checks each end of the month 
int FullDate::endOfMonth()
{
	//Last day of each month
	//January - 31 days
	//February - 28 days in a common year and 29 days in leap years
	//March - 31 days
	//April - 30 days
	//May - 31 days
	//June - 30 days
	//July - 31 days
	//August - 31 days
	//September - 30 days
	//October - 31 days
	//November - 30 days
	//December - 31 days

	const int finalDate[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Declaration of last day of the month as a constant array

	if (month != 2) //Checking if is not February
		return finalDate[month - 1];
	else
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 4 != 0)) //If it is February checks if the year is leap or not.
			return 29;	//Leap year
		else
			return 28; //Not a leap year
	}
}

//Operator overloading, for adding one day to the existing one
FullDate FullDate::operator ++ (int)
{
	if (day == endOfMonth())  //endOfMonth returns 28, 29, 30 or 31 depending on month 
	{
		if (month == 12) //If it is the last month of the year
		{
			year += 1;
			month = 1;
		}
		else 
			month += 1; //If it is not it just adds one month to the existing one
		day = 1; //And it start in the first day of the next month
	}
	else
		day += 1; //If is not on the end of the month nor the year it just adds one day to the existing day
	return *this;
}

//
FullDate FullDate::nextDate()
{
	FullDate temp(month, day, year); //Declaring temporal of the class FullDate
	temp++; //Operator overloading for the next day
	return temp;
}
string FullDate::compareDates(FullDate secondDate)
{
	int caseTrinary;
	if (year < secondDate.year)
		caseTrinary = 0;
	else if (year > secondDate.year)
		caseTrinary = 1;
	else
	{
		if (month < secondDate.month)
			caseTrinary = 0;
		else if (month > secondDate.month)
			caseTrinary = 1;
		else
		{
			if (day < secondDate.day)
				caseTrinary = 0;
			else if (day > secondDate.day)
				caseTrinary = 1;
			else
				caseTrinary = 2;
		}
	}
	if (caseTrinary == 0)
		return "The first date comes before the second one.";
	else if (caseTrinary == 1)
		return "The first date comes after the second one.";
	else
		return "The first date and the second date are the same date.";
}
DateInitialization::DateInitialization(void)
{
	date = "01-01-1900";
}
void DateInitialization::setDate(string userDate)
{
	date = userDate;
}
bool checkInput(string date, FullDate &dateObj)
{
	bool ck = false; //check input
	for (int i = 0; i < date.size(); i++)
	{
		if (i != 2 && i != 5)
		{
			if (!(date[i] >= '0' && date[i] <= '9'))
				ck = true;
		}
		else
		{
			if (date[i] != '-')
				ck = true;
		}

	}
	if (ck == false)
	{
		dateObj.setDate(date);
		dateObj.stringToInt();
		if (dateObj.check() == false)
			ck = true;
	}
	return !ck;
}
void processInput(string date, FullDate &dateObj, bool firstOrSecond)
{

	while (checkInput(date, dateObj) == false)
	{
		cout << "Incorrect day!" << endl;
		if (firstOrSecond)
			cout << "Enter the first date using the format mm-dd-yyyy: ";
		else
			cout << "Enter the second date using the format mm-dd-yyyy: ";
		getline(cin, date); //Reading string of date of format mm-dd-yyyy
	}
}