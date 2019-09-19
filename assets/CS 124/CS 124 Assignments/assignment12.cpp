/***********************************************************************
* Program:
*    Assignment 12, Input & Variables
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Accepting data from the user and storing it in a variable.
*
*    Estimated:  0.40 hrs   
*    Actual:     0.20 hrs
*      The hardest part of this program was understanding the
*      'cin' operator.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Demonstrating different variables and inputs 
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   double income;
   
   cout << "\tYour monthly income: ";
   cin  >> income;

   cout << "Your income is: $" << setw(9) << income << endl;

   
   return 0;
}
