/**************************************************************************************************************
** Program name: main()
** Author: Sangyun Lee
** Date: Oct 15 2019
** Description: This is main() where all the class are initialized and perform its function
***************************************************************************************************************/

#include "die.hpp"						//load all the necessary library
#include "loadedDie.hpp"
#include "game.hpp"
#include <iostream>

int main()
{
	Game dieWar;						//set the Game object and create necessary variables
	int rDies = 0;						// side of reg dice
	int lDies = 0;						// side of loaded dice
	int ranNrd = 0;						// roll of reg dice
	int ranNld = 0;						// roll of loaded dice


	do									//do while loop
	{
		if (dieWar.setState() == 2)		//if gameState == 2, then game close
		{
			cout << "thank you for using this game, close." << endl;
			return 0;
		}
	
		dieWar.setGameRd();				//set game round
		dieWar.setRdie();				//set side of reg dice
		dieWar.setLdie();				//set side of loaded dice
		dieWar.setPtype();				//set which one have a which idce
		rDies = dieWar.getRdie();		//get side of reg dice
		lDies = dieWar.getLdie();		//get side of loaded dice
	
		std::shared_ptr<Die> regDie = std::make_shared<Die>();;						//creat Die class object
		std::shared_ptr<loadedDie> loadDie = std::make_shared<loadedDie>();			//creat loadedDie class object
		
		regDie->setSide(rDies);			// set side of Die class object
		loadDie->setSide(lDies);		// set side of loadedDie class object


		while (dieWar.getGameRd() != 0)	// while game round is not 0, keep playing game
		{	
			ranNrd = regDie->randNum();												//roll the dices
			ranNld = loadDie->randNum();											
			dieWar.playGame(ranNrd, ranNld);										// play game
			cout << endl;
		}
		dieWar.gameResult();														// get final result of the game
		dieWar.setrdCount();														// and reset game round gounter
		dieWar.setScore(0, 0);														// reset score of both dices 

	} while (dieWar.getState() == 1);												// check weather the user wants to play more game
	

	return 0;
}