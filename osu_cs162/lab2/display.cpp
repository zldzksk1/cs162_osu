/********************************************************************************************************************************************
** Program name: display.hpp
** Author: Sangyun Lee
** Date: OCT 8: 2019
** Description: This is display function implementation file. This is for displaying the context of the txt file. Since it take parameter
**				as reference, rewind it before end the function.
** Reference:
********************************************************************************************************************************************/

#include "display.hpp"

void TxtDisplay(std::ifstream& file)
{
	string input;

	cout << endl;
	std::getline(file, input);					// get first line of text file
	while(!file.fail())
	{
		cout << input << endl;					// display text
		std::getline(file, input);				// get next line
	}
	file.clear();								// since it received the ios file as reference,
	file.seekg(0, std::ios::beg);				// rewinds it to the beginning for the next process

	cout << endl;								// for better readability
}
