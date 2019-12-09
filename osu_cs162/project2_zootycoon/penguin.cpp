/*********************************************************************************************************
** Program: penguin.cpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/

#include "penguin.hpp"

/*********************************************************************************************************
** Program: penguin::penguin()
** Description: tiger class constructor
**********************************************************************************************************/
penguin::penguin()
{
	species = 'p';										
	setAge(1);				
	setCost(1000);									//cost to buy a penguin
	setFcost(10);									//cost to feed them
	setPayOff(getCost() * 0.1);						//getCost() is cost
	setNumBb(5);									//number of baby they pregnant 
}

/*********************************************************************************************************
** Program: penguin::getSpecies()
** Description: getter function returns animal type
**********************************************************************************************************/
char penguin::getSpecies()
{
	return species;
}
