#include "Calendar.h"

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

void DateInitialization ::toString()
{

}
