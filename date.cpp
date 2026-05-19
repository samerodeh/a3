#include "date.h"

Date::Date(int month, int day, int year)
    : month(month), day(day), year(year)
{
    // this->month = month;
    // this->day = day;
    // this->year = year;
}

Date::~Date() {}


void Date::print_date() const {

    std::cout << "the current date is: " 
              << month << std::setw(2) 
              << day << std::setw(2) 
              << year;
              
}