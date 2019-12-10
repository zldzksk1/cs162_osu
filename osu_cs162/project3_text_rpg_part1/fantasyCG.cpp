/*********************************************************************************************************************
**	Program: fantasyCG.cpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is specification file of fantasyCG class. This abstract (base) class of others.
**
**********************************************************************************************************************/

#include "fantasyCG.hpp"

/*********************************************************************************************************************
** Program: fantasyCG::fantasyCG()
** Description: This is constructor for fantasyCG class, no parameter, and set it as 0 since it is abstract class.
**********************************************************************************************************************/
fantasyCG::fantasyCG()
{
	armor = 0;
	strength = 0;
}

/*********************************************************************************************************************
** Program: fantasyCG::~fantasyCG()
** Description: This is destructor.
**********************************************************************************************************************/
fantasyCG::~fantasyCG()
{

}

/*********************************************************************************************************************
** Program: fantasyCG::setArmor()
** Description: This is setter function to set up armor variable. It accpets an int as parameter
**********************************************************************************************************************/
void fantasyCG::setArmor(int x)
{
	armor = x;
}

/*********************************************************************************************************************
** Program: fantasyCG::setHealth()
** Description: This is setter function to set up armor health. It accpets an int as parameter
**********************************************************************************************************************/
void fantasyCG::setStrength(int x)
{
	strength = x;
}

/*********************************************************************************************************************
** Program: fantasyCG::setType()
** Description: This is setter function to set up setType. It accpets a string as parameter. 
**********************************************************************************************************************/
void fantasyCG::setType(std::string chac)
{
	type = chac;
}

/*********************************************************************************************************************
** Program: fantasyCG::getArmor()
** Description: This is getter function, it returns the armor variable.
**********************************************************************************************************************/
int fantasyCG::getArmor()
{
	return armor;
}

/*********************************************************************************************************************
** Program: fantasyCG::getHealth()
** Description: This is getter function, it returns the health variable.
**********************************************************************************************************************/
int fantasyCG::getStrength()
{
	return strength;
}

/*********************************************************************************************************************
** Program: fantasyCG::getType()
** Description: This is getter function, it returns the character type.
**********************************************************************************************************************/
std::string fantasyCG::getType()
{
	return type;
}

/*********************************************************************************************************************
** Program: fantasyCG::sskill()
** Description: void virtual function for special skill.
**********************************************************************************************************************/
// some reason, my sub class couldn't override this function, so I make it as virtual.