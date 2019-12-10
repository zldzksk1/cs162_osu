#include <iostream>
#include "Game.hpp"
#include "menu.hpp"
#include "getInput.hpp"

enum Fantasy
{
	newGame,
	player1,
	player2,
	oneMore,
};

int main()
{
	int gameStart = menu(Fantasy::newGame);
	if (gameStart != 2)
	{
		do {
			int p1 = menu(Fantasy::player1);
			int p2 = menu(Fantasy::player2);
			Game g1(p1, p2);
			g1.playGame();
			gameStart = menu(Fantasy::oneMore);
		} while (gameStart != 2);
		return 0;
	}

	else if (gameStart == 2)
	{
		std::cout << "** Thank you for playing!" << std::endl;
		return 0;
	}
}
