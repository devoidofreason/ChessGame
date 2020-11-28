#ifndef BOARD_H
#define BOARD_H
#include "Square.h"

class Board
{
public:
	Board();
	Square*** board;
	Piece** pieces;
	bool** squaresAttackedByWhite;
	bool** squaresAttackedByBlack;
	bool onBoard(int, int);
	~Board();
};

#endif