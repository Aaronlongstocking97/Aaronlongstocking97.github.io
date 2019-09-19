/***********************************************************************
 * Header File:
 *    Sacred Bird :
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/


#ifndef SACRED_BIRD_H
#define SACRED_BIRD_H

#include <iostream>
#include "bird.h"

using namespace std;

 /*********************************************
  * SACRED BIRD
  * . . . 
  *********************************************/
class SacredBird : public Bird
{
public:

	/********************
	 * Constructors
	********************/
	//SacredBird();

	/********************
	 * Member Variables
	********************/
	void draw();
	int hit();
	
};

#endif // SACRED_BIRD_H
