/**************************************************************************************************************
** Program name: game.cpp
** Author: Sangyun Lee
** Date: Oct 15 2019
** Description: This is implementation file of game class. This class will get all inputes from users and pass
**				it to necessary functions and other classes.
***************************************************************************************************************/

#include "game.hpp"


Game::Game()				// constructor
{
	gameState = 1;
	gameRd = 0;
	rdCount = 1;
	rDie = 6;
	lDie = 6;
	scoreRd = 0;
	scoreLd = 0;
	player1 = 1;
	player2 = 2;

}

/**************************************************************************************************************
** Program name: Game::setState()
** Description: it will ask user to decide weather they play game or not. It return integer and save to
**				gameState
***************************************************************************************************************/

int Game::setState()
{
	int x = menu(gameCheck::play);
	return x;
}

/**************************************************************************************************************
** Program name: Game::setGameRd()
** Description: it will ask user to decide how many rounds they play. It save the variable to gameRd. 
***************************************************************************************************************/
void Game::setGameRd()
{
	int x = menu(gameCheck::gRound);
	gameRd = x;
}

/**************************************************************************************************************
** Program name: Game::setRdie()
** Description: it will ask user to enter number of side for regular dice. 
***************************************************************************************************************/
void Game::setRdie()
{
	int x = menu(gameCheck::RdieSide);
	 rDie = x;
}

/**************************************************************************************************************
** Program name: Game::setLdie()
** Description: it will ask user to enter number of side for Loaded dice.
***************************************************************************************************************/
void Game::setLdie()
{
	int x = menu(gameCheck::Ldieside);
	lDie = x;
}

/**************************************************************************************************************
** Program name: Game::setPtype()
** Description: it will ask user to decide which dice will belongs to which player. Once user decide for player1
**				player 2 will be get the rest one
***************************************************************************************************************/
void Game::setPtype()
{
	int x = menu(gameCheck::dieType);
	if (x == 1)											// if x == 1, player 1 will have reg dice
	{													// then player 2 will have loaded dice
		player1 = 1;
		player2 = 2;
		cout << "Player 1 has a regular die" << endl;
		cout << "Player 2 has a loaded die" << endl;
		cout << endl;
	}

	else if (x == 2)									// if x == 2, player 1 will have loaded dice
	{													// then player 2 will have reg dice
		player1 = 2;
		player2 = 1;
		cout << "Player 1 has a loaded die" << endl;
		cout << "Player 2 has a regular die" << endl;
		cout << endl;
	}
}

/**************************************************************************************************************
** Program name: Game::setScore()
** Description: Purpose of this function is to reset the score of reg dice and loaded dice earned.
** Implementation: Since while loop is used to keep play-game, it will set the each score as 0
***************************************************************************************************************/
void Game::setScore(int x, int y)
{
	scoreRd = x;
	scoreLd = y;
}

/**************************************************************************************************************
** Program name: Game::setrdCount()
** Description: It sets the rdCount as 1. It is to display each round of game.
***************************************************************************************************************/
void Game::setrdCount()
{
	rdCount = 1;
}

/**************************************************************************************************************
** Program name: Game::getState()
** Description: It return gameState, its value will be either 1 or 2. If it is 1, then playgame. If it is 2,
**				then quit the game.
***************************************************************************************************************/
int Game::getState()
{
	return gameState;
}


/**************************************************************************************************************
** Program name: Game::getGameRd()
** Description: It return gameRd, it is used for while loop on main.cpp. if it return 0, then one game is ended
***************************************************************************************************************/
int Game::getGameRd()
{
	return gameRd;
}

/**************************************************************************************************************
** Program name: Game::getGameRd()
** Description: It return getRide which is number of side of reg dice, this value will be passed to die class
***************************************************************************************************************/
int Game::getRdie()
{
	return rDie;
}

/**************************************************************************************************************
** Program name: Game::getGameRd()
** Description: It return getRide which is number of side of loaded dice, this value will be passed to 
**				loaded die class
***************************************************************************************************************/
int Game::getLdie()
{
	return lDie;
}


/**************************************************************************************************************
** Program name: Game::getScoreRd()
** Description: It return score that reg dice earned. 
***************************************************************************************************************/
int Game::getScoreRd()
{
	return scoreRd;
}

/**************************************************************************************************************
** Program name: Game::getScoreRd()
** Description: It return score that loaded dice earned.
***************************************************************************************************************/
int Game::getScoreLd()
{
	return scoreLd;
}

