#include "Calendar.h"

FullDate::FullDate(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}
void  FullDate::stringToInt()
{
	month = year = day = 0; //To clear previos date
	month = (date[0] - '0') * 10 + (date[1] - '0');
	day = (date[3] - '0') * 10 + (date[4] - '0');
	for (int i = 6; i < date.size(); i++)
		year = year * 10 + (date[i] - '0');

}
bool FullDate::check()
{
	if (month > 12)
		return false;
	if (day > endOfMonth())
		return false;
	return true;
}
void FullDate::intToString()
{
	string m;
	if (month < 10)
		m = "0" + to_string(month);
	else
		m = to_string(month);

	string d;
	if (day < 10)
		d = "0" + to_string(day);
	else
		d = to_string(day);

	date = m + "-" + d + "-" + to_string(year);
}
string FullDate::toString()
{
	const string monthName[] = { "January", "February", "March", "April", "May", "June",
								 "July", "August", "September", "October", "November", "December" };

	string ordinalNumbers[40] = { "1st", "2nd", "3rd" };
	for (int i = 3; i < 30; i++)
	{
		if (i + 1 > 20 && i + 1 < 24)
			continue;
		ordinalNumbers[i] = to_string(i + 1) + "th";
	}
	ordinalNumbers[30] = "21st";
	ordinalNumbers[30] = "22nd";
	ordinalNumbers[30] = "23rd";
	ordinalNumbers[30] = "31st";
	string returnedDate = "";
	returnedDate = monthName[month - 1] + " " + ordinalNumbers[day - 1] + ", " + to_string(year);
	return returnedDate;
}
int FullDate::endOfMonth()
{
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


	const int finalDate[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month != 2)
		return finalDate[month - 1];
	else
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 4 != 0))
			return 29;
		else
			return 28;
	}
}
FullDate FullDate::operator ++ (int)
{
	if (day == endOfMonth())  //endOfMonth returns 28, 29, 30 or 31 depending on month 
	{
		if (month == 12)
		{
			year += 1;
			month = 1;
		}
		else
			month += 1;
		day = 1;
	}
	else
		day += 1;
	return *this;
}
FullDate FullDate::nextDate()
{
	FullDate temp(month, day, year);
	temp++;
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
void processInput(string date, FullDate &dateObj,bool firstOrSecond)
{

	while (checkInput(date, dateObj) == false)
	{
		cout << "Incorrect day!" << endl;
		if(firstOrSecond)
		cout << "Enter the first date using the format mm-dd-yyyy: " << endl;
		else
		cout << "Enter the second date using the format mm-dd-yyyy: " << endl;
		getline(cin, date); //Reading string of date of format mm-dd-yyyy
	}
}
