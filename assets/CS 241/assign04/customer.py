"""
 Program:
    CS241 Assignment 04, An E-Commerce System of Classes
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will passes in values/objects from the Order class
    and count each time the user takes a new order. Continually it
    will display a detailed summary of the users receipt which is 
    a combination of all classes into one display function.
                     
"""


"""
* Passes in the Order class through an empty list and
* counts each time the customer takes a new order which is added to the
* total value that will be displayed in a detailed reciept.
"""
class Customer:
    
    def __init__(self):
        self.id = ""
        self.name = ""
        self.orders = []
        
    """
    * Populating the empty orders list while linking this new list 
    * to previous lists from other class data.
    """    
    def add_order(self, order):
        
        self.orders.append(order)
        
    
    """
    * Everytime there is a new order it will incremented 
    * to the count variable.
    """    
    def get_order_count(self):
        
        count = 1
        
        for objects in range(len(self.orders)):
            count += objects
        
        return count
    
    """
    * Passes in the value from the get_total function in the Order class
    * and increments each time the user adds another oder to the list.
    """    
    def get_total(self):
        
        total = 0
        
        for total_value in self.orders:
            
            total += total_value.get_total()
        
        return total
        
    """
    * Displays the price and oder number for the user listed.
    """    
    def display_summary(self):
        
        count = self.get_order_count()
        total = self.get_total()
        
        print("Summary for customer '{}':" .format(self.id))
        print("Name: {}" .format(self.name))
        print("Orders: {}" .format(count))
        print("Total: ${}" .format("%.2f" % round(total,2)))
        
    """
    * Takes in the values from each display and creates a detailed
    * receipt from all of the users item information.
    """    
    def display_receipts(self):
        
        print("Detailed receipts for customer '{}':" .format(self.id))
        print("Name: {}" .format(self.name))
        
        for i in range(len(self.orders)):
            print()
            self.orders[i].display_receipt()