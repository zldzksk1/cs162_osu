/********************************************************************************************************************************************
** Program name: Ant.cpp
** Author: Sangyun Lee
** Date: OCT 10: 2019
** Description: This is implementation file of the Ant.hpp. 
** Reference: I got an idea about how to initialize 2d dynamic array on class function from
**			  https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/
********************************************************************************************************************************************/

#include "Ant.hpp"


/********************************************************************************************************************************************
**															Ant::Ant(int, int, int, int)
** Description: This is Ant constructor which takes four int parameters to set the necessary variables.
** it sets board sizes and start location of an ant. Board are created with dynamic 2d array.
** implementation: Since all of the aspect of board need to be set up by users, so decide to create constructor that accepts 4 int variable 
**				   to initialize the dynamic array board and ant location. Step will be setted by another function.
********************************************************************************************************************************************/

Ant::Ant(int rs, int cs, int rt, int rc)
{
	direction = 'u';									//initalize the direction, first move will be up always
	bColor = 'w';										//color tracking, assuming all board are white at the beginning
	rowSize = rs;
	colSize = cs;										
	step = 10;											
	antBoard = new char* [rowSize];						//pointer of 2d-array initialization
	for (int i = 0; i < rowSize; i++)
		antBoard[i] = new char[colSize];

	//antBoard initialization
	for (int i = 0; i < colSize; i++)
	{
		antBoard[0][i] = '-';							//up & down edges
		antBoard[rowSize - 1][i] = '-';

	}

	for (int i = 1; i < rowSize - 1; i++)
	{
		antBoard[i][0] = '|';							//left & right side edges
		antBoard[i][colSize - 1] = '|';
	}

	for (int i = 1; i < rowSize - 1; i++)
	{
		for (int j = 1; j < colSize - 1; j++)
		{
			antBoard[i][j] = ' ';						//initialize as white board
		}
	}

	//initialize the ant location 
	antRpos = rt;										//Ant will be in the middle of the board always
	antCpos = rc;

	antBoard[antRpos][antCpos] = '*';					// * is an ant
}



/********************************************************************************************************************************************
**															Ant::playGame()
** Description: This is void function that check the board condition and moving the ant to the right postion.
**				step, direction variables are used in this function. Steps are number of step the ant need to move, and the direction
**				is the orientation where the ant need to move (u,d,r,l)
** Implementation: I used the system("cls") to clear the screen, so it looks an ant move on the cmd window, and slow down the output
**				   for better visualization.
**
********************************************************************************************************************************************/

