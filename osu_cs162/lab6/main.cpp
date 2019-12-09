/********************************************************************************************************************************************
** Program name: menu.cpp
** Author: Sangyun Lee
** Date: Nov 9 2019
**Description: This is main() where functions are implemented.
**
********************************************************************************************************************************************/

#include "doublyList.hpp"								//include headers.
#include "getInput.hpp"
#include "menu.hpp"

enum menuOp												//enum for menu
{
	start,
	askNum,
};

int main()
{
	doublyList list;									//initiate doublyList class
	bool programCheck = true;							//while loop flag
	int num2node;										//container for user input number

	while (programCheck)
	{
		int userInput = menu(menuOp::start);			//display menu and get response

		switch (userInput)								//case
		{
		case 1:											//add node at front
			num2node = menu(menuOp::askNum);
			list.addNumF(num2node);
			std::cout << "** Your linked list is: ";
			list.print();
			std::cout << std::endl;
			break;
		case 2:											//add node at rear
			num2node = menu(menuOp::askNum);
			list.addNumE(num2node);
			std::cout << "** Your linked list is: ";
			list.print();
			std::cout << std::endl;
			break;
		case 3:
			list.deleteF();								//delete node at front
			std::cout << "** Your linked list is: ";
			list.print();
			std::cout << std::endl;
			break;
		case 4:											//delete node at rear
			list.deleteE();
			std::cout << "** Your linked list is: ";
			list.print();
			std::cout << std::endl;
			break;
		case 5:											//print travers
			list.printReverse();
			std::cout << std::endl;
			break;
		case 6:											//print travers
			list.printH();
			std::cout << std::endl;
			break;
		case 7:											//print travers
			list.printT();
			std::cout << std::endl;
			break;
		case 8:											//close program
			programCheck = false;
			std::cout << "** Thank you for using this program" << std::endl;
			return 0;									
		}
	
	}
}