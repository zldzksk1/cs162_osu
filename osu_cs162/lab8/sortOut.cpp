/********************************************************************************************************************************************
** Program name: sortOut.cpp
** Author: Sangyun Lee
** Date: Nov 19 2019
** Description: This is header file of sortOut.hpp.
** Reference: I adopt the code from Text book: Chapter 9.5 pg 625 ~ 626
********************************************************************************************************************************************/

#include "sortOut.hpp"

void sortOut(std::vector<std::vector<int>>* vecArr, std::vector<std::string>& uTitle, int vecSize)
{
	std::fstream outFile;
	std::string outTitle;
	int temp;
	int countOut = 1;																//count helper to let users know what number of book they are saving
	bool swap;

	std::cout << "Program will sort the numbers and save it as the file name of your choice" << std::endl;
//step 1: sort vector
	do 
	{
		swap = false;																//while loop checker;
		for (int i = 0; i < vecSize; i++)											//since it is 2d vector, for loop for row
		{
			for (int j = 0; j < (*vecArr)[i].size()-1; j++)							//for loop for col
			{
				if ((*vecArr)[i][j] > (*vecArr)[i][j + 1])							//if lvalue is greather than right
				{
					temp = (*vecArr)[i][j];											//swap it
					(*vecArr)[i][j] = (*vecArr)[i][j + 1];
					(*vecArr)[i][j + 1] = temp;
					swap = true;													//and flag swap, so it can be looping until no swap happend
				}
			}
		}
	} while (swap);

// step 2: output file 

	for (int i = 0; i < vecSize; i++)
	{
		std::cout << countOut << ". Enter a file name you want to save: ";						//prompt msg
		std::getline(std::cin,outTitle);														//get response from user
		outTitle += ".txt";																		// user response + txt
		uTitle.push_back(outTitle);																// save user title into title vector

		outFile.open(outTitle.c_str(), std::ios::out);											//out book open
		std::cout << "Sorted number: ";
		for (int j = 0; j < (*vecArr)[i].size(); j++)
		{
			outFile << (*vecArr)[i][j] << ' ';													//save sorted number
			std::cout << (*vecArr)[i][j] << " ";												//display sorted number
		}
		std::cout << std::endl;		
		countOut++;																				//count ++
		outFile.close();																		//book close if the row end;
	}
		

}

