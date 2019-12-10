/*********************************************************************************************************************
**	Program: Barbarian.cpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is specification file of fantasyCG class. This abstract (base) class of others.
**
**********************************************************************************************************************/

#include "Barbarian.hpp"

/*********************************************************************************************************************
** Program: Barbarian::Barbarian()
** Description: This is constructor for Vampire. User setter of base class to set up the vampire constructor
**********************************************************************************************************************/
Barbarian::Barbarian()
{
	srand(time(0));
	setType("Barbarian");
	setArmor(0);
	setStrength(12);
}

/*********************************************************************************************************************
** Program: Barbarian::~Barbarian()
** Description: This is destructor.
**********************************************************************************************************************/
Barbarian::~Barbarian()
{

}

/*********************************************************************************************************************
** Program: Barbarian::attack()
** Description: This is to attack other character, it returns int as attack point.
**********************************************************************************************************************/
int Barbarian::attack()					
{										//barbarian has two 6 sides dices for attack
	int aDice = rand() % 6 + 1;
	int aDice2 = rand() % 6 + 1;
	std::cout << "** Attacker's Dice: " << aDice <<" "<< aDice2 <<std::endl;
	return aDice + aDice2;
}

/*********************************************************************************************************************
** Program: Barbarian::deffence()
** Description: This is to defence other character's attack, it returns int as defence point.
**********************************************************************************************************************/
int Barbarian::defenseSK()
{										//barbarian has two 6 sides dices for defence
	int dDice = rand() % 6 + 1;
	int dDice2 = rand() % 6 + 1;
	std::cout << "** Defender's Dice: " << dDice << " " << dDice2 << std::endl;

	return dDice + dDice2;
}

/*********************************************************************************************************************
** Program: Barbarian::sskill()
** Description: This is special skill of barbarian.
**********************************************************************************************************************/
void Barbarian::sskill()
{										//Barbarian has no speical skill
	// do nothing
}