/**************************************************************************************************************
** Program name: Game::playGame()
** Description: This is to play game. It acceptes two int arguments which is roll number of each dice geneerated
**				from other class function			
***************************************************************************************************************/
void Game::playGame(int x, int y)
{
	int regDie = x;				//rolls of reg dice
	int loadedDie = y;			//rolls of loaded dice

	if (player1 == 1)			//player 1 has reg dice
	{
		cout << "------------------ Dice War ------------------" << endl << endl;						// prompt game title
		cout << std::setw(25) <<"-Round(" << rdCount << ")-" << endl << endl;							// prompt round
		cout << "Player 1"<< std::fixed << std::setw(31) << "Player 2" << endl;							// display players setting
		cout << "-Regular Dice" << std::fixed << std::setw(30) << "-Loaded Dice" << endl;
		cout << "-Side: " << rDie << std::fixed << std::setw(30) << "-Side: " << lDie << endl<< endl;

		cout << "*Dices are rolled*" << endl;															// let user the dice are rolled
		cout << "Player 1 Die: " << regDie << endl;														// show the side of dices
		cout << "Player 2 Die: " << loadedDie << endl;
			   
		if (regDie > loadedDie)																			// reg dice has higher side
		{
			cout << "-Player 1 win" << endl << endl;													// reg dice earn score
			scoreRd++;												
			setScore(scoreRd, scoreLd);																	// save score		
		}

		else if (regDie < loadedDie)																	// loaed dice has higher side
		{
			cout << "-Player 2 win" << endl << endl;
			scoreLd++;																					// loaded dice earn score
			setScore(scoreRd, scoreLd);
		}

		else if (regDie == loadedDie)																	// both have the same side
			cout << "-Draw" << endl << endl;															// draw and do nothing

		cout << std::setw(26) << "-Score-" << endl;														// show current score of each player
		cout << "Player 1: " << scoreRd << std::fixed << std::setw(30) << "Player 2: " << scoreLd << endl << endl;

	}

	if (player1 == 2)																					// player 1 has loaded dice
	{																									// and other description is same
		cout << "------------------ Dice War ------------------" << endl << endl;
		cout << std::setw(25) << "-Round(" << rdCount << ")-" << endl << endl;
		cout << "Player 1" << std::fixed << std::setw(31) << "Player 2" << endl;
		cout << "-Loaded Dice" << std::fixed << std::setw(32) << "-Regular Dice" << endl;
		cout << "-Side: " << lDie << std::fixed << std::setw(30) << "-Side: " << rDie << endl << endl;

		cout << "*Dices are rolled*" << endl;
		cout << "Player 1 Die: " << loadedDie << endl;
		cout << "Player 2 Die: " << regDie << endl;

		if (regDie > loadedDie)
		{
			cout << "-Player 2 win" << endl << endl;
			scoreRd++;
			setScore(scoreRd, scoreLd);
		}

		else if (regDie < loadedDie)
		{
			cout << "-Player 1 win" << endl << endl;
			scoreLd++;
			setScore(scoreRd, scoreLd);
		}

		else if (regDie == loadedDie)
			cout << "-Draw" << endl << endl;

		cout << std::setw(26) << "-Score-" << endl;
		cout << "-Player 1: " << scoreLd << std::fixed << std::setw(30) << "-Player 2: " << scoreRd << endl << endl;
		
	}
	gameRd--;																								//one round end
	rdCount++;																								//increase the rdCount to prompt next number
}


/**************************************************************************************************************
** Program name: Game::gameResult()
** Description: This is to prompt the final result, since it void function, do not return any values.
***************************************************************************************************************/
void Game::gameResult() 
{
	int x = getScoreRd();													// get the score reg dice earned
	int y = getScoreLd();													// get the score reg dice earned

	cout << "--------------- Game Result ---------------" << endl << endl;	// prompt the title

	cout << "This is the result of your game!" << endl;
	
	if (player1 == 1)														// when player 1 has reg dice
	{
		if (x > y)															// and reg dice made more score
		{																	// display score of each dices earned
			cout << "Player 1 earned the score of " << x << endl;
			cout << "Player 2 earned the score of " << y << endl;
			cout << "*Winner is Player 1" << endl << endl << endl;			// player 1 win
		}

		else if (x < y)														// loaded dice earned more score
		{
			cout << "Player 1 earned the score of " << x << endl;
			cout << "Player 2 earned the score of " << y << endl;
			cout << "*Winner is Player 2" << endl << endl << endl;			// player 2 win
		}

		else if (x == y)
		{
			cout << "Player 1 earned the score of " << x << endl;
			cout << "Player 2 earned the score of " << y << endl;
			cout << "*Draw game" << endl << endl << endl;					// tie game
		}
	}

	if (player1 == 2)														// when player 1 has loaded dice
	{
		if (x < y)															// loaded dice earned more score
		{
			cout << "Player 1 earned the score of " << y << endl;
			cout << "Player 2 earned the score of " << x << endl;
			cout << "*Winner is Player 1" << endl << endl << endl;			// player 1 win
		}
																			
		else if (x > y)														// reg dice earned more score
		{
			cout << "Player 1 earned the score of " << y << endl;			
			cout << "Player 2 earned the score of " << x << endl;		
			cout << "*Winner is Player 2" << endl << endl << endl;			// player 2 win
		}

		else if (x == y)
		{
			cout << "Player 1 earned the score of " << x << endl;
			cout << "Player 2 earned the score of " << y << endl;
			cout << "*Draw game" << endl << endl << endl;					//tie game
		}
	}
}