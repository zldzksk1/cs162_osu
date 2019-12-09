/**************************************************************************************************************
**	Program: queueNode.cpp
**	Author: Sangyun Lee
**	Date: Nov 12 2019
**	Description: This is specification file of queueNode. 
**	Reference: I learned and understood the concept of doubly circular linked at 
			   https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/ 
***************************************************************************************************************/

#include "queueNode.hpp"

/**************************************************************************************************************
**	circularQueue::circularQueue()
**	Description: This is constructor, it initialize the data member 'head' as null ptr
***************************************************************************************************************/

circularQueue::circularQueue()
{
	head = nullptr;
}

/**************************************************************************************************************
**	circularQueue::~circularQueue()
**	Description: This is destructor, it utilized the removeFront function, untill it gets empty
***************************************************************************************************************/
circularQueue::~circularQueue()
{
	while (!isEmpty())
	{
		removeFront();															//call removeFront(), until it removes all queue
	}
}

/**************************************************************************************************************
**	circularQueue::addBack()
**	Description: This is push function, it accepts int from a user, and add it back to queue
***************************************************************************************************************/
void circularQueue::addBack(int num)
{
	if (isEmpty())																//if queue is empty
	{																			//make it head
		circularQueue* newQueue = new circularQueue(num);
		head = newQueue;
		head->next = head;														//since it is circular
		head->prev = head;														//points itself
	}

	else 																		//if is additional queue
 	{
		circularQueue* newQueue = new circularQueue(num);						//create new queue
		newQueue->next = head;													//since new queue will be last queue in the queue list, 
		newQueue->prev = head->prev;											//newQueue->next point to head, newQueue->prev points the last queqe that head->prev points
		head->prev->next = newQueue;											//current last queue need to point to newqueue
		head->prev = newQueue;													//head->prev need to point to the new queue since the newqueue will be the last quete
	}
}

/**************************************************************************************************************
**	circularQueue::addBack()
**	Description: This is pop function, it remove the first queue in the queue list
***************************************************************************************************************/
void circularQueue::removeFront()	
{
	if (isEmpty())																//if it is empty, then prompt msg
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}

	else if (head->next == head)												//if the queus is the last one
	{
		delete head;															//delete
		head = nullptr;															//and make it nullptr
	}

	else
	{
		circularQueue* temp;													//creat temp container

		temp = head;															//save current head into temp
		(head->prev)->next = head->next;										//update last quere points head->next which will be new head;
		(head->next)->prev = head->prev;										//head->next, which will be new head, pointes the last queue;
		head = head->next;														//update head whith following queue.
		delete temp;															//delete head;
	}
}

/**************************************************************************************************************
**	circularQueue::getFront()
**	Description: This is print function, it display the value of head
***************************************************************************************************************/
void circularQueue::getFront()
{
	if (isEmpty())																//if it is empty, then prompt msg
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << head->value;												//cout, value of current head
	}
}

/**************************************************************************************************************
**	circularQueue::printQueue()
**	Description: This is print function, it display the all value in list of queue
***************************************************************************************************************/
void circularQueue::printQueue()
{
	
	if (isEmpty())
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << head->value << " ";											//display the first queue value
		
		circularQueue* temp = head->next;											//creat temp contain next queue of head
		while (temp->value != head->value)											//unless temp->value doesn't qual to head->value
		{
			std::cout << temp->value << " ";										//display, next queue value
			temp = temp->next;														//move to next quete
		}
		std::cout << std::endl;
		
	}
}

/**************************************************************************************************************
**	circularQueue::isEmpty()
**	Description: This function is to check the queue list. it returns true or faluse depends on queue list
***************************************************************************************************************/
bool circularQueue::isEmpty()
{
	return (head == nullptr);														//if head == nullptr, return true. It means eampty.
}