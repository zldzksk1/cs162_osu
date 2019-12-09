/*********************************************************************************************************
** Program: zoo.hpp
** Author: Sangyun Lee
** Date: OCT 22 2019
** Description: This is zoo.hpp specification file which you can see all variables and functions
** Reference: I found how to create array of pointers to object. And refer the code on the website.
**			java2s.com/tutorial/Cpp/010__Class/Anarrayofpointerstoobjects.htm
**********************************************************************************************************/

#include "zoo.hpp"

/*********************************************************************************************************
** Program: zoo::zoo()
** Description: This is constructor of zoo class, it initialize necessary variables.
**				Here, dynamic arrays are set up first here for each animal
**********************************************************************************************************/

zoo::zoo()
{
	day = 1;
	totalIncome = 0;
	setSaving(100000);															//set inital saving account

	cageSizeT = 10;																//set dynamic array
	tigerCage = new tiger[cageSizeT];
	totalT = 0;

	cageSizeP = 10;
	penguinCage = new penguin[cageSizeP];
	totalP = 0;

	cageSizeR = 10;
	turtleCage = new turtle[cageSizeR];
	totalR = 0;


}

/*********************************************************************************************************
** Program: zoo::~zoo()
** Description: This is destructor, to delete the dynamic arrays.
** reference: My TA recommend me to use destructor to prevent memory leak
**********************************************************************************************************/
zoo::~zoo()
{
	for (int i = 0; i < this->getTpop(); i++)
	{
		tigerCage[i].setAge(0);													//since nullptr is not allowed here, just make it as 0 and delete
	}
	delete[] tigerCage;

	for (int i = 0; i < this->getPpop(); i++)
	{
		penguinCage[i].setAge(0);												//since nullptr is not allowed here, just make it as 0 and delete
	}
	delete[] penguinCage;
	
	for (int i = 0; i < this->getRpop(); i++)
	{
		turtleCage[i].setAge(0);												//since nullptr is not allowed here, just make it as 0 and delete
	}
	delete[] turtleCage;
}

/*********************************************************************************************************
** Program: zoo::setSaving()
** Description: This is set function to set the saving variable
**********************************************************************************************************/
void zoo::setSaving(int x)
{
	saving = x;
}

/*********************************************************************************************************
** Program: zoo::getSaving()
** Description: This is get function, it returns the saving value
**********************************************************************************************************/
int  zoo::getSaving()
{
	return saving;
}

/*********************************************************************************************************
** Program: zoo::getDay()
** Description: This is get function, it returns the day value
**********************************************************************************************************/
int zoo::getDay()
{
	return day;
}

/*********************************************************************************************************
** Program: zoo::getTpop()
** Description: This is get function, it returns the totalT value
**********************************************************************************************************/
int zoo::getTpop()
{
	return totalT;
}

/*********************************************************************************************************
** Program: zoo::getPpop()
** Description: This is get function, it returns the totalP value
**********************************************************************************************************/
int zoo::getPpop()
{
	return totalP;
}

/*********************************************************************************************************
** Program: zoo::getRpop()
** Description: This is get function, it returns the totalR value
**********************************************************************************************************/
int zoo::getRpop()
{
	return totalR;
}
/*********************************************************************************************************
** Program: zoo::getCageT()
** Description: This is get function, it returns the cageSizeT value
**********************************************************************************************************/
int zoo::getCageT()
{
	return cageSizeT;
}

/*********************************************************************************************************
** Program: zoo::cageSizeP()
** Description: This is get function, it returns the cageSizeP value
**********************************************************************************************************/
int zoo::getCageP()
{
	return cageSizeP;
}

/*********************************************************************************************************
** Program: zoo::cageSizeR()
** Description: This is get function, it returns the cageSizeR value
**********************************************************************************************************/
int zoo::getCageR()
{
	return cageSizeR;
}

/*********************************************************************************************************
** Program: zoo::buyAnm()
** Description: This is function to decide what animal users want to buy.
** implementation: I used the menu and getInput function I created before, but my two functions designed
**				   for integer value, therefore, after receive a interger then cast it here into char.
**				   and it will pass to addAnimal function
**********************************************************************************************************/
char zoo::buyAnm()
{
	char x = static_cast<char>(menu(process::buyAnimal));									//it casted to int at getInput func, so get it back to char
	return x;
}

