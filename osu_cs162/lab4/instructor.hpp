/*********************************************************************************************************************
** Program: student.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of studennt class. And it is bass class of other classes.
**********************************************************************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"

class instructor : public person
{
private:
	double rate;
	int hour;
public:
	instructor(int, std::string);
	~instructor();
	void setRate(double);
	void setHour(int);
	double getRate();
	void proRdnum();
	void do_work();
	void printInfo();
	void printWork();
};
#endif // !INSTRUCTOR_HPP
