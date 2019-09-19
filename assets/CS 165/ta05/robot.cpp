/***************************************************************
 * File: robot.cpp
 * Author: Aaron Jones
 * Purpose: Contains the method implementations for the Robot
 *          class.
 ***************************************************************/

#include "robot.h"
#include <iostream>
using namespace std;

/**********************************************************************
 * Function(method): display
 * Purpose: Displays the robot.
 ***********************************************************************/
void Robot :: display() const
{
   position.display();
   cout << " - Energy: " << getEnergy();
}

/**********************************************************************
 * Default Constructor:
 * Purpose:
 ***********************************************************************/
Robot::Robot()
{
   energy = 100;
}

/**********************************************************************
 * Non-Default Constructor:
 * Purpose:
 ***********************************************************************/
Robot::Robot(int energy)
{
   setEnergy(energy);
}

/**********************************************************************
 * Non-Default Constructor:
 * Purpose:
 ***********************************************************************/
Robot::Robot(Point position, int energy)
{
   setPosition(position);
   setEnergy(energy);
}

/**********************************************************************
 * Function(method): setPosition
 * Purpose:
 ***********************************************************************/
void Robot::setPosition(const Point position)
{
   this->position = position;
}

/**********************************************************************
 * Function(method): setEnergy
 * Purpose:
 ***********************************************************************/
void Robot::setEnergy(const int energy)
{
   if (energy < 0)
   {
      this-> energy = 0;
   }
   else
   {
      this->energy = energy;
   }
}
