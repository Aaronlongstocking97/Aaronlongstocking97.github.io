/***************************************************************
 * File: address.cpp
 * Author: Aaron Jones
 * Purpose: Contains the method implementations for the
 *          Address class.
 ***************************************************************/

#include "address.h"
#include <iostream>
using namespace std;

/**********************************************************************
 * Function(method): Display
 * Purpose: Exhibits the Address specific member variables in the
 *          order listed.
 ***********************************************************************/
void Address::display()
{
   // Address Format:
   //Street
   //City, State Zip
   cout << street << endl << city << ", "
        << state << " "<< zip << endl;
}

/**********************************************************************
 * Default Constructor: Home
 * Purpose: Onces called by Main it will set the inital state values
            to the elements listed.
 ***********************************************************************/
Address::Address()
{
   street = "unknown";
   city = "";
   state = "";
   zip = "00000";
}

/**********************************************************************
 * Non-Default Constructor: Hotel
 * Purpose: Once called by Main it will then call the setter functions
            and pass the values to each setter.
 ***********************************************************************/
Address::Address(string street, string city, string state, string zip)
{
   setStreet(street);
   setCity(city);
   setState(state);
   setZip(zip);
}

/**********************************************************************
 * Function(method): setStreet
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Address::setStreet(const string street)
{
   this->street = street;
}

/**********************************************************************
 * Function(method): setCity
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Address::setCity(const string city)
{
   this->city = city;
}

/**********************************************************************
 * Function(method): setState
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Address::setState(const string state)
{
   this->state = state;
}

/**********************************************************************
 * Function(method): setZip
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Address::setZip(const string zip)
{
   this->zip = zip;
}
