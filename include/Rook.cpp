#include "Rook.h"

std::vector <Square*> Rook::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	for(int i = x - 1; board->onBoard(i, y); i--){
		if(!board->board[i][y]->getPiece())
			ret.push_back(board->board[i][y]);
		else{
			if(canCapture(board->board[i][y]))
				ret.push_back(board->board[i][y]);
			break;
		}
	}
	for(int i = x + 1; board->onBoard(i, y); i++){
		if(!board->board[i][y]->getPiece())
			ret.push_back(board->board[i][y]);
		else{ 
			if(canCapture(board->board[i][y]))
				ret.push_back(board->board[i][y]);
			break;
		}
	}
	for(int i = y - 1; board->onBoard(x, i); i--){
		if(!board->board[x][i]->getPiece())
			ret.push_back(board->board[x][i]);
		else{ 
			if(canCapture(board->board[x][i]))
				ret.push_back(board->board[x][i]);
			break;
		}
	}
	for(int i = y + 1; board->onBoard(x, i); i++){
		if(!board->board[x][i]->getPiece())
			ret.push_back(board->board[x][i]);
		else{ 
			if(canCapture(board->board[x][i]))
				ret.push_back(board->board[x][i]);
			break;
		}
	}
	return ret;
}

bool Rook::getWasMoved(){
	return wasMoved;
}

void Rook::setWasMoved(){
	wasMoved = true;
}