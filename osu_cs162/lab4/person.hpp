/*********************************************************************************************************************
** Program: perosn.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of perosn class. And it is base class of student and instructor class.
**********************************************************************************************************************/
#include<iostream>
#include<string>
#include<time.h>


#ifndef PERSON_HPP
#define PERSON_HPP

class person
{
protected:
	int age;
	std::string name;

public:
	person(int, std::string);				//constructor
	virtual ~person();						//destructor
	void setAge(int);						//setter
	void setName(std::string);
	int getAge();							//getter
	std::string getName();
	virtual void proRdnum() = 0;			//virtual, inheritance function
	virtual void do_work() = 0;
	virtual void printInfo();
	virtual void printWork() = 0;

};


#endif