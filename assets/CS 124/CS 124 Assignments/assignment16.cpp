/***********************************************************************
* Program:
*    Assignment 16, IF Statements 
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Determine which tax bracket that the user's income is in. 
*
*    Estimated:  0.2 hrs   
*    Actual:     0.3 hrs
*      The hardest part was understanding how the if statement worked.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Return the tax bracket as an integer value
 ***********************************************************************/
int computeTax(double income)
{
   double tax = 0;
   
   // Start with the one end of the range
   if (income <= 15100)
      tax = 10;
   // We already  know that the income is > 15100
   else if (income <= 61300)
      tax = 15;
   else if (income <= 123700)
      tax = 25;
   else if (income <= 188450)
      tax = 28;
   else if (income <= 336550)
      tax = 33;
   else if (income > 336550)
      tax = 35;
   
  
   return tax;
}

/**********************************************************************
 * Obtain the income and display that in the tax bracket
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   double income;
   cout << "Income: ";
   cin  >> income;

   int tax = computeTax(income);
   cout << "Your tax bracket is " << tax << "%\n";
   
   return 0;
}


