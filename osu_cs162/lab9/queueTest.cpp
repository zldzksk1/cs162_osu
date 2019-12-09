/**************************************************************************************************************
**	Program	:	queueTest.hpp
**	Author	:	Sangyun Lee
**	Date	:	Nov 26 2019
**	Description:	This specification file of queue.cpp.
**	Reference:		I referred the example and explanation from http://www.cplusplus.com/reference/queue/queue/
***************************************************************************************************************/

#include "queueTest.hpp"

/**************************************************************************************************************
**	Program	:	queueT()
**	Description:	This is constructor
***************************************************************************************************************/
queueT::queueT()
{
	srand(time(NULL));
	setRound();
	setApercent();
	setRpercent();
}

/**************************************************************************************************************
**	Program	:	~queueT()
**	Description:	This is destructor
***************************************************************************************************************/
queueT::~queueT()
{
	while (!iQueue.empty())
	{
		iQueue.pop();						//remove all elements from the queue until it get empty
	}
}

/**************************************************************************************************************
**	Program	:	setRound()
**	Description:	This is to set how many rounds of simulation would be conducted
***************************************************************************************************************/
void queueT::setRound()
{
	cout << "How many rounds will be simulated?" << endl;				//prompt msg
	userInput = getInput(0);											//get intput and validate
}

/**************************************************************************************************************
**	Program	:	setApercent()
**	Description:	This is to set the upper limmit of % to add the random number into queue
***************************************************************************************************************/
void queueT::setApercent()
{
	cout << "Decide % to add random number at the end of buffer" << endl;  //prompt msg
	aPercent = getInput(1);												   //get intput and validate
}

/**************************************************************************************************************
**	Program	:	setRpercent()
**	Description:	This is to set the upper limmit of % to remove the front of the queue
***************************************************************************************************************/
void queueT::setRpercent()
{
	cout << "Decide % to remove random number at the front of buffer" << endl;  //prompt msg
	rPercent = getInput(1);														//get intput and validate
}

/**************************************************************************************************************
**	Program	:	RndNumber()
**	Description:	This is to generate the randome number that can be added to the queue
***************************************************************************************************************/
int queueT::RndNumber()
{ 
	randomNum = rand() % 1000 + 1;												//generate number between 1 and 1000;
	cout << "-Randomly generated number: " << randomNum << endl;				//prompt msg
	return randomNum;															//return the value
}

/**************************************************************************************************************
**	Program	:	Probability()
**	Description:	This is % to decide whether add or remove an element, it accepts the % decided by users
***************************************************************************************************************/
bool queueT::Probability(int percent)
{
	if (int addRnum = (rand() % 100 + 1) <= percent)							//generate random number, if it is equal or less than user defined %
	{																			//return true
		return true;
	}
	else
		return false;
}

/**************************************************************************************************************
**	Program	:	print()
**	Description:	This is to print elements in the queue, it accepts the queue variable
***************************************************************************************************************/
void queueT::print(std::queue<int> q)
{
	cout << "-Queue size: " << q.size() << " / ";								//prompt the queue size and elements							
	cout << "Elements in the Queue: ";
	if (q.empty())
	{
		cout << "Empty Queue" << endl;											// if it is empty, let users know
	}

	while (!q.empty())															// if it is not empty
	{
		cout << " " << q.front();												// print the front element of the queue
		q.pop();																// remove front for the next number
	}
	cout << endl;
}

/**************************************************************************************************************
**	Program	:	calAL()
**	Description:	This is to calculate the average of buffer length of each round.
**					avgHd = previous AL
***************************************************************************************************************/
void queueT::calAL(std::queue<int> iq, int rnd, double& avgHd)
{
	double bLength;													//declare variables
	double avg;

	//if (rnd == 1)													//1st round, numb
	//{
	//	bLength = iq.size();
	//	avg = bLength;
	//	avgHd = avg;
	//}

	
	//{
		bLength = iq.size();										//get queue size
		int temp = rnd - 1;											//
		avg = ((avgHd * temp) + bLength) / rnd;
		avgHd = avg;
	//}

	cout << "-Average Length: " << avg << endl;
}

/**************************************************************************************************************
**	Program	:	Probability()
**	Description:	This is destructor
***************************************************************************************************************/
void queueT::simulation()
{
	cout << "Simularation start!" << endl << endl;
	int round = 1;

	while (userInput >= 1)
	{
		cout << "Round." << round << endl;										//prompt round
		int gRndNum = RndNumber();
	
		if (Probability(aPercent))												//if the function return true
		{
			cout << "-the random number is added onto queue" << endl;				//promt the number is added into queue
			iQueue.push(gRndNum);												//push into queue
		}

		else
			cout << "-the random number isn't added onto queue" << endl;		//else prompt msg that the number is not added into queue
			
		if (Probability(rPercent))												//if the function return true
		{
			if (!iQueue.empty())	
			{
				cout << "-Front number in the queue removed" << endl;			//prompt msg
				iQueue.pop();													//remove front element
			}
		}

		else																	//else let users know the front element is not removed.
		{
			cout << "-Front number isn't removed from the queue" << endl;
			cout << " or it is empty" << endl;
		}

		print(iQueue);															//print queue
		calAL(iQueue, round, avgHolder);										//calculate the Average length and display
		round++;																//round up
		userInput--;															//decrease the userInput which is a round.
		cout << endl;
	}
}