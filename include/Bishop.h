#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(int owner) : Piece(owner){ codeText = 'N'; }
	std::vector <Square*> possibleSquares(Board*, Square*) override;
};

#endif