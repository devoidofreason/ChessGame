#include "Pawn.h"

std::vector <Square*> Pawn::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	int x1, y1;
	x1 = x - owner;
	y1 = y - 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece())
			ret.push_back(board->board[x1][y1]);
		else{
			if(canCapture(board->board[x1][y1]))
				ret.push_back(board->board[x1][y1]);
			else{
				if(owner==1)
					board->squaresAttackedByWhite[x1][y1] = true;
				else
					board->squaresAttackedByBlack[x1][y1] = true;
			}
		}
	// En passant
	if(board->board[x1 + owner][y1]->getPiece())
		if(board->board[x1 + owner][y1]->getPiece()->getCodeText()=='P' && canCapture(board->board[x1 + owner][y1]))
			if(static_cast<Pawn*>( board->board[x1 + owner][y1]->getPiece() )->getCanBeCapturedEnPassant()){
				ret.push_back(board->board[x1][y1]);
			}
	y1 = y + 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece())
			ret.push_back(board->board[x1][y1]);
		else{
			if(canCapture(board->board[x1][y1]))
				ret.push_back(board->board[x1][y1]);
			else{
				if(owner==1)
					board->squaresAttackedByWhite[x1][y1] = true;
				else
					board->squaresAttackedByBlack[x1][y1] = true;
			}
		}
	// En passant
	if(board->board[x1 + owner][y1]->getPiece())
		if(board->board[x1 + owner][y1]->getPiece()->getCodeText()=='P' && canCapture(board->board[x1 + owner][y1]))
			if(static_cast<Pawn*>( board->board[x1 + owner][y1]->getPiece() )->getCanBeCapturedEnPassant()){
				ret.push_back(board->board[x1][y1]);
			}
	attackSquares(board, ret);
	if(owner==1 && y == 6){
		if(!board->board[x][4]->getPiece())
			ret.push_back(board->board[x][4]);
	}
	if(owner==-1 && y == 1){
		if(!board->board[x][1]->getPiece())
			ret.push_back(board->board[x][1]);
	}
	x1 = x - owner;
	y1 = y;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece())
			ret.push_back(board->board[x1][y1]);
	return ret;
}

void Pawn::enableCaptureEnPassant(){
	canBeCapturedEnPassant = true;
}

void Pawn::updateCanBeCapturedEnPassant(){
	canBeCapturedEnPassant = false;
}

bool Pawn::getCanBeCapturedEnPassant(){
	return canBeCapturedEnPassant;
}

void Pawn::promotePawn(Square* square, Piece* newPiece){
	square->setPiece(newPiece);
	delete this;
}