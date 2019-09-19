/***********************************************************************
 * Header File:
 *    Flying Objects :
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/

#ifndef FLYING_OBJECTS_H
#define FLYING_OBJECTS_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

 /*********************************************
  * FLYING OBJECTS
  * . .
  *********************************************/
class FlyingObjects
{
protected:
	/********************
	* Member Variables
	********************/
	Point center;
	Velocity velocity;
	float radius;
	bool alive;

public:
	
	/********************
	 * Default onstructors
	 ********************/
	FlyingObjects();
	FlyingObjects(Point center, Velocity velocity);

	/********************
	 * Getters
	 ********************/
	bool isAlive() const { return alive; }
	Point getPoint() const { return center; }
	Velocity getVelocity() const { return velocity; }

	/********************
	 * Setters
	 ********************/
	void setPoint(Point center);
	void setVelocity(Velocity velocity);
	void setAlive(const bool alive) { this->alive = alive; }

	/********************
	 * Member Variables
	 ********************/
	//void kill();
	void advance();
	virtual void draw() = 0;
	
};

#endif // FLYING_OBJECTS_H
