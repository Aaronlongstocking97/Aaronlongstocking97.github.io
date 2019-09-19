/***************************************************************
 * File: customer.h
 * Author: Aaron Jones
 * Purpose: Contains the definition of the Customer class
 ***************************************************************/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "address.h"
#include <iostream>
using namespace std;


class Customer
{
   private:
      string name;
      Address address;

   public:
      /********************
       * Display Functions
      ********************/
      void display();

      /********************
       * Constructors
      ********************/
      Customer() : address(), name("unspecified") {}
      Customer(string name, Address address);

      /********************
       * Getters
      ********************/
      string getName() const { return name; }
      Address getAddress() const { return address; }

      /********************
       * Setters
      ********************/
      void setName(const string name);
      void setAddress(const Address address);
};

#endif
