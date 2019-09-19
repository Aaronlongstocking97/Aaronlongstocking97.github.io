/***********************************************************************
 * Header File:
 *    Bullet :
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/


#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include "flying_objects.h"

using namespace std;

 /*********************************************
  * BULLET
  * . . .
  *********************************************/
class Bullet : public FlyingObjects
{
public:
	
	/********************
	 * Constructors
	********************/
	Bullet() {};

	/********************
	 * Member Variables
	********************/
	void draw();
	void kill();
	void fire(Point center, float angle);
};

#endif // BULLET_H
