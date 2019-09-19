// CS165 Checkpoint 09A

#include <iostream>
#include <string>
using namespace std;

class Car
{
   protected:
      string name;  // Available to all derived classes

   public:
      Car();
      string getName() const { return name; }
      void setName(const string &name) { this->name = name; }
      virtual string getDoorSpecs() const;  // Virtual means that all derived classes
                                            // must implement this function.  The software
                                            // will keep track of which getDoorsSpecs function
                                            // to call based on what kinds of Car object is
                                            // created.
};

class Civic : public Car
{
   public:
      Civic();
      string getDoorSpecs() const;
};

class Odyssey : public Car
{
   public:
      Odyssey();
      string getDoorSpecs() const;
};

class Ferrari : public Car
{
   public:
      Ferrari();
      string getDoorSpecs() const;
};

// Initialize unknown car
Car::Car()
{
   setName("Unknown Model");
}

// Get Door Specs for unknown car
string Car::getDoorSpecs() const
{
   return "Unknown doors";
}

// Initialize civic
Civic::Civic()
{
   setName("Civic");
}


// Get Doors Specs for civic car
string Civic::getDoorSpecs() const
{
   return "4 doors";
}

// Initialize Odyssey car
Odyssey::Odyssey()
{
   setName("Odyssey");
}

// Get Doors Specs for Odyssey car
string Odyssey::getDoorSpecs() const
{
   return "2 front doors, 2 sliding doors, 1 tail gate";
}

// Initialize Ferrari car
Ferrari::Ferrari()
{
   setName("Ferrari");
}

// Get Doors Specs for Ferrari car
string Ferrari::getDoorSpecs() const
{
   return "2 butterfly doors";
}

// Will accept any type of car object.  The software knows what type of
// Car was originally created and will call the appropraite getDoorSpecs
// function.
void attachDoors(const Car &car)
{
   cout << "Attaching doors to " << car.getName();  // In the base class
   cout << " - " << car.getDoorSpecs(); // The virtual function
   cout << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

   Civic civic;
   Odyssey odyssey;
   Ferrari ferrari;

   attachDoors(civic);
   attachDoors(odyssey);
   attachDoors(ferrari);

   return 0;
}
