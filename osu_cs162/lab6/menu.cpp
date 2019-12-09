/********************************************************************************************************************************************
** Program name: menu.cpp
** Author: Sangyun Lee
** Date: Nov 9 2019
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
		cout << "** Doubly Linked List Tester **" << endl;
		cout << "*******************************" << endl;
		cout << "1. Add a new node to the head" << endl;
		cout << "2. Add a new node to the tail" << endl;
		cout << "3. Delete from head" << endl;
		cout << "4. Delete from tail" << endl;
		cout << "5. Print the list reversely" << endl;
		cout << "6. Print the value of head (Extra Credit)" << endl;
		cout << "7. Print the value of tail (Extra Credit)" << endl;
		cout << "8. Exit" << endl;
		stateCheck = getInput(stateCheck);

		return stateCheck;
	}

	else if (stateCheck == 1)																
	{												
		cout << "** Please enter a positive integer." << endl;		//display prompt
		stateCheck = getInput(stateCheck);													//get input and validate at getInput()
		return stateCheck;																	//return value
	}

}
