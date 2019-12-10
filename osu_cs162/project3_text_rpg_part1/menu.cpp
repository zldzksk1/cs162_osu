/********************************************************************************************************************************************
** Program name: menu.cpp
** Author: Sangyun Lee
** Date: Nov 5 2019
**Description: This is menu() function with int as parameter, it is to interact with user by providing the messages such as introduction
**			   and get an input from user to further instruction. It collects input from user by using getInput fuction.
**			   
********************************************************************************************************************************************/

#include "menu.hpp"


int menu(int x)
{
	int stateCheck = x; // in order to let getInput function know it is to check gameState
	

	if (stateCheck == 0)																	//prompt menu to users
	{
		cout << endl;
		cout << "*******************************" << endl;
		cout << "**      Fantasy-Combat!      **" << endl;
		cout << "**       -Text Action-       **" << endl;
		cout << "*******************************" << endl;
		cout << "1. Play Game" << endl;
		cout << "2. Exit Game" << endl;
		stateCheck = getInput(stateCheck);

		return stateCheck;
	}

	else if (stateCheck == 1)																
	{												
		cout << "** Select character for player1." << endl;		//display prompt
		cout << "1. Vampire" << std::endl;
		cout << "2. Barbarian" << std::endl;
		cout << "3. Blue Men" << std::endl;
		cout << "4. Medusa" << std::endl;
		cout << "5. Harry Potter" << std::endl;
		stateCheck = getInput(stateCheck);													//get input and validate at getInput()
		return stateCheck;																	//return value
	}

	else if (stateCheck == 2)																
	{
		cout << "** Select character for player2." << endl;		//display prompt
		cout << "1. Vampire" << std::endl;
		cout << "2. Barbarian" << std::endl;
		cout << "3. Blue Men" << std::endl;
		cout << "4. Medusa" << std::endl;
		cout << "5. Harry Potter" << std::endl;
		stateCheck = getInput(1);													//get input and validate at getInput()
		return stateCheck;																	//return value
	}

	if (stateCheck == 3)																	//prompt menu to users
	{
		cout << endl;
		cout << "*******************************" << endl;
		cout << "**       One more game?      **" << endl;
		cout << "*******************************" << endl;
		cout << "1. Play Game" << endl;
		cout << "2. Exit Game" << endl;
		stateCheck = getInput(0);

		return stateCheck;
	}
}
