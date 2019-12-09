/*********************************************************************************************************
** Program: zoo.hpp
** Author: Sangyun Lee
** Date: OCT 18 2019
** Description: This is zoo.hpp specification file which you can see all variables and functions
**********************************************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "menu.hpp"
#include "getInput.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include <fstream>   //for extra credit


enum process
{
	playGame,
	buyAnimal,
	howMany,
	checking,
};


class zoo
{
private:

	tiger* tigerCage;
	int totalT;					//number of tigers in the cage;
	int cageSizeT;				//array size

	penguin* penguinCage;
	int totalP;					//number of tigers in the cage;
	int cageSizeP;				//array size

	turtle* turtleCage;
	int totalR;					//number of tigers in the cage;
	int cageSizeR;				//array size


	int saving;					//total money in bank
	int totalIncome;
	int zEvent;					//Event
	int day;
				
public:
	zoo();						//constructor
	~zoo();						//destructor

	void setSaving(int);		//please refer the detail info at the cpp file
	void setZevent();
	int getSaving();
	int getDay();
	int getTpop();				//get how many tigers in cage
	int getPpop();
	int getRpop();
	int getCageT();				//in order to debug, the cageSize is getting expanded
	int getCageP();				// ''
	int getCageR();				// ''
	void playgame();
	void gameStart();			//initialize the game for the first time
	void closingDay();			//close ments
	int caltotalIncome();
	int totalFcost();
	char buyAnm();				//buy animal
	int buyHmany();				//decide quantity
	void addAnimal(char, int);
	void buildCage(char, int);
	void agingAnm();
	void feedingAnm();
	void buyAdult();

};


#endif ZOO_HPP
