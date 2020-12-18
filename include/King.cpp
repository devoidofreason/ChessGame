#include "King.h"
#include "Rook.h"
#include <iostream>

std::vector<Square*> King::possibleSquares(Board* board, Square* square){
	std::vector <Square*> ret;
	int x = square->getX(), y = square->getY();
	// Standard moves
	for(int i = x-1; i <= x+1; i++)
		for(int j = y-1; j <= y+1; j++)
			if(board->onBoard(i, j) && (i != x || j != y))
				if(!board->board[i][j]->getPiece() || canCapture(board->board[i][j]))
					if(!isInCheck(board, board->board[i][j]))
						ret.push_back(board->board[i][j]);
	// Castels
	if( (!wasMoved) && (!isInCheck(board, square)) ){
		if(owner == 1){
			if(	// White queen side castels
				board->board[7][0]->getPiece() &&
				!board->board[7][1]->getPiece() &&
				!board->board[7][2]->getPiece() &&
				!board->board[7][3]->getPiece()
				)
				if(board->board[7][0]->getPiece()->getCodeText() == 'R'){
					if(
						!static_cast<Rook*>( board->board[7][0]->getPiece() )->getWasMoved() &&
						!isInCheck(board, board->board[7][2]) &&
						!isInCheck(board, board->board[7][3])
						)
						ret.push_back(board->board[7][2]);
				}
			if(	// White king side castles
				board->board[7][7]->getPiece() &&
				!board->board[7][6]->getPiece() &&
				!board->board[7][5]->getPiece()
				)
				if(board->board[7][7]->getPiece()->getCodeText() == 'R'){
					if(
						!static_cast<Rook*>( board->board[7][7]->getPiece() )->getWasMoved() &&
						!isInCheck(board, board->board[7][6]) &&
						!isInCheck(board, board->board[7][5])
						)
						ret.push_back(board->board[7][6]);
				}
		}
		else{
			if(	// Black queen side castels
				board->board[0][0]->getPiece() &&
				!board->board[0][1]->getPiece() &&
				!board->board[0][2]->getPiece() &&
				!board->board[0][3]->getPiece()
				)
				if(board->board[0][0]->getPiece()->getCodeText() == 'R'){
					if(
						!static_cast<Rook*>( board->board[0][0]->getPiece() )->getWasMoved() &&
						!isInCheck(board, board->board[0][2]) &&
						!isInCheck(board, board->board[0][3])
						)
						ret.push_back(board->board[0][2]);
				}
			if(	// Black king side castles
				board->board[0][7]->getPiece() &&
				!board->board[0][6]->getPiece() &&
				!board->board[0][5]->getPiece()
				)
				if(board->board[0][7]->getPiece()->getCodeText() == 'R'){
					if(
						!static_cast<Rook*>( board->board[0][7]->getPiece() )->getWasMoved() &&
						!isInCheck(board, board->board[0][6]) &&
						!isInCheck(board, board->board[0][5])
						)
						ret.push_back(board->board[0][6]);
				}
		}
	}
	return ret;
}

bool King::isInCheck(Board* board, Square* square){ // Thats enough of such troubles
	int x = square->getX(), y = square->getY();
	// Rooks rays - a bit copypasted from Rook.cpp
	// Must check if enemy rook or queen at the end of a given ray
	Piece* piece;
	for(int i = x - 1; board->onBoard(i, y); i--)
		if(piece = board->board[i][y]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'R'
					)
				)
				return true;
			else
				break;
	for(int i = x + 1; board->onBoard(i, y); i++)
		if(piece = board->board[i][y]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'R'
					)
				)
				return true;
			else
				break;
	for(int i = y - 1; board->onBoard(x, i); i--)
		if(piece = board->board[x][i]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'R'
					)
				)
				return true;
			else
				break;
	for(int i = y + 1; board->onBoard(x, i); i++)
		if(piece = board->board[x][i]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'R'
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
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'B'
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
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'B'
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
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'B'
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
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
					(
					piece->getCodeText() == 'Q' ||
					piece->getCodeText() == 'B'
					)
				)
				return true;
			else
				break;
		i++;
		j++;
	}
	// Pawn rays ?
	// Rays or not - must check if king checked by a pawn
	i = x - owner;
	j = y - 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'P'
				)
				return true;
	j = y + 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'P'
				)
				return true;
	// Knight rays
	// Ofc once again - does hostille knight attack this square?
	i = x - 2;
	j = y - 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	j = y + 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	i = x + 2;
	j = y - 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	j = y + 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	i = x - 1;
	j = y - 2;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	i = x + 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	i = x - 1;
	j = y + 2;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	i = x + 1;
	if(board->onBoard(i, j))
		if(piece = board->board[i][j]->getPiece())
			if(
				piece->getOwner() != owner && 
				piece->getCodeText() == 'N'
				)
				return true;
	// Finally kings rays
	// Imagine duel of kings
	for(int i = x-1; i <= x+1; i++)
		for(int j = y-1; j <= y+1; j++)
			if(board->onBoard(i, j) && (i != x || j != y))
				if(piece = board->board[i][j]->getPiece())
					if(
						piece->getOwner() != owner && 
						piece->getCodeText() == 'K'
						)
						return true;
	return false;
}

bool King::getWasMoved(){
	return wasMoved;
}

void King::setWasMoved(){
	wasMoved = true;
}