void Ant::playGame()
{
	while (step != -1)
	{

		cout << "Your Langton's ant simulation" << endl << endl;
		cout << "Remaining step: " << step << endl;					//display the remain steps

		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < colSize; j++)
			{
				//Sleep(8);											//slow down the output speed
				cout << antBoard[i][j];
			}
			cout << endl;
		}

		// up direction
		if (direction == 'u' && bColor == 'w')						//when ant direction is up and on white board
		{
			if ((antBoard[antRpos - 1][antCpos] == ' '))			//ant will move onto white
			{
				bColor = 'w';										//so color tracking will be white for the next move
				antBoard[antRpos][antCpos] = '#';					//ant is on white, so change it to black
				antRpos -= 1;										//move up
				antBoard[antRpos][antCpos] = '*';					//ant are on new position
				direction = 'r';									//since ant is on the new white position, will turn right
			}

			else if (antBoard[antRpos - 1][antCpos] == '#')			//ant will move onto black
			{
				bColor = 'b';										//so color tracking will be black
				antBoard[antRpos][antCpos] = '#';					//ant is on white, so change it in black
				antRpos -= 1;										//move up
				antBoard[antRpos][antCpos] = '*';
				direction = 'l';									//since ant is on the new position on black, will turn left
			}

			else if (antBoard[antRpos - 1][antCpos] == '-')			//if the new postion is edge
			{
				antBoard[antRpos][antCpos] = '#';
				antRpos = rowSize - 2;								//go through it and come out opposite way
				if (antBoard[antRpos][antCpos] == ' ')				//checking the board color
				{
					bColor = 'w';									//and set up variables as need
					direction = 'r';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'l';
				}
				antBoard[antRpos][antCpos] = '*';
			}
		}

		else if (direction == 'u' && bColor == 'b')					//when ant direction is up and on black board
		{
			if ((antBoard[antRpos - 1][antCpos] == ' '))			//and will move onto white board
			{
				bColor = 'w';										//color tracing will be white for next move
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it to white
				antRpos -= 1;										//move up
				antBoard[antRpos][antCpos] = '*';					//ant are on new position
				direction = 'r';									//since ant is on the new white board, will turn right
			}

			else if (antBoard[antRpos - 1][antCpos] == '#')			//ant will move onto black board
			{
				bColor = 'b';										//bColor will be black for the next trun
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it to white
				antRpos -= 1;										//move up
				antBoard[antRpos][antCpos] = '*';					//ant on new position
				direction = 'l';									//since ant is on the new black board, will turn left
			}

			else if (antBoard[antRpos - 1][antCpos] == '-')			// if the new position is edge
			{
				antBoard[antRpos][antCpos] = ' ';
				antRpos = rowSize - 2;								//go through it and come out opposite way
				if (antBoard[antRpos][antCpos] == ' ')				//checking the board color															
				{													//and set up variables as need
					bColor = 'w';
					direction = 'r';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'l';
				}
				antBoard[antRpos][antCpos] = '*';
			}
		}

		// down direction
		else if (direction == 'd' && bColor == 'w')					//ant is on white board
		{
			if (antBoard[antRpos + 1][antCpos] == ' ')
			{
				bColor = 'w';										//ant new position will be white
				antBoard[antRpos][antCpos] = '#';					//ant is on white, so change it to black after
				antRpos += 1;										//move up
				antBoard[antRpos][antCpos] = '*';					//ant is on new position
				direction = 'l';									//since ant is on white, turn right
			}

			else if (antBoard[antRpos + 1][antCpos] == '#')
			{
				bColor = 'b';
				antBoard[antRpos][antCpos] = '#';
				antRpos += 1;
				antBoard[antRpos][antCpos] = '*';					//are is on new position
				direction = 'r';									//since ant is on black, turn left
			}

			else if (antBoard[antRpos + 1][antCpos] == '-')			//if the new position is edge
			{
				antBoard[antRpos][antCpos] = '#';
				antRpos = 1;										//go through it and come out opposite way
				if (antBoard[antRpos][antCpos] == ' ')				//checking the new position board color																		
				{
					bColor = 'w';
					direction = 'l';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'r';
				}
				antBoard[antRpos][antCpos] = '*';
			}
		}

		else if (direction == 'd' && bColor == 'b')					//ant is on black board
		{
			if (antBoard[antRpos + 1][antCpos] == ' ')
			{
				bColor = 'w';										//new position will be white, so mark it
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it in white after move
				antRpos += 1;										//move up
				antBoard[antRpos][antCpos] = '*';					//ant is on new position
				direction = 'l';									//since ant is on white, turn right
			}

			else if (antBoard[antRpos + 1][antCpos] == '#')			//new position will be black
			{
				bColor = 'b';
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it in white after
				antRpos += 1;										//move up
				antBoard[antRpos][antCpos] = '*';					//now new position
				direction = 'r';									//since ant is on black, turn left
			}

			else if (antBoard[antRpos + 1][antCpos] == '-')			//if the new position is edge
			{
				antBoard[antRpos][antCpos] = ' ';
				antRpos = 1;										//go though and come out from opposite way
				if (antBoard[antRpos][antCpos] == ' ')																						//test
				{
					bColor = 'w';
					direction = 'l';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'r';
				}
				antBoard[antRpos][antCpos] = '*';
			}
		}

		// right direction
		else if (direction == 'r' && bColor == 'w')					//ant is on white board
		{
			if (antBoard[antRpos][antCpos + 1] == ' ')
			{
				bColor = 'w';
				antBoard[antRpos][antCpos] = '#';					//ant is on white, so change it to black after
				antCpos += 1;										//move right
				antBoard[antRpos][antCpos] = '*';					//ant are on new position
				direction = 'd';									//since ant is on white, turn right
			}

			else if (antBoard[antRpos][antCpos + 1] == '#')
			{
				bColor = 'b';										//new positon will be black
				antBoard[antRpos][antCpos] = '#';					//ant is on white, change it to black after
				antCpos += 1;										//move right
				antBoard[antRpos][antCpos] = '*';					//ant is on new psotion
				direction = 'u';									//since ant is on black, turn left 90 degree
			}

			else if (antBoard[antRpos][antCpos + 1] == '|')			//if the new position is edge
			{
				antBoard[antRpos][antCpos] = '#';
				antCpos = 1;										//go through and come out from opposite way
				if (antBoard[antRpos][antCpos] == ' ')				//checking the board color															
				{													//and set up variables as need
					bColor = 'w';
					direction = 'd';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'u';
				}
				antBoard[antRpos][antCpos] = '*';
			}
		}

		else if (direction == 'r' && bColor == 'b')					//ant is on black board
		{
			if (antBoard[antRpos][antCpos + 1] == ' ')
			{
				bColor = 'w';
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it in white after
				antCpos += 1;										//move right
				antBoard[antRpos][antCpos] = '*';					//ant is on new position
				direction = 'd';									//since ant is on white, turn right
			}

			else if (antBoard[antRpos][antCpos + 1] == '#')
			{
				bColor = 'b';
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it in white after
				antCpos += 1;										//move right		
				antBoard[antRpos][antCpos] = '*';					//ant is on new position
				direction = 'u';									//since ant was on black, turn left
			}

			else if (antBoard[antRpos][antCpos + 1] == '|')			//if the new position is edge
			{
				antBoard[antRpos][antCpos] = ' ';
				antCpos = 1;										//go through and come out from opposite way
				if (antBoard[antRpos][antCpos] == ' ')				//checking the board color															
				{													//and set up variables as need
					bColor = 'w';
					direction = 'd';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'u';
				}
				antBoard[antRpos][antCpos] = '*';
			}
		}

		// left direction
		else if (direction == 'l' && bColor == 'w')					//ant is on white board
		{
			if (antBoard[antRpos][antCpos - 1] == ' ')
			{
				bColor = 'w';
				antBoard[antRpos][antCpos] = '#';					//ant is on white, so change it in black after
				antCpos -= 1;										//move left
				antBoard[antRpos][antCpos] = '*';					//ant is on new position white
				direction = 'u';									//since ant is on white, turn right
			}

			else if (antBoard[antRpos][antCpos - 1] == '#')
			{
				bColor = 'b';
				antBoard[antRpos][antCpos] = '#';					//ant is on white, so change it in black after
				antCpos -= 1;										//move left
				antBoard[antRpos][antCpos] = '*';					//ant is on new position black
				direction = 'd';									//since ant is on black, turn left
			}

			else if (antBoard[antRpos][antCpos - 1] == '|')			//if the new position is edge
			{
				antBoard[antRpos][antCpos] = '#';				
				antCpos = colSize - 2;								//go through and come out from opposite way
				if (antBoard[antRpos][antCpos] == ' ')				//checking the board color															
				{													//and set up variables as need
					bColor = 'w';
					direction = 'u';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'd';
				}
				antBoard[antRpos][antCpos] = '*';
			}													
		}

		else if (direction == 'l' && bColor == 'b')					 //ant is on black board
		{
			if (antBoard[antRpos][antCpos - 1] == ' ')
			{
				bColor = 'w';
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it in white after
				antCpos -= 1;										//move left
				antBoard[antRpos][antCpos] = '*';					//ant is on new position white
				direction = 'u';									//since ant is on white, turn right
			}

			else if (antBoard[antRpos][antCpos - 1] == '#')
			{
				bColor = 'b';
				antBoard[antRpos][antCpos] = ' ';					//ant is on black, so change it in white after
				antCpos -= 1;										//move left
				antBoard[antRpos][antCpos] = '*';					//ant is on new position black
				direction = 'd';									//since ant is on black, turn left
			}

			else if (antBoard[antRpos][antCpos - 1] == '|')			//if the new postion is edge
			{
				antBoard[antRpos][antCpos] = ' ';
				antCpos = colSize - 2;								//go through and come out from opposite way
				if (antBoard[antRpos][antCpos] == ' ')				//checking the board color															
				{													//and set up variables as need
					bColor = 'w';
					direction = 'u';
				}
				else if (antBoard[antRpos][antCpos] == '#')
				{
					bColor = 'b';
					direction = 'd';
				}
				antBoard[antRpos][antCpos] = '*';
			}
		}
		step--;
	}
}


/********************************************************************************************************************************************
**															Ant::setStep()
** Description: This is void function that set the number of step for ant, it has one int parameter.
**
********************************************************************************************************************************************/
void Ant::setStep(int st)
{
	step = st;
}

/********************************************************************************************************************************************
**															Ant::clearBoard()
** Description: This is void function that delete the dynamic array to clear the memory and prevent the memory leak.
**
********************************************************************************************************************************************/
void Ant::clearBoard()
{
	for (int i = 0; i < rowSize; i++)
	{
		antBoard[i] = nullptr;		//make null pointer
		delete[] antBoard[i];		//and delete
	}
	
	antBoard = nullptr;				//make null pointer
	delete[] antBoard;				//and delete
}

