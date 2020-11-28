#include "Knight.h"

std::vector <Square*> Knight::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	int x1, y1;
	x1 = x - 2;
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
	x1 = x + 2;
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
	x1 = x - 1;
	y1 = y - 2;
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
	x1 = x + 1;
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
	x1 = x - 1;
	y1 = y + 2;
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
	x1 = x + 1;
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
	return ret;
}