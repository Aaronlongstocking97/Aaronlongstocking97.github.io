/***********************************************************************
 * Header File:
 *    Standard Bird :
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/


#ifndef STANDARD_BIRD_H
#define STANDARD_BIRD_H

#include <iostream>
#include "bird.h"

using namespace std;

 /*********************************************
  * STANDARD BIRD
  * 
  *********************************************/
class StandardBird : public Bird
{
public:
	
	/********************
	 * Constructors
	********************/
	//StandardBird();

	/********************
	 * Member Variables
	********************/
	void draw();
	int hit();

};

#endif // STANDARD_BIRD_H
