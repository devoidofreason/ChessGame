#include "Piece.h"

Piece::Piece(int owner){
	this->owner = owner;
	alive = true;
}

int Piece::getOwner(){
	return owner;
}

char Piece::getCodeText(){
	return codeText;
}

bool Piece::isAlive(){
	return alive;
}

void Piece::setCaptured(){
	alive = false;
}

bool Piece::canCapture(Square* square){	// potentially unsafe, nullptr
	return owner != square->getPiece()->getOwner();
}

bool Piece::canMove(Board* board, Square* square1, Square* square2){
	std::vector <Square*> v = possibleSquares(board, square1);
	for(int i=0; i<v.size(); i++)
		if(v[i] == square2)
			return true;
	return false;
}