#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Negamax.h"

#include <string>

class Game
{
public:
	Game(bool, bool);
	void performGame();
	void performHumanMove();
	void performAiMove();
	~Game();
private:
	Board* board;
	Negamax* negamax;
	Negamax* negamaxWhite;
	Negamax* negamaxBlack;
	bool humanPlayerWhite, humanPlayerBlack;
	std::string codeText;
	std::string gameStoryPGN;
};

#endif