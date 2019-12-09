/**************************************************************************************************************
** Program name: die.hpp
** Author: Sangyun Lee
** Date: Oct 15 2019
** Description: This is header file of regDie class.
***************************************************************************************************************/


#ifndef DIE_HPP
#define DIE_HPP

#include "game.hpp"
#include <memory>

class Die
{
private:
	int sideN;					//side of dice

public:
	Die();
	Die(int);
	void setSide(int);
	int getSide();
	int randNum();
//	int randNum(int, int, int);
};
#endif DIE_HPP
