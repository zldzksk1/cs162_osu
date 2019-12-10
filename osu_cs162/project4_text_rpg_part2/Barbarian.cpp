/*********************************************************************************************************************
**	Program: Barbarian.cpp
**	Author: Sangyun Lee
**	Date: Nov 17 2019
**	Description: This is specification file of fantasyCG class. This abstract (base) class of others.
**
**********************************************************************************************************************/

#include "Barbarian.hpp"

/*********************************************************************************************************************
** Program: Barbarian::Barbarian()
** Description: This is constructor for Vampire. User setter of base class to set up the vampire constructor
**********************************************************************************************************************/
Barbarian::Barbarian(std::string name)
{
	setName(name);
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
** Program: Barbarian::defenseSK()
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


/*********************************************************************************************************************
** Program: Barbarian::healing()
** Description: This is healing skill, figher will get strength recovery after they win
**********************************************************************************************************************/
void Barbarian::healing()
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
	if (cHp > 12)																	//if strength after heal is bigger than max strength
		cHp = 12;																	//set it as maximum strength
	setStrength(cHp);
}