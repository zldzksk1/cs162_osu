/*********************************************************************************************************************
**	Program: Medusa.cpp
**	Author: Sangyun Lee
**	Date: Nov 07 2019
**	Description: This is specification file of Medusa class.
**
**********************************************************************************************************************/

#include "Medusa.hpp"

/*********************************************************************************************************************
** Program: Medusa::Medusa()
** Description: This is constructor for Bluemen. User setter of base class to set up the vampire constructor
**********************************************************************************************************************/
Medusa::Medusa()
{
	srand(time(0));
	setType("Medusa");
	setArmor(3);
	setStrength(8);
	spAbility = 0;
}

/*********************************************************************************************************************
** Program: Medusa::~Medusa()
** Description: This is destructor.
**********************************************************************************************************************/
Medusa::~Medusa()
{

}

/*********************************************************************************************************************
** Program: Medusa::attack()
** Description: This is to attack other character, it returns int as attack point.
**********************************************************************************************************************/
int Medusa::attack()
{												//Medusa has two 6 sides dices for attack
	int aDice = rand() % 6 + 1;
	int aDice2 = rand() % 6 + 1;
	spAbility = aDice + aDice2;					//if medusa roll 12, special skill will be activated, for that skill stat needs to be updated

	if (spAbility == 12)
	{
		std::cout << "** Attacker's Dice: " << aDice << " " << aDice2 << std::endl;
		std::cout << "** [Special ability -Glare- activated]" << std::endl;
		std::cout << "** [Opponent got critical damage!    ]" << std::endl;
		spAbility = 0;				
		return 100;								//reset special ability point
	}
	
	else 
	{
		std::cout << "** Attacker's Dice: " << aDice << " " << aDice2 << std::endl;
		return spAbility;
	}
}

/*********************************************************************************************************************
** Program: Medusa::deffence()
** Description: This is to defence other character's attack, it returns int as defence point.
**********************************************************************************************************************/
int Medusa::defenseSK()
{												//Medusa has one 6 sides defence dice
	int dDice = rand() % 6 + 1;
	std::cout << "** Defender's Dice: " << dDice << " + " << this->getArmor() << "(Armor)" << std::endl;

	return dDice;
}


/*********************************************************************************************************************
** Program: Medusa::sskill()
** Description: This is special skill of Medusa, if skill is activated, it returns true.
**********************************************************************************************************************/
void Medusa::sskill()
{
	//do nothing
}

