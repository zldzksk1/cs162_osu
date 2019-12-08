/********************************************************************************************************************************************
** Program name: readMatrix.cpp
** Author: Sangyun Lee
** Date: OCT 3 2019
** Description: This void function accepts pointer of pointer to int array and int as parameters.											
**				And, it will ask user to enter integers based on the maxtix size they chosen, and fill the array.						
**				It also validate the user input.																						
** reference: I refer the input validation code from http://www.cplusplus.com/forum/beginner/62834/	
**			  and https://stackoverflow.com/questions/3826281/how-do-i-make-a-c-program-that-filter-out-non-integers
********************************************************************************************************************************************/

#include "readMatrix.hpp"
#include <iostream>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;

void readMatrix(int** arr, int x)
{
	int size = x;
	int userNum;
	int count = 1;																				//this is for numbering the user input


	cout << "Your matrix size is " << size << "x" << size << endl;
	cout << "Please enter " << size * size << " numbers" << endl << endl;


	if (x == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int validation = 1;																	//reset the validation flag
				while (validation)																	//validation the user input
				{
					cout << count << ". enter the number in range -30000 and 30000: ";
					cin >> userNum;																	
																									// if the input larger than 30000, it might have overflow
					if (cin.fail() || userNum < -30000 || userNum > 30000 || cin.get() != '\n')		//if a user enter non integer value or out of the given range 
					{																				//ask another number.		
						cout << "Wrong input, or it is too large or small, please try again." << endl << endl;
						cin.clear();																//clear the cin
						cin.ignore(1000, '\n');														//skip to newline to remove remained wrong input in cin
					}
					else if (typeid(userNum) == typeid(int))										//if everything is okay, then save the input
					{
						arr[i][j] = userNum;
						count++;
						validation = 0;																//end the while loop
					}
				}
			}
		}
	}

	else if(x == 3)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int validation = 1;																	//reset the validation flag
				while (validation)																	//validation the user input
				{
					cout << count << ". enter the number in range -1200 and 1200: ";
					cin >> userNum;																																									// if the input larger than 30000, it might have overflow
																									// if the input ouy of -1200 ~ 1200, it might have overflow on 3x3 matrix
					if (cin.fail() || userNum < -1200 || userNum > 1200 || cin.get() != '\n')		//if a user enter non integer value or out of the given range
					{																				//And ask another number.		
						cout << "Wrong input, or it is too large or small, please try again." << endl << endl;
						cin.clear();																//clear the cin
						cin.ignore(1000, '\n');														//skip to newline to remove remained wrong input in cin
					}
					else if (typeid(userNum) == typeid(int))										//if everything is okay, then save the input
					{
						arr[i][j] = userNum;
						count++;
						validation = 0;																//end the while loop
					}
				}
			}
		}
	}
	
}