/*********************************************************************************************************
** Program: zoo::buyHmany()
** Description: This is function to decide what animal users want to buy.
** implementation: I used the menu and getInput function I created before, it will pass to addAnimal function
**********************************************************************************************************/
int zoo::buyHmany()
{
	int x = menu(process::howMany);
	return x;
}



/*********************************************************************************************************
** Program: zoo::gameStart()
** Description: Game starter, this function ask user to set up the initial game stage by adopting animals.
**				howMnay(), addAnimal() are used here
**********************************************************************************************************/
void zoo::gameStart()
{
	int x = 0;

	cout << "**********  Welcome to the Zoo Tycoon! ***********" << endl;					//prompt welcome message
	cout << "**                                              **" << endl;
	cout << "**  It is time to run your zoo!, do your best   **" << endl; 
	cout << "**          to have a wonderful Zoo!            **" << endl;
	cout << "**   Now you have $100,000 in saving accout.    **" << endl;
	cout << "**  To start the game, you should adopt Tiger,  **" << endl; 
	cout << "**              Penguin and Tutle!              **" << endl; 
	cout << "**                                              **" << endl;
	cout << "**************************************************" << endl;
	cout << endl;

	cout << "**************************************************" << endl;
	cout << "**           First, let's adopt tiger!          **" << endl;					//adopt animals
	cout << "**************************************************" << endl;
	x = buyHmany();																			//get input and validate
	addAnimal('t', x);																		//pass info to addAnimal()
																							//order of tiger, penguin and turtle
	cout << "**************************************************" << endl;
	cout << "**          Next, let's adopt Penguin!          **" << endl;
	cout << "**************************************************" << endl;
	x = buyHmany();
	addAnimal('p', x);

	cout << "**************************************************" << endl;
	cout << "**       Almost ready, let's adopt Turtle!      **" << endl;
	cout << "**************************************************" << endl;
	x = buyHmany();
	addAnimal('r', x);

	cout << "**                  Game Start!                 **" << endl << endl;

}

/*********************************************************************************************************
** Program: zoo::closingDay()
** Description: This prompt the game summury of the day, and ask user to adopt an adult animal or not
**********************************************************************************************************/
void zoo::closingDay()																		
{																							//prompt summary of the game
	cout << "**                                              **" << endl;
	cout << "**           Day: " << day <<", service is closed!         **" << endl;
	cout << "**                                              **" << endl;
	cout << "**               Summary of Today               **" << endl;
	cout << "**    Tigers in Cage: " << totalT <<"                         **" << endl;
	cout << "**    Penguins in Cage: " << totalP << "                       **" << endl;
	cout << "**    Turtles in Cage: " << totalR << "                        **" << endl;
	cout << "**    Income(No Bonus): " << totalIncome << std::setw(22)<< "**" << endl;
	cout << "**    Total Food cost: " << totalFcost()<< std::setw(24) << "**" << endl;
	cout << "**    Balance: " << getSaving() << std::setw(30)<<"**" << endl;
	cout << "**                                              **" << endl;
	cout << "**************************************************" << endl;

	this->buyAdult();																		//ask user to adopt an adult animal
}


/*********************************************************************************************************
** Program: zoo::addAnimal()
** Description: This function to add animal at beginning process and when they have a baby
** Implementation: It accepts char and int as parameter. Char represent the type of animal, and num is
**				   number of animals need to be added.
**********************************************************************************************************/
void zoo::addAnimal(char type, int num)
{
	if (type == 't')																		//if it is tiger
	{
		totalT = this->getTpop() + num;														//add number of tiger to total number of tiger
		if (totalT > cageSizeT)																//if cage(array) is small then call buildCage()
		{
			buildCage(type, num);
		}

		saving -= tigerCage[0].getCost() * num;												//update the balance
	}

	else if (type == 'p')																	//same process for penguin
	{
		totalP = this->getPpop() + num;
		if (totalP > cageSizeP)
		{
			buildCage(type, num);
		}

		saving -= penguinCage[0].getCost() * num;
	}

	else if (type == 'r')																	//same process for turtle
	{
		totalR = this->getRpop() + num;
		if (totalR > cageSizeR)
		{
			buildCage(type, num);
		}

		saving -= turtleCage[0].getCost() * num;
	}
}

