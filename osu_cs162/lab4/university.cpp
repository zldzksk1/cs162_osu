/*********************************************************************************************************************
** Program: university.hpp
** Author: Sangyun Lee
** Date: Oct 23 2019
** Description: This is specfriciation file of university class. And it is bass class of other classes.
**********************************************************************************************************************/

#include"university.hpp"

/*********************************************************************************************************************
** Program: university::~university()
** Description: This is constuctor, it initialize three variables
**********************************************************************************************************************/
university::university()
{
	uName = "Oregone State University";
	numBilding = 0;
	numPeople = 0;
}

/*********************************************************************************************************************
** Program: university::~university()
** Description: This is destructor
**********************************************************************************************************************/
university::~university()
{
	//desturctor
}

/*********************************************************************************************************************
** Program: university::setUname()
** Description: This is setter to set up the uName variable of university class, it accpets string
**********************************************************************************************************************/
void university::setUname(std::string x)
{
	uName = x;
}

/*********************************************************************************************************************
** Program: university::setNumB()
** Description: This is setter to set up the numBilding variable of university class, it is total number of building
**********************************************************************************************************************/
void university::setNumB(std::vector<std::shared_ptr<building>> x)
{
	numBilding = x.size();												//vector of pointer to building class, 
																		//and get vector.size() to see how many objects it has
}

/*********************************************************************************************************************
** Program: university::setNumP()
** Description: This is setter to set up the numPeople variable of university class, it is total number of people
**********************************************************************************************************************/
void university::setNumP(std::vector<std::shared_ptr<person>> y)
{
	numPeople = y.size();												//vector of pointer to person class, 
}																		//and get vector.size() to see how many objects it has

/*********************************************************************************************************************
** Program: university::getUname()
** Description: This is getter to get uName of university class.
**********************************************************************************************************************/
std::string university::getUname()
{
	return uName;														//return string
}

/*********************************************************************************************************************
** Program: university::getNumB()
** Description: This is getter to get number of building of university class. which is size of vector of pointer to building class
**********************************************************************************************************************/
int university::getNumB()
{
	return numBilding;
}

/*********************************************************************************************************************
** Program: university::getNumP()
** Description: This is getter to get number of people of university class. which is size of vector of pointer to person class
**********************************************************************************************************************/
int university::getNumP()
{
	return numPeople;
}


/*********************************************************************************************************************
** Program: university::setupB()
** Description: This is to declare objects of the vector shared_ptr to building class
**********************************************************************************************************************/
std::vector<std::shared_ptr<building>> university::setupB()
{
	osuBuilding =
	{
		std::make_shared<building>("Kearney Hall", "1491 SW CAMPUS WAY, CORVALLIS OR", 26919),			//hard coding to set variable
		std::make_shared<building>("Graf Hall", "1680 SW MONROE AVE, CORVALLIS OR", 38221),
		std::make_shared<building>("Coveel Hall","1691 SW CAMPUS WAY",35760),
	};
	
	this->setNumB(osuBuilding);																			//set number of building
	return osuBuilding;
}


/*********************************************************************************************************************
** Program: university::setupP()
** Description: This is to declare objects of the vector shared_ptr to person class
**********************************************************************************************************************/
std::vector<std::shared_ptr<person>> university::setupP()
{
	people =
	{
		std::make_shared<student>(19, "Jessica Dobson"),												//hard coding to set variable
		std::make_shared<instructor>(43, "Berry Lison"),												
	};

	this->setNumP(people);																				//set number of building

	int size = people.size();															//vector size
	for (int i = 0; i < size; i++)														//iterate
	{
		people[i]->proRdnum();															//generate randome number for GPA and Rate, and set its value
		people[i]->do_work();
	}
	return people;
}

/*********************************************************************************************************************
** Program: university::schoolInfo()
** Description: This is to iterate the vector of pointer to building class, and display contents of it by using
**				printBinfo()
**********************************************************************************************************************/
void university::schoolInfo(std::vector<std::shared_ptr<building>> x)
{
	int size = x.size();															//vector size
	for (int i = 0; i < size; i++)													//iterate
	{
		std::cout << i + 1 << ". " << std::endl;									//for numbering
		x[i]->printBinfo();
		std::cout << "-" << std::endl;
	}
}

/*********************************************************************************************************************
** Program: university::printPeople()
** Description: This is to iterate the vector of pointer to person class, and display contents of it by using
**				printBinfo()
**********************************************************************************************************************/
void university::printPeople(std::vector<std::shared_ptr<person>> x)
{
	int size = x.size();															//vector size
	for (int i = 0; i < size; i++)													//iterate
	{
		x[i]->printInfo();															//print content of the person objects
	}
		
}

/*********************************************************************************************************************
** Program: university::workPeople()
** Description: This is to display the name of person class object. This is type of menu function to display options
**				user can choose
**********************************************************************************************************************/
void university::workPeople(std::vector<std::shared_ptr<person>> x)
{
	int size = x.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		std::cout << x[i]->getName() << std::endl;

	}
}

/*********************************************************************************************************************
** Program: university::playUniv()
** Description: This is to initiate all class objects and play the university information system which people can get
**				building infomation and member infomation
**********************************************************************************************************************/
void university::playUniv()
{
	bool exitP = false;									//while loop flag = false
	this->setupB();										//initiate the building class objects
	this->setupP();										//initiate the person class objects

	do
	{

		enum option { display };						
			
		int choice = menu(option::display);				//display menu, that people can choose

		if (choice == 1)								//if users choose 1, then prompt number of building and building information
		{
			std::cout << "Total number of building: " << this->getNumB() << std::endl;
			schoolInfo(osuBuilding);
			std::cout << endl;
		}

		else if (choice == 2)							//if users choose 2, then prompt number of memebers and there information
		{
			std::cout << "Total number of member: " << this->getNumP() << std::endl;
			printPeople(people);
			std::cout << endl;
		}

		else if (choice == 3)							//if users choose 3, then prompt another option they can choose for further process
		{
			std::cout << "Please choose a person to do work" << endl;
			workPeople(people);							//prompt options they can select
			int subChoise = getInput(this->getNumP());	//input validation
			people[subChoise - 1]->printWork();			//prompt proper output
			std::cout << std::endl;
		} 

														//if users choose 4, close program
		else if (choice == 4)
		{
			std::cout << "Thank you for using this program" << std::endl;
			exitP = true;
		}
	} while (!exitP);

}

