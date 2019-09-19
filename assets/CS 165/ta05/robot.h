/***************************************************************
 * File: robot.h
 * Author: Aaron Jones
 * Purpose: Contains the definition of the Robot class
 ***************************************************************/

#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

/****************************************************************
 * Class: Robot
 * Purpose: A Robot that has position and energy and can move
 *          around the world.
 ****************************************************************/
class Robot
{
   private:
      Point position;
      int energy;

   public:
      /********************
       * Display Functions
       ********************/
      void display() const;

      /********************
       * Constructors
       ********************/
      Robot();
      Robot(int energy);
      Robot(Point position, int energy);

      /********************
       * Getters
       ********************/
      Point getPosition() const { return position; }
      int getEnergy() const { return energy; }

      /********************
       * Setters
       ********************/
      void setPosition(Point position);
      void setEnergy(int energy);
};

#endif
