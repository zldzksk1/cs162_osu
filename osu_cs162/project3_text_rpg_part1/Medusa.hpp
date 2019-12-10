/***********************************************************************************************************************************
**	Program: Medusa.hpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is headerfile of bluemen class. This is derived class of fantasyCG
**
***********************************************************************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "fantasyCG.hpp"

class Medusa : public fantasyCG						//declare parent class
{	
private:
	int spAbility;
public:
	Medusa();
	~Medusa();
	int attack();
	int defenseSK();
	void sskill();
};
#endif //!MEDUSA_HPP
