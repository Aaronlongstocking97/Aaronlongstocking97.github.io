/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*    Get grades from user and calculate the average.
*
*    Estimated:  0.35 hrs   
*    Actual:     0.42 hrs
*      The hardest part was figuring out how to get the correct letter.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Count the number of occurances of "Letter" in the "text" given.
 ***********************************************************************/
int countLetters(char * text, char letter)
{

   int count = 0;
   
   while (*text != 0)
   {
      if (*text == letter)
      {
         count++;
      }
      text++;
   }
   return count;
}

/**********************************************************************
 * The driver program for countLetters().
 ***********************************************************************/
int main()
{
   char text[256] = "";
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
