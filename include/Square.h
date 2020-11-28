#ifndef SQUARE_H
#define SQUARE_H
class Piece;	// forward declarations
class Board;

class Square
{
public:
	Square(int, int, Piece*);
	Piece* getPiece();
	void setPiece(Piece*);
	int getX();
	int getY();
private:
	int x, y;
	Piece* piece;
};

#endif