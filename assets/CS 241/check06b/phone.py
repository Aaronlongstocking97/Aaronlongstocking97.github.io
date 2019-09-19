"""
 Program:
    CS241 Team Activity 06, 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
    
"""

class Phone:
    
    def __init__(self):
        self.area_code = 0
        self.prefix = 0
        self.suffix = 0
        
    def prompt_number(self):
        self.area_code = input("Area Code: ")
        self.prefix = input("Prefix: ")
        self.suffix = input("Suffix: ")
        
    def display(self):
        print("Phone info: ")
        print("({}){}-{}" .format(self.area_code, self.prefix, self.suffix))
