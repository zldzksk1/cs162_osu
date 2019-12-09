/**************************************************************************************************************
** Program name: die.cpp
** Author: Sangyun Lee
** Date: Oct 15 2019
** Description: This is implementation file of class die. It is base class. So element and functions will be
**				shared with another class
***************************************************************************************************************/

#include <iostream>
#include "die.hpp"

/**************************************************************************************************************
** Program name: Die::Die()
** Description: Defualt constructor
***************************************************************************************************************/

Die::Die()
{
	setSide(0);
}

/**************************************************************************************************************
** Program name: Die::Die()
** Description: constructor that accept int data, and useing setSide function to set the constructor
***************************************************************************************************************/
Die::Die(int x)
{
	setSide(x);
}

/**************************************************************************************************************
** Program name: Die::setSide()
** Description: it sets the sideN variable by receiving a int parameter
***************************************************************************************************************/
void Die::setSide(int x)
{
	sideN = x;
}

/**************************************************************************************************************
** Program name: Die::getSide()
** Description: return sideN value
***************************************************************************************************************/
int Die::getSide()
{
	return sideN;
}

/**************************************************************************************************************
** Program name: Die::randNum()
** Description: It generated random number between 1 and side of dice. And return the random number
***************************************************************************************************************/
int::Die::randNum()
{
	int x = getSide();
	int r = rand() % x + 1;

	return r;
}


