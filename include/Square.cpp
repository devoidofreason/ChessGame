#include "Square.h"

Square::Square(int x, int y, Piece* piece){
	this->x = x;
	this->y = y;
	this->piece = piece;
}

Piece* Square::getPiece(){
	return piece;
}

void Square::setPiece(Piece* piece){
	this->piece = piece;
}

int Square::getX(){
	return x;
}

int Square::getY(){
	return y;
}