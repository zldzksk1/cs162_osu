/***********************************************************************************************************************************
**	Program: Vampire.hpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is headerfile of vampire class. This is derived class of fantasyCG
**
***********************************************************************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "fantasyCG.hpp"

class Vampire : public fantasyCG				//declare parent class
{
private:
public:
	Vampire(std::string);									//necessaru functions
	~Vampire();
	int attack();
	int defenseSK();
	void sskill();
	void healing();

};

#endif //!VAMPIRE_HPP