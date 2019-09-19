// CS165 Checkpoint 3B

#include <iostream>
#include <limits>
using namespace std;

int prompt()
{
   int number = 0;
   bool validNumber;

   // Loop until a valid number is entered
   do
   {
      validNumber = true;
      cout << "Enter a number: ";
      cin >> number;

      // If not numeric, then fail bit will be set
      if (cin.fail())
      {
         // Clear the fail bit
         cin.clear();

         // Ignore everything up to and including the newline
         // This would also be okay: cin.ignore(100,'\n');
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
         cout << "Invalid input." << endl;

         // Repeat the while loop to get a better input
         validNumber = false;
      }
   }
   while (!validNumber);
   return number;
}

/**********************************************************************
 *
 ***********************************************************************/
int main()
{
   int value = prompt();
   cout << "The number is " << value << "." << endl;

   return 0;
}
