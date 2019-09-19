/***************************************************************
 * File: order.cpp
 * Author: Aaron Jones
 * Purpose: Contains the method implementations for the
 *          Order class.
 ***************************************************************/

#include "order.h"
#include <iostream>
using namespace std;

/**********************************************************************
 * Function(method): Display Shipping Label
 * Purpose: Exhibits the Customer Classes display method called
 *          through the Public member variable in the Order class.
 ***********************************************************************/
void Order::displayShippingLabel()
{
   // Name & Address Format:
   // Name
   // Street
   // City, State Zip
   customer.display();
}

/**********************************************************************
 * Function(method): Display Information
 * Purpose: Exhibits the Customer and Product classes getName method
 *          through the Public member variable in the Order class.
 *          Cannot be used if there is no local variable name to set
 *          the call too.
 ***********************************************************************/
void Order::displayInformation()
{
   // Customer & Product Info:
   // customerName
   // productName
   // Total Price: $xx.xx

   string customerName = customer.getName();
   string productName = product.getName();

   cout << customerName << endl
        << productName << endl
        << "Total Price: $" << getTotalPrice() << endl;
}

/**********************************************************************
 * Non-Default Constructor: orderStaff
 * Purpose: Once called by Main it will then call the setter functions
            and pass the values to each setter.
 ***********************************************************************/
Order::Order(Product product, int quantity, Customer customer)
{
   setProduct(product);
   setQuantity(quantity);
   setCustomer(customer);
}

/**********************************************************************
 * Function(method): setProduct
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Order::setProduct(const Product product)
{
   this->product = product;
}

/**********************************************************************
 * Function(method): setQuantity
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Order::setQuantity(const int quantity)
{
   this->quantity = quantity;
}

/**********************************************************************
 * Function(method): setCustomer
 * Purpose: A method serving two purposes: to translate client
 *          properties into member data, and to validate that the
 *          member data is within the valid range.
 ***********************************************************************/
void Order::setCustomer(const Customer customer)
{
   this->customer = customer;
}

/**********************************************************************
 * Function(method): getShippingZip
 * Purpose: Calls the Customer Classes getAddress function which
 *          intern calls the Address Classes getZip method function.
 *          Cannot be used if there is no local variable name to set
 *          the call too.
 ***********************************************************************/
string Order::getShippingZip()
{
   string zip = customer.getAddress().getZip();
   return zip;
}

/**********************************************************************
 * Function(method): getTotalPrice
 * Purpose: Calls the Product Classes getTotalPrice function and
 *          uses the total to multiply against the Order Classes
 *          public member varibale quantity. Cannot be used if there
 *          is no local variable name to set the call too.
 ***********************************************************************/
double Order::getTotalPrice()
{
   double total = product.getTotalPrice() * quantity;
   return total;
}
