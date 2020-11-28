#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include <iostream>

Board::Board(){
	board = new Square** [8];
	pieces = new Piece* [32];
	squaresAttackedByWhite = new bool* [8];
	squaresAttackedByBlack = new bool* [8];
	for(int i=0; i<8; i++){
		board[i] = new Square* [8];
		squaresAttackedByWhite[i] = new bool [8];
		squaresAttackedByBlack[i] = new bool [8];
		for(int j=0; j<8; j++){
			board[i][j] = new Square(i, j, 0);
			squaresAttackedByWhite[i][j] = false;
			squaresAttackedByBlack[i][j] = false;
		}
	}

	board[1][1]->setPiece(new Queen(1));
	board[3][1]->setPiece(new Rook(1));
	board[1][3]->setPiece(new Rook(-1));
	std::vector <Square*> test = board[1][1]->getPiece()->possibleSquares(this, board[1][1]);
	for(int i=0; i<test.size(); i++){
		std::cout << test[i]->getX() << " " << test[i]->getY() << "\n";
	}
}

bool Board::onBoard(int x, int y){
	return (x>=0 && x<8) ? ( (y>=0 && y<8) ? true : false ) : false;
}

Board::~Board(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
			delete board[i][j];
		delete [] board[i];
		delete [] squaresAttackedByWhite[i];
		delete [] squaresAttackedByBlack[i];
	}
	delete [] board;
	delete [] squaresAttackedByWhite;
	delete [] squaresAttackedByBlack;
	for(int i=0; i<32; i++)
		delete pieces[i];
	delete [] pieces;
}