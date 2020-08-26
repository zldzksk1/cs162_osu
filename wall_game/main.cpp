/****************************************************************************************************
** Program: main.cpp
** Author:	Sangyun Lee
** Date:	Nov 22 2019
** Description: This is personal project to create the game:tetirs. I followed the instruction
**				provided by Assort Rock Game Academy Game Academy
**
**
*****************************************************************************************************/

#include "uilities.hpp"

/*
0 - wall
1 - way or road
2 - start point
3 - goal point
4 - bomb
5 - bomb Power
6 - push wall
7 - invisible
8 - warm hall
*/

struct tagPoint
{
	int x;
	int y;
};

typedef tagPoint POINT;
typedef tagPoint* PPOINT;

typedef struct tagPlayer
{
	tagPoint tPos;
	bool	 bWallPush;
	bool	 bPushOnOff;
	bool	 bTransparency;
	int		 iBombPowers;
}PLAYER, * PPLAYER;


void setMaze(char Maze[21][21], PPLAYER tPlayer, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;				//set the start point
	pStartPos->y = 0;

	tPlayer->tPos = *pStartPos;		//set the player poition as same as start point

	pEndPos->x = 12;
	pEndPos->y = 19;


	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111111000010000");
	strcpy_s(Maze[2],  "00100000001111110000");
	strcpy_s(Maze[3],  "00100000001000000000");
	strcpy_s(Maze[4],  "00001111111000000000");
	strcpy_s(Maze[5],  "00111000000000000000");
	strcpy_s(Maze[6],  "00101111100000000000");
	strcpy_s(Maze[7],  "00100000100000000000");
	strcpy_s(Maze[8],  "00111111111000000000");
	strcpy_s(Maze[9],  "01000000001111000000");
	strcpy_s(Maze[10], "01111000001000000000");
	strcpy_s(Maze[11], "00000000001111111100");
	strcpy_s(Maze[12], "00000000000000000100");
	strcpy_s(Maze[13], "00000111111111111100");
	strcpy_s(Maze[14], "01111100000000000000");
	strcpy_s(Maze[15], "01000100000000000000");
	strcpy_s(Maze[16], "01111111111110000000");
	strcpy_s(Maze[17], "01000000000010000000");
	strcpy_s(Maze[18], "01111111111010000000");
	strcpy_s(Maze[19], "00000000000030000000");
}

void outPut(char Maze[21][21], PPLAYER pPlayer)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (Maze[i][j] == '4')
				cout << "¡Ø";
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "¡Ù";
			else if (Maze[i][j] == '0')					//since symbol is 2 bytes
				cout << "¡á";
			else if (Maze[i][j] == '1')
				cout << "  ";						//give two spaces
			else if (Maze[i][j] == '2')
				cout << "¡Ú";
			else if (Maze[i][j] == '3')
				cout << "¢Í";
			else if (Maze[i][j] == '5')
				cout << "¡Ó";
			else if (Maze[i][j] == '6')
				cout << "¡×";
			else if (Maze[i][j] == '7')
				cout << "¡Û";
		}
		cout << endl;
	}
	cout << "Power: " << pPlayer->iBombPowers << endl;
	cout << "Wall Pass: "; 
	if (pPlayer->bTransparency)
		cout << "on\t";
	else
		cout << "off\t";
	cout << "Wall Push: ";
	if (pPlayer->bWallPush)
	{
		cout << "on\t" << endl;
		if (pPlayer->bPushOnOff)
			cout << "on" << end;
		else
			cout << "off" << endl;
	}
		else
		cout << "off\t" <<endl;

}

bool addItem(char cItemType, PPLAYER pPlayer)
{
	if (cItemType == '5')
	{	
		if(pPlayer->iBombPowers < 5)
			pPlayer->iBombPowers++;
		return true;
	}
	else if (cItemType == '6')
	{
		pPlayer->bWallPush = true;
		pPlayer->bPushOnOff = true;
		return true;
	}
	else if (cItemType == '7')
	{
		pPlayer->bTransparency = true;
		return true;
	}
	return false;
}

