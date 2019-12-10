/***********************************************************************************************************
** Program: Tournament.cpp
** Author:	Sangyun Lee
** Date:	Nov 16 2019
** Discription:	This is specification file of Tournament class.
** reference: C++ early objects 9 edition (chapter 17 ~ 18) and from lab 6~7
************************************************************************************************************/

#include "Tournament.hpp"

/***********************************************************************************************************
** Program: Tournament::Tournament()
** Discription:	This is constructor, initialize node* to nullptr
************************************************************************************************************/
Tournament::Tournament()
{
	teamH = nullptr;
}

/***********************************************************************************************************
** Program: Tournament::Tournament()
** Discription:	This is destructor. Free allocated memory
************************************************************************************************************/
Tournament::~Tournament()
{
	if (isEmpty())
	{
		//do nothing
	}

	else if (teamH->next == nullptr)		//if next point is nullptr
	{
		delete teamH;						//delete current teamH
		teamH = nullptr;					//and points to nullptr
	}
	else
	{
		Node* temp = teamH;					//move header to temp 
		teamH = teamH->next;				//update head
		delete temp;						//delete temp
	}
	
}

/***********************************************************************************************************
** Program: Tournament::addPlayer()
** Discription:	it is to add a fighter to node. It accpets pointer of character class
************************************************************************************************************/
void Tournament::addPlayer(fantasyCG* val)
{
	if (isEmpty())								//if head is empty
	{
		teamH = new Node(val);					//make it head
	}

	else
	{
		Node* member = teamH;					
		while (member->next != nullptr)
			member = member->next;				//move to the last node
		member->next = new Node(val);			//create new last node
	}
}

/***********************************************************************************************************
** Program: Tournament::getPlayer()
** Discription:	it returns address of fighter object.
************************************************************************************************************/
fantasyCG* Tournament::getPlayer()
{
	if (isEmpty())
	{
		//if empty node, then do nothing
	}
	
	else 
	{
		Node* temp;					//create temp container
		fantasyCG* chac;			//pointer to fantasyCG

		temp = teamH;				//get from head
		chac = teamH->character;	//get fighter
		teamH = teamH->next;		//update head to contain next fighter
		delete temp;				//delete temp
		return chac;				//return fighter
	}

}

/***********************************************************************************************************
** Program: Tournament::disPlay()
** Discription:	It displays all characters in node.
************************************************************************************************************/
void Tournament::disPlay()
{
	Node* temp = teamH;																			//create temp and points to head
	while (!isEmpty())																			//if is not empty node
	{
		std::cout << temp->character->getName() <<"(" << temp->character->getType() << ") ";	//prompt its name and type
		if (temp->next == nullptr)																//end of node, then do nothing
			return;
		temp = temp->next;																		//move next;
	}
	delete temp;

	if (isEmpty())
		std::cout << "No fighter(s)" << std::endl;
}


/***********************************************************************************************************
** Program: Tournament::addPlayer()
** Discription:	it is simply function to check the node
************************************************************************************************************/
bool Tournament::isEmpty()
{
	return (teamH == nullptr);
}



