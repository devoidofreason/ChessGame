#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(int owner) : Piece(owner){ codeText = 'B'; }
	Bishop(Piece* parent) : Piece(parent){}
	std::vector <Square*> possibleSquares(Board*, Square*) override;
};

#endif