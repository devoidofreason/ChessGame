#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(int owner) : Piece(owner){ codeText = 'Q'; }
	std::vector <Square*> possibleSquares(Board*, Square*) override;
};

#endif