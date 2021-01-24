#include "QueenHeuristic.h"
#include "Piece.h"
#include <math.h>

float QueenHeuristic::evaluatePiece(Board* board, Square* square){
	Piece* piece;
	float queenValue = 0.0f;
	if(piece = square->getPiece()){
		if(piece->getCodeText() != 'Q')
			return queenValue;
		if(board->prevHashes.size() < 4)	// Penalty 0.4 for moving queen from staring square too early
			if(piece->getOwner() == 1){
				if(square->getX() != 7 || square->getY() != 3)
					queenValue -= 0.4f;
			}
			else{
				if(square->getX() != 0 || square->getY() != 3)
					queenValue -= 0.4f;
			}
		else if(board->prevHashes.size() < 8)	// Penalty 0.2 for moving queen a bit too early
			if(piece->getOwner() == 1){
				if(square->getX() != 7 || square->getY() != 3)
					queenValue -= 0.2f;
			}
			else{
				if(square->getX() != 0 || square->getY() != 3)
					queenValue -= 0.2f;
			}
		else{
			float x = ABS(3.5f - square->getX());
			float y = ABS(3.5f - square->getY());
			float d = (float)sqrt( (x * x) + (y * y) );	// Pythagorean theorem -  distance from center
			queenValue -= 0.1f * d;		// Penalty for not centralising queen in middle game
		}
		if(piece->getOwner() != 1)
			queenValue *= -1;
	}
	return queenValue * board->whosTurn;
}