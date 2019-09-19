/***********************************************************************
 * Header File:
 *    Bird :
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/


#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include "flying_objects.h"


using namespace std;

 /*********************************************
  * BIRD
  * . . .
  *********************************************/
class Bird : public FlyingObjects
{
public:
	
	/********************
	 * Constructors
	********************/
	//Bird();
	Bird(Point center);

	/********************
	 * Member Variables
	********************/
	void kill();
	virtual void draw() = 0;
	virtual int hit() = 0;

};

#endif // BIRD_H
