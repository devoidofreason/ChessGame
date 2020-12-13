#include "King.h"
#include "Rook.h"
#include <iostream>

std::vector <Square*> King::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	int x1, y1;
	// Standard moves
	x1 = x - 1;
	y1 = y - 1;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	x1 = x;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	x1 = x + 1;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	x1 = x - 1;
	y1 = y;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	x1 = x + 1;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	x1 = x - 1;
	y1 = y + 1;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	x1 = x;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	x1 = x + 1;
	if(board->onBoard(x1, y1)){
		if(owner == 1)
			board->squaresAttackedByWhite[x1][y1] = true;
		else
			board->squaresAttackedByBlack[x1][y1] = true;
		if(!board->board[x1][y1]->getPiece())
			if(owner == 1){
				if(!board->squaresAttackedByBlack[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
			else{
				if(!board->squaresAttackedByWhite[x1][y1])
					ret.push_back(board->board[x1][y1]);
			}
		else{
			if(canCapture(board->board[x1][y1]))
				if(owner == 1){
					if(!board->squaresAttackedByBlack[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
				else{
					if(!board->squaresAttackedByWhite[x1][y1])
						ret.push_back(board->board[x1][y1]);
				}
		}
	}
	// Castels
	if(!wasMoved && !isInCheck) // TO DO
		if(owner == 1){
			if(	// White queen side castels
				board->board[7][0]->getPiece() &&
				!board->board[7][1]->getPiece() &&
				!board->board[7][2]->getPiece() &&
				!board->board[7][3]->getPiece()
				)
				if(board->board[7][0]->getPiece()->getCodeText()=='R'){	
					if(
						!static_cast<Rook*>( board->board[7][0]->getPiece() )->getWasMoved() &&
						!board->squaresAttackedByBlack[7][2] &&
						!board->squaresAttackedByBlack[7][3]
						)
						ret.push_back(board->board[7][2]);
				}
			if(	// White king side castles
				board->board[7][7]->getPiece() &&
				!board->board[7][6]->getPiece() &&
				!board->board[7][5]->getPiece()
				)
				if(board->board[7][7]->getPiece()->getCodeText()=='R')
					if(
						!static_cast<Rook*>( board->board[7][7]->getPiece() )->getWasMoved() &&
						!board->squaresAttackedByBlack[7][6] &&
						!board->squaresAttackedByBlack[7][5]
						)
						ret.push_back(board->board[7][6]);
		}
		else{
			if(	// Black queen side castels
				board->board[0][0]->getPiece() &&
				!board->board[0][1]->getPiece() &&
				!board->board[0][2]->getPiece() &&
				!board->board[0][3]->getPiece()
				)
				if(board->board[0][0]->getPiece()->getCodeText()=='R')
					if(
						!static_cast<Rook*>( board->board[0][0]->getPiece() )->getWasMoved() &&
						!board->squaresAttackedByWhite[0][2] &&
						!board->squaresAttackedByWhite[0][3]
						)
						ret.push_back(board->board[0][2]);
			if(	// Black king side castles
				board->board[0][7]->getPiece() &&
				!board->board[0][6]->getPiece() &&
				!board->board[0][5]->getPiece()
				)
				if(board->board[0][7]->getPiece()->getCodeText()=='R')
					if(
						!static_cast<Rook*>( board->board[0][7]->getPiece() )->getWasMoved() &&
						!board->squaresAttackedByWhite[0][6] &&
						!board->squaresAttackedByWhite[0][5]
						)
						ret.push_back(board->board[0][6]);
		}
	return ret;
}

bool King::isInCheckAfterSelfDiscovery(Board* board, Square* square){ // Thats enough of such troubles
	int x = square->getX(), y = square->getY();
	// Rooks rays - a bit copypasted from Rook.cpp
	// Must check if enemy rook or queen at the end of a given ray
	for(int i = x - 1; board->onBoard(i, y); i--)
		if(board->board[i][y]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'R'
					)
				)
				return true;
			else
				break;
	for(int i = x + 1; board->onBoard(i, y); i++)
		if(board->board[i][y]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'R'
					)
				)
				return true;
			else
				break;
	for(int i = y - 1; board->onBoard(x, i); i--)
		if(board->board[x][i]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'R'
					)
				)
				return true;
			else
				break;
	for(int i = y + 1; board->onBoard(x, i); i++)
		if(board->board[x][i]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'R'
					)
				)
				return true;
			else
				break;
	// Bishops rays - a bit copypasted from Bishop.cpp
	// Must check if enemy bishop or queen at the end of a given ray
	int i, j;
	i = x - 1;
	j = y - 1;
	while(board->onBoard(i,j)){
		if(board->board[i][j]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'B'
					)
				)
				return true;
			else
				break;
		i--;
		j--;
	}
	i = x + 1;
	j = y - 1;
	while(board->onBoard(i,j)){
		if(board->board[i][j]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'B'
					)
				)
				return true;
			else
				break;
		i++;
		j--;
	}
	i = x - 1;
	j = y + 1;
	while(board->onBoard(i,j)){
		if(board->board[i][j]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'B'
					)
				)
				return true;
			else
				break;
		i--;
		j++;
	}
	i = x + 1;
	j = y + 1;
	while(board->onBoard(i,j)){
		if(board->board[i][j]->getPiece())
			if(
				board->board[i][y]->getPiece()->getOwner() != owner && 
					(
					board->board[i][y]->getPiece()->getCodeText() == 'Q' ||
					board->board[i][y]->getPiece()->getCodeText() == 'B'
					)
				)
				return true;
			else
				break;
		i++;
		j++;
	}
	return false;
}

bool King::getWasMoved(){
	return wasMoved;
}

void King::setWasMoved(){
	wasMoved = true;
}

bool King::getIsInCheck(){
	return isInCheck;
}

void King::setIsInCheck(bool isInCheck){
	this->isInCheck = isInCheck;
}