/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    This program will display to the user the Sudoku Game 
*    and will prompt the user a list of menu options that 
*    can be accessed through the key words listed. Continually
*    the program will read in a file and write to a separate 
*    file that will be saved with the users response. The saved 
*    file can be reused if the user wants to play the game again. 

*    Estimated:  4.0 hrs   
*    Actual:     6.05 hrs
*      The hardest part was getting the correct values to display
*      for the imputed location on the sudoku board.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define BOARD 9

/**********************************************************************
 * Reads in the file from the user and sends the file to be read.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin  >> fileName;
}

/**********************************************************************
 * Takes in the file information from the user and stores it into a
 * char array that will be passed through to other functions.
 ***********************************************************************/
bool readFile(char fileName[],char board[][BOARD], int size)
{
   ifstream fin(fileName);
   int row;
   int col;
   
   if (fin.fail())
   {
      return false; 
   }
   else 
   {
      for (row = 0; row < size; row++)
      {
         for (col = 0; col < size; col++)
         {
            fin >> board[row][col];
         }
      }
      return true;
   }
   fin.close();
}

/**********************************************************************
 * Displays to the user a list of options that can be accessed through
 * the key word options.
 ***********************************************************************/
char menuOptions()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n";
   cout << "\n";
}

/**********************************************************************
 * Projects to the user a board the will mimic the style of sudoku.
 * Additionally it will account for white space and will ignore
 * the zeros from the board array. 
 ***********************************************************************/
void displayBoard(char board[][BOARD], int size)
{
   int count = 1;
   cout << "   " << "A B C D E F G H I\n";
   for (int row = 0; row < size; row++)
   {
      cout << count++ << "  ";
      for (int col = 0; col < size; col++)
      {
         if (board[row][col] != '0')
         {
            if (col == 2)
            {
               cout << board[row][col];
            }
            else if (col == 5)
            {
               cout << board[row][col];
            }
            else if (col == 8) 
            {
               cout << board[row][col];
            }
            else 
            {
               cout << board[row][col] << " ";
            }
         }
         if (board[row][col] == '0')
         {
            if (col == 2)
            {
               cout << " ";
            }
            else if (col == 5)
            {
               cout << " ";
            }
            else if (col == 8)
            {
               cout << " ";
            }
            else 
            {
               cout << "  ";
            }
         }
         if (col == 2)
         {
            cout << "|";
         }
         else if (col == 5)
         {
            cout << "|";
         }
         else if (col == 8)
         {
            cout << '\n';
         }
      }
      if (row == 2)
      {
         cout << "   -----+-----+-----\n";
      }
      else if (row == 5)
      {
         cout << "   -----+-----+-----\n";
      }
   }
   cout << endl;
}

/**********************************************************************
 * Stores the users response for the coordinates on the sudoku board
 * inside of the char coords array.
 ***********************************************************************/
void getCoordinates(char coords[])
{
   cout << "What are the coordinates of the square: ";
   cin  >> coords;
}

/**********************************************************************
 * Checks to see if the space on the board is filled and if it is not 
 * equal to a zero. 
 ***********************************************************************/
bool isValid(char coords[], int row, int col, char board[][BOARD])
{
   if (board[row][col] != '0')
   {
      cout << "ERROR: Square \'" << (char)toupper(coords[0]) 
           << coords[1] << "\' is filled\n" << endl;
      return false;
   }
   return true;
}

/**********************************************************************
 * Checks each each row and column to see if the value taken in from
 * the user is valid. If the value is not valid then the expression 
 * will return false.
 ***********************************************************************/
bool isValidValue(int prow, int pcol, char board[][BOARD], int value)
{
   int top = prow / 3 * 3;
   int bottom = top + 2;
   int left = pcol / 3 * 3;
   int right = left + 2;
   int size = BOARD;
   
   // Checking the top row against the bottom
   for (int row = top; row <= bottom; row++)
   {  
      // Checking the left side against the right
      for (int col = left; col <= right; col++)
      {
         if (value + 48 == board[row][col])
            return false;
      }
   }
   // Checking the column
   for (int col = 0; col < size; col++)
   {
      if (value + 48 == board[prow][col])
         return false;
   }
   // Checking the row
   for (int row = 0; row < size; row++)
   {
      if (value + 48 == board[row][pcol])
         return false;
   }
   return true;
}

