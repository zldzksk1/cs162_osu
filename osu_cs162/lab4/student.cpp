/*********************************************************************************************************************
** Program: student.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of studennt class. And it is bass class of other classes.
** reference: I adopted the code about generating double random number at
**			  stackoverflow.com/questions/452018938/c-generating-a-double-between-2-doubles
**********************************************************************************************************************/
#include "student.hpp"


/*********************************************************************************************************************
** Program: student::student()
** Description: This is constructor for person class, it accepts two parameter which are int and string, but two variable
**				will be drived from person class. And one double variable for GPA
**********************************************************************************************************************/
student::student(int a, std::string n) : person(a, n)
{
	srand(time(NULL));											//random seed
	GPA = 0.0;
	hour = 0;
}

/*********************************************************************************************************************
** Program: student::~student()
** Description: This is destructor
**********************************************************************************************************************/
student::~student()
{
	//destructor
}

/*********************************************************************************************************************
** Program: student::setGPA()
** Description: This is setter function for GPA variable, it accpets double
**********************************************************************************************************************/
void student::setGPA(double score)
{
	GPA = score;
}

/*********************************************************************************************************************
** Program: student::setHour()
** Description: This is setter function for hour variable, it accpets int
**********************************************************************************************************************/
void student::setHour(int time)
{
	hour = time;
}

/*********************************************************************************************************************
** Program: student::getGPA()
** Description: This is getter function for GPA variable, it return double
**********************************************************************************************************************/
double student::getGPA()
{
	return GPA;
}


/*********************************************************************************************************************
** Program: student::printInfo()
** Description: This is void function to print student class objects
**********************************************************************************************************************/
void student::printInfo()
{
	std::cout << "-Student- "<< name << "(" << age << ") " << "GPA: " << GPA << std::endl;
}


/*********************************************************************************************************************
** Program: student::proRdnum()
** Description: This is to generate the random number for GPA
**********************************************************************************************************************/
void student::proRdnum()
{
	double x = (double)(rand() % 40) / 10;							//rand() produce random number between 0 and 41, than divide it by 10
	setGPA(x);
}


/*********************************************************************************************************************
** Program: student::do_work()
** Description: This is to generate the random number for work hours, and prompt the work hours and message
**********************************************************************************************************************/
void student::do_work()
{
	int hour = rand() % 40;											//rand() produce random number between 0 and 40, for hous of work
	setHour(hour);													//set hour variable
}

void student::printWork()
{
	std::cout << name << " did " << hour << " hours of homework." << std::endl;

}