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
	

	if (stateCheck == 1)
	{
		cout << "Welcome to Langton's Ant simulation" << endl;
		cout << "1. Start Langton's Ant simulation" << endl;
		cout << "2. Quit" << endl;
		stateCheck = getInput(stateCheck);

		return stateCheck;
	}

	else if (stateCheck == 2)															//Row size for board
	{												
		cout << "Row size of the board, you can enter from 3 to 100" << endl;			//display prompt
		stateCheck = getInput(stateCheck);												//get input and validate at getInput()
		return stateCheck;
	}

	else if (stateCheck == 3)															//Col size for board
	{
		cout << "Colum size of board, you can enter from 3 to 100" << endl;				//display prompt
		stateCheck = getInput(stateCheck);												//get input and validate at getInput()
		return stateCheck;	
	}

	else if (stateCheck == 4)															//location for row
	{
		cout << "Row position of ant on the board" << endl;
		stateCheck = getInput(stateCheck);
		return stateCheck;
	}

	else if (stateCheck == 5)															//location for col
	{
		cout << "Colum position of ant on the board" << endl;
		stateCheck = getInput(stateCheck);
		return stateCheck;
	}

	else if (stateCheck == 6)
	{
		cout << "How many steps do you want an ant to move?" << endl;					//number of steps for ants
		stateCheck = getInput(stateCheck);
		return stateCheck;
	}

	else if (stateCheck == 7)															//replay the game or not
	{
		cout << "Do you want to play it again?" << endl;								//its options are only 1 and 2
		cout << "1. Start Langton's Ant simulation" << endl;
		cout << "2. Quit" << endl;
		stateCheck = getInput(1);														//Use getInput(1)
		return stateCheck;
	}

	else if (stateCheck == 8)
	{
		cout << "This is for Extra Credit" << endl;										//its options are only 1 and 2
		cout << "1. Random Location" << endl;
		cout << "2. Location by users" << endl;
		stateCheck = getInput(1);														//Use getInput(1)
		return stateCheck;
	}
}