void moveUp(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y - 1 >= 0)
	{

		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0'&& Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;
	
		if (addItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}
void moveDw(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 < 20)
	{
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
		{
			++pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;

		if (addItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}
void moveLf(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x - 1 >= 0)
	{
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;

		if (addItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}
void moveRg(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 < 20)
	{
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0' && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;

		if (addItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
		{
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void movePlayer(char Maze[21][21], PPLAYER pPlayer, char uinput)
{
	switch (uinput)
	{
	case 'w':
	case 'W':
		moveUp(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		moveDw(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		moveLf(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		moveRg(Maze, pPlayer);
		break;
	}
}

void CreatBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBomb, int * pBombCount )
{
	if (*pBombCount == 5)
		return;

	if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	for (int i = 0; i < *pBombCount; i++)
	{
		if (pPlayer->tPos.y == pBomb[i].y && pPlayer->tPos.x == pBomb[i].x)
			return;
	}

	pBomb[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void Explode(char Maze[21][21], PPLAYER pPlayer, PPOINT pBomb, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; i++)
	{

		Maze[pBomb[i].y][pBomb[i].x] = '1';

		if (pPlayer->tPos.x == pBomb[i].x && pPlayer->tPos.x == pBomb[i].y)
		{
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}

		for (int j = 1; j <= pPlayer->iBombPowers; j++)
		{
			if (pBomb[i].y - j >= 0)	//check upside, if it is not edge, explode  
			{
				if (Maze[pBomb[i].y - j][pBomb[i].x] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBomb[i].y - j][pBomb[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBomb[i].y - j][pBomb[i].x] = '6';
						else
							Maze[pBomb[i].y - j][pBomb[i].x] = '7';
					}
					else
						Maze[pBomb[i].y - j][pBomb[i].x] = '1';
				}

				//when player got hurts by bomb, return to start point

				if (pPlayer->tPos.x == pBomb[i].x && pPlayer->tPos.y == pBomb[i].y - j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			if (pBomb[i].y + j < 20)	//check downside, if it is not edge, explode  
			{
				if (Maze[pBomb[i].y + j][pBomb[i].x] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBomb[i].y + j][pBomb[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBomb[i].y + j][pBomb[i].x] = '6';
						else
							Maze[pBomb[i].y + j][pBomb[i].x] = '7';
					}
					else
						Maze[pBomb[i].y + j][pBomb[i].x] = '1';
				}
				//when player got hurts by bomb, return to start point

				if (pPlayer->tPos.x == pBomb[i].x && pPlayer->tPos.y == pBomb[i].y + j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			if (pBomb[i].x - j >= 0)	//check left, if it is not edge, explode  
			{
				if (Maze[pBomb[i].y][pBomb[i].x - j] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBomb[i].y][pBomb[i].x - j] = '5';
						else if (iPercent < 80)
							Maze[pBomb[i].y][pBomb[i].x - j] = '6';
						else
							Maze[pBomb[i].y][pBomb[i].x - j] = '7';
					}
					else
						Maze[pBomb[i].y][pBomb[i].x - j] = '1';
				}
				//when player got hurts by bomb, return to start point

				if (pPlayer->tPos.x == pBomb[i].x - j && pPlayer->tPos.y == pBomb[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			if (pBomb[i].x + j < 20)	//check right, if it is not edge, explode  
			{
				if (Maze[pBomb[i].y][pBomb[i].x + j] == '0')
				{
					if (rand() % 100 < 20)
					{
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBomb[i].y][pBomb[i].x + j] = '5';
						else if (iPercent < 80)
							Maze[pBomb[i].y][pBomb[i].x + j] = '6';
						else
							Maze[pBomb[i].y][pBomb[i].x + j] = '7';
					}
					else
						Maze[pBomb[i].y][pBomb[i].x + j] = '1';
				}
				//when player got hurts by bomb, return to start point

				if (pPlayer->tPos.x == pBomb[i].x + j && pPlayer->tPos.y == pBomb[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}
		
	}

	*pBombCount = 0;
}


int main()
{
	srand((unsigned int)time(0));

	//creat 20 x 20 board for game
	char strMaze[21][21] = {};

	//set postion
	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPowers = 1;

	int bombCount = 0;
	POINT tBombPosp[5];

	//set Maza for game
	setMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);

	//prompt the maze
	while (true)
	{
		system("cls");
		outPut(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y)
		{
			cout << "Goal In!" << endl;
			return 0;
		}
			
		cout << "w - up, s - down, a - left, d - right" << endl;
		cout << "t - Bomb, u - Explode, i - Push On/Off" << endl;
		char userInput = _getch();

		if (userInput == 'q' || userInput == 'Q')
			break;

		else if (userInput == 't' || userInput == 'T')
		{
			CreatBomb(strMaze, &tPlayer, tBombPosp, &bombCount);
		}

		else if (userInput == 'u' || userInput == 'U')
		{
			Explode(strMaze, &tPlayer, tBombPosp, &bombCount);
		}

		else if (userInput == 'i' || userInput == 'I')
		{
			if (tPlayer.bPushOnOff)
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
		}

		movePlayer(strMaze, &tPlayer, userInput);

	}
	

	return 0;
}