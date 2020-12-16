#ifndef GAME_H
#define GAME_H
#include "Board.h"

class Game
{
public:
	Game();
	void performGame();
	bool performHumanMove();
	~Game();
private:
	Board* board;
	bool humanPlayerWhite, humanPlayerBlack;
	std::vector<unsigned long long int> gameStory;
	std::string gameStoryPGN;
};

#endif