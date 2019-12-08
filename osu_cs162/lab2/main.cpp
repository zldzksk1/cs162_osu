/********************************************************************************************************************************************
** Program name: main.cpp
** Author: Sangyun Lee
** Date: OCT 8: 2019
** Description:	This is main cpp where all functions are implemented. There are three functions here which are count_letters, output letters
**				and display. Please refer the each function header for more information
** reference: I refered examples on textbooks chapter 13
********************************************************************************************************************************************/

#include "count_letters.hpp"
#include "display.hpp"

int main()
{
	int cFlag = 1;											// flag variable for while loop
	int size = 26;											// array size which is number of alphabet
	int* alphabetInt = new int[size];						// pointer ot int array
	string userTitle;										// string will save the user input
	std::ifstream book;										// open a book 

	cout << "*Welcome to this program*" << endl;
	cout << "Program ask you to enter file name that you want to open," << endl;
	cout << "and it will save each paragraph with a name you provide" << endl;

	do
	{
		cout << "Enter a file name: ";						// ask user to enter their response
		std::getline(cin, userTitle);						// getline and save in userTitle
		userTitle += ".txt";								// add .txt to user input
		book.open(userTitle.c_str(), std::ios::in);			// open file
		
		if (book)											// if open successfully, set the flag = 0
		{													// break while loop
			cFlag = 0;
		}

		if (!book)											// fail to open the file, then ask again
		{
			cout << "The text file you entered can't be opened" << endl;
			cout << "Please check the name, and try again" << endl << endl;
		}

	} while (cFlag);
	
	TxtDisplay(book);										// prompt text
	count_letters(book, alphabetInt);						// call count_letter function
	book.close();											// book close;

	cout << endl;
	cout << "Please check output files" << endl;

	alphabetInt = nullptr;									// make the pointer to null ptr
	delete[] alphabetInt;									// clear the memory

	return 0;
}


