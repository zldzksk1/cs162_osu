/********************************************************************************************************************************************
** Program name: count_letters.cpp
** Author: Sangyun Lee
** Date: OCT 9: 2019
** Description: This is count_letters function implementation file. The function recieve ifstream variable as reference, and point to array
**				Once it receive the ifstream file, it counts the letter and save the count into arr. Then pass it to different function 
**				for the further process
** Reference:
********************************************************************************************************************************************/

#include "count_letters.hpp"

void count_letters(std::ifstream& file, int* arr)
{
	int charCount = 0;												// variable that contain number of letter count
	int* tempArr = arr;												// point to array that contain the argument, since I pass it to another function here
	char ch;														// char varaible will contain single letter to compare it with alphabet
	string alphbetStr = "abcdefghijklmnopqrstuvwxyz";				// string variable 
	string input;													// string variable that hold ifsream context
	std::ofstream bookOut;											// declare ofstream file to save the letter counts 

	std::getline(file, input);										// get first line of text file
	while (file)
	{
		for (int i = 0; i < alphbetStr.length(); i++)				//iterate the all alphabet
		{
			for (int j = 0; j < input.length(); j++)
			{
				ch = input[j];										// get a single char from the input text
				ch = tolower(ch);									// make it lower case
				if (ch == alphbetStr[i])							// compare it with alphabet
				{
					charCount++;									// if it matchs, count 1
				}
			}
			tempArr[i] = charCount;									// save to array
			charCount = 0;											// reset count
		}
		output_letters(bookOut, tempArr);							// pass it to output_letter function to save it
		bookOut.close();											// close output file for the next file
		std::getline(file, input);									// get next line

		

		if (input.size() == 1)										// if input consist of only '\n', string size == 1 on vim
		{															// if the next line is line break
			std::getline(file, input);								// move to the next line
		}
	}
}


