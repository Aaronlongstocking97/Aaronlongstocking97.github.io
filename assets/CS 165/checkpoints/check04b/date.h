// CS165 Checkpoint 04B

#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
   private:
      int month;
      int day;
      int year;

   public:
      void set(const int month, const int day, const int year);
      void displayAmerican() const;  // const means will not modify member data
      void displayEuropean() const;
      void displayISO() const;
};

#endif
