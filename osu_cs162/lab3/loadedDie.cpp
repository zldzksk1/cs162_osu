/**************************************************************************************************************
** Program name: loadedDie.cpp
** Author: Sangyun Lee
** Date: Oct 15 2019
** Description: This is implementation file of loadedDie class. Since it inherited elements and functions from its
**				parents class, so it doesn't have any elements or function which are created in this class
***************************************************************************************************************/

#include "loadedDie.hpp"


/**************************************************************************************************************
** Program name: loadedDie::randNum()
** Description: overload function to Die::randNum(), it generated random number for the game play.
**				This func should generated biased random number, its base number is always higher than reg dice
**				So, it will have higher change to win
***************************************************************************************************************/
int loadedDie::randNum()
{
	int x = getSide();
	int r;
	if (x <= 4)				// if the side of dice is equal or less than 4
	{
		r = rand() % x + 2;	// loadedDie sdie will have 2 at least
		if (r > x)
			r = x;
	}

	else if(x > 5 && x <=6)				// if it is more than 4,
	{
		r = rand() % x + 3;	// loadedDie sdie will have 3 at least
		if (r > x)
			r = x;
	}

	else if(x > 6 && x <= 8)
	{
		r = rand() % x + 4;	// loadedDie sdie will have 3 at least
		if (r > x)
			r = x;
	}

	else if (x > 8)
	{
		r = rand() % x + 5;	// loadedDie sdie will have 3 at least
		if (r > x)
			r = x;
	}
	return r;
}
