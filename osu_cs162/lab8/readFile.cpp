/********************************************************************************************************************************************
** Program name: readFile.cpp
** Author: Sangyun Lee
** Date: Nov 19 2019
** Description: This is specification file of readFile fuction. It accepts pointer to 2d vector of int, vector of string
				Using for loop, get text title to open in order. Then push back number onto 2d vector;
********************************************************************************************************************************************/

#include "readFile.hpp"

void readFile(std::vector<std::vector<int>>* vFile, std::vector<std::string> vecTitle)	//prototype of function;
{

	std::fstream inFile;
	std::string container;											//temp container that holds the string num from inFile

	std::cout << "Program is trying to read text files" << std::endl;
	for (int k = 0; k < vecTitle.size(); k++)
	{
		inFile.open(vecTitle[k], std::ios::in);						//get text file;

		if (inFile.fail())
		{
			std::cout << "No such file" << std::endl;
			return;
		}
		else
		{
			std::getline(inFile, container, ' ');						//get line unitl it faces ' '
			(*vFile).push_back(std::vector<int>());						//2d vector declare
			while (!inFile.fail())
			{
				int con = stoi(container);								//string to int
				(*vFile)[k].push_back(con);								//allocate number into vec
				std::getline(inFile, container, ' ');					//get next number
			}
			inFile.clear();
			inFile.close();												//cloase book for the next book
		}
	}
	std::cout << "*Program successfully read all the text files" << std::endl;
}