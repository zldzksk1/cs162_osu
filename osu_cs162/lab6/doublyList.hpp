/***********************************************************************************************************************
** Program: doublyList.hpp 
** Author:	Sangyun Lee
** Date:	NOV 08 2019
** Description: This is header file of doublyList file. It contains necessary variables and functions
**				I learned about doubly linked list, adopt and referred code at 
**				https://www.youtube.com/watch?v=5s0x8bc9DvQ,
**				https://www.youtube.com/watch?v=18RZxObuz08,
**				https://www.softwaretestinghelp.com/doubly-linked-list/,
**				and textbook
************************************************************************************************************************/

#ifndef DOUBLYLIST_HPP
#define DOUBLYLIST_HPP

#include <iostream>
#include <algorithm>

class doublyList
{
private:
	struct Listnode																	//create structure
	{
		int value;
		struct Listnode* next;														//container points to next
		struct Listnode* prev;														//container points to previous
		Listnode(int value1, Listnode* next1 = nullptr, Listnode* prev1 = nullptr)	//constructor
		{
			value = value1;
			next = next1;
			prev = prev1;
		}
	};

	Listnode* head;																	
	Listnode* tail;
	
public:
	doublyList();																	//constructor
	~doublyList();																	//destructor

	void addNumF(int);																//necessary function
	void addNumE(int);
	void print();
	void printReverse();
	void deleteF();
	void deleteE();
	void printH();
	void printT();
};
#endif // !DOUBLYLIST_HPP
