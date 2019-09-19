"""
 Program:
    CS241 Checkpoint 04B, Intro to Importing A Class
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This file contains the following classes:
    CreditCard
    Address
    
    and then it contains a main function.

Your task it to break it into three files, then tar them up, and submit.
                     
"""

from address import Address 

class CreditCard:
    """ Contains a credit card that has two addressess"""
    def __init__(self):
        self.name = ""
        self.number = ""
        self.mailing_address = Address()
        self.billing_address = Address()

    def display(self):
        print(self.name)
        print(self.number)
      
        print("Mailing Address:")
        self.mailing_address.display()

        print("Billing Address:")
        self.billing_address.display()

