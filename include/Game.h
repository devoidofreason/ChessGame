#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Negamax.h"
#include <string>

class Game
{
public:
	Game();
	void performGame();
	void performHumanMove();
	void performAiMove();
	~Game();
private:
	Board* board;
	Negamax* negamax;
	bool humanPlayerWhite, humanPlayerBlack;
	std::string codeText;
	std::vector<unsigned long long int> gameStory;
	std::string gameStoryPGN;
};

#endif