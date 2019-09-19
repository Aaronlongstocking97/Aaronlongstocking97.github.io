/***************************************************************
 * File: product.h
 * Author: Aaron Jones
 * Purpose: Contains the definition of the Product class
 ***************************************************************/

#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;


class Product
{
   private:
      string name;
      string description;
      double weight;
      double basePrice;

   public:
      /********************
      * Display Functions
      ********************/
      void displayAdvertising();
      void displayInventory();
      void displayReceipt();

      /********************
       * Constructors
      ********************/
      Product();
      Product(string name, string description,
              double basePrice, double weight);

      /********************
       * Getters
      ********************/
      string getName() const { return name; }
      string getDescription() const { return description; }
      double getBasePrice() const { return basePrice; }
      double getWeight() const { return weight; }

      /********************
       * Setters
      ********************/
      void setName(const string name);
      void setDescription(const string description);
      void setBasePrice(const double basePrice);
      void setWeight(const double weight);

      /********************
       * Member Functions
      ********************/
      void prompt();
      double getSalesTax();
      double getShippingCost();
      double getTotalPrice();
};

#endif
