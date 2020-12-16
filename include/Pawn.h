#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(int owner) : Piece(owner){ codeText = 'P'; canBeCapturedEnPassant = false; }
	Pawn(Piece* parent) : Piece(parent){ canBeCapturedEnPassant = static_cast<Pawn*>(parent)->getCanBeCapturedEnPassant(); }
	std::vector<Square*> possibleSquares(Board*, Square*) override;
	void enableCaptureEnPassant();
	void updateCanBeCapturedEnPassant();
	bool getCanBeCapturedEnPassant();
	void promotePawn(Square*, Piece*);
private:
	bool canBeCapturedEnPassant;
};

#endif