"""
 Program:
    CS241 Checkpoint 01B, Input & Output
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will put the text "Hello Python World!" on the screen.                 
"""

name = input("Please enter your name: ")
#Input command only returns string values
age = int(input("Please enter your age: ")) 

print() # Used to print a blank line

print("Hello {}, you are {} years old." .format(name, age))
print("On your next birthday, you will be {}." .format(age + 1))
