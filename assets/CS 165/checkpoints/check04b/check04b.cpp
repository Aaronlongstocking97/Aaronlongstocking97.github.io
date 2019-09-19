// CS165 Checkpoint 04B

#include <iostream>
#include "date.h"
using namespace std;

int main()
{
   Date date;
   int new_month = 0;
   int new_day = 0;
   int new_year = 0;

   // Prompt for the date
   cout << "Month: ";
   cin >> new_month;
   cout << "Day: ";
   cin >> new_day;
   cout << "Year: ";
   cin >> new_year;

   date.set(month, day, year);

   // Display the date in all 3 formats.
   cout << endl;
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
