/*********************************************************************************************************************
**	Program: Medusa.cpp
**	Author: Sangyun Lee
**	Date: Nov 17 2019
**	Description: This is specification file of Medusa class.
**
**********************************************************************************************************************/

#include "Medusa.hpp"

/*********************************************************************************************************************
** Program: Medusa::Medusa()
** Description: This is constructor for Bluemen. User setter of base class to set up the vampire constructor
**********************************************************************************************************************/
Medusa::Medusa(std::string name)
{
	setName(name);
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
** Program: Medusa::defenseSK()
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

/*********************************************************************************************************************
** Program: Medusa::healing()
** Description: This is healing skill, figher will get strength recovery after they win
**********************************************************************************************************************/
void Medusa::healing()
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
	if (cHp > 8)																	//if strength after heal is bigger than max strength
		cHp = 8;																	//set it as maximum strength
	setStrength(cHp);
}