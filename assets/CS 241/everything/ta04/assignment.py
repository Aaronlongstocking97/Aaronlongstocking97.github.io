"""
 Program:
    CS241 Team Activity 03, Rational Numbers
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
                     
"""

from date import Date

class Assignment:
    # The initializer or Constructor gives the new instances of Complex
    # an initial state value.
    def __init__(self):
        self.name = "Untitled"
        self.start_date = Date()
        self.due_date = Date()
        self.end_date = Date()
        
    def prompt(self):
        
        self.name = input("Name: ")
        print()
        print("Start Date:")
        self.start_date.prompt()
        print("Due Date:")
        self.due_date.prompt()
        print("End Date:")
        self.end_date.prompt()
        
    def display(self):
        
        print("Assignment: {}" .format(self.name))
        print("Start Date:")
        self.start_date.display()
        print("Due Date:")
        self.due_date.display()
        print("End Date:")
        self.end_date.display()
    
    
