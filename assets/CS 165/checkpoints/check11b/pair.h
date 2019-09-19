/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

template<class T1, class T2>
class Pair
{
   private:
      T1 item1;
      T2 item2;

   public:
      T1 getFirst() 
      {
         return item1;
      }

      T2 getSecond()
      {
         return item2;
      }

      void setFirst(T1 item1)
      {
         this->item1 = item1;
      }
 
      void setSecond(T2 item2)
      {
         this->item2 = item2;
      }

};

template<class T1, class T2>
void Pair<T1,T2>::display()
{
   cout << item1 << " - " << item2;
}

#endif // PAIR_H
