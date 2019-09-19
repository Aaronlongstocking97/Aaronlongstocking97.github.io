/***********************************************************************
* Program:
*    Test 3a, Grade Validation
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
 * Prompting the user...
 ***********************************************************************/
void getGrades(int grades[], int numOfGrades)
{
   // int count = 1;
   for (int i = 0; i < numOfGrades; i++)
   {
      cout << "\tEnter grade " << i + 1 << ": ";
      cin  >> grades[i];
      // count++;
   } 
}

/**********************************************************************
 * Calculate the average from the array and its size.
 ***********************************************************************/
int averageGrades(int grades[], int numOfGrades, int &average)
{
   int sum = 0;
   // int count = 1;
   for (int i = 0; i < numOfGrades; i++)
   {
      if (grades[i] > 100 || grades[i] < 0)
      {
         cout << "\tGrade " << i + 1 << " is not valid. " 
              << "Please re-enter grade " << i + 1 << ": "; 
         cin  >> grades[i];
      }
      // count++;
      sum += grades[i];
      average = sum / numOfGrades;
   }
   return average;
}

/**********************************************************************
 * Driver program for all the other functions.
 ***********************************************************************/
int main()
{

   int numOfGrades;
   int average = 0;
   
   cout << "How many grades? ";
   cin  >> numOfGrades;
   int grades[numOfGrades];
   getGrades(grades, numOfGrades);
   int result = averageGrades(grades, numOfGrades, average);
   cout << "The average grade is " << result << "%" << endl;


   return 0;
}
