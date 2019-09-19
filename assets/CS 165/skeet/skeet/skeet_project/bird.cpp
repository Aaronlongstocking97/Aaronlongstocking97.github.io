/***********************************************************************
 * File:
 *    bird.cpp
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/

#include "bird.h"

 /******************************************
  * BIRD : NON-DEFAULT CONSTRUCTOR
  * 
  *****************************************/
Bird::Bird(Point center)
{
	center.setX(0);
	center.setY(0);
}

void Bird::kill()
{
	alive = false;
}





