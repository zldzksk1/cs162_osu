
/***********************************************************************************************************************************
**	Program: game.hpp
**	Author: Sangyun Lee
**	Date: Nov 05 2019
**	Description: This is specification of Game class. Most of functions here is to run the text rpg game.
**	Reference: I referred the code about how to dellocate memry of vector 
**			   from stackoverflow.com/questions/3054567/right-way-to-deallocate-an-stdvector-object
***********************************************************************************************************************************/
#include "Game.hpp"

/*********************************************************************************************************************
** Program: Game::Game()
** Description: This is constructor for Game class. It set the two int variables as 0, this is for selecting character
**********************************************************************************************************************/
Game::Game(int p1, int p2)
{
	p1Chac = p1-1;
	p2Chac = p2-1;
}

/*********************************************************************************************************************
** Program: Game::~Game()
** Description: This is destructor for Game class. It declare empty vector for memory dellocation 
**********************************************************************************************************************/
Game::~Game()
{
	std::vector<std::shared_ptr<fantasyCG>> nothing;							//As I mentioned above as reference, I noticed the good way of delocating vector is 
}																				// to create new vector of pointer to class, and do nothing.

/*********************************************************************************************************************
** Program: Game::setupP1()
** Description: Declare and setup vector of fantasyCG class to game charactors for player 1. It returns vector point object
**********************************************************************************************************************/
std::vector<std::shared_ptr<fantasyCG>> Game::setupP1()
{
	player1 =
	{
		std::make_shared<Vampire>(),											//set all charactors
		std::make_shared<Barbarian>(),
		std::make_shared<Bluemen>(),
		std::make_shared<Medusa>(),
		std::make_shared<Harry>(),
	};

	return player1;
}

/*********************************************************************************************************************
** Program: Game::setupP2()
** Description: Declare and setup vector of fantasyCG class to game charactors for player 2. It returns vector point object
**********************************************************************************************************************/
std::vector<std::shared_ptr<fantasyCG>> Game::setupP2()
{
	player2 =
	{
		std::make_shared<Vampire>(),													//set all charactors
		std::make_shared<Barbarian>(),
		std::make_shared<Bluemen>(),
		std::make_shared<Medusa>(),
		std::make_shared<Harry>(),
	};

	return player2;
}


/*********************************************************************************************************************
** Program: Game::attackPlayer()
** Description: Function to calculate the inflicted dmg for battle. It accepts vector of pointer to fantasyCG and int variable
**				It returns dmg as int for later process
**********************************************************************************************************************/
int Game::attackPlayer(std::vector<std::shared_ptr<fantasyCG>> attack, std::vector<std::shared_ptr<fantasyCG>> defense, int atkChac, int defChac)
{
	int attPoint = attack[atkChac]->attack();											//get attackers' attack points
	int defPoint = defense[defChac]->defenseSK() + defense[defChac]->getArmor();		//get defenders' defense point and armor if they have
	int dmg = attPoint - defPoint;														//calculate the total dmg

	if (dmg < 0)																		//if dmg less than 0, dmg = 0;
		dmg = 0;
	
	std::cout << "** " << attack[atkChac]->getType() << " attacks " << defense[defChac]->getType() << std::endl;
	std::cout << "** Attack Point: " << attPoint << std::endl;							//promt attack points and defense points
	std::cout << "** defense Point: " << defPoint << std::endl;
	
	return  dmg;																		//return it
}

void Game::defensePlayer(std::vector<std::shared_ptr<fantasyCG>> defense, int defChac, int dmg)
{
	int newStrength = defense[defChac]->getStrength() - dmg;							//calculate the new strength
	if (newStrength < 0)																//if strength < 0, then strength = 0;
		newStrength = 0;
	defense[defChac]->setStrength(newStrength);											//update strength
	std::cout << "** " << defense[defChac]->getType() << " is inflicted damage " << dmg << std::endl;
	defense[defChac]->sskill();															//check if defender have special skill
}

