/*********************************************************************************************************************
**	Program: Harry.cpp
**	Author: Sangyun Lee
**	Date: Nov 07 2019
**	Description: This is specification file of Medusa class.
**
**********************************************************************************************************************/

#include "Harry.hpp"

/*********************************************************************************************************************
** Program: Medusa::Medusa()
** Description: This is constructor for Bluemen. User setter of base class to set up the vampire constructor
**********************************************************************************************************************/
Harry::Harry()
{
	srand(time(0));
	setType("Harry Potter");
	setArmor(0);
	setStrength(10);
	spAbility = 1;
}

/*********************************************************************************************************************
** Program: Medusa::~Medusa()
** Description: This is destructor.
**********************************************************************************************************************/
Harry::~Harry()
{

}

/*********************************************************************************************************************
** Program: Harry::attack()
** Description: This is to attack other character, it returns int as attack point.
**********************************************************************************************************************/
int Harry::attack()	
{																//Harry has two 6 sides dices for attack
	int aDice = rand() % 6 + 1;	
	int aDice2 = rand() % 6 + 1;
	std::cout << "** Attacker's Dice: " << aDice << " " << aDice2 << std::endl;

	return aDice + aDice2;
}


/*********************************************************************************************************************
** Program: Harry::deffence()
** Description: This is to defence other character's attack, it returns int as defence point.
**********************************************************************************************************************/
int Harry::defenseSK()
{																//Harry has two 6 sides dices for attack
	int dDice = rand() % 6 + 1;
	int dDice2 = rand() % 6 + 1;
	std::cout << "** Defender's Dice: " << dDice << " " << dDice2 << std::endl;

	return dDice + dDice2;
}

/*********************************************************************************************************************
** Program: Harry::sskill()
** Description: This is special skill of Harry, if skill is activated, it returns true.
**********************************************************************************************************************/
void Harry::sskill()
{
	if (spAbility == 1)												//if spAbility == 1, and he dead. Then, skill activated
	{
		if (this->getStrength() == 0)								//if strength == 0, then activate the special skill
		{
			std::cout << "** [Special ability -Hogwarts- activated]" << std::endl;
			std::cout << "** [Harry Potter's strength became 20   ]" << std::endl;
			this->setStrength(20);									//reconver his strength to 20
			spAbility = 0;											//reset special ability point
		}
	}
}

