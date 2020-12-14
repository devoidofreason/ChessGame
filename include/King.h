#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece
{
public:
	King(int owner) : Piece(owner){ codeText = 'K'; wasMoved = false; }
	King(Piece* parent) : Piece(parent){ wasMoved = static_cast<King*>(parent)->getWasMoved(); }
	std::vector <Square*> possibleSquares(Board*, Square*) override;
	bool isInCheck(Board*, Square*);
	bool getWasMoved();
	void setWasMoved();
	bool getIsInCheck();
	void setIsInCheck(bool);
private:
	bool wasMoved, inCheck;
};

#endif