/*********************************************************************************************************
** Program: zoo::agingAnm()
** Description: Everyday, animals get one day age.
**********************************************************************************************************/
void zoo::agingAnm()
{																							//tiger
	for (int i = 0; i < totalT; i++)														//getting total population of tiger
		tigerCage[i].setAge(tigerCage[i].getAge() + 1);										//add 1 for each 

	for (int i = 0; i < totalP; i++)														//penguin
		penguinCage[i].setAge(penguinCage[i].getAge() + 1);

	for (int i = 0; i < totalR; i++)														//turtle
		turtleCage[i].setAge(turtleCage[i].getAge() + 1);
}

/*********************************************************************************************************
** Program: zoo::feedingAnm()
** Description: Everyday, animals need to be feeded. It gets food cost from animal class and its derive class
**********************************************************************************************************/
void zoo::feedingAnm()						
{
	if (totalT != 0)																		//if there is animals
		saving -= totalT * tigerCage[0].getFcost();											//get food cost and time with number of animals
																							//and deduct from saving account
	if (totalP != 0)
		saving -= totalP * penguinCage[0].getFcost();

	if (totalR != 0)
		saving -= totalR * turtleCage[0].getFcost();
}

/*********************************************************************************************************
** Program: zoo::buildCage()
** Description: If animalCage(array) is small to contain all animals, then expand it. It accepts two parameters
**				char is to distinguish the animal type, and int is for number of animals need to be added
**********************************************************************************************************/
void zoo::buildCage(char type, int newAnm)
{
	if (type == 't')																		//if it is tiger
	{
		cageSizeT *= 2;																		//double the array size
		int oldCage = totalT - newAnm;														//build temp array to contain value
		int* tempCage = new int[oldCage];
		for (int i = 0; i < oldCage; i++)
		{
			tempCage[i] = tigerCage[i].getAge();											//move to animals(variables) to temp array
		}

		delete[] tigerCage;																	//delete old array

		tigerCage = new tiger[cageSizeT];													//build new array with bigger size
		for (int i = 0; i < cageSizeT; i++)
		{
			tigerCage[i].setAge(tempCage[i]);												//move value to new array
		}
	
		delete[] tempCage;																	//delete temp
																							//let user the cage is expanded
		cout << "   [New cage, now you can have " << this->getCageT() << " tigers here]" << endl << endl;
	}

	else if (type == 'p')																	//this is for penguin
	{
		cageSizeP *= 2;
		int oldCage = totalP - newAnm;
		int* tempCage = new int[oldCage];
		for (int i = 0; i < oldCage; i++)
		{
			tempCage[i] = penguinCage[i].getAge();
		}

		delete[] penguinCage;

		penguinCage = new penguin[cageSizeP];
		for (int i = 0; i < cageSizeP; i++)
		{
			penguinCage[i].setAge(tempCage[i]);
		}
		
		delete[] tempCage;

		cout << "   [New cage!, now you can have " << this->getCageP() << " penguins here]" << endl << endl;
	}

	else if (type == 'r')																		//This is for turtle
	{
		cageSizeR *= 2;
		int oldCage = totalR - newAnm;
		int* tempCage = new int[oldCage];
		for (int i = 0; i < oldCage; i++)
		{
			tempCage[i] = turtleCage[i].getAge();
		}

		delete[] turtleCage;

		turtleCage = new turtle[cageSizeR];
		for (int i = 0; i < cageSizeR; i++)
		{
			turtleCage[i].setAge(tempCage[i]);
		}
			
		delete[] tempCage;

		cout << "   [New cage!, now you can have " << this->getCageR() << " turtles here]" << endl << endl;
	}
}

/*********************************************************************************************************
** Program: zoo::caltotalIncome()
** Description: This func is to calculate the total pay off of animals
**********************************************************************************************************/
int zoo::caltotalIncome()
{
	int tIncome = totalT * tigerCage[0].getPayoff();										//get payoff of tiger * total tiger
	int pIncome = totalP * penguinCage[0].getPayoff();										//get payoff of penguin * total penguin
	int rIncome = totalR * turtleCage[0].getPayoff();										//get payoff of turtle * total turtle

	totalIncome = tIncome + pIncome + rIncome;											//put them all together
	saving += totalIncome;
	return totalIncome;																		//return it
}

/*********************************************************************************************************
** Program: zoo::totalFcost()
** Description: This func is to calculate the total food cost of animals
**********************************************************************************************************/
int zoo::totalFcost()
{
	int foodT = totalT * tigerCage[0].getFcost();											//get food cost of tiger * total tiger
	int foodP = totalP * penguinCage[0].getFcost();											//get food cost of penguin * total penguin
	int foodR = totalR * turtleCage[0].getFcost();											//get food cost of turtle * total turtle
	
	int totalFcost = foodT + foodP + foodR;													//put them all together
	return totalFcost;																		//return it
}


