#include "PawnHeuristic.h"
#include "Piece.h"

float PawnHeuristic::evaluatePiece(Board* board, Square* square){
	Piece* piece;
	float pawnValue = 0.0f;
	if(piece = square->getPiece()){
		if(piece->getCodeText() != 'P')
			return pawnValue;
		pawnValue -= 0.01f * ABS(3.5f - square->getY());	// Captures towards center are preffered
		for(int i=0; i<8; i++){
			Piece* doubledPawn;
			if(doubledPawn = board->board[i][square->getY()]->getPiece())
				if(doubledPawn->getCodeText() == 'P' && piece->getOwner() == doubledPawn->getOwner()){
					pawnValue -= 0.3f;		// Penalty for doubled pawns
					break;
				}
		}
		bool friendlyPawnNerby = false;		// Penatly for isolated pawns
		if(square->getY() == 0){
			Piece* pawn;
			for(int i=0; i<8; i++)
				if(pawn = board->board[i][1]->getPiece())
					if(pawn->getCodeText() == 'P' && piece->getOwner() == pawn->getOwner())
						friendlyPawnNerby = true;
		}
		else if(square->getY() == 7){
			Piece* pawn;
			for(int i=0; i<8; i++)
				if(pawn = board->board[i][6]->getPiece())
					if(pawn->getCodeText() == 'P' && piece->getOwner() == pawn->getOwner())
						friendlyPawnNerby = true;
		}
		else{
			Piece* pawn;
			for(int i=0; i<8; i++){
				if(pawn = board->board[i][square->getY() - 1]->getPiece())
					if(pawn->getCodeText() == 'P' && piece->getOwner() == pawn->getOwner())
						friendlyPawnNerby = true;
				if(pawn = board->board[i][square->getY() + 1]->getPiece())
					if(pawn->getCodeText() == 'P' && piece->getOwner() == pawn->getOwner())
						friendlyPawnNerby = true;
			}
		}
		if(!friendlyPawnNerby)
			pawnValue -= 0.5f;

		bool hostilePawnNearby = false;	// Bonus for passed pawns
		if(piece->getOwner() == 1){
			Piece* pawn;
			for(int i = square->getX() - 1; i>0; i--)
				for(int j = square->getY() - 1; j <= square->getY() + 1; j++)
					if(board->onBoard(i, j))
						if(pawn = board->board[i][j]->getPiece())
							if(pawn->getCodeText() == 'P' && pawn->getOwner() != piece->getOwner()){
								hostilePawnNearby = true;
								goto endLoop;
							}
		}
		else{
			Piece* pawn;
			for(int i = square->getX() + 1; i<7; i++)
				for(int j = square->getY() - 1; j <= square->getY() + 1; j++)
					if(board->onBoard(i, j))
						if(pawn = board->board[i][j]->getPiece())
							if(pawn->getCodeText() == 'P' && pawn->getOwner() != piece->getOwner()){
								hostilePawnNearby = true;
								goto endLoop;
							}
		}
		endLoop:
		if(!hostilePawnNearby){		// Constant bonus 0.5 for passed pawn + 0.25 for each square closer to promotion
			pawnValue += 0.5f;
			pawnValue +=  0.25f * ( (piece->getOwner() == 1) ?  (6 - square->getX()) : (square->getX() - 1) );
		}
		if(piece->getOwner() != 1)
			pawnValue *= -1;
	}
	return pawnValue * board->whosTurn;
}