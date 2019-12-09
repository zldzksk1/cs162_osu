/*****************************************************************************************************************************
** Program: reverse.hpp
** Author: Sangyun Lee
** Date: Oct 28 2019
** Description: This is implementation file of reverse function. It accepts string variable, and reverse the context of string
				and display it.
** Reference: I found a std::string::erase function from geeksforgeeks.org/stdstringerase-in-cpp/
******************************************************************************************************************************/

#include "reverse.hpp"

void reverse(std::string x)
{
	int size = x.size();
	if (size > 0)								//base case, if length of the string greater than zero
	{
		std::cout << x[size - 1] ;				// display the last character first
		x.erase(size - 1);						// and erase it
		reverse(x);								// recall the function
	}
	else
		std::cout << std::endl;					//if length of the string less than zero, print new line. And finish
}