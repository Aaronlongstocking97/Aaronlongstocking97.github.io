/***********************************************************************
 * File:
 *    lander.h 
 * Author:
 *    Aaron Jones
 * Summary:
 *    Controls the functions of the ship so it can move
 *		and the position where the lander is. 
 ************************************************************************/


#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

 /*********************************************
  * LANDER
  * Sets the boundaries for the ship to land.
  *********************************************/
class Lander
{
public:
	
	/********************
	 * Constructors
	********************/
	Lander();
	Point getPoint();
	Velocity getVelocity();

	/********************
	 * Getters
	********************/
	int getFuel()       const { return fuel; }
	bool isAlive()	    const { return alive; }
	bool isLanded()     const { return landed;  }


	/********************
	 * Setters
	********************/
	void setLanded(const bool landed) { this->landed = landed; }
	void setAlive(const bool alive) { this->alive = alive;  }
	void setFuel(int fuel) { this->fuel = fuel; }

	/********************
	 * Member Variables
	********************/
	bool canThrust();
	void applyGravity(float);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();
	void draw() const;


private:
	Point center;
	Velocity velocity;
	bool alive;
	bool landed;
	int fuel;
};

#endif // LANDER_H
