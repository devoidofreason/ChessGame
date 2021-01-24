#include "KingHeuristic.h"
#include "Piece.h"
#include "MaterialHeuristic.h"

float KingHeuristic::evaluatePiece(Board* board, Square* square){
	Piece* piece;
	float kingValue = 0.0f;
	if(piece = square->getPiece()){
		if(piece->getCodeText() != 'K')
			return kingValue;
		if(board->prevHashes.size() < 12){
			if(piece->getOwner() == 1){
				if(square->getX() != 7)
					kingValue -= 0.5f;	// Penalty for leaving back rank
			}
			else{
				if(square->getX() != 0)
					kingValue -= 0.5f;
			}
			if(square->getY() <= 3)
				kingValue -= 0.15f * (float)square->getY();	// Penalty for being far from corner
			else
				kingValue -= 0.15f * ABS(7.0f - square->getY());
		}
		if(piece->getOwner() != 1)
			kingValue *= -1;
	}
	return kingValue * board->whosTurn;
}