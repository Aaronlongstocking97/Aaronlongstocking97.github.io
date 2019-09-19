// CS165 Checkpoint 07A

#include <iostream>
#include <string>
using namespace std;

#include "icecream.h"

/*****************************************
 * Function: Main
 * Purpose: Tests the Ice Cream class
 *****************************************/

int main()
{
   IceCream iceCream1;
   iceCream1.prompt();

   IceCream iceCream2;
   iceCream2.prompt();

   cout << "\nMenu:\n";
   iceCream1.display();
   iceCream2.display();
   cout << endl;

   float tax;
   cout << "Enter alternate sales tax: ";
   cin >> tax;

   // salesTax is public so it can be set.  Its static
   // so no object is needed.  IceCream:: is used to
   // tell the compile which class salesTax is part of.
   IceCream::salesTax = tax;


   cout << "\nMenu:\n";
   iceCream1.display();
   iceCream2.display();

   return 0;
}
