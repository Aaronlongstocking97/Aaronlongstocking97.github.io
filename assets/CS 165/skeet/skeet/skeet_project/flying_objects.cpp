/***********************************************************************
 * File:
 *    flying_objects.cpp
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/

#include "flying_objects.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

 /******************************************
  * FLYING OBJECTS : DEFAULT CONSTRUCTOR
  * 
  *****************************************/
FlyingObjects::FlyingObjects()
{
	radius = 0.0;
	setAlive(true);
}

FlyingObjects::FlyingObjects(Point point, Velocity velocity)
{
	setPoint(point);
	setVelocity(velocity);
}

void FlyingObjects::setPoint(Point center) 
{ 
	this->center.setX(center.getX());
	this->center.setY(center.getY());
}

void FlyingObjects::setVelocity(Velocity velocity)
{
	this->velocity.setDx(velocity.getDx());
	this->velocity.setDy(velocity.getDy());
}

/*void FlyingObjects::kill()
{

}*/

void FlyingObjects::advance()
{
	center.addX(velocity.getDx());
	center.addY(velocity.getDy());
}

void FlyingObjects::draw()
{
	return;
}
