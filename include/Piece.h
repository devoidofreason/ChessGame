#ifndef PIECE_H
#define PIECE_H

#include "Board.h"
#include "Square.h"

#include <vector>

class Piece{
public:
	Piece(int); // 1 = white, -1 = black
	Piece(Piece*);
	int getOwner();
	char getCodeText();
	bool canCapture(Square*);
	bool canMove(Board*, Square*, Square*);
	virtual std::vector<Square*> possibleSquares(Board*, Square*) = 0;
protected:
	int owner;
	char codeText;
};

#endif