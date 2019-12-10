/***********************************************************************************************************************************
**	Program: Harry.hpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is headerfile of bluemen class. This is derived class of fantasyCG
**
***********************************************************************************************************************************/

#ifndef HARRY_HPP
#define HARRY_HPP
#include "fantasyCG.hpp"

class Harry : public fantasyCG					//declare parent class
{
private:
	int spAbility;
public:
	Harry(std::string);
	~Harry();
	int attack();
	int defenseSK();
	void sskill();
	void healing();

};
#endif //!HARRY_HPP

