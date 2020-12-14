#include "Queen.h"

std::vector <Square*> Queen::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	// copypasted from Rook.cpp cuz why not
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
	// copypasted from Bishop.cpp cuz why not
	int i, j;
	i = x - 1;
	j = y - 1;
	while(board->onBoard(i,j)){
		if(!board->board[i][j]->getPiece())
			ret.push_back(board->board[i][j]);
		else{ 
			if(canCapture(board->board[i][j]))
				ret.push_back(board->board[i][j]);
			break;
		}
		i--;
		j--;
	}
	i = x + 1;
	j = y - 1;
	while(board->onBoard(i,j)){
		if(!board->board[i][j]->getPiece())
			ret.push_back(board->board[i][j]);
		else{ 
			if(canCapture(board->board[i][j]))
				ret.push_back(board->board[i][j]);
			break;
		}
		i++;
		j--;
	}
	i = x - 1;
	j = y + 1;
	while(board->onBoard(i,j)){
		if(!board->board[i][j]->getPiece())
			ret.push_back(board->board[i][j]);
		else{ 
			if(canCapture(board->board[i][j]))
				ret.push_back(board->board[i][j]);
			break;
		}
		i--;
		j++;
	}
	i = x + 1;
	j = y + 1;
	while(board->onBoard(i,j)){
		if(!board->board[i][j]->getPiece())
			ret.push_back(board->board[i][j]);
		else{ 
			if(canCapture(board->board[i][j]))
				ret.push_back(board->board[i][j]);
			break;
		}
		i++;
		j++;
	}
	return ret;
}