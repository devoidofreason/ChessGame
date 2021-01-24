#include "RookHeuristic.h"
#include "Piece.h"

float RookHeuristic::evaluatePiece(Board* board, Square* square){
	Piece* piece;
	float rookValue = 0.0f;
	if(piece = square->getPiece()){
		if(piece->getCodeText() != 'R')
			return rookValue;
		float d = ABS(3.5f - square->getY());
		rookValue -= 0.2f * d;	// So moves towards center are preffered
		bool onOpenedFile = true;
		for(int i=0; i<8; i++){
			Piece* pawn;
			if(pawn = board->board[i][square->getY()]->getPiece())
				if(pawn->getCodeText() == 'P')
					onOpenedFile = false;
		}
		if(onOpenedFile)
			rookValue += 0.5f;	// Bonus for occupying openned file - with no pawns coliding
		bool connected = false;
		int x = square->getX(), y = square->getY();
		for(int i = x - 1; board->onBoard(i, y); i--){	// Copypasted from rook.cpp cuz why not
			Piece* friendlyRook;
			if(friendlyRook = board->board[i][y]->getPiece()){
				if(friendlyRook->getCodeText() == 'R' && friendlyRook->getOwner() == piece->getOwner())
					connected = true;
				break;
			}
		}
		for(int i = x + 1; board->onBoard(i, y); i++){
			Piece* friendlyRook;
			if(friendlyRook = board->board[i][y]->getPiece()){
				if(friendlyRook->getCodeText() == 'R' && friendlyRook->getOwner() == piece->getOwner())
					connected = true;
				break;
			}
		}
		for(int i = y - 1; board->onBoard(x, i); i--){
			Piece* friendlyRook;
			if(friendlyRook = board->board[i][y]->getPiece()){
				if(friendlyRook->getCodeText() == 'R' && friendlyRook->getOwner() == piece->getOwner())
					connected = true;
				break;
			}
		}
		for(int i = y + 1; board->onBoard(x, i); i++){
		Piece* friendlyRook;
			if(friendlyRook = board->board[i][y]->getPiece()){
				if(friendlyRook->getCodeText() == 'R' && friendlyRook->getOwner() == piece->getOwner())
					connected = true;
				break;
			}
		}
		if(connected)
			rookValue += 0.25f;	// Bonus 0.5 for connected rooks (0.25 each)
		if(piece->getOwner() == 1 && square->getX() == 1)
			rookValue += 0.5f;	// Bonus 0.5 for rook on seventh rank
		else if(piece->getOwner() == -1 && square->getX() == 6)
			rookValue += 0.5f;
		if(piece->getOwner() != 1)
			rookValue *= -1;
	}
	return rookValue * board->whosTurn;
}