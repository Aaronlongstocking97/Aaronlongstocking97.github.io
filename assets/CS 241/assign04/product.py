"""
 Program:
    CS241 Assignment 04, An E-Commerce System of Classes
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will use the products id, name, price, and quantity
    to find the items total price. It will then display the total 
    price with the quantity that is in stock for the item name listed.
                     
"""


"""
* A class that passes in multiple values from main and sets the
* instances to the set values given.
"""
class Product:
    
    def __init__(self, p_id, p_name, p_price, p_quantity):
        self.id = p_id
        self.name = p_name
        self.price = p_price
        self.quantity = p_quantity

    """
    * Calculates the total price based on the quantity of the item.
    """
    def get_total_price(self):
        
        p_total = 0.0
        p_total = (self.price * self.quantity)
        
        return p_total
 
    """
    * Shows the user the total price with the item name and quantity.
    """
    def display(self):
        
        p_total = self.get_total_price()
        
        print("{} ({}) - ${}" .format(self.name, self.quantity,
                                      "%.2f" % round(p_total,2)))