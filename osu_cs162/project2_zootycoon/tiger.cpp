/*********************************************************************************************************
** Program: tiger.cpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/

#include "tiger.hpp"

/*********************************************************************************************************
** Program: tiger::tiger()
** Description: tiger class constructor
**********************************************************************************************************/
tiger::tiger() 
{
	species = 't';
	setAge(1);
	setCost(10000);								//cost to buy a tiger
	setFcost(50);								//cost to feed them
	setPayOff(getCost() * 0.2);					//getCost() * 0.2 is total cost
	setNumBb(1);								//number of baby they pregnant 
}

/*********************************************************************************************************
** Program: tiger::getSpecies()
** Description: getter function returns animal type
**********************************************************************************************************/
char tiger::getSpecies()
{
	return species;
}
