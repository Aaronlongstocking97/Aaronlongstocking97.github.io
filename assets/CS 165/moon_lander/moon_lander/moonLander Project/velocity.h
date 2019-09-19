/***********************************************************************
 * Header File:
 *    Velocity :
 * Author:
 *    Aaron Jones
 * Summary:
 *		Provides the necessary components for the lander to move.
 ************************************************************************/


#ifndef VELOCITY_H
#define VELOCITY_H

 /*********************************************
  * VELOCITY
  * Applies the movement to the object.
  *********************************************/
class Velocity
{
public:
	
	/********************
	 * Constructors
	********************/
	Velocity();
	Velocity(const float dx, const float dy);

	/********************
	 * Getters
	********************/
	float getDx() const { return dx; }
	float getDy() const { return dy; }

	/********************
	 * Setters
	********************/
	void setDx(const float dx) { this->dx = dx; }
	void setDy(const float dy) { this->dy = dy; }

private:
	float dx;
	float dy;
};

#endif // VELOCITY_H
