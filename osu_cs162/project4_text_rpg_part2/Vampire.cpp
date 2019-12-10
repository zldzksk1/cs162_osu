/*********************************************************************************************************************
**	Program: Vampire.cpp
**	Author: Sangyun Lee
**	Date: Nov 17 2019
**	Description: This is specification file of fantasyCG class. This abstract (base) class of others.
**
**********************************************************************************************************************/

#include "Vampire.hpp"

/*********************************************************************************************************************
** Program: Vampire::Vampire()
** Description: This is constructor for Vampire. User setter of base class to set up the vampire constructor
**********************************************************************************************************************/
Vampire::Vampire(std::string name)
{
	setName(name);
	srand(time(0));
	setType("Vampire");
	setArmor(1);
	setStrength(18);
}

/*********************************************************************************************************************
** Program: Vampire::~Vampire()
** Description: This is destructor.
**********************************************************************************************************************/
Vampire::~Vampire()
{

}

/*********************************************************************************************************************
** Program: Vampire::attack()
** Description: This is to attack other character, it returns int as attack point.
**********************************************************************************************************************/
int Vampire::attack()
{
	int aDice = rand() % 12 + 1;											//vampire has one 12 sides dice
	std::cout << "** Attacker's Dice: " << aDice << std::endl;
	return aDice;
}

/*********************************************************************************************************************
** Program: Vampire::defenseSK()
** Description: This is to defence other character's attack, it returns int as defence point.
**********************************************************************************************************************/
int Vampire::defenseSK()
{
	int specialS = rand() % 2 + 1;											//50% chance to avoid others' attack
	if (specialS == 1)
	{
		int	dDice = rand() % 6 + 1;											//vampire has one 6 sides dice
		std::cout << "** [Special ability -Charm- activated]" << std::endl;	//prompt the skill
		std::cout << "** [Vampire's defense enhanced]" << std::endl;
		std::cout << "** Defender's Dice: " << dDice << " + " << this->getArmor() << "(Armor) + (Charm)" << std::endl;
		return 99;
	}

	else
	{
		int	dDice = rand() % 6 + 1;											//vampire has one 6 sides dice
		std::cout << "** Defender's Dice: " << dDice << " + " << this->getArmor() << "(Armor)" << std::endl;
		return dDice;
	}

}

/*********************************************************************************************************************
** Program: Vampire::sskill()
** Description: This is special skill of vampire, if skill is activated, it returns true.
**********************************************************************************************************************/
void Vampire::sskill()
{
	//do nothing
}

/*********************************************************************************************************************
** Program: Vampire::healing()
** Description: This is healing skill, figher will get strength recovery after they win
**********************************************************************************************************************/
void Vampire::healing()
{
	srand(time(NULL));
	int hpPack = rand() % 3;
	int cHp = getStrength();
	switch (hpPack)
	{
	case 0:																			//no heal
		std::cout << "** [Obtained wrong portion  ]" << std::endl;
		std::cout << "** [Strength + 0            ]" << std::endl;
		break;
	case 1:																			//strength +1
		std::cout << "** [Obtained small portion  ]" << std::endl;
		std::cout << "** [Strength + 1            ]" << std::endl;
		cHp += 1;
		break;
	case 2:																			//strength +2
		std::cout << "** [Obtained medium portion ]" << std::endl;
		std::cout << "** [Strength + 2            ]" << std::endl;
		cHp += 2;
		break;
	case 3:																			//strength +3
		std::cout << "** [Obtained large portion  ]" << std::endl;
		std::cout << "** [Strength + 3            ]" << std::endl;
		cHp += 3;
		break;
	}
	if (cHp > 18)																	//if strength after heal is bigger than max strength
		cHp = 18;																	//set it as maximum strength
	setStrength(cHp);
}
