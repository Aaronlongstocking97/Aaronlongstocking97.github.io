"""
 Program:
    CS241 Checkpoint 06A, Book Info
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    This program takes in the multiples values from the
    user and displays them accordingly. 
                     
"""

class Book:

    def __init__(self):
        self.title = ""
        self.author = ""
        self.publication_year = 0
    
    def prompt_book_info(self):
        self.title = input("Title: ")
        self.author = input("Author: ")
        self.publication_year = input("Publication Year: ")
        
    def display_book_info(self):
       
       print("{} ({}) by {}" .format(self.title, self.publication_year, self.author))
        
class TextBook(Book):
    
    def __init__(self):
        super().__init__()
        self.subject = ""

    def prompt_subject(self):
        
        self.subject = input("Subject: ")
        
    def display_subject(self):
        
        print("Subject: {}" .format(self.subject))

class PictureBook(Book):
    def __init__(self):
        self.illustrator = ""
        
    def prompt_illustrator(self):
        
        self.illustrator = input("Illustrator: ")        
        
    def display_illustrator(self):
        
        print("Illustrated by {}" .format(self.illustrator))

def main():

    b = Book()
    b.prompt_book_info()
    print()
    b.display_book_info()
    print()
    
    tb = TextBook()
    tb.prompt_book_info()
    tb.prompt_subject()
    print()
    tb.display_book_info()
    tb.display_subject()
    print()
    
    pb = PictureBook()
    pb.prompt_book_info()
    pb.prompt_illustrator()
    print()
    pb.display_book_info()
    pb.display_illustrator()

if __name__ == "__main__":
    main()
