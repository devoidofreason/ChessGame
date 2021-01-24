#ifndef BOARD_H
#define BOARD_H

#include "Square.h"

#include <vector>
#include <string>

#define WHITE_WINS	1
#define BLACK_WINS	2
#define DRAW		3

class Board
{
public:
	Board();
	Board(Board*);
	Square*** board;
	Square* whiteKingPos;
	Square* blackKingPos;
	Square* square1;
	Square* square2;
	char capturedPiece;
	std::vector<Piece*> pieces;
	int whosTurn;
	bool onBoard(int, int);
	Square* resolveSquareCode(std::string);
	void printBoard();
	std::vector<Board*> generateChildren();
	std::vector<Board*> generateChildren(std::vector<std::string>* labels);
	void calculateHashCode();
	int getStatus();
	bool drawBy3FoldRepetition();
	bool drawByInsufficientMaterial();
	unsigned long long int hashCode;
	std::vector<unsigned long long int> prevHashes;
	float evaluation;
	~Board();
};

#endif