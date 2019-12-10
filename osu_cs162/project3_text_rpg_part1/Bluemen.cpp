/*********************************************************************************************************************
**	Program: Bluemen.cpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is specification file of Bluemen class.
**
**********************************************************************************************************************/

#include "Bluemen.hpp"

/*********************************************************************************************************************
** Program: Bluemen::Bluemen()
** Description: This is constructor for Bluemen. User setter of base class to set up the vampire constructor
**********************************************************************************************************************/
Bluemen::Bluemen()
{													
	srand(time(0));
	setType("Blue Men");
	setArmor(3);
	setStrength(12);
	spAbility = 2;									//indicate how many special skills left
	mob1 = 1;										//mob prompt counter strength 5~8
	mob2 = 1;										//mob prompt counter strength 1~4
}

/*********************************************************************************************************************
** Program: Bluemen::~Bluemen()
** Description: This is destructor.
**********************************************************************************************************************/
Bluemen::~Bluemen()
{

}

/*********************************************************************************************************************
** Program: Bluemen::attack()
** Description: This is to attack other character, it returns int as attack point.
**********************************************************************************************************************/
int Bluemen::attack()
{													//blue men has two 10sides dices for attack
	int aDice = rand() % 10 + 1;
	int aDice2 = rand() % 10 + 1;
	std::cout << "** Attacker's Dice: " << aDice << " " << aDice2 << std::endl;
	return aDice + aDice2;
}

/*********************************************************************************************************************
** Program: Bluemen::deffence()
** Description: This is to defence other character's attack, it returns int as defence point.
**********************************************************************************************************************/
int Bluemen::defenseSK()								//blue men has three 6 sides dices for defence
{													//howeverm they loose dice when they lost their strength
	int curStrength = this->getStrength();
	//special ability (mob)	
	if (curStrength > 8)							//if strength is greater than 8, full defence dice
	{
		//std::cout << "[3d6]" << std::endl;		function checker
		int dDice = rand() % 6 + 1;
		int dDice2 = rand() % 6 + 1;
		int dDice3 = rand() % 6 + 1;
		std::cout << "** Defender's Dice: " << dDice << " " << dDice2 << " " << dDice3 << " + " << this->getArmor() << "(Armor)" <<std::endl;

		return dDice + dDice2 + dDice3;
	}

	else if (curStrength <= 8 && curStrength > 4)	//if strength is less than 8 and greater than 4, lose one defence dice
	{
		if (mob1 == 1)
		{
			std::cout << "** [Special condition -mob- activated]" << std::endl;		//prompt
			std::cout << "** [Blue Men lost defesce dice       ]" << std::endl;
			mob1 = 0;																//counter --, so promot can be made one time only
			int dDice = rand() % 6 + 1;
			int dDice2 = rand() % 6 + 1;

			std::cout << "** Defender's Dice: " << dDice << " " << dDice2 << " + " << this->getArmor() << "(Armor)" << std::endl;
			return dDice + dDice2;													//return total defense dice point
		}
		else 
		{
			int dDice = rand() % 6 + 1;
			int dDice2 = rand() % 6 + 1;

			std::cout << "** Defender's Dice: " << dDice << " " << dDice2 << " + " << this->getArmor() << "(Armor)" << std::endl;
			return dDice + dDice2;
		}	
	}
	else if (curStrength <= 4 && curStrength > 0)	//if strength is less than 4, lose one more defence dice
	{
		if (mob2 == 1)
		{
			std::cout << "** [Special condition -mob- activated]" << std::endl;
			std::cout << "** [Blue Men lost defense dice       ]" << std::endl;
			mob2 = 0;
			int dDice = rand() % 6 + 1;

			std::cout << "** Defender's Dice: " << dDice << " + " << this->getArmor() << "(Armor)" << std::endl;
			return dDice;
		}

		else
		{
			int dDice = rand() % 6 + 1;

			std::cout << "** Defender's Dice: " << dDice << " + " << this->getArmor() << "(Armor)" << std::endl;
			return dDice;
		}
	}
}

/*********************************************************************************************************************
** Program: Barbarian::sskill()
** Description: This is special skill of barbarian. Since blue men's special skill will be activated on attack function
**				It is just for displaying comments for special skill
**********************************************************************************************************************/
void Bluemen::sskill()
{
//	do nothing
}

