/*********************************************************************************************************
** Program: tiger.hpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/


#ifndef TIGER_HPP
#define TIGER_HPP

#include "animal.hpp"

class tiger : public animal
{
private:
	char species;										//variables to recoginize animal type just in case
public:
	tiger();
	char getSpecies();
};

#endif TIGER_HPP
