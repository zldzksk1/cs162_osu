/********************************************************************************************************************************************
** Program name: main.cpp
** Author: Sangyun Lee
** Date: Nov 5 2019
**Description: This is main.cpp where eveything declared and ran
********************************************************************************************************************************************/
#include "Tournament.hpp"
#include "Barbarian.hpp"
#include "Bluemen.hpp"
#include "Harry.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "menu.hpp"
#include "getInput.hpp"
#include <iomanip>

enum gamePlay														//enum to interact with meny() & getInput()
{
	intro,
	teamN,
	chac,
	more,
};

int main()															//declare and initialize all necessary variables
{
	int p1choice;
	int p2choice;
	int howMany;
	int pointP1 = 0;
	int pointP2 = 0;
	bool gameProcess = true;
	std::string player1n;
	std::string player2n;

	Tournament player1;
	Tournament loserP1;
	Tournament player2;
	Tournament loserP2;
	fantasyCG* fighter;
	fantasyCG* fighterP1;
	fantasyCG* fighterP2;

//game start
	int gameCheck = menu(gamePlay::intro);														//get user choice

	while (gameCheck == 1)																		//if they want to play, choose 1
	{
		howMany = menu(gamePlay::teamN);														//decide how many team member & build up team;

//Build Team 1
		std::cout << "** Select characters for [Team 1]" << std::endl;
		for (int i = 0; i < howMany; i++)														//Looping until users select all fighter as much
		{
			std::cout << "** Fighter. " << i + 1 << std::endl;
			p1choice = menu(gamePlay::chac);													//select fighter

			std::cout << "** Set name for you fighter " << i + 1 << std::endl;					//set name
			std::getline(std::cin, player1n);
			std::cout << std::endl;

			switch (p1choice)																	//based on their response, declare class object and add to node
			{
			case 1:
				cout << "[Vampire selected]" << std::endl;
				fighter = new Vampire(player1n);
				player1.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 2:
				cout << "[Barbarian selected]" << std::endl;
				fighter = new Barbarian(player1n);
				player1.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 3:
				cout << "[Blue-Men selected]" << std::endl;
				fighter = new Bluemen(player1n);
				player1.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 4:
				cout << "[Medusa selected]" << std::endl;
				fighter = new Medusa(player1n);
				player1.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 5:
				cout << "[Harry Potter selected]" << std::endl;
				fighter = new Harry(player1n);
				player1.addPlayer(fighter);
				std::cout << std::endl;
				break;
			}//end of switch
		}// end of for loop

//Build Team 2
		std::cout << "** Select characters for [Team 2]" << std::endl;						
		for (int i = 0; i < howMany; i++)													//Looping until users select all fighter as much
		{
			std::cout << "** Fighter. " << i + 1 << std::endl;
			p2choice = menu(chac);															//select fighter

			std::cout << "** Set name for you fighter " << i + 1 << std::endl;				//set name
			std::getline(std::cin, player2n);
			std::cout << std::endl;
			switch (p2choice)
			{																				//based on their response, declare class object and add to node
			case 1:
				cout << "[Vampire selected]" << std::endl;
				fighter = new Vampire(player2n);
				player2.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 2:
				cout << "[Barbarian selected]" << std::endl;
				fighter = new Barbarian(player2n);
				player2.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 3:
				cout << "[Blue-Men selected]" << std::endl;
				fighter = new Bluemen(player2n);
				player2.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 4:
				cout << "[Medusa selected]" << std::endl;
				fighter = new Medusa(player2n);
				player2.addPlayer(fighter);
				std::cout << std::endl;
				break;
			case 5:
				cout << "[Harry Potter selected]" << std::endl;
				fighter = new Harry(player2n);
				player2.addPlayer(fighter);
				std::cout << std::endl;
				break;
			}//end of switch
		}// end of for loop

//Prompt user line up of each team
		std::cout << "****************Line-Up*******************" << std::endl;
		std::cout << "** Team1: "; 
		player1.disPlay();
		std::cout << std::endl;
		std::cout << "** Team2: ";
		player2.disPlay();
		std::cout << std::endl;


//Battle start
		int match = 1;																	//first match
		while (!player1.isEmpty() && !player2.isEmpty())								//if any team has no member to fight, game will be terminated
		{
			//common container
			int round = 1, dmg = 0;														//declare and initialize necessary variables only in this scope
			bool playCheck = true;

			//get ready p1
			fighterP1 = player1.getPlayer();											//get a figher from line
			int atckP1 = 0, defP1 = 0, strP1 = 0, armP1 = 0, curHp1 = 0;

			//get ready p2
			fighterP2 = player2.getPlayer();											//get a figher from line
			int	atckP2 = 0, defP2 = 0, strP2 = 0, armP2 = 0, curHp2 = 0;

			do
			{																			//Prompt all the information about fighters
				std::cout << std::endl << std::endl;
				std::cout << "****************  " << "Match." << match << "  ***************" << std::endl;
				std::cout << "****************  " << "Round." << round << "  ***************" << std::endl;
				std::cout << "** [Player 1]" << std::setw(29) << "**" << std::endl;
				std::cout << std::setw(10) << "** Name : " << std::setw(12) << fighterP1->getName() << std::setw(20) << "**" << std::endl;
				std::cout << std::setw(10) << "** Tribe: " << std::setw(12) << fighterP1->getType() << std::setw(20) << "**" << std::endl;
				std::cout << std::setw(10) << "** Armor: " << std::setw(12) << fighterP1->getArmor() << std::setw(20) << "**" << std::endl;
				std::cout << std::setw(10) << "** Strength: " << std::setw(9) << fighterP1->getStrength() << std::setw(20) << "**" << std::endl;
				std::cout << "******************* vs *******************" << std::endl;
				std::cout << "** [Player 2]" << std::setw(29) << "**" << std::endl;
				std::cout << std::setw(10) << "** Name : " << std::setw(12) << fighterP2->getName() << std::setw(20) << "**" << std::endl;
				std::cout << std::setw(10) << "** Tribe: " << std::setw(12) << fighterP2->getType() << std::setw(20) << "**" << std::endl;
				std::cout << std::setw(10) << "** Armor: " << std::setw(12) << fighterP2->getArmor() << std::setw(20) << "**" << std::endl;
				std::cout << std::setw(10) << "** Strength: " << std::setw(9) << fighterP2->getStrength() << std::setw(20) << "**" << std::endl;
				std::cout << "******************************************" << std::endl;

				//player 1 attack turn
				std::cout << "** [Player 1 Attack] vs [Player 2 Defense]" << std::endl;
				std::cout << "** --" << std::endl;
				atckP1 = fighterP1->attack();																//get attack point
				defP2 = fighterP2->defenseSK() + fighterP2->getArmor();										//get defence point + armor
				dmg = atckP1 - defP2;																		//calcularate the total dmg
				if (dmg <= 0)
					dmg = 0;
				std::cout << "** " << fighterP2->getName() << " is inflicted damage " << dmg << std::endl;	
				curHp2 = fighterP2->getStrength() - dmg;													//update strenght points
				fighterP2->setStrength(curHp2);
				fighterP2->sskill();																		//check special skill

				if (fighterP2->getStrength() <= 0)															//if defender's strength ==0, game over
				{
					std::cout << "******************************************" << std::endl;
					std::cout << "** The " << match << ". Match End!" << std::endl;							//prompt game situation
					std::cout << "** " << fighterP2->getName() << " of Player 2 dead" << std::endl;
					std::cout << "** " << "Player 1 has won" << std::endl;
					pointP1 += 2;																			//points for winner and loser
					pointP2 -= 1;
					match++;																				//increase match
					std::cout << "** Player1: " << pointP1 << " | player2: " << pointP2 << std::endl;		
					std::cout << "--" << std::endl;
					std::cout << "[" << fighterP1->getName() << " joined for the next match!] " << std::endl;
					fighterP1->healing();																	//healing winner									
					player1.addPlayer(fighterP1);															//add winner back to their team
					loserP2.addPlayer(fighterP2);															//add loser to the loser container
					playCheck = false;

				}
				else																						//if defender is alive, then time to revenge
				{																							//same procress as above
					//player 2 attack turn
					std::cout << "******************************************" << std::endl;
					std::cout << "** [Player 2 Attack] vs [Player 1 Defense]" << std::endl;
					std::cout << "** --" << std::endl;
					atckP2 = fighterP2->attack();
					defP1 = fighterP1->defenseSK() + fighterP1->getArmor();
					dmg = atckP2 - defP1;
					if (dmg <= 0)
						dmg = 0;
					std::cout << "** " << fighterP1->getName() << " is inflicted damage " << dmg << std::endl;
					std::cout << "******************************************" << std::endl;
					curHp1 = fighterP1->getStrength() - dmg;
					fighterP1->setStrength(curHp1);
					fighterP1->sskill();

					if (fighterP1->getStrength() <= 0)
					{
						std::cout << "******************************************" << std::endl;
						std::cout << "** The " << match << ". Match End!" << std::endl;
						std::cout << "** " << fighterP1->getName() << " of Player 1 dead" << std::endl;
						std::cout << "** " << "Player 2 has won" << std::endl;
						pointP2 += 2;
						pointP1 -= 1;
						match++;
						std::cout << "** Player1: " << pointP1 << " | player2: " << pointP2 << std::endl;
						std::cout << "--" << std::endl;
						std::cout << "[" << fighterP2->getName() << " joined for the next match!] " << std::endl;
						fighterP2->healing();																
						player2.addPlayer(fighterP2);														
						loserP1.addPlayer(fighterP1);
						playCheck = false;
					}
				}
				round++;																						//keep going rounds until one die
			} while (playCheck);
		}//while loop for tournement

//battle ends
		std::cout << "******************************************" << std::endl;									//prompt the result of all matchs
		std::cout << "** Result of Tournement" << std::endl;
		std::cout << "** Total Match:    " << match - 1 << std::endl;
		std::cout << "** Score of team1: " << pointP1 << std::endl;
		std::cout << "** Score of team2: " << pointP2 << std::endl;
		if (pointP1 > pointP2)																					//announce winner based on points they earned
			std::cout << "** [Winner is Player 1]" << std::endl;
		else if (pointP1 < pointP2)
			std::cout << "** [Winner is Player 2]" << std::endl;
		else if (pointP1 == pointP2)
			std::cout << "** [Draw!]" << std::endl;

//play more, display losers
		int moreGame = menu(gamePlay::more);
		if (moreGame == 1)
		{
			//do nothing
		}
		else if (moreGame == 2)
		{
			std::cout << "Loser(s) from team 1: ";
			loserP1.disPlay();
			std::cout << endl;
			std::cout << "Loser(s) from team 2: ";
			loserP2.disPlay();
			std::cout << endl;
			gameCheck = menu(gamePlay::intro);
		}
		else if (moreGame == 3)
		{
                        //Mark gameCheck as 2 to close program
			gameCheck = 2;
		}

	}

//ends program
	std::cout << "** Thank you for playing game!" << std::endl;
	return 0;
}//end of main


