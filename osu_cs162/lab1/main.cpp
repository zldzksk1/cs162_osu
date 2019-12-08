/********************************************************************************************************************************************
** Program name: main()
** Author: Sangyun Lee
** Date: OCT 3 2019
** Description: It is main. cpp where I can test the two function which is readMatrix and determinant.
**				And, necessary variables are created here and pass into the functions.
********************************************************************************************************************************************/

#include <iostream>
#include "determinant.hpp"
#include "readMatrix.hpp"


using std::cout;
using std::cin;
using std::endl;

//enumerate, in order to validate the user input that decides the size of matrix
enum mlevel {
	matrix2 = 1,
	matrix3 = 2,
};

int main()
{
	int level;														//variable to decide the size of matrix
	int size = 0;													//variable to hold size of matrix, initialize with 0
	int resultDtmnt;												//variable to hold the determinant result
	int checkMatrix = 1;

	while (checkMatrix)												// ask user to choose a size of matrix//
	{
		cout << "Please choose size of matrix: " << endl;
		cout << "1. 2x2" << endl;
		cout << "2. 3x3" << endl;
		cin >> level;

		if (cin.fail() || (level < matrix2 || level > matrix3) || cin.get() != '\n')
		{
			cout << "Wrong input, please try again." << endl <<endl;
			cin.clear();											//clear the cin
			cin.ignore(256, '\n');									//ignore numeric value
		}
		else
			checkMatrix = 0;										//if user input are correct, then break the loop
	}

	//set the size of the matrix
	if (level == matrix2)
		size = 2;
	else if (level == matrix3)
		size = 3;


	int** matrix = new int* [size];									 // pointer to pointer to array for 2d array
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];									//initialize the size of the pointer to array.
	}


	readMatrix(matrix, size);										//call readMatrix function to fill up the array

	resultDtmnt = determinant(matrix, size);						//call determinant() to calculate the answer and display the matrix

	
	//display user's matrix;
	cout << endl << "This is the matrix you created" << endl <<endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}

	cout << "Determinant value: " << resultDtmnt << endl;

	//make matrix as null ptr of arr
	for (int i = 0; i < size; i++)
	{
		matrix[i] = nullptr; 
	}
	matrix = nullptr;

	delete[] matrix;												//free the allocated memory
	
	return 0;
}