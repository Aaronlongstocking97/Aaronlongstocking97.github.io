/***************************************************************
 * File: address.h
 * Author: Aaron Jones
 * Purpose: Contains the definition of the Address class
 ***************************************************************/

#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;


class Address
{
   private:
      string street;
      string city;
      string state;
      string zip;

   public:
      /********************
       * Display Functions
      ********************/
      void display();

      /********************
       * Constructors
      ********************/
      Address();
      Address(string street, string city,
              string state, string zip);

      /********************
       * Getters
      ********************/
      string getStreet() const { return street; }
      string getCity() const { return city; }
      string getState() const { return state; }
      string getZip() const { return zip; }

      /********************
       * Setters
      ********************/
      void setStreet(const string street);
      void setCity(const string city);
      void setState(const string state);
      void setZip(const string zip);
};

#endif
