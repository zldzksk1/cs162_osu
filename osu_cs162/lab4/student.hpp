/*********************************************************************************************************************
** Program: student.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of studennt class. And it is derived class of person class.
**********************************************************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "person.hpp"

class student : public person
{
private:
	double GPA;
	int hour;

public:
	student(int, std::string);
	~student();
	void setGPA(double);
	void setHour(int);
	double getGPA();
	void proRdnum();
	void do_work();
	void printInfo();
	void printWork();
};

#endif // !STUDENT_HPP
