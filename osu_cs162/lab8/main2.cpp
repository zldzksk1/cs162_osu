
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "readFile.hpp"
#include "simpleSearch.hpp"
#include "sortOut.hpp"
#include "biSearch.hpp"
#include "getInput.hpp"

enum userAsk
{
	play,
	askNum,
};

int main()
{
	int const vecSize = 4;
	int userVal;
	int playCheck;
	std::vector<std::vector<int>>* vec = new std::vector<std::vector<int>>(vecSize);			//2d vector
	std::vector<std::string> title = { "original.txt", "early.txt", "middle.txt", "end.txt" };	//these are the initial text files' title
	std::vector<std::string> userTitle = {};													//it will contain the titles of user entered later
	
	std::cout << "Welcome to read and sort program" << std::endl;
	std::cout << "1. Start" << std::endl;
	std::cout << "2. Close" << std::endl;
	playCheck = getInput(userAsk::play);

	while(playCheck == 1)
	{
	readFile(vec, title);																		//read file and put numbers into vector


	std::cout << "Enter a number you want to look up" << std::endl;
	userVal = getInput(userAsk::askNum);
	std::cout << std::endl;

	simpleSearch(vec, title, userVal);
	std::cout << std::endl;
	
	sortOut(vec, userTitle, vecSize);
	std::cout << std::endl;

	std::cout << "File list is updated with files you saved" << std::endl;
	std::cout << std::endl;

	readFile(vec, userTitle);																	//read value from user saved file
	std::cout << std::endl;

	std::cout << "Enter a number you want to look up using binary search" << std::endl;
	userVal = getInput(userAsk::askNum);
	std::cout << std::endl;

	biSearch(vec, userTitle, userVal);
	std::cout << std::endl;

	std::cout << "Want to try one more time?" << std::endl;
	std::cout << "1. Start" << std::endl;
	std::cout << "2. Close" << std::endl;
	playCheck = getInput(userAsk::play);
	}

// prompt close msg and free the 2d vector
	std::cout << "Thank you for using my program" << std::endl;

	for (int i = 0; i < vecSize; i++)
	{
		(*vec)[i].erase((*vec)[i].begin(), (*vec)[i].end());
		(*vec)[i].shrink_to_fit();
	}



	return 0;
}
