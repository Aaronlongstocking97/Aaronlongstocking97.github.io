/***********************************************************************
* Program:
*    Project 09, Mad Lib 
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*    This program will take in the users response for 
*    each question asked and will replace the original
*    location in the displayed story. It will also check 
*    the file that is read into the story array if it 
*    is a question or a punctuation based on the multi-dimensional
*    array.
*
*    Estimated:  2.25 hrs   
*    Actual:     3.30 hrs
*      The hardest part was getting everything to compile and 
*      understanding the design of the project.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Prompting the user for the Madlib text file that will contain the
 * original story for the game to be played.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
}

/**********************************************************************
 * Loops through the story array and takes the questions in the original
 * text and redefines these questions so they are readable to the user.
 ***********************************************************************/
void replaceQuestionTag(char word[])
{
   cout << '\t' << (char)toupper(word[1]);
   
   for (int i = 2; word[i]; i++)
   {
      if (word[i] == '_')
      {
         cout << ' ';
      }
      else 
      {
         cout << (char)tolower(word[i]);
      }
   }
   cout << ": ";
   cin.getline(word, 256);
}

/**********************************************************************
 * Reading the Madlib file and storing this file inside of the story
 * array. It will bypass main for calling two different functions that
 * are defined as questions. These functions will be the questions 
 * asked if the IF statement is initiated. 
 ***********************************************************************/
void readFile(char fileName[], char story[][32], int &numWords)
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
   }
   
   while (fin >> story[numWords])
   {
      if (story[numWords][0] == ':' && isalpha(story[numWords][1]))
      {
         replaceQuestionTag(story[numWords]);
      }
      numWords++;
   }
   fin.close();
}

/**********************************************************************
 * Prompting the user for input on whether or not they want to play
 * the Madlib game again.
 ***********************************************************************/
bool askplayAgain()
{
   cout << "Thank you for playing.\n";
   return false;
}

/**********************************************************************
 * Driver program for all the other functions. It will story multiple
 * arrays that will be used throughout the story and each variable will
 * be used through pass by reference. 
 ***********************************************************************/
int main()
{

   char fileName[256];
   char story [256][32];
   int numWords = 0;

   getFileName(fileName);
   cin.ignore();
   readFile(fileName, story, numWords);
   bool playAgain = askplayAgain();

   return 0;
}
