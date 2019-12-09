/**************************************************************************************************************
** Program name: getInput.cpp
** Author: Sangyun Lee
** Date: Nov 20 2019
** Description: This is function to get an input from users and validate it. It revised for lab 8.
**				It just get an int input from users and validate it, then return the user input
**************************************************************************************************************/

#include "getInput.hpp"
using std::cin;
using std::cout;
using std::endl;


int getInput(int option)
{
	int userNum;					// variable that contains the user's input
	int validate = 0;				//validate flag to use while loop

	if (option == 0)				// number of round
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 1 || userNum > 20000000 || cin.get() != '\n')			//if the input is not an integer, or unintended interger
			{
				cout << "Your input is wrong, please try again." << endl << endl;						//print error message
				cin.clear();																			//clear the cin
				cin.ignore(256, '\n');																	//skip to the newline
			}

			else
				validate = 1;																			//set the validate variable as 1, then get out from while loop
		}

		return userNum;
	}

	else if (option == 1)			//percentage
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 0 || userNum > 100 || cin.get() != '\n')			//if the input is not an integer, or unintended interger
			{
				cout << "Your input is wrong, please try again." << endl << endl;						//print error message
				cin.clear();																			//clear the cin
				cin.ignore(256, '\n');																	//skip to the newline
			}

			else
				validate = 1;																			//set the validate variable as 1, then get out from while loop
		}

		return userNum;																					//return the value }
	}

	else if (option == 2)			//percentage
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 1 || userNum > 3 || cin.get() != '\n')			//if the input is not an integer, or unintended interger
			{
				cout << "Your input is wrong, please try again." << endl << endl;						//print error message
				cin.clear();																			//clear the cin
				cin.ignore(256, '\n');																	//skip to the newline
			}

			else
				validate = 1;																			//set the validate variable as 1, then get out from while loop
		}

		return userNum;																					//return the value }
	}
}

