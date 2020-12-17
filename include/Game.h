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
	void testGame(std::string);
	bool performHumanMove(int);
	bool performHumanMove();
	~Game();
private:
	std::string codeText;
	Board* board;
	bool humanPlayerWhite, humanPlayerBlack;
	std::vector<unsigned long long int> gameStory;
	std::string gameStoryPGN;
};

#endif