#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include <vector>
#include <string>

class Board
{
public:
	Board();
	Board(Board*);
	Square*** board;
	Square* whiteKingPos;
	Square* blackKingPos;
	std::vector <Piece*> pieces;
	int whosTurn;
	bool onBoard(int, int);
	Square* resolveSquareCode(std::string);
	void printBoard();
	void printBoard(Square*);
	std::vector <Board*> generateChildren();
	void calculateHashCode();
	unsigned long long int hashCode;
	~Board();
};

#endif