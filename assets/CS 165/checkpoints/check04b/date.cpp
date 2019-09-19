// CS165 Check 04B

#include <iostream>
#include "date.h"
using namespace std;

// Set the date components to the values provided by the user
void Date::set(const int month, const int day, const int year)
{
   this->month = month;
   this->day = day;
   this->year = year;
}

// Display the date components in the american format
void Date::displayAmerican() const
{
   cout << month << "/" << day << "/" << year << endl;
}

// DIsplay the date components in the european format
void Date::displayEuropean() const
{
   cout << day << "/" << month << "/" << year << endl;
}

// DIsplay the date components in the ISO format
void Date::displayISO() const
{
   cout << year << "-" << month << "-" << day << endl;
}
