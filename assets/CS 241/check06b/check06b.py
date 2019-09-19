"""
 Program:
    CS241 Team Activity 06, 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will take in a users phone # 
    info and email info as well as demonstrate
    the uses of inhertance through a base class and 
    a derived class.
    
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
        print("Phone info:")
        print("({}){}-{}" .format(self.area_code, self.prefix, self.suffix))


class SmartPhone(Phone):
    
    def __init__(self):
        super().__init__()
        self.email = ""
        
    def prompt(self):
        self.prompt_number() # doesn't need to use super(). because the function
        self.email = input("Email: ") # name is not the same as the function calling it.
        
    def display(self):
        super().display()
        print(self.email)


def main():

    p = Phone()
    sp = SmartPhone()

    print("Phone:")
    p.prompt_number()
    print()
    p.display()
    print()
    print("Smart phone:")
    sp.prompt()
    print()
    sp.display()

if __name__ == "__main__":
    main()
