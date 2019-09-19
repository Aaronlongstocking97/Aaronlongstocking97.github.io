/***********************************************************************
* Program:
*    Assignment 43, Command Line 
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Demonstrate the use of command line arguments. Convert feet to meters. 
*
*    Estimated:  0.45 hrs   
*    Actual:     0.52 hrs
*    The hardest part was understanding the new library.
************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

/**********************************************************************
 * the Driver for ->
 * argc = number of arguments
 * argv = argument array 
 ***********************************************************************/
int main(int argc, char ** argv)
{
   double feet = 0.0;
   double meters = 0.0;

   cout.precision(1);
   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);

   for (int i = 1; i < argc; i++)
   {
      feet = atof(argv[i]);
      meters = 0.3048 * feet;
      cout << feet << " feet is " << meters << " meters" << endl;
   }
   
   return 0;
}
