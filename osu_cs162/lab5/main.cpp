/*****************************************************************************************************************************
** Program: reverse.hpp
** Author: Sangyun Lee
** Date: Oct 28 2019
** Description: This is implementation file of reverse function. It accepts string variable, and reverse the context of string
				and display it.
**
******************************************************************************************************************************/
#include "reverse.hpp"
#include "arrSum.hpp"
#include "triAnglular.hpp"
#include "menu.hpp"
#include "getInput.hpp"
#include "fillArr.hpp"


int main()
{
	enum calProcess { menuDis, ssReverse, arrCalSum, triAngleSum };					//enum data type for specification
	bool programRun = true;															//while loop flag

	std::cout << "Welcome to my program!" << std::endl;								//welcome msg
	do
	{
		int choice = menu(calProcess::menuDis);										//display options they can choose

		if (choice == 1)															//if they choose sentence reverse program
		{
			std::string ss;															//string variable

			std::cout << "Please enter any sentence:" << std::endl;					//display msg
			std::getline(std::cin, ss);												//get an input
			std::cout << std::endl;
			std::cout << "Reversed: " << std::endl;
			reverse(ss);															//call recursive funtion
		}

		else if (choice == 2)														//if users choose array calculation
		{
			int arrSize;															//declare necessary variables
			int result;					

			arrSize = menu(calProcess::arrCalSum);									//display msg and get an input

			int* arraySum = new int[arrSize];										//dynamic array
			fillArr(arraySum, arrSize);

			result = arrSum(arraySum, arrSize);										//save the ouput from reculsive function to result varaible
			std::cout << "sum: " << result << std::endl;													//display the result

			arraySum = nullptr;														//deallocate the memory
			delete[] arraySum;
		}

		else if (choice == 3)														//if they choose trianglular
		{
			int baseNum;															//declare necessary variables
			int result;

			baseNum = menu(calProcess::triAngleSum);								//display msg and get an input
			result = triAngCal(baseNum);											//save the ouput from reculsive function to result varaible	
			std::cout <<"Trianglular Number: " << result;							//display the result
			std::cout << endl;
		}

		else if (choice == 4)														//they selected 'exit'
		{
			programRun = false;														//set the flag
			std::cout << "Thank you for using this program" << std::endl;			//closeing msg
			return 0;
		}
	} while (programRun);
}
