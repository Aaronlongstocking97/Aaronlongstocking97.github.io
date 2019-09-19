/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }


   NumberList(int size);
   NumberList(const NumberList &rhs);
   ~NumberList();
   NumberList& operator=(const NumberList &rhs);

   int getNumber(int index) const;
   void setNumber(int index, int value);

   void displayList() const;

};

#endif
