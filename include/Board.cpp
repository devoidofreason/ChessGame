#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include <iostream>
#include <Windows.h>

Board::Board(){
	board = new Square** [8];
	squaresAttackedByWhite = new bool* [8];
	squaresAttackedByBlack = new bool* [8];
	for(int i=0; i<8; i++){
		board[i] = new Square* [8];
		squaresAttackedByWhite[i] = new bool [8];
		squaresAttackedByBlack[i] = new bool [8];
		for(int j=0; j<8; j++){
			board[i][j] = new Square(i, j);
			squaresAttackedByWhite[i][j] = false;
			squaresAttackedByBlack[i][j] = false;
		}
	}

	Piece* newPiece;
	int owner = -1; // Firstsly: black pieces
	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[0][0]->setPiece(newPiece);
	newPiece = new Knight(owner);
	pieces.push_back(newPiece);
	board[0][1]->setPiece(newPiece);
	newPiece = new Bishop(owner);
	pieces.push_back(newPiece);
	board[0][2]->setPiece(newPiece);
	newPiece = new Queen(owner);
	pieces.push_back(newPiece);
	board[0][3]->setPiece(newPiece);
	newPiece = new King(owner);
	pieces.push_back(newPiece);
	board[0][4]->setPiece(newPiece);
	newPiece = new Bishop(owner);
	pieces.push_back(newPiece);
	board[0][5]->setPiece(newPiece);
	newPiece = new Knight(owner);
	pieces.push_back(newPiece);
	board[0][6]->setPiece(newPiece);
	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[0][7]->setPiece(newPiece);
	for(int i=0; i<8; i++){ // Black pawns
		newPiece = new Pawn(owner);
		pieces.push_back(newPiece);
		board[1][i]->setPiece(newPiece);
	}

	owner = 1; // Now white pieces, first to move so last to be set up :D
	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[7][0]->setPiece(newPiece);
	newPiece = new Knight(owner);
	pieces.push_back(newPiece);
	board[7][1]->setPiece(newPiece);
	newPiece = new Bishop(owner);
	pieces.push_back(newPiece);
	board[7][2]->setPiece(newPiece);
	newPiece = new Queen(owner);
	pieces.push_back(newPiece);
	board[7][3]->setPiece(newPiece);
	newPiece = new King(owner);
	pieces.push_back(newPiece);
	board[7][4]->setPiece(newPiece);
	newPiece = new Bishop(owner);
	pieces.push_back(newPiece);
	board[7][5]->setPiece(newPiece);
	newPiece = new Knight(owner);
	pieces.push_back(newPiece);
	board[7][6]->setPiece(newPiece);
	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[7][7]->setPiece(newPiece);
	for(int i=0; i<8; i++){ // White pawns
		newPiece = new Pawn(owner);
		pieces.push_back(newPiece);
		board[6][i]->setPiece(newPiece);
	}

}

bool Board::onBoard(int x, int y){
	return (x>=0 && x<8) ? ( (y>=0 && y<8) ? true : false ) : false;
}

void Board::printBoard(){
	std::cout << "  ";
	for(int i=0; i<8; i++)
		std::cout << char('a' + i) << " ";
	for(int i=0; i<8; i++){
		std::cout << "\n\n" << char('8' - i) << " ";
		for(int j=0; j<8; j++){
			if(board[i][j]->getPiece())
				std::cout << board[i][j]->getPiece()->getCodeText();
			else
				std::cout << char(176);
			std::cout << " ";
		}
	}
	std::cout << "\n";
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
	for(int i=0; i<pieces.size(); i++)
		delete pieces[i];
	pieces.clear();
}