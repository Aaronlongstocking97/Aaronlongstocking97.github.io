"""
 Program:
    CS241 Checkpoint 03B, Intro to Classes and Objects 
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
     This program takes in a class that has three different 
     functions that are inside of the classes pararemeters.
     The user will be prompted for a real and imainary 
     number and these numbers will be displayed to the 
     user in a certain format.
    
"""

class Complex:
    # The initializer or Constructor gives the new instances of Complex
    # an initial state value.
    def __init__(self):
        self.real = 0 # initial state value until the user is prompted otherwise
        self.imaginary = 0 
    
    def prompt(self):
    
        self.real = int(input("Please enter the real part: "))
        self.imaginary = int(input("Please enter the imaginary part: "))
    
    def display(self):
        print("{} + {}i" .format(self.real, self.imaginary) )
       

def main():
    
    c1 = Complex() # First loop through the Complex Class
    c2 = Complex() # Second loop through the Complex class

    print("The values are:")
    c1.display()
    c2.display()

    print()
    c1.prompt()

    print()
    c2.prompt()

    print("\nThe values are:")
    c1.display()
    c2.display()
    
# If this is the main program being run, call our main function above
if __name__ == "__main__":
    main()
