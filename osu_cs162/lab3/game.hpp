/**************************************************************************************************************
** Program name: game.hpp
** Author: Sangyun Lee
** Date: Oct 17 2019
** Description: This is header file of game class. There is user-type data to use menu and getInput function
***************************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <iomanip>
#include "getInput.hpp"
#include "menu.hpp"

enum gameCheck				//user-data type
{
	play = 1,
	gRound,
	RdieSide,
	Ldieside,
	dieType,
};

class Game
{
private:
	int gameState;				// int variable to play or quit game
	int gameRd;					// number of game round
	int rdCount;				// to display game round
	int rDie;					// side of regular dice
	int lDie;					// side of loaded dice
	int scoreRd;				// score of the regular die
	int scoreLd;				// score of the loaded die
	int player1;				// players will hold dice type
	int player2;				

public:
	Game();						// defualt constructor
	int setState();				// get and validate the userinput for gameStatus
	void setGameRd();			// get and validate the userinput for game round
	void setRdie();				// get and validate the userinput for side of reg dice
	void setLdie();				// get and validate the userinput for side of loaded dice
	void setPtype();			// get and validate the userinput and allocate the dice to player 1 and 2
	void setScore(int, int);	// it is for resetting the score for the new game;
	void setrdCount();			// it is for resetting the round count for the new game;

	int getState();				// get user response
	int getGameRd();			// get number of round	
	int getRdie();				// get reg dice side
	int getLdie();				// get loaded dice side
	int getScoreRd();			// get score of reg dice player
	int getScoreLd();			// get score of loaded dice player
	void playGame(int, int);	// play game
	void gameResult();			// prompt the final result
};

#endif GAME_HPP