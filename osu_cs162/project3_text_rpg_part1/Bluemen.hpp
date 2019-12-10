/***********************************************************************************************************************************
**	Program: Bluemen.hpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is headerfile of bluemen class. This is derived class of fantasyCG
**
***********************************************************************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "fantasyCG.hpp"

class Bluemen : public fantasyCG					//declare parent class
{
private:
	int spAbility;
public:
	Bluemen();
	~Bluemen();
	int mob1;
	int mob2;
	int attack();
	int defenseSK();
	void sskill();

};
#endif //!BLUEMEN_HPP