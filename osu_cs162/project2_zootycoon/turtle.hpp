/*********************************************************************************************************
** Program: tiger.hpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/


#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "animal.hpp"

class turtle : public animal
{
private:
	char species;
public:
	turtle();
	char getSpecies();
};

#endif TURTLE_HPP

