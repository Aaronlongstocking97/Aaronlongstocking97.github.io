"""
 Program:
    CS241 Checkpoint 09a, Exceptions 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will prompt the user for a number
    and if a value error occurs then the user will
    be repromted for a number until it is assigned
    to be a true value.
    
"""

complete = False
while not complete:
    try:
        number = int(input("Enter a number: "))
        complete = True
    except ValueError:
        print("The value entered is not valid")
        
print("The result is: {}" .format(number * 2))
        
