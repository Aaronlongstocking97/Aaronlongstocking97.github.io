/***********************************************************************
* Program:
*    Assignment 44, Search Speed 
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*    This program compares the search speed of the linear search and
*    the binary search using instrumentation.
*
*    Estimated:  1.2 hrs   
*    Actual:     1.5 hrs
*    The hardest part was understanding linear and binary functions.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Takes in the list of numbers to search through while max is
 * defining the size of the numbers list. Producing the number of
 * items read. 
 ***********************************************************************/
int readNumbers(int list[], int max)
{
   char fileName[256];
   int num = 0;

   cout << "Enter filename of list: ";
   cin >> fileName;

   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Enable to open file " << fileName << endl;
      return 0;
   }

   while (num < max && fin >> list[num])
      num++;

   fin.close();
   return num;
}

/**********************************************************************
 * Takes in the list of numbers to search through while num uses the
 * size of the numbers list and search uses the number that you are
 * trying to find. Producing the number of times each compare was made
 * before search was found in the numbers array. 
 ***********************************************************************/
int linear(int list[], int num, int search)
{
   bool found = false;
   int compares = 0;

   for (int i = 0; i < num && ! found; i++)
   {
      compares++;
      if (search == list[i])
         found = true;
   }

   return compares;
   
}

/**********************************************************************
 * Takes in the list of numbers to search through while num uses the
 * size of the numbers list. Produces the number of times each
 * compare was made before search was found in the numbers array. 
 ***********************************************************************/
int binary(int list[], int num, int search)
{
   bool found = false;
   int compares = 0;

   int iFirst = 0;
   int iLast = num - 1;

   while (iLast >= iFirst && !found) 
   {
      compares++;
      int iMiddle = (iLast + iFirst) / 2;

      if (list[iMiddle] == search)
         found = true;
      else if (list[iMiddle] > search)
         iLast = iMiddle - 1;
      else
         iFirst = iMiddle + 1;
   }

   return compares;

}

/**********************************************************************
 * Takes in the list of numbers to search through and uses num to
 * define the size of the numbers in the list. Converting the average
 * number of comparisons to find each item in the array.
 ***********************************************************************/
float computeAverageLinear(int list[], int num)
{
   float averageLinear = 0.0;

   for (int i = 0; i < num; i++)
   {
      averageLinear += linear(list, num, list[i]);
   }

   averageLinear /= num;

   return averageLinear;
}

/**********************************************************************
 * Takes in the list of numbers to search through and num defines the
 * size of the numbers in that list. Converts the average number in
 * comparison to find each item in the array. 
 ***********************************************************************/
float computeAverageBinary(int list[], int num)
{
   float averageBinary = 0.0;

   for (int i = 0; i < num; i++)
   {
      averageBinary += binary(list, num, list[i]);
   }

   averageBinary /= num;

   return averageBinary;

}

/**********************************************************************
 * Reads the list and determines the speed of the searches
 ***********************************************************************/
int main()
{
   int list[1024];
   const int MAX = sizeof (list) / sizeof (list[0]);
   int num;

   if (!(num = readNumbers(list, MAX)))
      return 1;

   float averageLinear;
   averageLinear = computeAverageLinear(list, num);

   float averageBinary;
   averageBinary = computeAverageBinary(list, num);

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << "Linear search: " << setw(10) << averageLinear << endl;
   cout << "Binary search: " << setw(10) << averageBinary << endl;
   
   return 0;
}
