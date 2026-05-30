#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() : month(1), day(1), year(2000) {}

Date::Date(int month, int day, int year)
    : month(month), day(day), year(year) {}

Date::~Date() {}

int Date::getMonth() const { return month; }
int Date::getDay()   const { return day; }
int Date::getYear()  const { return year; }

void Date::setMonth(int m) { month = m; }
void Date::setDay(int d)   { day = d; }
void Date::setYear(int y)  { year = y; }

void Date::print() const {
    cout << month << "/" << day << "/" << year;
}
