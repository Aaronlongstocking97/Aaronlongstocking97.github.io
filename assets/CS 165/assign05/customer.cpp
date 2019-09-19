/***************************************************************
 * File: customer.cpp
 * Author: Aaron Jones
 * Purpose: Contains the method implementations for the
 *          Customer class.
 ***************************************************************/

#include "customer.h"
#include <iostream>
using namespace std;

/**********************************************************************
 * Function(method): Display
 * Purpose: Exhibits the Customer specific member variable and the
 *          Address display method in the order listed.
 ***********************************************************************/
void Customer::display()
{
   // Name & Address Format:
   // Name
   // Street
   // City, State Zip
   cout << name << endl;
   address.display();
}

/**********************************************************************
 * Non-Default Constructor: gandalf
 * Purpose: Once called by Main it will then call the setter functions
            and pass the values to each setter.
 ***********************************************************************/
Customer::Customer(string name, Address address)
{
   setName(name);
   setAddress(address);
}

/**********************************************************************
 * Function(method): setName
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Customer::setName(const string name)
{
   this->name = name;
}

/**********************************************************************
 * Function(method): setAddress
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Customer::setAddress(const Address address)
{
   this->address = address;
}
