#include "BishopHeuristic.h"
#include "Piece.h"

float BishopHeuristic::evaluatePiece(Board* board, Square* square){
	Piece* piece;
	float bishopValue = 0.0f;
	if(piece = square->getPiece()){
		if(piece->getCodeText() != 'B')
			return bishopValue;
		bool fianchetto = false;	// Bonus for bishop fianchetto
		if(piece->getOwner() == 1)
			if(square->getX() == 6)
				if(square->getY() == 1 || square->getY() == 6)
					fianchetto = true;
		else{
			if(square->getX() == 1)
				if(square->getY() == 1 || square->getY() == 6)
					fianchetto = true;
		}
		if(fianchetto)
			bishopValue += 0.3f;
		if(piece->getOwner() != 1)
			bishopValue *= -1;
	}
	return bishopValue * board->whosTurn;
}