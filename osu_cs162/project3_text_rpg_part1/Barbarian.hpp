/***********************************************************************************************************************************
**	Program: Barbarian.hpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is headerfile of barbarian class. This is derived class of fantasyCG
**
***********************************************************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "fantasyCG.hpp"

class Barbarian : public fantasyCG					//declare parent class
{
private:
public:
	Barbarian();
	~Barbarian();
	int attack();
	int defenseSK();
	void sskill();
};
#endif //!BARBARIAN_HPP
