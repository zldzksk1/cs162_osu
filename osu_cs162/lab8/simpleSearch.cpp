/********************************************************************************************************************************************
** Program name: simpleSearch.cpp
** Author: Sangyun Lee
** Date: Nov 19 2019
** Description: This is specification file of simpleSearch fuction. It accepts pointer to 2d vector of int, vector of string and int.
			    2d vector of int: numbers from text files
				vector of string: title of the text files
				int value: the number users want to search from the text file.
********************************************************************************************************************************************/
#include "simpleSearch.hpp"

void simpleSearch(std::vector<std::vector<int>>* vecArr, std::vector<std::string> vecTitle, int userNum)
{
	for (int i = 0; i < vecTitle.size(); i++)													//iterate as much as number of txt file
	{
		int checker = -1;																		//checker to check whether it has the key number
		for (int j = 0; j < (*vecArr)[i].size(); j++)
		{
			if ((*vecArr)[i][j] == userNum)														// if vector array has the key number
			{
				checker = 1;																	// flag the checker
			}
		}
		if (checker == 1)
			std::cout << vecTitle[i] << ": target value found" << std::endl;					// if checker flag, prompt msg that the number is found;
		else
			std::cout << vecTitle[i] << ": target value not found" << std::endl;				// or, not found
	}
	std::cout << std::endl;
}
