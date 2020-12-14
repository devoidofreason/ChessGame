#include "Knight.h"

std::vector <Square*> Knight::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	int x1, y1;
	x1 = x - 2;
	y1 = y - 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	y1 = y + 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	x1 = x + 2;
	y1 = y - 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	y1 = y + 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	x1 = x - 1;
	y1 = y - 2;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	x1 = x + 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	x1 = x - 1;
	y1 = y + 2;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	x1 = x + 1;
	if(board->onBoard(x1, y1))
		if(!board->board[x1][y1]->getPiece() || canCapture(board->board[x1][y1]))
			ret.push_back(board->board[x1][y1]);
	return ret;
}