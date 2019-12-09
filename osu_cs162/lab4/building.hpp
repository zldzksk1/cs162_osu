/*********************************************************************************************************************
** Program: building.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of building class.
**********************************************************************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP
#include <iostream>
#include <string>


class building
{
private:														//declare variables
	std::string bName;											//building name
	std::string address;										//address
	int size;													//size;

public:
	building(std::string const , std::string const , int);		//declare member function
	~building();
	void setBname(std::string);
	void setAddress(std::string);
	void setSize(int);
	std::string getBname();
	std::string getAddress();
	int getSize();
	void printBinfo();
};


#endif
