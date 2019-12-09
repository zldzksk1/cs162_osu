/**************************************************************************************************************
** Program name: getInput.cpp
** Author: Sangyun Lee
** Date: OCT 10 2019
** Description: This is function to get an input from users and validate it. It accept int as parameter,
**				so it can distinguish and prompt the right message and getting user input.
**			    If the user input is the correct input, then return the value for further process.
**************************************************************************************************************/

#include "getInput.hpp"
using std::cin;
using std::cout;
using std::endl;


int getInput(int x)
{
	int userNum;					// variable that contains the user's input
	int validate = 0;				//validate flag to use while loop


//game play or not
	if (x == 0)
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 1  || userNum > 2 || cin.get() != '\n')						//if the input is not an integer, or unintended interger
			{
				cout << "Your input is wrong, please try again." << endl << endl;					//print error message
				cin.clear();																		//clear the cin
				cin.ignore(256, '\n');																//skip to the newline
			}

			else
				validate = 1;																		//set the validate variable as 1, then get out from while loop
		}

		return userNum;																				//return the value
	}


// what animals do you want to buy
	else if (x == 1)
	{
		char animal;																				//prepare necessary variavles
		std::string anmType;

		while (!validate)
		{
			cout << "Please enter your response: ";											
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 1 || userNum > 3 || cin.get() != '\n')						//if the input is not an integer, or out of range
			{
				cout << "Your input is wrong or out of range, please try again." << endl << endl;	//print error message
				cin.clear();																		//clear the cin
				cin.ignore(256, '\n');																//skip to the newling
			}

			else																					//change intevalue into char
			{
				
				if (userNum == 1)
				{
					animal = 't';
					anmType = "Tiger";
				}

				else if (userNum == 2)
				{
					animal = 'p';
					anmType = "Penguin";
				}

				else if (userNum == 3)
				{
					animal = 't';
					anmType = "Turtle";
				}
				cout << "You choose: " << anmType << endl << endl;									//display what they choose
				validate = 1;																		//set the validate variable as 1, then get out from while loop
			}

		}

		return static_cast<int>(animal);															//change the char to int, and return
	}


//How many buy
	else if (x == 2)
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 1 || userNum > 2 || cin.get() != '\n')						//if the input is not an integer, or out of range
			{
				cout << "Your input is wrong or out of range, please try again." << endl <<endl;	//print error message
				cin.clear();																		//clear the cin
				cin.ignore(256, '\n');																//skip to the newline
			}

			else
			{
				cout << "Your entered " << userNum << endl << endl;
				validate = 1;																		//set the validate variable as 1, then get out from while loop
			}

		}

		return userNum;																				//return the value
	}

}

