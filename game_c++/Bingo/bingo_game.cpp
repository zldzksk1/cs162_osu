/************************************************************************************************************
** Program: Bingo Game
** Author: Sangyun Lee
** Date: July 2019
** Description:	This is bingo game implementation. I created this program by taking online lecture provided 
**				by assortrock.com. Most of code were adopted from the lecture.
*************************************************************************************************************/

#include <iostream>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;

enum AImode				//enum data type for game lever
{
	AI_Easy = 1, 
	AI_Hard,
};

enum AIline				//enum data type for checking all the possible bingo line
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_DLR,
	LN_DRL,
};

//Func proto type
void outputNumber(int* pArray, int iBingo);
AImode selectAImode();
void Shuffle(int* pArray);
void setNumber(int* pArray);
bool changeNumber(int* pArray, int input);
int selectAInumber(int* pArray, AImode mode);
int bingoCount(int* pArray);
int bingoCountH(int* pArray);
int bingoCountV(int* pArray);
int bingoCountLTD(int* pArray);
int bingoCountRTD(int* pArray);


int main()
{
	
	srand((unsigned int)time(0));
	
	//Board for player and AI
	int Board[25] = {}; 
	int AIBoard[25] = {};

	setNumber(Board);
	setNumber(AIBoard);

	//Generate random numbers bewtween 1 to 25 for the two board
	Shuffle(Board);
	Shuffle(AIBoard);

	//set the number of bingo line to 0
	int Bingo = 0, AIBingo = 0;
	

	// Give users to choice level: easy or hard
	AImode Mode = selectAImode();

	// prompt the board
	while (true)
	{
		system("cls");

		cout << "==================Player Board==================" << endl <<endl;
		
		outputNumber(Board, Bingo);

		cout << "====================AI Board====================" << endl << endl;
		outputNumber(AIBoard, AIBingo);

		//print the game level
		switch (Mode)
		{
		case AI_Easy:
			cout << "AI_Mode: Easy" << endl;
			break;
		case AI_Hard:
			cout << "Ai_mode: Hard" << endl;
			break;
		}

		// Counts the number of bingo and give a result 
		if (Bingo >= 5)
		{
			cout << "You made 5 Bingo! Congraturation! " << endl;
			break;
		}
		else if (AIBingo >= 5)
		{
			cout << "Sorry! AI made 5 Bingo!" << endl;
			break;
		}

		// Receive a number from users
		cout << "enter your number (enter 0 to close): ";
		int input;
		cin >> input;

		//validate the user input
		if (input == 0)
			break;
		else if (input < 1 || input > 25)
			continue;


		// Check the user input whether it is duplicated or not
		bool bAcc = changeNumber(Board, input);
		
		//if bAcc is true, then it is duplicated number, so ask put new number
		if (bAcc)
			continue;

		//If it is not duplicated number, then mark on AIBoard as well
		changeNumber(AIBoard, input);

		//input from computer
		input = selectAInumber(AIBoard, Mode);

		//update board accordingly

		changeNumber(Board, input);
		changeNumber(AIBoard, input);

		//Counts number of line of bingo every time we get an number from user 
		Bingo = bingoCount(Board);
		AIBingo = bingoCount(AIBoard);
	}

	return 0;
}

/*****************************************************************************************************************
** Function implementations
*****************************************************************************************************************/

//Setnumber is to generate the board
void setNumber(int* pArray)
{
	for (int i = 0; i < 25; i++)	//using for loop, generate number from 1 to 25
	{
		pArray[i] = i + 1;			//add into array
	}
}

//shuffle the numbers on the board
void Shuffle(int* pArray)
{
	int itemp, idx1, idx2;			//declare variables
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;			//generate random number
		idx2 = rand() % 25;

		itemp = pArray[idx1];		//get an number from board
		pArray[idx1] = pArray[idx2];//and update the board with randomly generated numbers
		pArray[idx2] = itemp;
	}
}

//fucntion to choose the game leve;
AImode selectAImode()
{
	int Mode;
	while (true)				//promt option
	{
		cout << "Please select your level: " << endl;
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cin >> Mode;		//get input

		if (Mode >= AI_Easy && Mode <= AI_Hard)
			break;
	}
	return (AImode)Mode;
}

//display board
void outputNumber(int* pArray, int iBingo)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (pArray[i * 5 + j] == INT_MAX)		//if the value is marked as int_max, then mark it as *
				cout << "*	";
			else
				cout << pArray[i * 5 + j] << "	";
		}
		cout << endl;
	}

	cout << "Bingo Line : " << iBingo << endl << endl;		//display number of bingo line they made
}

bool changeNumber(int* pArray, int input)
{

	for (int i = 0; i < 25; i++)
	{
		if (input == pArray[i])								//if the input is in the array,
		{
													
			pArray[i] = INT_MAX;							//mark it as max_int
			return false;                                   //false means it is not duplicated number
		}
	}
	return true;
}


