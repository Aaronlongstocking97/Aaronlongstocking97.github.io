// CS165 Checkpoint 5B

#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;

public:
   Money();
   Money(const int dollars);
   Money(const int dollars, const int cents);
   void prompt();
   void display() const;
   int getDollars() const { return dollars; }
   int getCents() const { return cents; }
   void setDollars(const int dollars);
   void setCents(const int cents);
};

#endif
