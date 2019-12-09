/*********************************************************************************************************
** Program: tiger.hpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is animal.hpp specification file which you can see all variables and functions
**********************************************************************************************************/

#include "zoo.hpp"

int main()
{
	zoo zooTycoon;

	int playGame = menu(0);

	if (playGame == 1)
		zooTycoon.playgame();
	else if (playGame != 1)
		cout << "Good bye, hope to see you again!" << endl;

	return 0;
}
