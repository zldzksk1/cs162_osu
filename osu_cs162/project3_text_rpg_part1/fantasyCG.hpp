/***********************************************************************************************************************************
**	Program: fantasyCG.hpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is headerfile of fantasyCG class. This abstract (base) class of others.
**
***********************************************************************************************************************************/

#ifndef FANTASYCG_HPP
#define FANTASYCG_HPP

#include <iostream>
#include <string>
#include <time.h>

class fantasyCG						//parent class
{
private:
	std::string type;				//declare necessary variabls
	int armor;
	int strength;

public:
	fantasyCG();					//constructor
	~fantasyCG();					//desctructor
	void setArmor(int);				//setter functions
	void setStrength(int);
	void setType(std::string);
	int getArmor();					//getter functions
	int getStrength();
	std::string getType();
	virtual int attack() = 0;		//virtual function for playing game
	virtual int defenseSK() = 0;
	virtual void sskill() = 0;
};
#endif // !FANTASYCG_HPP
