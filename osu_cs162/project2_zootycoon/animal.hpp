/*********************************************************************************************************
** Program: animal.hpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/


#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iomanip>

class animal
{
private:														//set variables
	int age;
	int cost;
	int numberofbabies;
	int foodCost;
	int payOff;

public:
	animal();													//set and get function as described at instructions
	void setAge(int);
	void setCost(int);
	void setNumBb(int);
	void setFcost(int);
	void setPayOff(int);
	int getAge();
	int getCost();
	int getNumBb();
	int getFcost();
	int getPayoff();
	

};


#endif ANIMAL_HPP