/**********************************************************************
 * Takes in the coordinates from the user and calls isValidValue to 
 * show the possible values that the user can input for the selected 
 * location. 
 ***********************************************************************/
void displayPossibleValues(char board[][BOARD])
{
   char coords[2]; // storing the coordinates into a two 
   // dimensional array
   getCoordinates(coords);   

   int row = int(coords[1]) - 49; //number
   int col = (int)toupper(coords[0]) - 65; //letter
   
   cout << "The possible values for \'" << (char)toupper(coords[0]) 
        << coords[1] << "\' are: ";
   
   bool isFirst = true; // Checking if the value printed is the first
   
   for (int i = 0; i < 10; i++)
   {
      if (isValidValue(row, col, board, i))
      {
         if (isFirst)
         {
            cout << i;
            isFirst = false;
         }
         else 
         {
            cout << ", " << i;
         }
      }
   }
   cout << "\n"; 
}

/**********************************************************************
 * Calls multiple functions to take in the users response and checks if 
 * the coordinates taken in are accurate to the boards values. 
 ***********************************************************************/
void editSquare(char board[][BOARD])
{
   char coords[2];
   getCoordinates(coords);   

   int row = (int)(coords[1]) - 49; //number
   int col = (int)toupper(coords[0]) - 65; //letter
   
   if (isValid(coords, row, col, board))
   {
      int value;
      cout << "What is the value at \'" << (char)toupper(coords[0]) 
           << coords[1] << "\': ";
      cin  >> value;
      
      if (isValidValue(row, col, board, value))
      {  
         board[row][col] = value + 48;
         cout << "\n";
      }
      else
      {
         cout << "ERROR: Value \'" << value
              << "\' in square \'" 
              << (char)toupper(coords[0]) 
              << coords[1] << "\' is invalid\n" << endl;
      }
   }  
}

/**********************************************************************
 * Calls multiple functions based on the users key word response and 
 * loops through until the user quits the loop.
 ***********************************************************************/
void menu(char board[BOARD][BOARD])
{
   char response;
   
   do 
   {
      cout << "> ";
      cin >> response;
      
      if (response == '?')
      {
         menuOptions();
         cout << "\n";
      }
      else if (toupper(response) == 'D')
      {
         displayBoard(board, BOARD);
      }
      else if (toupper(response) == 'E')
      {
         editSquare(board);
      }
      else if (toupper(response) == 'S')
      {
         displayPossibleValues(board);
         cout << "\n";
      }
      else if (toupper(response) != 'Q')
      {
         cout << "ERROR: Invalid command\n";
      }
   }
   while (toupper(response) != 'Q');
}

/**********************************************************************
 * Takes in a new file so that the users input can be stored inside 
 * of a different file. Once completed the game will display 
 * 'Board written successfully.'
 ***********************************************************************/
bool quitGame(char newFileName[],char board[][BOARD], int size)
{
   ofstream fout(newFileName);
   if (fout.fail())
   {
      return false;
   }
   for (int row = 0; row < size; row++)
   { 
      for (int col = 0; col < size; col++)
      {
         fout << board[row][col];
      }
   }
   cout << "Board written successfully" << endl;
   fout.close();
   return true;
}

/**********************************************************************
 * The driver program that initiates the if statement if the file read
 * in has no errors. Once the condition is met the user will be able 
 * to play the sudoku game. When the user exits the game then they will
 * be prompted for a file name to write there data too. 
 ***********************************************************************/
int main()
{
   char fileName[256];
   char newFileName[256];
   char board[BOARD][BOARD];
   bool file = false;
   
   getFileName(fileName);
   file = readFile(fileName, board, BOARD);
   if (file)
   {
      menuOptions();
      displayBoard(board, BOARD);
      menu(board);
      
      cout << "What file would you like to write your board to: ";
      cin >> newFileName;
      
      file = quitGame(newFileName, board, BOARD);
   }
   return 0;
}
