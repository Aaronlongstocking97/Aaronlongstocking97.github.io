/***************************************************************
 * File: point.h
 * Author: Aaron Jones
 * Purpose: Contains the definition of the Point class
 ***************************************************************/

#ifndef POINT_H
#define POINT_H

/****************************************************************
 * Class: Point
 * Purpose: A simple class for an x and y coordinate.
 ****************************************************************/
class Point
{
   private:
      int x;
      int y;

   public:
      /********************
       * Display Functions
       ********************/
      void display() const;

      /********************
       * Constructors
       ********************/
      Point();
      Point(int x, int y);

      /********************
       * Getters
       ********************/
      int getX() const { return x; }
      int getY() const { return y; }

      /********************
       * Setters
       ********************/
      void setX(const int x);
      void setY(const int y);

};

#endif
