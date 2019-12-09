/********************************************************************************************************************************************
** Program name: menu.cpp
** Author: Sangyun Lee
** Date: OCT 10 2019
**Description: This is menu() function with int as parameter, it is to interact with user by providing the messages such as introduction
**			   and get an input from user to further instruction. It collects input from user by using getInput fuction.
**			   
********************************************************************************************************************************************/

#include "menu.hpp"


int menu(int x)
{
	int stateCheck = x; // Enum data type to select menu
	

	if (stateCheck == 1)													// program start, and ask user weather play or not
	{
		cout << "Welcome to Die War Game" << endl;
		cout << "1. Play game" << endl;
		cout << "2. Quit game" << endl;
		stateCheck = getInput(stateCheck);									// call getInput function

		return stateCheck;
	}

	else if (stateCheck == 2)												//how many round
	{												
		cout << "How many rounds do you want to play?" << endl;				//display prompt
		stateCheck = getInput(stateCheck);									//get input and validate at getInput()
		return stateCheck;
	}

	else if (stateCheck == 3)												//reg dice side
	{
		cout << "Please decide the number of side of Regular Dice" << endl;	//display prompt
		cout << "[Minimum 4, Maximum 10]" << endl;
		stateCheck = getInput(stateCheck);									//get input and validate at getInput()
		return stateCheck;	
	}

	else if (stateCheck == 4)												//loaded dice side
	{
		cout << "Please decide the number of side of Loaded Dice" << endl;	//display prompt
		cout << "[Minimum 4, Maximum 10]" << endl;
		stateCheck = getInput(stateCheck);									//get input and validate at getInput()
		return stateCheck;
	}

	else if (stateCheck == 5)												//select dice
	{
		cout << "Select the dice type for Player 1" << endl;				//prompt options
		cout << "1. Regular Die" << endl;
		cout << "2. Loaded Die" << endl;
		stateCheck = getInput(stateCheck);									//get input and validate at getInput()
		return stateCheck;
	}
}
