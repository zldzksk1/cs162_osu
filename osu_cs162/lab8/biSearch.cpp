/********************************************************************************************************************************************
** Program name: biSearch.cpp
** Author: Sangyun Lee
** Date: Nov 19 2019
** Description: This is specification of biSearch functioin. It search the number from vector using binary search.
				It accpets the pointer to 2d vector of int, and vector of string and int value (key number). 
** Reference: I reffered the code from https://www.tutorialspoint.com/binary-search-in-cplusplus and 
				https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
********************************************************************************************************************************************/
#include "biSearch.hpp"

void biSearch(std::vector<std::vector<int>>* vecArr, std::vector<std::string> vecTitle, int key)	//prototype of function;
{

	for (int i = 0; i < vecTitle.size(); i++)
	{
		int checker = -1;															//declare necessary varaibles
		int low = 0;
		int high = (*vecArr)[i].size() - 1;

		while (low <= high && checker != 1)											//while low is lower than high and key number not found
		{
			int mid = (low + high) / 2;												//calculate the mid point
			if ((*vecArr)[i][mid] == key)											// if key num found
				checker = 1;														//flag the checker and get out from while
			else if ((*vecArr)[i][mid] < key)										//unless, keep updating the mid point
				low = mid + 1;
			else if ((*vecArr)[i][mid] > key)
				high = mid - 1;
		}

		if (checker == 1)															//if key found from a text file, then prompt text tile and msg 'found number'
			std::cout << vecTitle[i] << ": target value found" << std::endl;
		else																		//or prompt text title and msg 'not found'
			std::cout << vecTitle[i] << ": target value not found" << std::endl;
	}
}
