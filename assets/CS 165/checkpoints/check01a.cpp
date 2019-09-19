// CS165 - Checkpoint 01A

#include <iostream>
using namespace std;

// Demonstrate proper use of cout/cin
int main()
{
   string name;
   int age;

   cout << "Hello CS 165 World!\n";
   cout << "Please enter your first name: ";
   cin >> name;
   cout << "Please enter your age: ";
   cin >> age;
   cout << "\nHello " << name << ", you are " << age << " years old.\n";

   return 0;
}
