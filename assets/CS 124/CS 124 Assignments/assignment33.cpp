/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Tracking the money that was spent during the date.
*
*    Estimated:  0.25 hrs   
*    Actual:     0.32 hrs
*      The hardest part was understanding how to pass a pointer.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Calculating the cost of data from the selected account.
 ***********************************************************************/
void date(float * pAccount)
{

   float dinner = 0.0;
   float movie = 0.0;
   float iceCream = 0.0;
   
   cout << "Cost of the date:" << endl;
   cout << "\tDinner:    ";
   cin >> dinner;
   
   cout << "\tMovie:     ";
   cin >> movie;
   
   cout << "\tIce cream: ";
   cin >> iceCream;
   
   *pAccount -= dinner;
   *pAccount -= movie;
   *pAccount -= iceCream;
}

/**********************************************************************
 * Driver for date function.
 ***********************************************************************/
int main()
{
   float * pAccount = 0;
   float samBalance = 0.0;
   float sueBalance = 0.0;
   
   cout << "What is Sam's balance? ";
   cin >> samBalance;
   
   cout << "What is Sue's balance? ";
   cin >> sueBalance;
   
   if (samBalance >= sueBalance)
   {
      pAccount = &samBalance;
   }
   else
   { 
      pAccount = &sueBalance;
   }  
   
   date(pAccount);
   
   cout << "Sam's balance: $" << samBalance << endl;
   cout << "Sue's balance: $" << sueBalance << endl;


   return 0;
}
