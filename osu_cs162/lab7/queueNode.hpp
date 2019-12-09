/**************************************************************************************************************
**	Program: queueNode.hpp
**	Author: Sangyun Lee
**	Date: Nov 12 2019
**	Description: 
**
***************************************************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include <iostream>
#include <memory>

class circularQueue
{
private:
	int value;
	circularQueue *next;
	circularQueue *prev;
	circularQueue(int val, circularQueue* nx = nullptr, circularQueue* pr = nullptr)
	{
		value = val;
		next = nx;
		prev = pr;
	}
	circularQueue *head;

public:
	circularQueue();
	~circularQueue();
	void addBack(int);
	void removeFront();
	void getFront();
	void printQueue();
	bool isEmpty();

	class underflow {};
};

#endif // !QUEUENODE_HPP
