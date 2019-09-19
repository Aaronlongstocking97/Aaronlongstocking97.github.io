/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory 
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Prompting the user for a certain number of charaters and if there
*    isn't an allocation failure then the text will be dislayed. 
*
*    Estimated:  0.45 hrs   
*    Actual:     1.0 hrs
*    The hardest part was getting the right text. 
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The driver program for getting the text. 
 ***********************************************************************/
int main()
{
   int size;
   char *text;

   cout << "Number of characters: ";
   cin  >> size;
   cin.ignore(1);
   text = new (nothrow)char[size + 1];
   if (text == NULL)
   {
      cout << "Allocation failure!" << endl;
   }
   else
   {
      cout << "Enter Text: ";
      cin.getline(text, size + 1);
      cout << "Text: " << text << endl;
      delete text;
   }
   
   return 0;
}
