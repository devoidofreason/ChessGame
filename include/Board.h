#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include <vector>

class Board
{
public:
	Board();
	Square*** board;
	std::vector <Piece*> pieces;
	bool** squaresAttackedByWhite;
	bool** squaresAttackedByBlack;
	bool onBoard(int, int);
	void printBoard();
	~Board();
};

#endif