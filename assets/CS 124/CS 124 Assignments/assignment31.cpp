/***********************************************************************
* Program:
*    Assignment 30, Array Design
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    Prompting the user for there grades and calculating the average
*    from the values given. The users response cannot be = -1. 
*
*    Estimated:  0.30 hrs   
*    Actual:     0.32 hrs
*      The hardest part was understanding how an array is 
*      pass by reference.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Getting the grades from the user and returning
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
 * Calculate the average from the array and its size.
 ***********************************************************************/
bool averageGrades(int nums[], int numOfGrades, int &average)
{
   int sum = 0;
   int count = 0;
   
   for (int i = 0; i < numOfGrades; i++)
   {
      if (nums[i] != -1)
      {
         sum += nums[i];
         count++;
      }
   }
   if (count > 0)
   {
      average = sum / count;
      return true;
   }
   else
   {
      average = 0;
      return false;
   }
   
}

/**********************************************************************
 * The driver function that promots and holds member data.
 ***********************************************************************/
int main()
{
   int grades[10] = {}; // {} in an array will set all values to NULL
   int average = 0;
   bool result = false;
   
   getGrades(grades, 10);
   result = averageGrades(grades, 10, average);
   
   if (result)
   {
      cout << "Average Grade: " << average << "%\n";
   }
   else
   {
      cout << "Average Grade: ---%\n";
   }
   
   return 0;
}





