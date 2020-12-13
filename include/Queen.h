#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(int owner) : Piece(owner){ codeText = 'Q'; }
	Queen(Piece* parent) : Piece(parent){}
	std::vector <Square*> possibleSquares(Board*, Square*) override;
};

#endif