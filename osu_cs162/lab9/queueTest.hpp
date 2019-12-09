/**************************************************************************************************************
**	Program	:	queueTest.hpp
**	Author	:	Sangyun Lee
**	Date	:	Nov 26 2019
**	Description:	This header file of queue.cpp.
***************************************************************************************************************/

#ifndef QUEUETEST_HPP
#define QUEUETEST_HPP

#include "utilities.hpp"

class queueT
{
protected:
	std::queue<int> iQueue;
	int userInput, aPercent, rPercent, randomNum;
	double avgHolder;
public:												
	queueT();
	~queueT();
	void setRound();
	void setApercent();
	void setRpercent();
	int  RndNumber();
	bool Probability(int);
	void print(std::queue<int> q);
	void calAL(std::queue<int> iq, int rnd, double& dq);
	void simulation();

};

#endif // !QUEUETEST_HPP
