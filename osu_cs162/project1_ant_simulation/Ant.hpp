/********************************************************************************************************************************************
** Program name: Ant.hpp
** Author: Sangyun Lee
** Date: OCT 5 2019
** Description: This is specification of the Ant class. There two data type which are char and int.
**
********************************************************************************************************************************************/

#include "getInput.hpp"

class Ant 
{
private:
	char** antBoard;			//variable to hold board
	char direction;				//checking direction of an ant
	char bColor;				//checking the board color
	int antRpos;				//variable to hold ant's start poistion
	int antCpos;				//variable to hold ant's start poistion
	int rowSize;				//Board size
	int colSize;				//Board size
	int step;					//number of step


public:
	Ant(int, int, int, int);	//ant constructor
	void playGame();			//function to start the simulation
	void setStep(int);			//set the number of step
	void clearBoard();

};
