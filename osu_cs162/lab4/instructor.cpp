/*********************************************************************************************************************
** Program: student.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of studennt class. And it is bass class of other classes.
**********************************************************************************************************************/
#include "instructor.hpp"


/*********************************************************************************************************************
** Program: instructor::instructort()
** Description: This is constructor for person class, it accepts two parameter which are int and string, but two variable
**				will be drived from person class. And one double variable for RATE
**********************************************************************************************************************/
instructor::instructor(int a, std::string n) : person(a, n)
{	
	hour = 0;
	rate = 0.0;
}

/*********************************************************************************************************************
** Program: instructor::~instructort()
** Description: This is destructor
**********************************************************************************************************************/
instructor::~instructor()
{
	//destructor
}


/*********************************************************************************************************************
** Program: instructor::setRate()
** Description: This is setter function for Rate variable, it accpets double
**********************************************************************************************************************/
void instructor::setRate(double x)
{
	rate = x;
}

/*********************************************************************************************************************
** Program: student::setHour()
** Description: This is setter function for hour variable, it accpets int
**********************************************************************************************************************/
void instructor::setHour(int time)
{
	hour = time;
}

/*********************************************************************************************************************
** Program: instructor::getRate()
** Description: This is getter function for Rate variable, it return double
**********************************************************************************************************************/
double instructor::getRate()
{
	return rate;
}

/*********************************************************************************************************************
** Program: instructor::printInfo()
** Description: This is void function to print instructor class objects
**********************************************************************************************************************/
void instructor::printInfo()
{
	std::cout << "-Instructor- "<< name << "(" << age << ") " << "RATE: " << rate << std::endl;
}

/*********************************************************************************************************************
** Program: instructor::proRdnum()
** Description: This is to generate the random number for Rate, it returns double
**********************************************************************************************************************/
void instructor::proRdnum()
{
	srand(time(0));
	double x = (double)(rand() % 50) / 10;									//rand() produce random number between 0 and 50, than divide it by 10
	setRate(x);
}

/*********************************************************************************************************************
** Program: instructor::do_work()
** Description: This is to generate the random number for work hours, and prompt the work hours and message
**********************************************************************************************************************/
void instructor::do_work()
{
	srand(time(0));
	int hour = rand() % 40;
	setHour(hour);
}

void instructor::printWork()
{
	std::cout << name << " graded papers for " << hour << " hours." << std::endl;

}