/***********************************************************************
* Program:
*    Project 07, Calendar 
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    This program will take in the month number and year from the 
*    user and display that calendar month in the year inputted. 
*
*    Estimated:  2.35 hrs   
*    Actual:     2.0 hrs
*      The hardest part was understanding how compute offset worked. 
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Gets the value from the user for the month number. 
 ***********************************************************************/
int getMonth()
{
   int month ;
   
   cout << "Enter a month number: ";
   cin >> month;
   
   while (month > 12 || month < 1)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> month;
   }

   return month;
}

/**********************************************************************
 * Gets the value from the user for the year number. 
 ***********************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;

   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> year;
   }

   return year;
}

/**********************************************************************
 * Returns true or false for whether or not it is a leap year.
 ***********************************************************************/
bool isLeap(int year)
{

   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
      return true; 
   else
      return false;
}

/**********************************************************************
 * Takes in the year and whether or not it is leap year it will return 
 * the number of days in the year. 
 ***********************************************************************/
int numDaysInYear(int year)
{
   
   if (isLeap(year) == true)
   {
      year = 366;
   }
   else 
   {
      year = 365;
   }

   return year;
}

/**********************************************************************
 * Takes in the values of month and year and determines how many days
 * will be in that month.
 ***********************************************************************/
int numDaysInMonth(int month, int year)
{

   int daysInMonth = 0;
   
   if (month == 1)
      daysInMonth = 31;
   else if (month == 2 && isLeap(year) == true)
      daysInMonth = 29;
   else if (month == 2 && isLeap(year) == false)
      daysInMonth = 28;
   else if (month == 3)
      daysInMonth = 31;
   else if (month == 4)
      daysInMonth = 30;
   else if (month == 5)
      daysInMonth = 31;
   else if (month == 6)
      daysInMonth = 30;
   else if (month == 7)
      daysInMonth = 31;
   else if (month == 8)
      daysInMonth = 31;
   else if (month == 9)
      daysInMonth = 30;
   else if (month == 10)
      daysInMonth = 31;
   else if (month == 11)
      daysInMonth = 30;
   else if (month == 12)
      daysInMonth = 31;

   return daysInMonth;
}


/**********************************************************************
 * Determines the day of the week of the  first day of the month by 
 * counting how many days have passed since the 1st of January, 1753.
 ***********************************************************************/
int computeOffset(int year, int month)
{

   int offset = 0;
   int numDays = 0;
   
   for (int y = 1753; y < year; y++)
      numDays += numDaysInYear(y);
 
   for (int m = 1; m < month; m++)
      numDays += numDaysInMonth(m, year);
      
   

   return offset = (numDays % 7);
}

/**********************************************************************
 * Takes in the month number and displays what the month name would be 
 * based on the month number inputted.
 ***********************************************************************/
void dsiplayHeader(int month, int year)
{

   if (month == 1)
      cout << "January";
   else if (month == 2)
      cout << "February";
   else if (month == 3)
      cout << "March";
   else if (month == 4)
      cout << "April";
   else if (month == 5)
      cout << "May";
   else if (month == 6)
      cout << "June";
   else if (month == 7)
      cout << "July";
   else if (month == 8)
      cout << "August";
   else if (month == 9)
      cout << "September";
   else if (month == 10)
      cout << "October";
   else if (month == 11)
      cout << "November";
   else if (month == 12)
      cout << "December";
      
   cout << ", " << year << endl;
 
}

/**********************************************************************
 * Takes the number of days in a month and the offset as parameters 
 * and will display the calendar table. 
 ***********************************************************************/
void displayTable(int offset, int daysInMonth)
{
   
   cout << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu" 
        << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr" 
        << setw(4) << "Sa" << endl;
   
   if (offset < 6)
   {
      cout << setw(4);
      for (int i = 0; i <= offset; i++)
         cout << "  " << setw(4);
   }
   
   for (int count = 1; count <= daysInMonth; count++)
   {
      cout << setw(4) << count;
      if ((count + offset + 1) % 7 == 0 || count == daysInMonth)
         cout << "\n";
   }
}

/**********************************************************************
 * The driver function for all other functions. 
 ***********************************************************************/
int main()
{
   
   int month = getMonth();
   int year = getYear();
   bool leapYear = isLeap(year);
   int numDaysInYear(year);
   int daysInMonth = numDaysInMonth(month, year);
   int offset = computeOffset(year, month);
   
   cout << "\n";
   dsiplayHeader(month, year);
   displayTable(offset, daysInMonth);

   return 0;
}
