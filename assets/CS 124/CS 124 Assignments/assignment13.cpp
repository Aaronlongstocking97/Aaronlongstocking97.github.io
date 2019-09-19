/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Kristi Hansen, cs124
* Author:
*    Aaron Jones
* Summary:
*    Promting the user for the Fahrenheit number and converting that
*    number into Celsius.
*
*    Estimated:  0.20 hrs   
*    Actual:     0.10 hrs
*      The hardest part was realizing that I needed to put precision(0).
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Converting Fahrenheit into Clesius
 ***********************************************************************/
int main()
{

   cout.setf(ios::fixed);
   cout.precision(0);

   int fahrenheit;

   cout << "Please enter Fahrenheit degrees: ";
   cin >> fahrenheit;

   float celsius = 5.0 / 9.0 * int(fahrenheit - 32);
   cout << "Celsius: " << celsius << "\n";

   
   return 0;
}
