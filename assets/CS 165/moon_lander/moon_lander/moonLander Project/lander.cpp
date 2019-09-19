/***********************************************************************
 * File:
 *    lander.cpp 
 * Author:
 *    Aaron Jones
 * Summary:
 *    controls how the lander will move and where the lander will
 *		be poisitioned. Creates the lander and gives it the ability 
 *		to move as well as apply gravity to it.
 ************************************************************************/

#include "lander.h"

 /******************************************
  * LANDER : DEFAULT CONSTRUCTOR
  * Assigned initial state values.
  *****************************************/
Lander::Lander()
{
	velocity.setDx(0.0);
	velocity.setDy(0.0);
	center.setX(0);
	center.setY(0);
	setAlive(true);
	setLanded(false);
	setFuel(0);
}

/******************************************
 * POINT LANDER : NON-DEFAULT CONSTRUCTOR
 * Default constructor pulled in 
 *	from the Point class.
 *****************************************/
Point Lander::getPoint() {
	return center;
}

/******************************************
 * VELOCITY LANDER : NON-DEFAULT CONSTRUCTOR
 * Default constructor pulled in
 *	from the Velocity class.
 *****************************************/
Velocity Lander::getVelocity() {
	return velocity;
}
/*******************************************
 * LANDER : canThrust
 * If fuel is greater than zero the then
 *	return true.
 *******************************************/
bool Lander::canThrust()
{
	return fuel > 0;
}

/*******************************************
 * LANDER : applyGravity
 * Applies the effects of gravity to the 
 *	ship.
 *******************************************/
void Lander::applyGravity(float gravity)
{
	velocity.setDy(velocity.getDy() - gravity);
}

/*******************************************
 * LANDER : applyThrustLeft
 *	Shifts the lander to the left.
 *******************************************/
void Lander::applyThrustLeft()
{
	if (!canThrust()) return;
	velocity.setDx(1);
	fuel--;
}

/*******************************************
 * LANDER : applyThrustRight
 * Shifts the lander to the right.
 *******************************************/
void Lander::applyThrustRight()
{
	if (!canThrust()) return;
	velocity.setDx(-1);
	fuel--;
}

/*******************************************
 * LANDER : applyThrustBottom
 * Shifts the lander to the bottom.
 *******************************************/
void Lander::applyThrustBottom()
{
	if (!canThrust()) return;
	velocity.setDy(1);
	fuel--;
}

/*******************************************
 * LANDER : advance
 * Gives the lander the ability to move.
 *******************************************/
void Lander::advance()
{
	center.addX(velocity.getDx());
	center.addY(velocity.getDy());
}

/*******************************************
 * LANDER : draw
 * Creates the lander object on the screen.
 *******************************************/
void Lander::draw() const
{
	drawLander(center);
}

