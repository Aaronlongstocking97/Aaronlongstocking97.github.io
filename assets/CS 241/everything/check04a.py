"""
 Program:
    CS241 Checkpoint 04A, Intro to Importing A Class
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program creates two classes that are connected through the
    author varibale that is initialized in the Book class. The main
    function will display both classes intial state values and ask
    the user to input there Book/Person information to overwrite
    the intial state values of each class. Once the new values are
    inputed then main will display the same format with the new
    values that the user gave.
                     
"""

class Person:
    # The initializer or Constructor gives the new instances of Complex
    # an initial state value.
    def __init__(self):
        self.name = "anonymous"
        self.year = "unknown"
        
    def display(self):
        
        print(("{} (b. {})") .format(self.name, self.year))
        
class Book:
    # The initializer or Constructor gives the new instances of Complex
    # an initial state value.
    def __init__(self):
        self.title = "untitled"
        self.author = Person()
        self.publisher = "unpublished"
    
    def display(self):
        print(self.title)
        print("Publisher:")
        print(self.publisher)
        print("Author:")
        self.author.display()
        
def main():
    
    book = Book()
    book.display()
    
    print()
    print("Please enter the following:")
    book.author.name = input("Name: ")
    book.author.year = input("Year: ")
    book.title = input("Title: ")
    book.publisher = input("Publisher: ")
    print()
    book.display() 
  
# If this is the main program being run, call our main function above
if __name__ == "__main__":
    main()