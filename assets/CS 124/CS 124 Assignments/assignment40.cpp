/***********************************************************************
* Program:
*    Assignment 40, Multi-dimensional arrays
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Display a tic tac toe board on the screen from a file. 
*
*    Estimated:  0.55 hrs   
*    Actual:     1.2 hrs
*    The hardest part was getting the program to compile. 
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

#define BOARD_SIZE 3

/***********************************************************************
 * Read the tic tac toe board from a file into a multi-dimensional
 * array.
 ***********************************************************************/
bool readFile(char fileName[],char board[][BOARD_SIZE],
              int size)
{
   ifstream fileIn(fileName);
   char input = '\0';

   if (fileIn.fail())
   {
      return false;
   }
   int row = 0;
   int col = 0;
   while (fileIn >> input)
   {
      if (row == size)
      {
         fileIn.close();
         return false;
      }
      board[row][col] = input;
      if (col == size - 1)
      {
         row++;
         col = 0;
      }
      else
      {
         col++;
      }
   }
   fileIn.close();
   if (row != size)
   {
      return false;
   }
   return true;
}

/**********************************************************************
 * Display the tic tac toe array on the screen
 ***********************************************************************/
void displayBoard(char board[][BOARD_SIZE],int size)
{
   for (int row = 0; row < size; row++)
   {
      for (int col = 0; col < size; col++)
      {
         if (board[row][col] == '.')
         {
            cout << "   ";
         }
         else
         {
            cout << " " << board[row][col] << " ";
         }
         if (col != size - 1)
         {
            cout << "|";
         }
      }
      if (row != size - 1)
      {
         cout << "\n---+---+---\n";
      }
   }
   cout << endl;
}

/**********************************************************************
 * Write the tic tac toe array back to a file
 ***********************************************************************/
bool writeFile(char fileName[],char board[][BOARD_SIZE],
               int size)
{
   ofstream fileOut(fileName);
   if (fileOut.fail())
   {
      return false;
   }
   for (int row = 0; row < size; row++)
   { 
      for (int col = 0; col < size; col++)
      {
         fileOut << board[row][col] << " ";
      }
   }
   cout << "File written" << endl;
   fileOut.close();
   return true;
}
   
/**********************************************************************
 * Driver for the program 
 *****************************************************************/            
int main()
{
   char fileName[100];
   bool result = false;
   char board[BOARD_SIZE][BOARD_SIZE];
   cout << "Enter source filename: ";
   cin >> fileName;

   result = readFile(fileName, board, BOARD_SIZE);
   if (result)
   {
      displayBoard(board, BOARD_SIZE);

      cout << "Enter destination filename: ";
      cin >> fileName;

      result = writeFile(fileName, board, BOARD_SIZE);
   }
   
   return 0;
}
