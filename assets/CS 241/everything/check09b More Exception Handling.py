"""
 Program:
    CS241 Checkpoint 09b, More Exceptions 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program will check for multiple exceptions
    and if the user inputs a normal number then
    it will return one divided by the number.
    
"""

class NegativeNumberError(Exception):
    
    def __init__(self, message):
        super().__init__(message)


def get_inverse(number):
    n = float(number) 

    if n < 0:
        raise NegativeNumberError("Error: The value cannot be negative")
        
    return 1 / n


def main():

    number = input("Enter a number: ")
    try:
        result = get_inverse(number)
        print("The result is: {}" .format(result))
    except ValueError:
        print("Error: The value must be a number")
    except ZeroDivisionError:
        print("Error: Cannot divide by zero")
    except NegativeNumberError as e:
        print(e)
    
    
if __name__ == "__main__":
    main()

