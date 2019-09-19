/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Finding the multiples of a number using a loop.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.30 hrs
*      The hardest part was understand which loop to use.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Sum of every multiple that has a specified value from 1 to less than
 * 100.
 ***********************************************************************/
int sumMultiple(int multiple)
{
   int sum = 0;
   
   for (int i = 1; i < 100; i++)
   {
      if (i % multiple == 0)
      {
         sum = i + sum;
      }
   }
   
   return sum;
}

/**********************************************************************
 * Driver for the sumMultiple function.
 ***********************************************************************/
int main()
{
   
   int multiple = 0; 
   
   cout << "What multiples are we adding? ";
   cin  >> multiple;
   
   int sum = sumMultiple(multiple);
   
   cout << "The sum of multiples of " << multiple 
        << " less than 100 are: " << sum << endl;

   return 0;
}















