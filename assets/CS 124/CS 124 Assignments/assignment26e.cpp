/***********************************************************************
* Program:
*    Assignment 26, Files
*    Sister Hansen, CS 124
* Author:
*    Aaron Jones
* Summary: 
*    Reading ten different grades from a file and displaying
*    the average.
*
*    Estimated:  0.4 hrs   
*    Actual:     0.55 hrs
*      The hardest part was understanding how to read a file.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Prompting the user for the filename containing the grades.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

/**********************************************************************
 * Prompting the user for the filename containing the grades.
 ***********************************************************************/
 bool writeFile()
 {
    // declare  the output stream 
    ofstream fout;
    
    //open the file 
    fout.open("greeting.txt");
    if (fout.fail())
       return false; // exit function
       
       // write the text
       fout << "Hello world\n";
       if (fout.fail())
       {
          fout.close();
          return false;
       }
    fout.close();
    return true;

 }
/**********************************************************************
 * Reading the grades from the file and returning the average.
 * If there is an error or less than ten grades, display error and
 * return -1.0.
 ***********************************************************************/
float readFile(char fileName[])
{
   int count = 0;
   int sum = 0;
   int value = 0;
   ifstream fileIn(fileName);

   if (fileIn.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1.0;
   }

   while (fileIn >> value)
   {
      count++;
      sum += value;
   }

   fileIn.close();

   if (count != 10)
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1.0;
   }

   return ((float)sum / (float)count);
}

/**********************************************************************
 * Showing the average grade.
 ***********************************************************************/
void display(float average)
{

   if (average >= 0.0)
   {
      cout.setf(ios::fixed);
      cout.precision(0);
      
      cout << "Average Grade: " << average << "%" << endl;
   }
  
}

/**********************************************************************
 * Driver for the program.
 ***********************************************************************/
int main()
{

   char fileName[256];
   float average = 0.0;

   getFileName(fileName);
   average = readFile(fileName);
   display(average);

   return 0;
}
