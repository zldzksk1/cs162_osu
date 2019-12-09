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
	static int rBarrier;			//contain row size, so start point can't over the row size
	static int cBarrier;			//contain col size, so start point can't over the col size

// menu one: introduction
	if (x == 1)
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum <= 0 || userNum >= 3 || cin.get() != '\n')					//if the input is not an integer, or unintended interger
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


// menu two: row for the board size
	else if (x == 2)
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 3 || userNum > 100 || cin.get() != '\n')						//if the input is not an integer, or out of range
			{
				cout << "Your input is wrong or out of range, please try again." << endl << endl;	//print error message
				cin.clear();																		//clear the cin
				cin.ignore(256, '\n');																//skip to the newling
			}

			else
			{
				cout << "Your entered " << userNum << endl << endl;
				validate = 1;																		//set the validate variable as 1, then get out from while loop
			}

		}

		rBarrier = userNum;																			//save row size
		return userNum;																				//return the value
	}


// menu three: colum for the board size
	else if (x == 3)
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum < 3 || userNum > 100 || cin.get() != '\n')						//if the input is not an integer, or out of range
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

		cBarrier = userNum;																			//save the col size
		return userNum;																				//return the value
	}


//menu four: row for the ant start position
	else if (x == 4)
	{
		while (!validate)
		{
			cout << "Please enter your response (do not exceed " << rBarrier << "): ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum <= 0 || userNum > rBarrier || cin.get() != '\n')				//if the input is not an integer, or out of range
			{
				cout << "Your input is wrong or out of range, please try again." << endl << endl;	//print error message
				cin.clear();																		//clear the cin
				cin.ignore(256, '\n');																//skip to the newling
			}

			else
			{
				cout << "Your entered " << userNum << endl << endl;
				validate = 1;																		//set the validate variable as 1, then get out from while loop
			}

		}

		return userNum;																				//return the value
	}


//menu five: col for the ant start position
	else if (x == 5)
	{
		while (!validate)
		{
			cout << "Please enter your response (do not exceed " << cBarrier << "): ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum <= 0 || userNum > cBarrier || cin.get() != '\n')				//if the input is not an integer, or out of range
			{
				cout << "Your input is wrong or out of range, please try again." << endl << endl;	//print error message
				cin.clear();																		//clear the cin
				cin.ignore(256, '\n');																//skip to the newling
			}

			else
			{
				cout << "Your entered " << userNum << endl << endl;
				validate = 1;																		//set the validate variable as 1, then get out from while loop
			}

		}

		return userNum;																				//return the value
	}



//menu six: number of step
	else if (x == 6)
	{
		while (!validate)
		{
			cout << "Please enter your response: ";
			cin >> userNum;
			cout << endl;

			if (cin.fail() || userNum <= 0 || userNum >= 20000 || cin.get() != '\n')				//if the input is not an integer, or out of range
			{
				cout << "Your input is wrong or too large, please try again." << endl << endl;		//print error message
				cin.clear();																		//clear the cin
				cin.ignore(256, '\n');																//skip to the newling
			}

			else
			{
				cout << "Your number of step is " << userNum << endl;
				validate = 1;																		//set the validate variable as 1, then get out from while loop
			}
		}
		return userNum;																				//return the value
	}


	else
		return 0;
}

