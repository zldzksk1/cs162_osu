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
	

	if (stateCheck == 0)																	//prompt menu to users
	{
		cout << endl;
		cout << "Please choose one of function you want to implement" << endl;
		cout << "1. Reverse my sentence" << endl;
		cout << "2. Generate array and find the sum of the array" << endl;
		cout << "3. Find triangular number" << endl;
		cout << "4. Exit" << endl;
		stateCheck = getInput(stateCheck);

		return stateCheck;
	}

	else if (stateCheck == 2)																
	{												
		cout << "Please decide the array size you want to create." << endl;		//display prompt
		stateCheck = getInput(stateCheck);													//get input and validate at getInput()
		return stateCheck;																	//return value
	}

	else if (stateCheck == 3)																
	{
		cout << "Please enter an integer, then program will find trianglular value" << endl;//display prompt
		stateCheck = getInput(stateCheck);													//get input and validate at getInput()
		return stateCheck;	
	}

}
