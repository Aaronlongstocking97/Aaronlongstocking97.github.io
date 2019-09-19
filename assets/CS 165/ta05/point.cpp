/***************************************************************
 * File: point.cpp
 * Author: Aaron Jones
 * Purpose: Contains the method implementations for the Point
 *          class.
 ***************************************************************/

#include "point.h"

#include <iostream>
using namespace std;

/**********************************************************************
 * Function(method): display
 * Purpose: Displays the point.
 ***********************************************************************/
void Point::display() const
{
   // Note: We could just use x and y here and not the getters
   // because it's a member function. But this will force you
   // to deal with const :-)...

   cout << "(" << getX() << ", " << getY() << ")";
}

/**********************************************************************
 * Default Constructor:
 * Purpose:
 ***********************************************************************/
Point::Point()
{
   x = 5;
   y = 5;
}

/**********************************************************************
 * Non-Default Constructor:
 * Purpose:
 ***********************************************************************/
Point::Point(int x, int y)
{
   setX(x);
   setY(y);
}

/**********************************************************************
 * Function(method): setX
 * Purpose:
 ***********************************************************************/
void Point::setX(const int x)
{
   if (x < 1)
   {
      x = 1;
   }
   else if (x > 10)
   {
      x = 10;
   }

   this->x = x;
}

/**********************************************************************
 * Function(method): setY
 * Purpose:
 ***********************************************************************/
void Point::setY(const int y)
{
   if (y < 1)
   {
      y = 1;
   }
   else if (y > 10)
   {
      y = 10;
   }

   this->y = y;
}
