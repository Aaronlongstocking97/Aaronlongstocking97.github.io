"""
 Program:
    CS241 Team Activity 03, Rational Numbers
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
                     
"""

class Date:
    # The initializer or Constructor gives the new instances of Complex
    # an initial state value.
    def __init__(self):
        self.day = 1
        self.month = 1
        self.year = 2000
        
    def prompt(self):
        
        self.day = int(input("Day: "))
        self.month = int(input("Month: "))
        self.year = int(input("Year: "))
        print()
        
    def display(self):
        
        print("{}/{}/{}" .format(self.month, self.day, self.year))
    

