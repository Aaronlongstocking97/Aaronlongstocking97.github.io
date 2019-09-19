// CS165 Checkpoint 08A

#include <iostream>
#include <string>
using namespace std;

class Book
{
   private:
      string title;
      string author;
      int publicationYear;

   public:
      void promptBookInfo()
      {
         cout << "Title: ";
         getline(cin,title);
         cout << "Author: ";
         getline(cin,author);
         cout << "Publication Year: ";
         cin >> publicationYear;
         cin.ignore(1);
      }

      // Display the book information
      void displayBookInfo() const
      {
         cout << title << " (" << publicationYear << ") by " << author << endl;
      }

};

class TextBook : public Book
{
   private:
      string subject;

   public:
      // Prompt for text book subject
      void promptSubject()
      {
         cout << "Subject: ";
         getline(cin,subject);
      }

      // Display the text book subject
      void displaySubject() const
      {
         cout << "Subject: " << subject << endl;
      }
};

class PictureBook : public Book
{
   private:
      string illustrator;

   public:
      // Prompt for the picture book illustrator
      void promptIllustrator()
      {
         cout << "Illustrator: ";
         getline(cin,illustrator);
      }

      // Display the picture book illustrator
      void displayIllustrator() const
      {
         cout << "Illustrated by " << illustrator << endl;
      }
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;

   book.promptBookInfo();
   cout << endl;
   book.displayBookInfo();
   cout << endl;

   // Declare a TextBook object here and call its methods
   TextBook textBook;

   textBook.promptBookInfo();
   textBook.promptSubject();
   cout << endl;
   textBook.displayBookInfo();
   textBook.displaySubject();
   cout << endl;

   // Declare a PictureBook object here and call its methods
   PictureBook pictureBook;

   pictureBook.promptBookInfo();
   pictureBook.promptIllustrator();
   cout << endl;
   pictureBook.displayBookInfo();
   pictureBook.displayIllustrator();

   return 0;
}
