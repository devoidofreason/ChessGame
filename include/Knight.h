#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(int owner) : Piece(owner){ codeText = 'N'; }
	std::vector <Square*> possibleSquares(Board*, Square*) override;
};

#endif