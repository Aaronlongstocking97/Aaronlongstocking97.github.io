/***********************************************************************
* Program:
*    Test 3, Reverse a File 
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones 
* Summary:
*    Prompting the user to input a file. From this input there will be
*    a reverse function that changes the original file.
*    The file will then display back to the user backwards.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*    The hardest part was trying to get the while loop in the readFile
*    function to work.
************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Prompting the user for the file name.
 ***********************************************************************/
void getFilename(char fileName[])
{

   cout << "Enter the filename: ";
   cin  >> fileName;
}

/**********************************************************************
 * Reading the input of the fileName and converting the data into a
 * string that can be reversed and display on the screen.
 ***********************************************************************/
int readFile(char fileName[], float data[])
{

   int count = 0;
   ifstream fin(fileName);
   if (fin.fail())    
   {
      cout << "Error opening file " << fileName << "\n";
   }

   while (fin >> data[count])
   {
      cerr << data[count] << endl;
      count++;
   }
   cerr << "count is: " << count << endl;  
   fin.close(); 
   return count;                    
}

/**********************************************************************
 * Reversing the data from the original input and sending that data to
 * the screen. 
 ***********************************************************************/
void reverse(float data[], int count)
{
   int i;
   if (count > 0)
   {
      cout << "New order:\n";
   }
   for (i = count - 1; i >= 0; i--)
   {
      cout << data[i] << endl;
   }
}

/**********************************************************************
 * Driver program for the input of the fileName and sent to readFile
 * to eventually be outputted onto the screen backwards.
 ***********************************************************************/
int main()
{

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   float data[100] = {};
   char fileName[256];
   getFilename(fileName);
   int count = readFile(fileName, data);
   reverse(data, count);

   return 0;
}
