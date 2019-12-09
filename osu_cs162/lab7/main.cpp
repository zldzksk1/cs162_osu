/**************************************************************************************************************
**	Program: Main.cpp
**	Author: Sangyun Lee
**	Date: Nov 13 2019
**	Description: Main.cpp where all function of queueNode are impplemented. I reused the code I created duing lab 6
**
***************************************************************************************************************/

#include "queueNode.hpp"
#include "getInput.hpp"
#include "menu.hpp"

enum option
{
	start,
	askNum,
};

int main()
{
	int num2node = 0;
	circularQueue queueTest;
	bool programCheck = true;

	while (programCheck)
	{
		int playOption = menu(option::start);
		switch (playOption)
		{
		case 1:											//add queue at front
			num2node = menu(option::askNum);
			queueTest.addBack(num2node);
			std::cout << std::endl;
			break;
		case 2:											//add queue at rear
			queueTest.getFront();
			std::cout << std::endl;
			break;
		case 3:
			queueTest.removeFront();					//delete a queue from head
			std::cout << std::endl;
			break;
		case 4:											//print all queue
			queueTest.printQueue();
			std::cout << std::endl;
			break;
		case 5:											//exit program
			std::cout << "Thank you" << endl;
			programCheck = false;
			break;
		}
	}
	
	return 0;
}