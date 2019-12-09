/**************************************************************************************************************
**	Program	:	main.cpp
**	Author	:	Sangyun Lee
**	Date	:	Nov 27 2019
**	Description:	This is to initialize the class and run the test.
***************************************************************************************************************/

#include "utilities.hpp"
#include "queueTest.hpp"
#include "stackString.hpp"

int main()
{
	int playCheck;
	
	cout << "Welcome to my program!" << endl;								//prompt welcome msg
	cout << "1. Buffer Simulation" << endl;									//prompt options
	cout << "2. Palindrome Simulation" << endl;
	cout << "3. Exit" << endl;

	playCheck = getInput(2);												//get users' response

	while (playCheck != 3)													//if it is not exit
	{
		if (playCheck == 1)													//user selects buffer simulation
		{
			cout << "*Buffer Simulation" << endl;							//promt msg
			queueT queTest;													//test starts;
			queTest.simulation();
		}

		else if (playCheck == 2)											//user selects Palindrome simulation
		{
			cout << "*palindrome Simulation" << endl;						//promt msg
			sstack stackTest;												//test starts;
			stackTest.simulation();
		}

		cout << "Try more test?" << endl;									//prompt msg
		cout << "1. Buffer Simulation" << endl;								//prompt options
		cout << "2. Palindrome Simulation" << endl;
		cout << "3. Exit" << endl;
		playCheck = getInput(2);											//get users' response
	}																	

	cout << "Thank you for using my program!" << endl;						//good bye msg and close
	return 0;
};
