/********************************************************************************************************************************************
** Program name: determinant.cpp
** Author: Sangyun Lee
** Date: OCT 3 2019
** Description: This function accepts pointer of pointer to int array and int as parameters and return integer.								
			And, it will display the matrix with the numbers entered, and it also calculate the determinant of the matrix.				
			and return the result.	
********************************************************************************************************************************************/

#include "determinant.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int	determinant(int** arr, int x) 
{
	int result = 0;																//variable will contain determinant value
	int size = x;																//matrix size

	if (size == 2)																//when matrix size is 2
	{
		result = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
	}

	else if (size == 3)															//when matrix size is 3
	{
		int Fmax;																//devide the formula into three 
		int Smax;
		int Tmax;

		Fmax = arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1]));
		Smax = arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0]));
		Tmax = arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[1][1] * arr[2][0]));
		result = Fmax - Smax + Tmax;
	}

		return result;
}
