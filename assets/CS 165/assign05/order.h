/***************************************************************
 * File: order.h
 * Author: Aaron Jones
 * Purpose: Contains the definition of the Order class
 ***************************************************************/

#ifndef ORDER_H
#define ORDER_H
#include "product.h"
#include "customer.h"
#include <iostream>
using namespace std;


class Order
{
   private:
      Product product;
      int quantity;
      Customer customer;

   public:
      /********************
       * Display Functions
      ********************/
      void displayShippingLabel();
      void displayInformation();

      /********************
       * Constructors
      ********************/
      Order() : customer(), product(), quantity(0) {}
      Order(Product product, int quantity, Customer customer);

      /********************
       * Getters
      ********************/
      Product getProduct() const { return product; }
      int getQuantity() const { return quantity; }
      Customer getCustomer() const { return customer; }

      /********************
       * Setters
      ********************/
      void setProduct(const Product product);
      void setQuantity(const int quantity);
      void setCustomer(const Customer customer);

      /********************
       * Member Functions
      ********************/
      string getShippingZip();
      double getTotalPrice();
};

#endif
