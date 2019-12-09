/**************************************************************************************************************
** Program name: loadedDie.hpp
** Author: Sangyun Lee
** Date: Oct 15 2019
** Description: This is header file of loadedDie class. Since it inherited elements and functions from its
**				parents class, so it doesn't have any elements or function which are created in this class
***************************************************************************************************************/


#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "die.hpp"
#include <memory>

class loadedDie : public Die
{
private:

public:
	int randNum();
};
#endif LOADEDDIE_HPP

