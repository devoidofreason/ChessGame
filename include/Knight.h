#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(int owner) : Piece(owner){ codeText = 'N'; }
	Knight(Piece* parent) : Piece(parent){}
	std::vector <Square*> possibleSquares(Board*, Square*) override;
};

#endif