/***********************************************************************
 * Header File:
 *    Tough Bird :
 * Author:
 *    Aaron Jones
 * Summary:
 *		
 ************************************************************************/


#ifndef TOUGH_BIRD_H
#define TOUGH_BIRD_H

#include <iostream>
#include "bird.h"

using namespace std;

 /*********************************************
  * TOUGH BIRD
  * 
  *********************************************/
class ToughBird : public Bird
{
public:

	/********************
	 * Constructors
	********************/
	//ToughBird();

	/********************
	 * Member Variables
	********************/
	void draw();
	int hit();

//protected:
	//int hits;
};

#endif // TOUGH_BIRD_H
