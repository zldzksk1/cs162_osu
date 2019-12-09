/*****************************************************************************************************************************
** Program: fillArr.cpp
** Author: Sangyun Lee
** Date: Oct 31 2019
** Description: This is specification of fillArr. It accpets the point of int array and int variable as parameter.
** and ask user to fill up an array as much as size they decide
******************************************************************************************************************************/

#include "fillArr.hpp"
#include "getInput.hpp"

void fillArr(int* arr, int size)
{
	int count = 1;																					//counts users' input
	std::cout << "Your array size is " << size << ". Please fill up your array." << std::endl;		//prompt
	for (int i = 0; i < size; i++)																	//for loop, until it meets the size of the array
	{
		std::cout << count << ". ";
		arr[i] = getInput(4);																		//get int from users and validate
		count++;																					//increase count
	}
}
