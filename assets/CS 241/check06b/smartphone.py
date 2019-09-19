"""
 Program:
    CS241 Team Activity 06, 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
    
"""

from phone import Phone

class SmartPhone(Phone):
    
    def __init__(self):
        super().__init__()
        self.email = ""
        
    def prompt(self):
        self.prompt_number()
        self.email = input("Email: ")
        
    def display(self):
        super().display()
        print(self.email)



