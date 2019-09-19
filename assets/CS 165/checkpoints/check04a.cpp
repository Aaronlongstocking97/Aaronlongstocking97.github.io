
#include <iostream>
using namespace std;

class Book
{
   private:
      string title;
      string author;

   public:
      void prompt();
      void display() const;  // const means it will not change class variables
};

// Prompt for data in the book
void Book::prompt()
{
   cout << "Title: ";
   getline(cin, title);  // Saves the data into the class object
   cout << "Author: ";
   getline(cin, author);
}

// Display the data in the book
void Book::display() const
{
   cout << "\"" << title << "\" by " << author << endl;
}

// Driver
int main()
{
   Book myBook;  // myBook is an object (variable) of class (type) Book

   myBook.prompt();  // Use the dot notation (like structs) to call functions
   myBook.display();

   return 0;
}
