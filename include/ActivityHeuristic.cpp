#include "ActivityHeuristic.h"
#include "Piece.h"

float ActivityHeuristic::evaluatePiece(Board* board, Square* square){
	int whiteActivity = 0, blackActivity = 0;
	Piece* piece;
	if(piece = square->getPiece()){
		if(piece->getCodeText() == 'Q')
			return 0.0f;
		if(piece->getOwner() == 1)
			whiteActivity += piece->possibleSquares(board, square).size();
		else
			blackActivity += piece->possibleSquares(board, square).size();
	}
	return 0.05f * (float)(whiteActivity - blackActivity) * board->whosTurn;
}