/*********************************************************************************************************************
** Program: Game::playCheck()
** Description: Function to check whether the game should be finished or can keep to be played.
**********************************************************************************************************************/
int Game::playCheck(std::vector<std::shared_ptr<fantasyCG>> defender, int defChac)
{
	int defStr = defender[defChac]->getStrength();										//check deffender's strength
	if (defStr <= 0)																	// if they have 0 strength
	{																					// game is over.
		std::cout << "******************************************" << std::endl <<std::endl;
		std::cout << "** Result" << std::endl;
		std::cout << "** " << defender[defChac]->getType() << "'s Strength points became 0" << std::endl;
		return 0;
	}
	return 1;
}

/*********************************************************************************************************************
** Program: Game::playGame()
** Description: Function to paly game, most of Game class functions are used here.
**********************************************************************************************************************/
void Game::playGame()
{
	int round = 1;														//set round
	bool gameFinish = false;											//gameFinish is false

	this->setupP1();													//set up characters for player 1
	this->setupP2();													//set up characters for player 2

	

	std::string p1Type = player1[p1Chac]->getType();					//get player 1's character info for display
	int p1Armor = player1[p1Chac]->getArmor();				
	int p1Totaldmg = 0;

	std::string p2Type = player2[p2Chac]->getType();					//get player 2's character info for display
	int p2Armor = player2[p2Chac]->getArmor();
		int p2Totaldmg = 0;

	do																	//do while loop,
	{																	//display game infomation
		std::cout << std::endl << std::endl;
		std::cout << "****************  " << "Round." << round << "  ***************"<< std::endl;
		std::cout << "** [Player 1]" << std::setw(29) << "**" << std::endl;
		std::cout << std::setw(10) << "** Tribe: " << std::setw(12) << p1Type << std::setw(20) << "**" << std::endl;
		std::cout << std::setw(10) << "** Armor: " << std::setw(12) << p1Armor << std::setw(20) << "**" << std::endl;
		std::cout << std::setw(10) << "** Strength: " << std::setw(9) << player1[p1Chac]->getStrength() << std::setw(20) << "**" << std::endl;
		std::cout << "******************* vs *******************" << std::endl;
		std::cout << "** [Player 2]" << std::setw(29) << "**" << std::endl;
		std::cout << std::setw(10) << "** Tribe: " << std::setw(12) << p2Type << std::setw(20) << "**" << std::endl;
		std::cout << std::setw(10) << "** Armor: "  << std::setw(12) << p2Armor << std::setw(20) << "**" << std::endl;
		std::cout << std::setw(10) << "** Strength: " << std::setw(9) << player2[p2Chac]->getStrength() << std::setw(20) << "**" << std::endl;
		std::cout << "******************************************" << std::endl;


																							//player 1 attack, player 2 defense
		std::cout << "** [Player 1 Attack] vs [Player 2 Defense]" << std::endl;
		std::cout << "** --" << std::endl;
		int damageP1 = this->attackPlayer(player1, player2, p1Chac, p2Chac);				//get dmg
		this->defensePlayer(player2, p2Chac, damageP1);										//update defender's status
		if (this->playCheck(player2, p2Chac) == 0)											//check whether the defender dead or not
		{
			gameFinish = true;
			std::cout << "** " << player2[p2Chac]->getType() << " of Player 2 dead" << std::endl;
			std::cout << "** " << "Player 1 has won" << std::endl;
		}

		else
		{	
																							//player 2 alive, time to revenge
			std::cout << "******************************************" << std::endl;
			std::cout << "**** [Attacker / Defender role swap!] ****" << std::endl;
			std::cout << "******************************************" << std::endl;
			std::cout << "** [Player 2 Attack] vs [Player 1 Defense]" << std::endl;
			int damageP2 = this->attackPlayer(player2, player1, p2Chac, p1Chac);
			this->defensePlayer(player1, p1Chac, damageP2);

			if (this->playCheck(player1, p1Chac) == 0)										//check one of character dead or not
			{																				//if one dead
				gameFinish = true;															//close game
				std::cout << "** " << player1[p1Chac]->getType() << " of Player 1 dead" << std::endl;
				std::cout << "** " << "Player 2 has won" << std::endl;
			}
		}

		round++;																			//if game is not over, increase round

	} while (!gameFinish);
}
