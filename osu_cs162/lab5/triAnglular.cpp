/*****************************************************************************************************************************
** Program: triAnglular.cpp
** Author: Sangyun Lee
** Date: Oct 28 2019
** Description: This is implementation file of triAnglular. It takes int paramemeter.
**				it call itself to find triangular number. When it call its function, decrement the argument by 1.
******************************************************************************************************************************/

#include "triAnglular.hpp"
int triAngCal(int x)
{
	if (x < 0)									//base case
		return 0;
	else										
		return x + triAngCal(x - 1);			//call reculsive function
}
