/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals 
*    Sister Hansen, CS124
* Author:
*    Aaron Jones
* Summary: 
*   Writing two functions that compute the letter grade from the users
*   input and display that number in the percentage form. 
*
*    Estimated:  0.50 hrs   
*    Actual:     1.15 hrs
*    The hardest part was understanding how to use swtich statements.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Convert the grade to a letter grade, for example A, B, C, D, F.
 ***********************************************************************/
char computeLetterGrade(const int grade)
{
   char letter = '\0';
   switch (grade / 10)
   {
      case 10:
      case 9:
         letter = 'A';
         break;
      case 8:
         letter = 'B';
         break;
      case 7:
         letter = 'C';
         break;
      case 6:
         letter = 'D';
         break;
      default:
         letter = 'F';
   }
   return letter;
}

/**********************************************************************
 * Determine the sign (+ or -) for the letter grade provided.
 * If theres no sign needed then return ' * ' 
 ***********************************************************************/
char computeGradeSign(const int grade)
{
   int lastDigit = grade % 10;
   char sign = '*';

   if ((grade >= 60) && (grade <= 96))
   {
      sign = (lastDigit <= 2) ? '-': ((lastDigit >= 7) ? '+' : '*');
   }
   return sign;
}

/**********************************************************************
 * Driver for computeLetterGrade() and computeGradeSign() 
 ***********************************************************************/
int main()
{
   int grade = 0;
   char letter = '\0';
   char sign = '\0';

   cout << "Enter number grade: ";
   cin >> grade;
   letter = computeLetterGrade(grade);
   sign = computeGradeSign(grade);
   cout << grade << "% is " << letter;
   if (sign != '*')
   {
      cout << sign;
   }
   cout << endl;
   return 0;
}