//This is to generate random input my computer(AI)
int selectAInumber(int* pArray, AImode Mode)
{
	//Give AI a list of number which is not seleceted by user or AI itself
	int NoneSelect[25] = {}; // creat empty list to contain none selected number
	int NoneSelectCount = 0;

	switch (Mode)
	{
	case AI_Easy:								//when game mode is easy
		pArray = 0;
		for (int i = 0; i < 25; i++)
		{
			if (pArray[i] != INT_MAX)
			{
				NoneSelect[NoneSelectCount] = pArray[i];
				NoneSelectCount++;
			}
		}

		//AI choose one number among given none selected numbers
		return NoneSelect[rand() % NoneSelectCount];
		break;

	case AI_Hard:
		int LineN;
		int StarCount; //count number of line every moment
		int SaveCount = 0; // save the line which has the most star which mean high possibility to make a bingo

		//checking Horizental line to find a line have the most star
		for (int i = 0; i < 5; i++)
		{
			StarCount = 0;
			for (int j = 0; j < 5; j++)
			{
				if (pArray[i * 5 + j] == INT_MAX)
					StarCount++;
			}

			if (StarCount < 5 && SaveCount < StarCount)
			{
				LineN = i;
				SaveCount = StarCount;
			}
		}

		//checking vertical line to find a line have the most star
		for (int i = 0; i < 5; i++)
		{
			StarCount = 0;
			for (int j = 0; j < 5; j++)
			{
				if (pArray[j * 5 + i] == INT_MAX)
					StarCount++;
			}

			if (StarCount < 5 && SaveCount < StarCount)
			{
				LineN = i + 5;
				SaveCount = StarCount;
			}
		}

		//checking upper left to lower right line to find a line have the most star
		StarCount = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
				StarCount++;
		}

		if (StarCount < 5 && SaveCount < StarCount)
		{
			LineN = LN_DLR;
			SaveCount = StarCount;
		}


		//checking upper left to lower right line to find a line have the most star
		StarCount = 0;
		for (int i = 0; i <= 20; i += 4)
		{
			if (pArray[i] == INT_MAX)
				StarCount++;
		}

		if (StarCount < 5 && SaveCount < StarCount)
		{
			LineN = LN_DRL;
			SaveCount = StarCount;
		}

		//Decide input based on the saved Saved count 
		if (LineN <= LN_H5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (pArray[LineN * 5 + i] != INT_MAX)
				{
					return pArray[LineN * 5 + i];
				}
			}
		}
		else if (LineN <= LN_V5)
		{
			for (int j = 0; j < 5; j++)
			{
				if (pArray[j * 5 + (LineN - 5)] != INT_MAX)
				{
					return pArray[j * 5 + (LineN - 5)];
				}
			}
		}

		else if (LineN == LN_DLR)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}

		else if (LineN == LN_DRL)
		{
			for (int j = 4; j < 21; j += 4)
			{
				if (pArray[j] != INT_MAX)
				{
					return pArray[j];
				}
			}
		}
		break;

	}

	return -1;
}

//in order to count the bingo line
int bingoCount(int* pArray)
{
	int iBingo = 0;

	iBingo += bingoCountH(pArray);
	iBingo += bingoCountV(pArray);
	iBingo += bingoCountLTD(pArray);
	iBingo += bingoCountRTD(pArray);
	return iBingo;

}

//below code to checking the binglibe horizontal, vertical, and diagonol 
int bingoCountH(int* pArray)
{
	int check1 = 0, Bingo = 0;

	// Horizontal
	for (int i = 0; i < 5; i++)
	{
		//reset the number of star
		check1 = 0;
		for (int j = 0; j < 5; j++)
		{
			if (pArray[i * 5 + j] == INT_MAX)
				check1++;
		}

		if (check1 == 5)
			Bingo++;
	}

	return Bingo;
}
int bingoCountV(int* pArray)
{
	int check1 = 0, Bingo = 0;

	// Vertical and Horizontal
	for (int i = 0; i < 5; i++)
	{
		//reset the number of star
		check1 = 0;
		for (int j = 0; j < 5; j++)
		{
			if (pArray[j * 5 + i] == INT_MAX)
				check1++;
		}

		if (check1 == 5)
			Bingo++;
	}

	return Bingo;
}
int bingoCountLTD(int* pArray)
{
	int check1 = 0, Bingo = 0;
	for (int i = 0; i < 25; i += 6)
	{
		if (pArray[i] == INT_MAX)
			check1++;
	}
	if (check1 == 5)
		Bingo++;
	
	return Bingo;
}

int bingoCountRTD(int* pArray)
{
	int check1 = 0, Bingo = 0;
	for (int j = 4; j <= 20; j += 4)
	{
		if (pArray[j] == INT_MAX)
			check1++;

	}
	if (check1 == 5)
		Bingo++;

	return Bingo;
}