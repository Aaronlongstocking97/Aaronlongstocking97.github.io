// CS165 - Checkpoint 01B

#include <iostream>
using namespace std;

// Prompt the user for the size of the list
int getSize()
{
    int size;

    cout << "Enter the size of the list: ";
    cin >> size;

    return size;
}

// Populate the array with user provided values
// Notice that the list is passed without a size in the
// brackets.  The size must be passed as a seperate
// parameter.
void getList(int list[], const int size)
{
   int i;

   for (i=0; i<size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];
   }
}

// Traverse through the array and look for numbers
// that are divisible by 3.
void displayMultiples(const int list[], const int size)
{
   int i;

   cout << "\nThe following are divisible by 3:\n";
   for (i=0; i<size; i++)
   {
      if ((list[i] % 3) == 0)
      {
         cout << list[i] << "\n";
      }
   }
}

// Driver
int main()
{
   int list[20];
   int size;

   size = getSize();
   getList(list, size);  
   displayMultiples(list, size);

   return 0;
}
