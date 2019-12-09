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
	int stateCheck = x; // in order to let getInput function know it is to check gameState
	

	if (stateCheck == 0)
	{
		cout << "Welcome to Zoo Tycoon" << endl;
		cout << "1. Start Game" << endl;
		cout << "2. Exit" << endl;
		stateCheck = getInput(stateCheck);

		return stateCheck;
	}

	else if (stateCheck == 1)															//Which animal do you want to buy?
	{												
		cout << "Which animal do you want to buy?" << endl;								//display prompt
		cout << "1. Tiger" << endl;
		cout << "2. Penguin" << endl;
		cout << "3. Turtle" << endl;
		stateCheck = getInput(stateCheck);												//get input and validate at getInput()
		return stateCheck;																//return casted int
	}

	else if (stateCheck == 2)															//How manu animals do you want do buy?
	{
		cout << "-How many do you want to buy?" << endl;								//display prompt
		cout << "-[Maximum purchase is 2]" << endl;
		stateCheck = getInput(stateCheck);												//get input and validate at getInput()
		return stateCheck;	
	}


	else if (stateCheck == 3)
	{
		cout << "1. Yes" << endl;														//Play again or no?
		cout << "2. No" << endl;
		stateCheck = getInput(0);
		return stateCheck;
	}
}
