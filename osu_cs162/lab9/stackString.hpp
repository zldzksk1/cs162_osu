/**************************************************************************************************************
**	Program	:	stackString.hpp
**	Author	:	Sangyun Lee
**	Date	:	Nov 26 2019
**	Description:	This header file of stackString.hpp.
***************************************************************************************************************/

#ifndef STACKSTRING_HPP
#define STACKSTRING_HPP

#include "utilities.hpp"

class sstack
{
protected:
	std::stack<char> cStack;
	std::string userString;
public:
	sstack();
	~sstack();
	void setUserStr();
	void print(std::stack<char> stack);
	void palindrome(std::stack<char> &stack);
	void simulation();
	void creatStack();
	//	void reversePrint(std::stack<char> stack);

};
#endif