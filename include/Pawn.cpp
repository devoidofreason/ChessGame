#include "Pawn.h"

std::vector<Square*> Pawn::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	int x1, y1;
	x1 = x - owner;
	y1 = y - 1;
	if(board->onBoard(x1, y1)){
		if(canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	}
	// En passant
	if(board->onBoard(x1, y1))
		if(canCapture(board->board[x][y1]))
			if(board->board[x][y1]->getPiece()->getCodeText()=='P')
				if(static_cast<Pawn*>(board->board[x][y1]->getPiece())->getCanBeCapturedEnPassant())
					ret.push_back(board->board[x1][y1]);
	y1 = y + 1;
	if(board->onBoard(x1, y1)){
		if(canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	}
	// En passant
	if(board->onBoard(x1, y1))
		if(canCapture(board->board[x][y1]))
			if(board->board[x][y1]->getPiece()->getCodeText()=='P')
				if(static_cast<Pawn*>(board->board[x][y1]->getPiece())->getCanBeCapturedEnPassant())
					ret.push_back(board->board[x1][y1]);
	y1 = y;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece())
			ret.push_back(board->board[x1][y1]);
	if(owner==1 && x == 6){
		if(!board->board[4][y]->getPiece() &&
			!board->board[5][y]->getPiece()
			)
			ret.push_back(board->board[4][y]);
	}
	if(owner==-1 && x == 1){
		if(!board->board[3][y]->getPiece() &&
			!board->board[2][y]->getPiece()
			)
			ret.push_back(board->board[3][y]);
	}
	return ret;
}

void Pawn::enableCaptureEnPassant(){
	canBeCapturedEnPassant = true;
}

void Pawn::disallowCaptureEnPassant(){
	canBeCapturedEnPassant = false;
}

bool Pawn::getCanBeCapturedEnPassant(){
	return canBeCapturedEnPassant;
}