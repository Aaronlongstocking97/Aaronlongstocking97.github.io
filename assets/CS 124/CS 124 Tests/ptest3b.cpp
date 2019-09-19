/***********************************************************************
* Program:
*    Test 3b, Threshold
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*    This program will...
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      The hardest part was...
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Prompting the user for the filename.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "What is the name of the file: ";
   cin >> fileName;
}

/**********************************************************************
 * Showing the...
 **********************************************************************
void display(int list[])
{

   cout << "The following items are below the threshold:\n";
   for (int i = 0; list[i]; i++)
   {
      cout << "\t " << list[i] << endl;
   }
}
*/
/**********************************************************************
 * Reading the file...
 ***********************************************************************/
void readFile(char fileName[], int list[], int &numbers, float &value)
{

   int sum = 0;
   ifstream fin(fileName);

   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
   }

   while (fin >> list[numbers])
   {
      if (value < list[numbers])
      {
         display(list[numbers]);
      }
      numbers++;
   }
   fin.close();
}

/**********************************************************************
 * Driver for the program.
 ***********************************************************************/
int main()
{

   char fileName[256];
   int list[10];
   float value = 0.0;
   int numbers = 0;

   getFileName(fileName);
   cout << "What is the threshold: ";
   cin  >> value << endl;
   readFile(fileName, list, numbers, value);
   display(list)

   return 0;
}

