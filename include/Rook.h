#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(int owner) : Piece(owner){ codeText = 'R'; wasMoved = false; }
	Rook(Piece* parent) : Piece(parent){ wasMoved = static_cast<Rook*>(parent)->getWasMoved(); }
	std::vector<Square*> possibleSquares(Board*, Square*) override;
	bool getWasMoved();
	void setWasMoved();
private:
	bool wasMoved;
};

#endif