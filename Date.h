#pragma once
#include<iostream>

using namespace std;

class Date {
private:
	int year;    // 1753-9999
	int month;   // 1-12
	int day;     // 1-31
	char* date;	// Monday, 9 Mar 2017
	const static char STR_MONTHS[12][4];
	const static char STR_DAYS[12][10];
	const static int DAYS_IN_MONTHS[12];
	const static int YEAR_MIN = 1753;
	const static int YEAR_MAX = 9999;

public:

	bool isLeapYear(int y);

	char* getDate();

	bool isValidDate(int y, int m, int d);

	int getDayOfWeek(int y, int m, int d);

	Date(const Date& dateObj);

	char* SD(int y, int m, int d);

	Date(int y, int m, int d);

	Date();

	void setDate(int y, int m, int d);

	int getYear();

	int getMonth();

	int getDay();

	void setYear(int y);

	void setMonth(int m);

	void setDay(int d);

	int getLastDayOfMonth(int year, int month);

	virtual ~Date() {
		delete[]this->date;
	}

};

//Initialize static non - integer variable(must be done outside the class declaration)
const char Date::STR_MONTHS[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

const int Date::DAYS_IN_MONTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char Date::STR_DAYS[12][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int Date::getDayOfWeek(int y, int m, int d)
{
	int centuryTable[] = { 4, 2, 0, 6, 4, 2, 0, 6 }; // 17xx, 18xx, ...
	int MonthTable[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
	int MonthLeapYearTable[] = { 6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };

	int century = y / 100;
	int twoDigitYear = y % 100;
	int centuryTableIndex = (century - 17) % 8;
	//Date before 17xx are not valid, but needed to prevent negative index
	if (centuryTableIndex < 0)
	{
		centuryTableIndex += 8;
	}
	int sum = centuryTable[centuryTableIndex] + twoDigitYear + twoDigitYear / 4;
	if (isLeapYear(y))
	{
		sum += MonthLeapYearTable[m - 1];
	}
	else
	{
		sum += MonthTable[m - 1];
	}
	sum += d;
	return sum % 7;
}
//Print this instance in the format "xxxday, d mmm yyyy".

Date::Date()
{

	this->day = 1;
	this->year = 2017;
	this->month = 1;

	this->date = SD(year, month, day);

}

Date::Date(int y, int m, int d)
{

	this->day = d;
	this->month = m;
	this->year = y;

	this->date = SD(y, m, d);

}

char* Date::SD(int y, int m, int d)
{

	int yc = y;
	int y1[4];
	for (int i = 0; i < 4; i++)
	{
		y1[i] = yc % 10;
		yc = yc / 10;
	}


	char* date = new char[50];
	char* str;
	const int x = getDayOfWeek(y, m, d);
	str = new char[10];
	char* strm = new char[10];

	for (int i = 0; i < strlen(STR_DAYS[x]); i++)
	{
		str[i] = STR_DAYS[x][i];
	}
	str[strlen(STR_DAYS[x])] = '\0';

	int len = strlen(str);

	for (int i = 0; i < strlen(STR_MONTHS[m]); i++)
	{
		strm[i] = STR_MONTHS[m][i];
	}
	strm[strlen(STR_MONTHS[m])] = '\0';

	int lenm = strlen(strm);

	//Default Constructor set Date to Default value : Sunday, 1 Jan 2017
	int i;
	for (i = 0; i < len;)
	{
		date[i] = str[i];
		i++;
	}
	date[i] = ',';
	i++;
	date[i] = ' ';
	i++;
	date[i] = (char)(d + 48);
	i++;
	date[i] = ' ';
	i++;
	for (int j = 0; j < lenm; j++)
	{
		date[i] = strm[j];
		i++;
	}
	date[i] = ' ';
	i++;

	for (int k = 3; k >= 0; k--) {
		date[i] = (char)(y1[k] + 48);
		i++;
	}

	date[i] = '\0';

	return date;
}

bool Date::isLeapYear(int y)
{
	if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::isValidDate(int y, int m, int d)
{
	if (y > YEAR_MIN&& y < YEAR_MAX) {
		if (m >= 1 && m <= 12 && d >= 1)
		{
			if ((d <= DAYS_IN_MONTHS[m - 1]) || (m == 2 && isLeapYear(y) && d <= 29))
			{
				return true;
			}

		}
	}
	return false;
}

char* Date::getDate() {
	return this->date;
}

Date::Date(const Date& dateObj)	//Copy Constructor and You must copy (dateObj.date to char * date).
{
	this->year = dateObj.year;
	this->day = dateObj.day;
	this->month = dateObj.month;
	this->date = new char[strlen(dateObj.date) + 1];

	for (int i = 0; i < strlen(dateObj.date); i++)
	{
		this->date[i] = dateObj.date[i];
	}
	this->date[strlen(dateObj.date)] = '\0';

}

void Date::setDate(int y, int m, int d)
{
	this->day = d;
	this->year = y;
	this->month = m;

	this->date = SD(y, m, d);
}

int Date::getDay()
{
	return this->day;
}

int Date::getYear()
{
	return this->year;
}

int Date::getMonth()
{
	return this->month;
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getLastDayOfMonth(int year, int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}

	if (month == 2) {
		bool x = isLeapYear(year);
		if (x == 1) {
			return 28;
		}
		else if (x == 0) {
			return 29;
		}
	}
}
