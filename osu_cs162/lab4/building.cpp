/*********************************************************************************************************************
** Program: building.cpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of university class. And it is bass class of other classes.
**********************************************************************************************************************/
#include "building.hpp"

/*********************************************************************************************************************
** Program: building::building()
** Description: This is constructor of building class. 
**********************************************************************************************************************/
building::building(std::string const bn, std::string const add, int s)
{
	bName = bn;
	address = add;
	size = s;
}

/*********************************************************************************************************************
** Program: building::~building()
** Description: This is destructor of building class.
**********************************************************************************************************************/
building::~building()
{
	//destructor
}

/*********************************************************************************************************************
** Program: building::setBname()
** Description: This is setter to initialize the building name. it accepts string
**********************************************************************************************************************/
void building::setBname(std::string x)
{
	bName = x;
}

/*********************************************************************************************************************
** Program: building::setAddress()
** Description: This is setter to initialize the building address. it accepts string
**********************************************************************************************************************/
void building::setAddress(std::string y)
{
	address = y;
}

/*********************************************************************************************************************
** Program: building::setAddress()
** Description: This is setter to initialize the size of the building. it accepts int
**********************************************************************************************************************/
void building::setSize(int z)
{
	size = z;
}

/*********************************************************************************************************************
** Program: building::getBname()
** Description: This is getter function to get the building name. 
**********************************************************************************************************************/
std::string building::getBname()
{
	return bName;
}

/*********************************************************************************************************************
** Program: building::getAddress()
** Description: This is getter function to get the building address.
**********************************************************************************************************************/
std::string building::getAddress()
{
	return address;
}

/*********************************************************************************************************************
** Program: building::getSize()
** Description: This is getter function to get the building size.
**********************************************************************************************************************/
int building::getSize()
{
	return size;
}

/*********************************************************************************************************************
** Program: building::getSize()
** Description: This is void function to prompt the building information.
**********************************************************************************************************************/
void building::printBinfo()
{
	std::cout << bName << std::endl;
	std::cout << address << std::endl;
	std::cout << size << "(sqft)" << std::endl;
}