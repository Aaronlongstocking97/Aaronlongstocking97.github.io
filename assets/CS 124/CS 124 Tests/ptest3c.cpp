/***********************************************************************
* Program:
*    Test 03, Reverse a List
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    This program does...
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * This function does...
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Enter the filename: ";
   cin >> fileName;
}

/**********************************************************************
 * This function does...
 ***********************************************************************/
/**********************************************************************
 * Reading the file...
 ***********************************************************************/
void readFile(char fileName[], int list[], int &numbers, float &value)
{

   int sum = 0;
   ifstream fin(fileName);

   if (fin.fail())
   {
      cout << "Error opening file \"" << fileName << "\"" << endl;
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
 * This function does...
 ***********************************************************************/
void display()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   
   

   return 0;
}

/**********************************************************************
 * This function does...
 ***********************************************************************/
int main()
{

   char fileName[256];
   int list[10];
   float value = 0.0;
   int numbers = 0;

   getFileName(fileName);
   readFile(fileName, list, numbers, value);
   display(list)


   return 0;
}
