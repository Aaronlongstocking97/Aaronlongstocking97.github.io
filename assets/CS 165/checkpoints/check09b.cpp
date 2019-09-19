// CS165 Checkpoint 9B

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Shape
{
private:
   string name;

public:
   virtual ~Shape() { }
   string getName() const { return name; }
   void setName(const string &name) { this->name = name; }
   virtual float getArea() const = 0;
};

class Circle : public Shape
{
private:
   float radius;

public:
   Circle();
   ~Circle();
   float getRadius() const { return radius; }
   void setRadius(const float radius) { this->radius = radius; }
   float getArea() const;
};

// Initialize the circle object
Circle::Circle()
{
   setName("Circle");
}

// Deallocate the circle object
Circle::~Circle()
{
   cout << "Cleaning up " << getName() << endl;
}

// Calculate the area
float Circle::getArea() const
{
   return 3.14 * radius * radius;
}

class Rectangle : public Shape
{
private:
   float length;
   float width;

public:
   Rectangle();
   ~Rectangle();
   float getLength() const { return length; }
   float getWidth() const { return width; }
   void setLength(const float length) { this->length = length; }
   void setWidth(const float width) {this->width = width; }
   float getArea() const;
};

// Initialize the rectangle object
Rectangle::Rectangle()
{
   setName("Rectangle");
}

// Deallocate the rectanable object
Rectangle::~Rectangle()
{
   cout << "Cleaning up " << getName() << endl;
}

// Calculate the area
float Rectangle::getArea() const
{
   return length * width;
}

const int MAX_SIZE = 10;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // We will put all of our code in main for this one, just to keep
   // the focus on the virtual functions and not on passing items
   // between functions.

   // TODO: 1. Declare your array here
   // For this assignment you can use the size: MAX_SIZE
   Shape *shapes[MAX_SIZE];

   char letter;
   int count = 0;

   do
   {
      cout << "Please enter 'c' for circle, 'r' for rectangle or 'q' to quit: ";
      cin >> letter;

      if (letter == 'c')
      {
         float radius;
         cout << "Enter the radius: ";
         cin >> radius;

         // TODO: 2. Create your circle object here, set the radius value
         // and add it to the array at index "count".
         Circle *circle = new Circle();
         circle->setRadius(radius);
         shapes[count] = circle;


         count++; // we have seen another shape
      }
      else if (letter == 'r')
      {
         float length;
         float width;

         cout << "Enter the length: ";
         cin >> length;

         cout << "Enter the width: ";
         cin >> width;

         // TODO: 3. Create your rectangle object here, set the length and
         // width, and add it to the array at index "count".
         Rectangle *rectangle = new Rectangle();
         rectangle->setLength(length);
         rectangle->setWidth(width);
         shapes[count] = rectangle;

         count++; // we have seen another shape
      }

   } while (letter != 'q');

   // Set the precision for our decimals
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // Now we will display each shape
   for (int i = 0; i < count; i++)
   {
      // TODO: 4. Add a cout statment here to display the name and the area
      // of each shape in the list in the format "Circle - 10.32"
      cout << shapes[i]->getName() << " - " << shapes[i]->getArea() << endl;

   }

   // TODO: 5. Loop through and free the memory of each object.
   for (int i=0; i < count; i++)
   {
      delete shapes[i];
   }

   return 0;
}
