/*********************************************************************************************************************
** Program: university.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of university class. And it is bass class of other classes.
**********************************************************************************************************************/


#ifndef UNIVERSITY_HPP		
#define UNIVERSITY_HPP
#include "building.hpp"									//include necessary header files and library
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "menu.hpp"
#include "getInput.hpp"
#include <iostream>
#include <string>
#include <vector>
#include<memory>

class university
{
private:																	//declare variable
	std::string uName;
	int numBilding;
	int numPeople;
	std::vector<std::shared_ptr<building>> osuBuilding;
	std::vector<std::shared_ptr<person>> people;

public:																		//declare functions
	university();
	~university();
	void setUname(std::string);
	void setNumB(std::vector<std::shared_ptr<building>>);
	void setNumP(std::vector<std::shared_ptr<person>>);
	std::string getUname();
	int getNumB();
	int getNumP();
	std::vector<std::shared_ptr<building>> setupB();
	std::vector<std::shared_ptr<person>> setupP();
	void schoolInfo(std::vector<std::shared_ptr<building>>);
	void printPeople(std::vector<std::shared_ptr<person>>);
	void workPeople(std::vector<std::shared_ptr<person>>);
	void playUniv();


};


#endif