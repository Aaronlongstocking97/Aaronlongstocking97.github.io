/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Prompting the user for input and displaying the number for a
*    a string.
*
*    Estimated:  0.20 hrs   
*    Actual:     0.35 hrs
*      The hardest part was understanding how to use the cin.getline 
*      operator.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Getting the number of times there is a letter in text.
 ***********************************************************************/
int countLetters(char text[], char letter)
{

   int count = 0;
   int i = 0;
   
   while (text[i] != 0)
   {
      if (text[i] == letter)
      {
         count++;
      }
      i++;
   }
   return count;
}

/**********************************************************************
 * The head that compiles other functions. 
 ***********************************************************************/
int main()
{
   char text[256];
   char letter = 0;
   int count = 0;
   
   cout << "Enter a letter: ";
   cin >> letter;
   
   cin.ignore(1);
   
   cout << "Enter text: ";
   cin.getline(text, 256);
   
   count = countLetters(text, letter);
   cout << "Number of '" << letter << "'s: " << count << endl;

   return 0;
}
