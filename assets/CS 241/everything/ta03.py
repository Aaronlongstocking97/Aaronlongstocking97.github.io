"""
 Program:
    CS241 Team Activity 03, Rational Numbers
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
                     
"""

class RationalNum:
    # The initializer or Constructor gives the new instances of Complex
    # an initial state value.
    def __init__(self):
        self.numerator = 0
        self.denominator = 1
        
    def prompt(self):
        
        self.numerator = int(input("Enter the numerator: "))
        self.denominator = int(input("Enter the denominator: "))
        
    def display_decimal(self):
        
        print("{}/{}" .format(self.numerator, self.denominator))
    
    def multiply(self):
    
        print(self.numerator/self.denominator)
    
def main():
  r = RationalNum()
  r.display_decimal()
  r.prompt()
  r.display_decimal()
  r.multiply()
  
  
# If this is the main program being run, call our main function above
if __name__ == "__main__":
    main()
