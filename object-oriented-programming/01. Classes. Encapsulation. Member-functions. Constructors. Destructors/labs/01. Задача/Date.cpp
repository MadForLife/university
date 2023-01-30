#include "Date.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date() { }

int Date::setDay(int day)
{
	if (day > 0 && day <= 31)
		this->day = day;
	else this->day = 0;
}

int Date::setMonth(int month)
{
	if (month > 0 && month <= 12)
		this->month = month;
	else this->month = 0;
}

int Date::setYear(int year)
{
	if (year > 0) this->year = year;
	else this->year = -year;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }