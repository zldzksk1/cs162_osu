
/***********************************************************************************************************************************
**	Program: Barbarian.hpp
**	Author: Sangyun Lee
**	Date: Nov 02 2019
**	Description: This is headerfile of Game class.
**
***********************************************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "fantasyCG.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Bluemen.hpp"
#include "Medusa.hpp"
#include "Harry.hpp"

#include <vector>
#include <memory>
#include <iomanip>

class Game
{
private:
	int p1Chac;
	int p2Chac;
	std::vector<std::shared_ptr<fantasyCG>> player1;
	std::vector<std::shared_ptr<fantasyCG>> player2;
public:
	Game(int, int);
	~Game();
	std::vector<std::shared_ptr<fantasyCG>> setupP1();
	std::vector<std::shared_ptr<fantasyCG>> setupP2();
	void playGame();

	int attackPlayer(std::vector<std::shared_ptr<fantasyCG>>, std::vector<std::shared_ptr<fantasyCG>>, int, int);
	void defensePlayer(std::vector<std::shared_ptr<fantasyCG>>, int, int);
	int playCheck(std::vector<std::shared_ptr<fantasyCG>>, int);
};
#endif //!GAME_HPP
