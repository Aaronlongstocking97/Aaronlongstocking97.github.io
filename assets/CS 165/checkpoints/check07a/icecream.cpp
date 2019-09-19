// CS165 Checkpoint 07A

/***********************************
 * File: icecream.cpp
 ***********************************/
#include "icecream.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/***********************************
 * Constructors
 ***********************************/
IceCream::IceCream()
{
   flavor = "unknown";
   price = 0;
}

IceCream::IceCream(string flavor, float price)
{
   this->flavor = flavor;
   this->price = price;
}

// The sales tax is member data that is static.  Since it is static,
// it needs to be initialized prior to use.  Constructor can't be used
// for this because static data needs to be used without creating an
// object (which is what a constructor is for).  Here is the syntax:
float IceCream::salesTax = 0.06;

/**********************************************************************
 * Function: IceCream::getTotalPrice
 * Purpose: Gets the total price of the ice cream, including sales tax.
 **********************************************************************/
float IceCream::getTotalPrice() const
{
   return (price * (1.0 + salesTax));  // Static data can be used in member functions
}

/**********************************************************************
 * Function: IceCream::getTotalPrice
 * Purpose: Prompts the user for the values of ice cream.
 **********************************************************************/
void IceCream::prompt()
{
   cout << "Flavor: ";
   getline(cin, flavor);

   cout << "Price: ";
   cin >> price;
   cin.ignore();
}

/**********************************************************************
 * Function: IceCream::display
 * Purpose: Displays the current ice cream.
 **********************************************************************/
void IceCream::display() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // we call the getTotalPrice() method here, so it will
   // automatically updated when sales tax is taken into accout.
   cout << "$" << getTotalPrice() << " - " << flavor << endl;
}
