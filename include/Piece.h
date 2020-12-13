#ifndef PIECE_H
#define PIECE_H
#include <vector>
#include "Board.h"
#include "Square.h"

class Piece{
public:
	Piece(int); // 1 = white, -1 = black
	Piece(Piece*);
	int getOwner();
	char getCodeText();
	bool isAlive();
	void setCaptured();
	bool canCapture(Square*);
	bool canMove(Board*, Square*, Square*);
	void attackSquares(Board*, std::vector <Square*>);
	virtual std::vector <Square*> possibleSquares(Board*, Square*) = 0;
protected:
	int owner;
	bool alive;
	char codeText;
};

#endif