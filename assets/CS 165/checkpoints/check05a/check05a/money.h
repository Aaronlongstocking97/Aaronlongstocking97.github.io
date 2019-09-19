/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;

public:
   void prompt();
   void display() const;

   // Getter, return dollars, cents. No more code in the CPP file.
   int getDollars() const { return dollars; }
   int getCents() const { return cents; }
   void setDollars(const int dollars);
   void setCents(const int cents);
};

#endif