/*********************************************************************************************************
** Program: zoo::setZevent()
** Description: This func is to generate the random event.
** Implementation: rand() generate the random number for event type and animals. For convenience, I use
**				   enum data tye
** reference: I noticed that if I used only rand(), it always generate randdom numbers with certain pattern.
**			  so I used srad(), I adopted a code from cplusplus.com/reference/cstdlib/rand/
**********************************************************************************************************/
void zoo::setZevent()
{
	std::fstream eventMsg("event.txt", std::ios::out);

	cout << "********************** Day " << day << " *********************" << endl;
	cout << "**                                              **" << endl;
	cout << "**              Event is happening!             **" << endl;

	enum Event {sick = 1, baby, boom, nope};												//this is for type of event
	enum Animals {tiger = 1, penguin, turtle};												//this is for selecting animals

	srand(time(NULL));
	int E = rand() % 4 + 1;																	//generate the random number for event type

	if (E == Event::sick)																	//event sick
	{
		int A = rand() % 3 + 1;																//generate random number for animals
		if (A == Animals::tiger)															//if it is tiger
		{
			if (this->getTpop() != 0)
			{
				cout << "**     Your tiger got sick. A tiger is gone     **" << endl;		//prompt display
				tigerCage[totalT - 1].setAge(0);											//remove one tiger
				totalT -= 1;
			}

			else if (this->getTpop() == 0)													//if there is no tiger, then no one get sick
			{
				cout << "**  No tigers, so tiger disease has no effects  **" << endl;
			}
		}

		else if (A == Animals::penguin)														//same process for penguin
		{
			if (this->getPpop() != 0)
			{
				cout << "**   Your penguin got sick. A penguin is gone   **" << endl;
				penguinCage[totalP - 1].setAge(0);
				totalP -= 1;
			}
			else if (this->getPpop() == 0)
			{
				cout << "**    No penguin, so disease has no effects     **" << endl;
			}
		}

		else if (A == Animals::turtle)														//same process for turtle
		{
			if (this->getRpop() != 0)
			{
				cout << "**    your turtle got sick. A turtle is gone    **" << endl;
				turtleCage[totalR - 1].setAge(0);
				totalR -= 1;
			}

			else if (this->getRpop() == 0)
			{
				cout << "**    No turtles, so disease has no effects     **" << endl;
			}
		}
	}


	else if (E == Event::baby)																//event baby
	{
		bool babyBoarn = false;																//flag
		//while (!babyBoarn)									
		//{
		int A = rand() % 3 + 1;															//random number for animal
			if (A == Animals::tiger)
			{
				for (int i = 0; i < totalT; i++)
				{
					if (tigerCage[i].getAge() >= 3)										//any of tigers are 3 years old
						babyBoarn = true;													//then set the flag
				}

				if (babyBoarn == true)
				{	
					int num = tigerCage->getNumBb();										//get number of baby
					cout << "**    Congratuation!, your tiger has a baby!    **" << endl;	//prompt
					totalT = this->getTpop() + num;											//add to total
					if (totalT > cageSizeT)													//if cage is small to have baby
					{
						buildCage('t', num);												//expand the cage
					}
				}

				else if (babyBoarn == false)												//if no baby born
				{
					cout << "**   Your tigers are too young to have babies   **" << endl;	//prompt
					babyBoarn = true;														//and set flag to break
				}

			}

			else if (A == Animals::penguin)													//same for penguin
			{
				for (int i = 0; i < totalP; i++)
				{
					if (penguinCage[i].getAge() >= 3)
						babyBoarn = true;
				}

				if (babyBoarn == true)
				{
					int num = penguinCage->getNumBb();
					cout << "**   Congratuation!, your penguin has babies!   **" << endl;
					totalP = this->getPpop() + num;
					if (totalP > cageSizeP)
					{
						buildCage('p', num);
					}
				}

				else if (babyBoarn == false)
				{
					cout << "**  Your penguins are too young to have babies  **" << endl;
					babyBoarn = true;
				}
			}

			else if (A == Animals::turtle)													//same for turtle
			{
				for (int i = 0; i < totalR; i++)
				{
					if (turtleCage[i].getAge() >= 3)
						babyBoarn = true;
				}

				if (babyBoarn == true)
				{
					int num = turtleCage->getNumBb();
					cout << "**   Congratuation!, your turtle has babies!    **" << endl;
					totalR = this->getRpop() + num;
					if (totalR > cageSizeR)
					{
						buildCage('r', num);
					}
				}
				else if (babyBoarn == false)
				{
					cout << "**  Your turtles are too young to have babies   **" << endl;
					babyBoarn = true;
				}
				
			}
				
		//}
		
	}

	else if (E == Event::boom)																		//event boom audience
	{
	int bonus = 0;																					//notice the rand() is working weird, it generate larger than 500 some reason
		do																							//so do while, to prevent from unwanted value
		{
			bonus = rand() % 500 + 250;																	//generate random income
		} while (bonus >= 500);

		int totalBonus = bonus * this->getTpop();
		saving += totalBonus;																		//add to saving account
	
		cout << "**    Group of people visted your Zoo Today!    **" << endl;
		cout << "**          You made additional $" << totalBonus << "!           **" << endl;		//display how much bonus
	}

	else if (E == Event::nope)																		//no event
	{
		cout << "**          Today went slow [no event]          **" << endl;
		//do not thing
	}
}

