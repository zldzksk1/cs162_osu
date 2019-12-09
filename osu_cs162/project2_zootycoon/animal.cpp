/*********************************************************************************************************
** Program: animal.hpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/

#include "animal.hpp"

/*********************************************************************************************************
** Program: animal::animal()
** Description: This is constructor of animal class, it initialize necessary variables.
**********************************************************************************************************/

animal::animal()
{
	setAge(1);
	setCost(0);
	setNumBb(0);
	setFcost(0);
	setPayOff(0);
}

/*********************************************************************************************************
** Program: animal::setAge()
** Description: setter function to set Age, it accept an interger
**********************************************************************************************************/
void animal::setAge(int x)
{
	age = x;
}

/*********************************************************************************************************
** Program: animal::setCost()
** Description: setter function to set Cost, it accept an interger
**********************************************************************************************************/
void animal::setCost(int x)
{
	cost = x;
}

/*********************************************************************************************************
** Program: animal::setNumBb()
** Description: setter function to set number of baby that animal can have, it accept an interger
**********************************************************************************************************/
void animal::setNumBb(int x)
{
	numberofbabies = x;
}


/*********************************************************************************************************
** Program: animal::setFcost()
** Description: setter function to set food cost, it accept an interger
**********************************************************************************************************/
void animal::setFcost(int x)
{
	foodCost = x;
}

/*********************************************************************************************************
** Program: animal::setPayOff()
** Description: setter function to set pay off which is moeny earned by each animal, it accept an interger
**********************************************************************************************************/
void animal::setPayOff(int x)
{
	payOff = x;
}

/*********************************************************************************************************
** Program: animal::getAge()
** Description: getter function returns age value
**********************************************************************************************************/
int animal::getAge()
{
	return age;
}

/*********************************************************************************************************
** Program: animal::getCost()
** Description: getter function returns cost of buying animal
**********************************************************************************************************/
int animal::getCost()
{
	return cost;
}

/*********************************************************************************************************
** Program: animal::getNumbBb()
** Description: getter function returns number of babies that animals can have
**********************************************************************************************************/
int animal::getNumBb()
{
	return numberofbabies;
}

/*********************************************************************************************************
** Program: animal::getFcost()
** Description: getter function returns food cost to calulate how much they spend
**********************************************************************************************************/
int animal::getFcost()
{
	return foodCost;
}

/*********************************************************************************************************
** Program: animal::getPayoff()
** Description: getter function returns how much profit maded
**********************************************************************************************************/
int animal::getPayoff()
{
	return payOff;
}
