#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece
{
public:
	King(int owner) : Piece(owner){ codeText = 'K'; wasMoved = false; }
	std::vector <Square*> possibleSquares(Board*, Square*) override;
	bool isInCheckAfterSelfDiscovery(Board*, Square*);
	bool getWasMoved();
	void setWasMoved();
	bool getIsInCheck();
	void setIsInCheck(bool);
private:
	bool wasMoved;
	bool isInCheck;
};

#endif