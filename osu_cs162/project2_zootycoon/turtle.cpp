/*********************************************************************************************************
** Program: turtle.cpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/

#include "turtle.hpp"

/*********************************************************************************************************
** Program: turtle::turtle()
** Description: tiger class constructor
**********************************************************************************************************/
turtle::turtle()
{
	species = 'r';
	setAge(1);
	setCost(100);								//cost to buy a tiger
	setFcost(5);								//cost to feed them
	setPayOff(getCost() * 0.05);	//(getCost() + getFcost()) is total cost
	setNumBb(10);								//number of baby they pregnant 
}

/*********************************************************************************************************
** Program: turtle::getSpecies()
** Description: getter function returns animal type
**********************************************************************************************************/
char turtle::getSpecies()
{
	return species;
}
