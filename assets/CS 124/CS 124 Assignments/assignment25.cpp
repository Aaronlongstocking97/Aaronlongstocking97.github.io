/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*    Displaying a calendar that is based on the number of days and
*    the offset starting on a Monday. 
*
*    Estimated:  0.45 hrs   
*    Actual:     0.40 hrs
*      The hardest part was understanding how loops work.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Taking in the number of days in a month from the user. 
 ***********************************************************************/
int getNumDays()
{
   int numDays;
   
   cout << "Number of days: ";
   cin >> numDays;

   return numDays;
}

/**********************************************************************
 * Taking in the offset value from the user. 
 ***********************************************************************/
int computeOffset()
{
   int offset;
   
   cout << "Offset: ";
   cin >> offset;

   return offset;
}

/**********************************************************************
 * Displaying the number of days based on the input of the offset.
 ***********************************************************************/
void displayTable(int numDays, int offset)
{

   int day;
   
   cout << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu" 
        << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr" 
        << setw(4) << "Sa" << endl;
   
   if (offset < 6)
   {
      cout << setw(4);
      for (int i = 0; i <= offset; i++)
         cout << "  " << setw(4);
   }
   
   for (int day = 1; day <= numDays; day++)
   {
      cout << setw(4) << day;
      if ((day + offset + 1) % 7 == 0 || day == numDays)
         cout << "\n";
   }
   
}


/**********************************************************************
 * The driver program that defines two returned values and passes them 
 * into the display function.
 ***********************************************************************/
int main()
{

   int numDays = getNumDays();
   int offset = computeOffset();

   displayTable(numDays, offset);


   return 0;
}
