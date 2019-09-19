// CS165 - Checkpoint 3A

#include <iostream>
using namespace std;

int prompt()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    // Peform error checking
    if (number < 0)
    {
       throw string("The number cannot be negative."); // Will exit the function
    }
    if (number > 100)
    {
       throw string("The number cannot be greater than 100.");
    }
    if (number % 2 != 0)  // Check if the number is odd
    {
       throw string("The number cannot be odd.");
    }

    // Passed error checking
    return number;
}

/**********************************************************************
 *
 ***********************************************************************/
int main()
{
   try
   {
      int value = prompt();
      cout << "The number is " << value << "." << endl; // Won't execute if exception is thrown
   }
   catch (const string &s)
   {
      cout << "Error: " << s << endl;
   }

   return 0;
}
