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
from smartphone import SmartPhone

def main():

    p = Phone()
    sp = SmartPhone()

    print("Phone:")
    p.prompt_number()
    print()
    p.display()
    print()
    print("Smart Phone:")
    sp.prompt()
    print()
    sp.display()

if __name__ == "__main__":
    main()
