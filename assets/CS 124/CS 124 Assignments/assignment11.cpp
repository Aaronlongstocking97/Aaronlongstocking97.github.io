/***********************************************************************
* Program:
*    Assignment 11, Output
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    A monthly budget program that passses to the user through
*    main. The budget includes a display with two different headers
*    ('Item', 'Projected'). The Projected column
*    will have int values for the amount predicted and the item
*    column will have a list of string values that are linked to
*    there int amount that's listed.
*
*    Estimated:  0.3 hrs   
*    Actual:     0.2 hrs
*      The hardest part about this program was getting the correct
*      values for setw()
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Creating output tables that are properly aligned.
 ***********************************************************************/
int main()
{

   cout.setf(ios::fixed);      // no scientific notation except for the deficit
   cout.setf(ios::showpoint);  // always show the decimal point
   cout.precision(2);          // two digits after the decimal
   
   cout << "\tItem           Projected"   << endl;
   cout << "\t=============  =========="  << endl;
   cout << "\tIncome"  << setw(10) << "$" << setw(9) << 1000.00 << endl;
   cout << "\tTaxes"   << setw(11) << "$" << setw(9) <<  100.00 << endl;
   cout << "\tTithing" << setw(9)  << "$" << setw(9) <<  100.00 << endl;
   cout << "\tLiving"  << setw(10) << "$" << setw(9) <<  650.00 << endl;
   cout << "\tOther"   << setw(11) << "$" << setw(9) <<   90.00 << endl;
   cout << "\t=============  =========="  << endl;
   cout << "\tDelta"   << setw(11) << "$" << setw(9) <<   60.00 << endl;

   
   return 0;
}
