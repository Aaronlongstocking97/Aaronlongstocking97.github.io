/***********************************************************************
 * File:
 *    velocity.cpp
 * Author:
 *    Aaron Jones
 * Summary:
 *		Controls the speed that the lander can move by.
 ************************************************************************/

#include "velocity.h"

 /******************************************
  * VELOCITY : DEFAULT CONSTRUCTOR
  * Assigned initial state values.
  *****************************************/
Velocity::Velocity()
{
	setDx(0.0);
	setDy(0.0);
}

/******************************************
 * VELOCITY : NON-DEFAULT CONSTRUCTOR
 *	Sets new values to the functions 
 * provided.
 *****************************************/
Velocity::Velocity(const float dx, const float dy)
{
	setDx(dx);
	setDy(dy);
}
