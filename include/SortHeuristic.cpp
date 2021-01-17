#include "SortHeuristic.h"
#include "Piece.h"

#include <stdlib.h>

float SortHeuristic::evaluatePosition(Board* board){
	if(!board->capturedPiece)
		return 0.0f;
	float capturedPieceVal = 10.0f;
	char capturedPiece = board->capturedPiece;
	if(capturedPiece == 'P')
		capturedPieceVal *= 1.0f;
	else if(capturedPiece == 'N')
		capturedPieceVal *= 3.0f;
	else if(capturedPiece == 'B')
		capturedPieceVal = 3.0f;
	else if(capturedPiece == 'R')
		capturedPieceVal *= 5.0f;
	else if(capturedPiece == 'Q')
		capturedPieceVal *= 9.0f;

	float capturingPieceVal = 1.0f;
	if(!board->square2->getPiece())
		capturingPieceVal = 0.0f;
	else{
		char capturingPiece = board->square2->getPiece()->getCodeText();
		if(capturingPiece == 'P')
			capturingPieceVal *= 1.0f;
		else if(capturingPiece == 'N')
			capturingPieceVal *= 3.0f;
		else if(capturingPiece == 'B')
			capturingPieceVal *= 3.0f;
		else if(capturingPiece == 'R')
			capturingPieceVal *= 5.0f;
		else if(capturedPiece == 'Q')
			capturingPieceVal *= 9.0f;
	}

	return 1000.0f + capturedPieceVal - capturingPieceVal;
}