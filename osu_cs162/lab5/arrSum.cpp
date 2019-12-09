/*****************************************************************************************************************************
** Program: arrSum.cpp
** Author: Sangyun Lee
** Date: Oct 28 2019
** Description: This is specification of arrSum. It takes pointer to int array and array size as paramemeter.
**				it call itself to calculate sum of the array.
******************************************************************************************************************************/

#include "arrSum.hpp"

int arrSum(int* arr, int size)
{
	if (size > 0)											//base case, 
	{
		return arr[size - 1] + arrSum(arr, size - 1);		//recursive function and sum the return of each function
	}

	else
	{
		return 0;											//if array size is less than 0, return 0
	}
}