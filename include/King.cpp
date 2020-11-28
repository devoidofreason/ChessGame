#include "King.h"

std::vector <Square*> King::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	int x1, y1;
	//standard moves
	x1 = x - 1;
	y1 = y - 1;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x + 1;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x - 1;
	y1 = y;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x + 1;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x - 1;
	y1 = y + 1;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	x1 = x + 1;
	if(!board->board[x1][y1]->getPiece())
		if(owner == 1)
			if(!board->squaresAttackedByBlack[x1][y1])
				ret.push_back(board->board[x1][y1]);
		else{
			if(!board->squaresAttackedByWhite[x1][y1])
				ret.push_back(board->board[x1][y1]);
		}		
	else{ 
		if(canCapture(board->board[x1][y1]))
			if(owner == 1)
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
	}
	// todo CASTLES !!!
	return ret;
}

bool Rook::getWasMoved(){
	return wasMoved;
}

void Rook::setWasMoved(){
	wasMoved = true;
}