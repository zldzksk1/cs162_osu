/***********************************************************************************************************
** Program: Tournament.hpp
** Author:	Sangyun Lee
** Date:	Nov 16 2019
** Discription:	This is header file of Tournament.hpp.
************************************************************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "fantasyCG.hpp"


class Tournament
{
private:
	struct Node
	{
		fantasyCG* character;								//pointer to fantasyCG
		Node* next;											//linked list node
		Node(fantasyCG* player, Node* next1 = nullptr)
		{
			character = player;
			next = next1;
		}
	};

	Node* teamH;

public:
	Tournament();
	~Tournament();
	void addPlayer(fantasyCG*);
	fantasyCG* getPlayer();
	void disPlay();
	bool isEmpty();
};

#endif // !TOURNAMENT_HPP
