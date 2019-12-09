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
	int stateCheck = x; 

	if (stateCheck == 0)																//single menu
	{
		cout << "Oregon State University Info System" << endl;							//display multiple choice
		cout << "1. Prints building infomation" << endl;
		cout << "2. Prints Student & instructor infomation" << endl;
		cout << "3. Choose a person to do work" << endl;
		cout << "4. Exit the program" << endl;
		stateCheck = getInput(stateCheck);

		return stateCheck;
	}

}
