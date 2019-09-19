#include "numberList.h"

#include <iostream>
using namespace std;

NumberList::NumberList(int size)
{
   this->size = size;
   array = new int[size];
   for (int i=0; i<size; i++)
   {
      array[i] = 0;
   }
}

NumberList::~NumberList()
{
   delete [] array;
   array = NULL;
   cout << "Freeing memory" << endl;
}

// Create object based on another NumberList object
NumberList::NumberList(const NumberList &rhs)
{
   // Use the same size
   size = rhs.size;
   array = new int[size];
   // Use the same values
   for (int i=0; i<size; i++)
   {
      array[i] = rhs.array[i];
   }
}

// Update current objet based on another NumberList object
NumberList& NumberList::operator=(const NumberList &rhs)
{
   // Delete current array
   if (array != NULL)
   {
      delete [] array;
      array = NULL;
   }
   // Use the same size
   size = rhs.size;
   array = new int[size];
   // Use the same values
   for (int i=0; i<size; i++)
   {
      array[i] = rhs.array[i];
   } 
   return *this;
}


/******************************************************
 * Function: getNumber
 * Description: Returns the number at the given index.
 ******************************************************/
int NumberList::getNumber(int index) const
{
   int number = -1;

   if (index >= 0 && index < size)
   {
      number = array[index];
   }

   return number;
}

/******************************************************
 * Function: setNumber
 * Description: Sets the value to the array at the given index.
 ******************************************************/
void NumberList::setNumber(int index, int value)
{
   if (index >= 0 && index < size)
   {
      array[index] = value;
   }
}

/******************************************************
 * Function: displayList
 * Description: displays the list
 ******************************************************/
void NumberList::displayList() const
{
   for (int i = 0; i < size; i++)
   {
      cout << array[i] << endl;
   }

   cout << endl;
}

