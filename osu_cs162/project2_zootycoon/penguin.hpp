/*********************************************************************************************************
** Program: tiger.hpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/


#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "animal.hpp"

class penguin : public animal
{
private:
	char species;
public:
	penguin();
	char getSpecies();
};

#endif PENGUIN_HPP

