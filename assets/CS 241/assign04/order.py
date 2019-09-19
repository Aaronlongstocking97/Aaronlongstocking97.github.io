"""
 Program:
    CS241 Assignment 04, An E-Commerce System of Classes
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will pass in the Product class to an empty list 
    and add on to this list by linking new information from 
    upcoming orders. It will also add to the display of the Product
    class' display function which will create a receipt for the user.
                     
"""


"""
* A class that'll pass in previous information and add onto this through
* linked list. 
"""
class Order:

    
    def __init__(self):
        self.id = ""   
        self.products = []

    """
    * Takes in the objects from the Product class and adds these to the 
    * empty list provided in the initializer.
    """
    def add_product(self, p):
        
        self.products.append(p)


    """
    * Calls the get_total_price from the Product class through the 
    * linked list and adds these values before tax is added.
    """
    def get_subtotal(self):
        
        sub = 0.0
        ## This will be a for loop for summing up all the products' price.
        
        for total in self.products:
            
            sub += total.get_total_price()
        
        return sub 
        
    """
    * Calls the previous function to find the tax based on the objects price.
    """    
    def get_tax(self):
        
        sub = self.get_subtotal()
        tax = 0.0
        tax = float(sub * 0.065)
        
        return tax

    """
    * Adds the values from two seperate functions to create a total price.
    """
    def get_total(self):
        
        tax = self.get_tax()
        sub = self.get_subtotal()
        o_total = 0.0
        o_total = float(sub + tax)
        
        return o_total

    """
    * Shows the user the combination of the Product classes display
    * function and adds these vaules to the new receipt format.
    """
    def display_receipt(self):
        
        sub = self.get_subtotal()
        tax = self.get_tax()
        o_total = self.get_total()
         
        print("Order: {}".format(self.id))
        for i in range(len(self.products)): # loops through the list to find
            self.products[i].display()      # each item listed in the display function
        print("Subtotal: ${}".format("%.2f" % round(sub,2)))
        print("Tax: ${}".format("%.2f" % round(tax,2)))  
        print("Total: ${}".format("%.2f" % round(o_total,2)))
        # rounds to the second decimal place 