#include "Bishop.h"

std::vector <Square*> Bishop::possibleSquares(Board* board, Square* square){
	std::vector<Square*> ret;
	int x = square->getX(), y = square->getY();
	int i, j;
	i = x - 1;
	j = y - 1;
	while(board->onBoard(i,j)){
		if(!board->board[i][j]->getPiece())
			ret.push_back(board->board[i][j]);
		else{ 
			if(canCapture(board->board[i][j]))
				ret.push_back(board->board[i][j]);
			else{
				if(owner==1)
					board->squaresAttackedByWhite[i][j] = true;
				else
					board->squaresAttackedByBlack[i][j] = true;
			}
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
			else{
				if(owner==1)
					board->squaresAttackedByWhite[i][j] = true;
				else
					board->squaresAttackedByBlack[i][j] = true;
			}
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
			else{
				if(owner==1)
					board->squaresAttackedByWhite[i][j] = true;
				else
					board->squaresAttackedByBlack[i][j] = true;
			}
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
			else{
				if(owner==1)
					board->squaresAttackedByWhite[i][j] = true;
				else
					board->squaresAttackedByBlack[i][j] = true;
			}
			break;
		}
		i++;
		j++;
	}
	return ret;
}