/***************************************************************
 * File: product.cpp
 * Author: Aaron Jones
 * Purpose: Contains the method implementations for the Product
 *          class.
 ***************************************************************/

#include "product.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Function(method): displayAdvertising
 * Purpose: Displays the name, basePrice, and description in the
 *          order listed.
 ***********************************************************************/
void Product::displayAdvertising()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << name << " - $" << basePrice << endl
        << "(" << description << ")" << endl;
}

/**********************************************************************
 * Function(method): displayInventory
 * Purpose: Displays the basePrice, name, and weight in the order
 *          listed.
 ***********************************************************************/
void Product::displayInventory()
{
   cout << "$" << basePrice << " - " << name << " - ";
   cout.precision(1);
   cout << weight << " lbs" << endl;
}

/**********************************************************************
 * Function(method): displayReceipt
 * Purpose: The most detailed option from the list. Option three gives
 *          the user every detail about the product.
 ***********************************************************************/
void Product::displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   double salesTax = getSalesTax();
   double shippingCost = getShippingCost();
   double total = getTotalPrice();

   cout << name << endl
        << "  Price:" << setw(10) << "$"
        << setw(8) << basePrice << endl;
   cout << "  Sales tax:" << setw(6) << "$"
        << setw(8) << salesTax << endl;
   cout << "  Shipping cost:" << setw(2) << "$"
        << setw(8) << shippingCost << endl;
   cout << "  Total:" << setw(10) << "$"
        << setw(8) << total << endl;
}

/**********************************************************************
 * Default Constructor: theRing
 * Purpose: Onces called by Main it will set the inital state values
            to the elements listed.
 ***********************************************************************/
Product::Product()
{
   name = "none";
   description = "";
   weight = 0;
   basePrice = 0.00;
}

/**********************************************************************
 * Non-Default Constructor: staff
 * Purpose: Once called by Main it will then call the setter functions
            and pass the values to each setter.
 ***********************************************************************/
Product::Product(string name, string description, double basePrice, double weight)
{
   setName(name);
   setDescription(description);
   setBasePrice(basePrice);
   setWeight(weight);
}

/**********************************************************************
 * Function(method): prompt
 * Purpose: Takes in the users response and stores it in private
 *          variables inside the class. If the user does not enter a
 *          valid price they will then be reprompted until it is
 *          correct.
 ***********************************************************************/
void Product::prompt()
{
   cout << "Enter name: ";
   getline(cin, name);
   cout << "Enter description: ";
   getline(cin, description);
   cout << "Enter weight: ";
   cin  >> weight;

   bool valid = true;

   do
   {
      valid = true;
      cout << "Enter price: ";
      cin  >> basePrice;

      if (cin.fail() || basePrice < 0)
      {
         cin.clear();
         cin.ignore(256, '\n');
         valid = false;
      }
   }
   while (!valid);
}

/**********************************************************************
 * Function(method): getSalesTax
 * Purpose: Calculates the sales tax based on the base price.
 ***********************************************************************/
double Product::getSalesTax()
{
   double salesTax = 0.06 * basePrice;
   return salesTax;
}

/**********************************************************************
 * Function(method): getShippingCost
 * Purpose: Calculates the shipping cost based on the weight of the
 *          product.
 ***********************************************************************/
double Product::getShippingCost()
{
   double shippingCost;
   if (weight < 5)
   {
      shippingCost = 2.00;
   }
   else
   {
      shippingCost = 2.00 + (weight - 5) * 0.10;
   }
   return shippingCost;
}

/**********************************************************************
 * Function(method): getTotalPrice
 * Purpose: Takes the values from the other getters and add them to
 *          the sum total price.
 ***********************************************************************/
double Product::getTotalPrice()
{
   // Tax + shipping cost + base price
   double salesTax = getSalesTax();
   double shippingCost = getShippingCost();
   double total;

   total = basePrice + salesTax + shippingCost;

   return total;
}

/**********************************************************************
 * Function(method): setName
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Product::setName(const string name)
{
   this->name = name;
}

/**********************************************************************
 * Function(method): setDescription
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Product::setDescription(const string description)
{
   this->description = description;
}

/**********************************************************************
 * Function(method): setBasePrice
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Product::setBasePrice(const double basePrice)
{
   this->basePrice = basePrice;
}

/**********************************************************************
 * Function(method): setWeight
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Product::setWeight(const double weight)
{
   this->weight = weight;
}