/*********************************************************************************************************
** Program: zoo::setZevent()
** Description: This func is to ask user to add adult animal or not.
** Implementation: getting input and validate the input on menu func & getInput func
**********************************************************************************************************/
void zoo::buyAdult()
{
	cout << "-It is time to add more animal to your zoo!" << endl;							//prompt message
	cout << "-Do you want to add an adult animal in your cage?" << endl;
	int check = menu(process::checking);													//getting input and validate

	if (check == 1)																			//if they want to add an adult animal, choose 1
	{
		char x = static_cast<char>(menu(process::buyAnimal));

		if (x == 't')																		//tiger
		{
			totalT += 1;																	//add one into total tiger
			if (totalT > cageSizeT)															//if cage is small
			{
				buildCage('t', 1);															//build new one
				tigerCage[(this->getTpop()) - 1].setAge(3);									//and bring 3 years old tiger into the new cage
			}
			else
				tigerCage[(this->getTpop()) - 1].setAge(3);									//if cage has space, then just bring new tiger
			saving -= tigerCage[0].getCost();													//deduct the cost from saving
		}

		else if (x == 'p')																	//same process for penguin
		{
			totalP += 1;
			if (totalP > cageSizeP)
			{
				buildCage('p', 1);
				penguinCage[(this->getPpop()) - 1].setAge(3);

			}
			else
				penguinCage[(this->getPpop()) - 1].setAge(3);
			saving -= penguinCage[0].getCost();
		}

		else if (x == 'r')																	//same process for turtle
		{
			totalR += 1;
			if (totalR > cageSizeR)
			{
				buildCage('r', 1);
				turtleCage[(this->getRpop()) - 1].setAge(3);

			}
			else
				turtleCage[(this->getRpop()) - 1].setAge(3);
			saving -= turtleCage[0].getCost();
		}

	}

	else if (check == 2)																	//don't want to buy, then select 2
	{
		cout << "You don't have to buy one now!" << endl << endl;
	}
}

/*********************************************************************************************************
** Program: zoo::playgame()
** Description: void function to play zoo tycoon game. most of funcs are used here.
**********************************************************************************************************/
void zoo::playgame()
{
	int playCheck = 1;																		//while loop checker
	gameStart();																			//call function

	while (playCheck == 1)
	{
		setZevent();
		agingAnm();																			//functions were ordered by the instructions given by instructor
		feedingAnm();
		caltotalIncome();
		cout << "**          You made $" << totalIncome << " except bonus         **" << endl;
		closingDay();

		cout << "**************************************************" << endl;
		cout << "**          Run your zoo is not easy!           **" << endl;
		cout << "**************************************************" << endl;
		cout << "-Do you want to run your zoo tomorrow as well?" << endl;
		playCheck = menu(process::checking);												//if user don't want to play game, then mark here
		day++;																				//increase the day for tomorrow
		if (this->getSaving() < 0)															//if balance is less than 0, then close the program 
		{
			cout << "**************************************************" << endl;
			cout << "**      Out of funds, close your bussiness!     **" << endl;
			cout << "**************************************************" << endl;
			playCheck = 0;
		}

	}

	cout << "**************************************************" << endl;					//program close
	cout << "**      Thank you for playing Zoo Tycoon!       **" << endl;
	cout << "**           Hope to see you again!             **" << endl;
	cout << "**************************************************" << endl;
}
