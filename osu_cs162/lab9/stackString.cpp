/**************************************************************************************************************
**	Program	:	stackString.hpp
**	Author	:	Sangyun Lee
**	Date	:	Nov 26 2019
**	Description:	This specification file of stackString.hpp.
**	Reference:		I referred the example and explanation from http://www.cplusplus.com/reference/stack/stack/
***************************************************************************************************************/

#include "stackString.hpp"

/**************************************************************************************************************
**	Program	:	queueT()
**	Description:	This is constructor
***************************************************************************************************************/
sstack::sstack()
{
	setUserStr();						//set user string
}

/**************************************************************************************************************
**	Program	:	~queueT()
**	Description:	This is destructor
***************************************************************************************************************/
sstack::~sstack()
{
	while (!cStack.empty())
	{
		cStack.pop();					//remove all elements from stack
	}
}

/**************************************************************************************************************
**	Program	:	setUserStr()
**	Description:	This is destructor
***************************************************************************************************************/
void sstack::setUserStr()
{
	cout << "-Please enter string to creat a palindrome: ";
	getline(cin, userString);
}

/**************************************************************************************************************
**	Program	:	print()
**	Description:	This is to print the contents of the stack from the top.
***************************************************************************************************************/
void sstack::print(std::stack<char> stack)
{
	while (!stack.empty())
	{
		cout << stack.top();			//then print the top content from Stack
		stack.pop();					//until it is empty
	}
}

/**************************************************************************************************************
**	Program	:	palindrome()
**	Description:	This is to create palindrome: it updates the stack so it has full string include 
***************************************************************************************************************/
void sstack::palindrome(std::stack<char>& stack)
{
	std::stack<char> sndStack(stack);			//create temp stack and copy of cStack
	while (!sndStack.empty())
	{
		stack.push(sndStack.top());				//and push it onto cStack, then char in sndStack will be stroed reversly 
		sndStack.pop();
	}
}

/**************************************************************************************************************
**	Program	:	simulation()
**	Description:	This is to run the palindrome simulation
***************************************************************************************************************/
void sstack::creatStack()
{
	for (int i = 0; i < userString.size(); i++)
	{
		cStack.push(userString[i]);
	}
}

/**************************************************************************************************************
**	Program	:	simulation()
**	Description:	This is to run the palindrome simulation
***************************************************************************************************************/
void sstack::simulation()
{
	cout << "Simularation start!" << endl << endl;
	creatStack();
	cout << "-Here is the palindrome of your string" << endl;
	cout << "-";
	palindrome(cStack);
	print(cStack);
	cout << endl << endl;
}

//no use
///**************************************************************************************************************
//**	Program	:	reversePrint()
//**	Description:	This is print the contects of the stack in reverse way
//***************************************************************************************************************/
//void sstack::reversePrint(std::stack<char> stack)
//{
//	std::stack<char> tempStack;			//creat temp stack
//
//	while (!stack.empty())
//	{
//		tempStack.push(stack.top());	//store the top content from stack into tempStack
//		stack.pop();					//remove the top
//	}									// it saves the contents reversly 
//
//	while (!tempStack.empty())
//	{
//		cout << tempStack.top();		//then print the contents from tempStack
//		tempStack.pop();
//	}
//}