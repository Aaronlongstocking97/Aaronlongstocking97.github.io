// CS165 Checkpoint 10A


#include <iostream>
#include <vector>

using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector<int> numbers;
   vector<string> strings;
   int inputInt;
   string inputString;

   do
   {
      cout << "Enter int: ";
      cin >> inputInt;
      if (inputInt != 0)
      {
         numbers.push_back(inputInt); // Add to the back of the vector
      }
   }
   while (inputInt != 0);

   cout << "Your list is:\n";

   // Implement without an iterator 
   for (int i=0; i<numbers.size(); i++)
   {
      cout << numbers[i] << endl;
   }

   cout << "\n";
   do
   {
      cout << "Enter string: ";
      cin >> inputString;
      if (inputString != "quit")
      {
         strings.push_back(inputString);
      }
   }
   while (inputString != "quit");

   cout << "Your list is:\n";

   /* Implement without an iterator */
   for (int i=0; i<strings.size(); i++)
   {
      cout << strings[i] << endl;
   }

   return 0;
}
