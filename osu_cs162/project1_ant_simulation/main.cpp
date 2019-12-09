/********************************************************************************************************************************************
** Program name: mian.cpp
** Author: Sangyun Lee
** Date: OCT 5 2019
**Description: This is main cpp. where all fuctions and class will be excuted. There is emum date type, to controle the menu function.
**
********************************************************************************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Ant.hpp"
#include "getInput.hpp"
#include "menu.hpp"


enum gamePlay											//enum data type to decide the role menue and getInput function
{
	intro = 1,
	getR,
	getC,
	setRp,
	setCp,
	getStep,
	replay,
	randomP,
};

int main()
{
	int gameSate;												//prepare necessary variables
	int rowSize;
	int colSize;
	int rPos;
	int cPos;
	int stepNum;
	int reGame = 0;
	int rdGame = 0;


	gameSate = menu(intro);

	if (gameSate == 2)
	{
		cout << "Thank you for using this program." << endl;
		return 0;
	}

	else if (gameSate == 1)
	{
		cout << "Langton's Ant Simulation Start!" << endl;
		cout << "Ant will move as much as step you provided" << endl;
		cout << "on the size of the board you decided" << endl << endl;
	}

	while (reGame != 2)
	{
		rowSize = menu(getR) + 2;								// since the board include edge bars,
		colSize = menu(getC) + 2;								// add 2 on the given user value

		rdGame = menu(randomP);
		if (rdGame == 2)
		{
			rPos = menu(setRp);									//set r & c position of ant by user value
			cPos = menu(setCp);
		}

		else if (rdGame == 1)
		{
			rPos = rand() % (rowSize - 2) + 1;					//if they want random location
			cPos = rand() % (colSize - 2) + 1;					// call rand() to generate random number
		}

		stepNum = menu(getStep);


		Ant antSimulation(rowSize, colSize, rPos, cPos);		// set and call ant class
		antSimulation.setStep(stepNum);
		antSimulation.playGame();								//start the simulation
		antSimulation.clearBoard();								//clear board and dynamic array

		reGame = menu(replay);									//ask another play
	}

	return 0;
}