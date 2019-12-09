/***********************************************************************************************************************
** Program: doublyList.cpp
** Author:	Sangyun Lee
** Date:	NOV 08 2019
** Description: This is specification file of doublyList file.
**
************************************************************************************************************************/

#include "doublyList.hpp"

/***********************************************************************************************************************
** Program: doublyList::doublyList()
** Description: This is constructor of doublyList class.
**
************************************************************************************************************************/
doublyList::doublyList()
{
	head = nullptr;
	tail = nullptr;
};

/***********************************************************************************************************************
** Program: doublyList::~doublyList()
** Description: This is destructor of doublyList class.
**
************************************************************************************************************************/
doublyList::~doublyList()
{
	struct Listnode* nodeptr = head;				//start from head
	while (nodeptr != nullptr)						//if it is not empty
	{
		Listnode* garbage = nodeptr;				//create temp, 
		nodeptr = nodeptr->next;					//move to next until the end;
		delete garbage;								//delete garbage;
	}
};

///***********************************************************************************************************************
//** Program: doublyList::addNumF()
//** Description: This is function to add int to ahead of linked list. It accpets int variable.
//**
//************************************************************************************************************************/
void doublyList::addNumF(int num)
{
	struct Listnode* newnode = new Listnode(num);		//create new node
	if (head == nullptr)								//if list is empty
	{
		head = newnode;									//this node will be head and tail
		tail = newnode;
		newnode->prev = nullptr;						//since it is head, prev points null, next will be nullptr
		newnode->next = nullptr;
	}

	else
	{													//if it is not first node
		head->prev = newnode;							//previous node point to this new node
		newnode->next = head;							//new node point to previous head
		head = newnode;									//and it becomes new head
	};
}

///***********************************************************************************************************************
//** Program: doublyList::addNumE()
//** Description: This is function to add int at the end of linked list. It accpets int variable.
//**
//************************************************************************************************************************/
void doublyList::addNumE(int num)
{
	struct Listnode* newnode = new Listnode(num);		//create new node
	if (tail == nullptr)								//if list is empty
	{
		head = newnode;									//this node will be head and tail
		tail = newnode;
		newnode->next = nullptr;						//since it is head, prev points null, next will be nullptr
		newnode->prev = nullptr;
	}

	else
	{													//if it is not first node
		tail->next = newnode;							//previous node point to this new node
		newnode->prev = tail;							//new node point to previous tail
		tail = newnode;									//and it becomes new tail
	};
}

///***********************************************************************************************************************
//** Program: doublyList::print()
//** Description: This is function to print int value of linked list.
//**
//************************************************************************************************************************/
void doublyList::print()
{
	struct Listnode* temp = head;						//it starts from head;
	
	if (temp == nullptr)								//if it is the eampty list
	{
		std::cout << "List is empty" << std::endl;		//prompt "empty list"
		return;
	}

	while (temp != nullptr)								//if is it not empty
	{
		std::cout << temp->value << " ";				//cout the value
		temp = temp->next;								//move to next
	}
}


///***********************************************************************************************************************
//** Program: doublyList::printReverse()
//** Description: This is function to print int value of linked list opposite way.
//**
//************************************************************************************************************************/
void doublyList::printReverse()							
{
	struct Listnode* temp = tail;						//it starts from tail;
	
	if (temp == nullptr)								//if it is the eampty list
	{
		std::cout << "List is empty" << std::endl;		//prompt "empty list"
		return;
	}

	while (temp != nullptr)								//if is it not empty
	{
		std::cout << temp->value << " ";				//cout the value
		temp = temp->prev;								//move backward for next data
	}
}

///***********************************************************************************************************************
//** Program: doublyList::deleteF()
//** Description: This is function to delete the first int value of linked list.
//**
//************************************************************************************************************************/
void doublyList::deleteF()								
{
	if (!head)											//if it is empty list
	{
		std::cout << "Nothing to delete" << std::endl;	//prompt "empty list"
		return;
	}
	
	struct Listnode* temp = head;						//if it is not empty, move head to temp node
	head = head->next;									//the second node becomes head
//	head->prev = nullptr;
	delete(temp);										//delete node
	
}

///***********************************************************************************************************************
//** Program: doublyList::printReverse()
//** Description: This is function to print int value of linked list opposite way.
//**
//************************************************************************************************************************/
void doublyList::deleteE()
{
	if (!tail)											//if it is empty list
	{
		std::cout << "Nothing to delete" << std::endl;	//prompt "empty list"
		return;
	}
	struct Listnode* temp = tail;						//start from tail
														
	if (tail->prev == nullptr)							//if it is only node
	{
		tail = tail->prev;								//tail becaome nullptr which is tail->prev points to
		tail = nullptr;	
		head = nullptr;									//head becomes nullptr as well;
		delete(temp);									//delete tail
	}
	else
	{
		tail = tail->prev;								//the second node from the tail becomes tail
		tail->next = nullptr;							//and it points to null
		delete(temp);									//delete node
	}
}

///***********************************************************************************************************************
//** Program: doublyList::printH()
//** Description: This is function to print int value of head.
//**
//************************************************************************************************************************/
void doublyList::printH()
{
	if (head != nullptr)
	{
		std::cout << "The number head points to is: ";				//promt msg
		std::cout << head->value << std::endl;						//get value in head
	}
	else if (head == nullptr)										//if head is nullptr
		std::cout << "List is empty" << std::endl;					//list is empty
}

///***********************************************************************************************************************
//** Program: doublyList::printT()
//** Description: This is function to print int value of tail.
//**
//************************************************************************************************************************/
void doublyList::printT()
{
	if (tail != nullptr)
	{
		std::cout << "The number tail points to is: ";				//promt msg
		std::cout << tail->value << std::endl;						//get value in tail
	}
	else if (tail == nullptr)										//if tail is nullptr
		std::cout << "List is empty" << std::endl;					//list is empty
}
