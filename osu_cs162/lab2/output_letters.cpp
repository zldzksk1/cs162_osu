/********************************************************************************************************************************************
** Program name: count_letters.cpp
** Author: Sangyun Lee
** Date: OCT 9: 2019
** Description: This is count_letters function implementation file. The function recieve ifstream variable as reference, and point to array
**				Once it receive the ifstream file, it save the file with the file name given by users
** Reference:
********************************************************************************************************************************************/

#include "output_letters.hpp"

void output_letters(std::ofstream& file, int* arr) 
{
	static int count = 1;
	string fileName;
	string alphbetStr = "abcdefghijklmnopqrstuvwxyz";					// string variable 

	cout << count << "p. Enter a file name you want to save: ";			// ask user a file name
	std::getline(cin, fileName);
	fileName += ".txt";													// in order to save as txt file

	file.open(fileName.c_str(), std::ios::out);							// open output file

	for (int i = 0; i < alphbetStr.length(); i++)
	{
		file << alphbetStr[i] << ": " << arr[i] << endl;
	}
	count++;
}
