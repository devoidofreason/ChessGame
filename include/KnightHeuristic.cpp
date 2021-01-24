#include "KnightHeuristic.h"
#include "Piece.h"

#include <math.h>

float KnightHeuristic::evaluatePiece(Board* board, Square* square){
	Piece* piece;
	float knightValue = 0.0f;
	if(piece = square->getPiece()){
		if(piece->getCodeText() != 'N')
			return knightValue;
		float x = ABS(3.5f - square->getX());
		float y = ABS(3.5f - square->getY());
		float d = (float)sqrt( (x * x) + (y * y) );	// Pythagorean theorem -  distance from center
		knightValue -= 0.15f * d;	// Penalty for being far from center
		if(piece->getOwner() != 1)
			knightValue *= -1;
	}
	return knightValue * board->whosTurn;
}