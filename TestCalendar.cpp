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
	for (int i = 6; i < 10; i++)
		year = year * 10 + (date[i] - '0');

}

string FullDate ::toString()
{
	const string monthName[] = { "January", "February", "March", "April", "May", "June",
								 "July", "August", "September", "October", "November", "December" };
	
	string ordinalNumbers[40] = {"1st", "2nd", "3rd" };
	for (int i = 3; i < 31; i++)
	{
		ordinalNumbers[i] = to_string(i+1) + "th";
	}
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
	
	
	const int finalDate[12]= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month != 2)
		return finalDate[month - 1];
	else
	{
		if (year % 400 || (year % 4 == 0 && year % 4 != 0))
			return 29;
		else
			return 28;
	}
}

void FullDate::operator++()
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
}

FullDate FullDate::nextDate(int m, int d, int y)
{
	FullDate temp(m, d, y);
	temp++;
	return temp;

}
DateInitialization::DateInitialization(void)
{
	date = "01-01-1900";
}

void DateInitialization::setDate(string userDate)
{
	date = userDate;
}