/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Prompting the user for ten grades and calculating the average
*    of those grades. 
*
*    Estimated:  0.30 hrs   
*    Actual:     0.35 hrs
*      The hardest part was understanding how an array worked.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Prompting the user for there grades and returning them
 * as an array with the size.
 ***********************************************************************/
void getGrades(int nums[], int numOfGrades)
{
   for (int i = 0; i < numOfGrades; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> nums[i];
   }
}

/**********************************************************************
 * Calculating the average from an array and the size of that array.
 ***********************************************************************/
void averageGrades(int nums[], int numOfGrades, int &average)
{
   int i;
   int sum = 0;
   for (i = 0; i < numOfGrades; i++)
   {
      sum += nums[i];
   }

   average = sum / numOfGrades;
   
}

/**********************************************************************
 * The head source, where each function will send signals too. 
 ***********************************************************************/
int main()
{
   int grades[10] = {}; // {} in an array will set all values to NULL
   int numGrades = 10;
   int average;
   
   getGrades(grades, numGrades);
   averageGrades(grades, numGrades, average);
   
   cout << "Average Grade: " << average << "%\n";
   
   return 0;
}





