/***********************************************************************
 * File:
 *    bullet.cpp
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/

#define _USE_MATH_DEFINES
#define BULLET_SPEED 10.0

#include "bullet.h"
#include <cmath>

void Bullet::draw() 
{
	drawDot(center);
}

void Bullet::kill()
{
	alive = false;
}

void Bullet::fire(Point center, float angle)
{
	float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
	float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
}
