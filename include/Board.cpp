#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "sha256.h" // Big thanks to Mr. Olivier Gay
// http://www.zedwood.com/article/cpp-sha256-function

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
	whosTurn = 1;

	
	//board[0][4]->setPiece(new King(-1));
	//board[0][0]->setPiece(new Rook(-1));
	//board[0][7]->setPiece(new Rook(-1));
	
	// c42a1a1ec5a6754640b51381c05fe85c41c434649640ec8fca9533604ab5d6d6
	// c94ccbe2b484884f772bf89484f3e3469fd2dc3dd207933de856add7cbf02329
	// 193406973
	// 193406974
 	
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
	calculateHashCode();
}

Board::Board(Board* parent){
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
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			if(newPiece = parent->board[i][j]->getPiece()){
				char codeText = newPiece->getCodeText();
				if(codeText == 'R')
					newPiece = new Rook(newPiece);
				else if(codeText == 'B')
					newPiece = new Bishop(newPiece);
				else if(codeText == 'Q')
					newPiece = new Queen(newPiece);
				else if(codeText == 'N')
					newPiece = new Knight(newPiece);
				else if(codeText == 'K')
					newPiece = new King(newPiece);
				else
					newPiece = new Pawn(newPiece);
				pieces.push_back(newPiece);
				board[i][j]->setPiece(newPiece);
			}
}

bool Board::onBoard(int x, int y){
	return (x>=0 && x<8) ? ( (y>=0 && y<8) ? true : false ) : false;
}

Square* Board::resolveSquareCode(std::string squareCode){
	if(squareCode.length()<2)
		return 0;
	int x = (int)('8' - squareCode[1]);
	int y = (int)(squareCode[0] - 'a');
	if(onBoard(x, y))
		return board[x][y];
	return 0;
}

void Board::printBoard(){
	system("cls");
	std::cout << "  ";
	for(int i=0; i<8; i++)
		std::cout << " " << char('a' + i) << " ";
	for(int i=0; i<8; i++){
		std::cout << "\n\n" << char('8' - i) << " ";
		for(int j=0; j<8; j++){
			if(board[i][j]->getPiece())
				std::cout << ( (board[i][j]->getPiece()->getOwner() == -1 ) ? "-" : " " )
					<< board[i][j]->getPiece()->getCodeText();
			else
				std::cout  << " " << char(176);
			std::cout << " ";
		}
	}
	std::cout << "\n";
}

void Board::printBoard(Square* square){
	system("cls");
	if(!square)
		return;
	if(!square->getPiece())
		return;
	std::vector <Square*> possibleSquares = square->getPiece()->possibleSquares(this, square);
	std::cout << "  ";
	for(int i=0; i<8; i++)
		std::cout << " " << char('a' + i) << " ";
	for(int i=0; i<8; i++){
		std::cout << "\n\n" << char('8' - i) << " ";
		for(int j=0; j<8; j++){
			if(board[i][j]->getPiece())
				std::cout << ( (board[i][j]->getPiece()->getOwner() == -1 ) ? "-" : " " )
					<< board[i][j]->getPiece()->getCodeText();
			else
				std::cout  << " " << char(176);
			std::cout << ( (std::find(possibleSquares.begin(), possibleSquares.end(), board[i][j]) != possibleSquares.end()) ? "<" : " ");
		}
	}
	std::cout << "\n";
	std::cout << "  ";
	for(int i=0; i<8; i++)
		std::cout << char('a' + i) << " ";
	for(int i=0; i<8; i++){
		std::cout << "\n\n" << char('8' - i) << " ";
		for(int j=0; j<8; j++)
			std::cout << squaresAttackedByWhite[i][j] << " ";
	}
	std::cout << "\n";
}


std::vector <Board*> Board::generateChildren(){ // TO DO
	std::vector <Board*> ret;
	for(int i=0; i<pieces.size(); i++){

	}
	return ret;
}

void Board::calculateHashCode(){
	std::string gameStateString = "";
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++){
			Piece* piece = board[i][j]->getPiece();
			if(!piece)
				gameStateString += 'e';
			else{
				char codeText = piece->getCodeText();
				gameStateString += (piece->getOwner() == 1) ? 'W' : 'B';
				if(codeText == 'K')
					gameStateString += (static_cast<King*>(piece)->getWasMoved()) ? '1' : '0';
				else if(codeText == 'R')
					gameStateString += (static_cast<Rook*>(piece)->getWasMoved()) ? '1' : '0';
				else if(codeText == 'P')
					gameStateString += (static_cast<Pawn*>(piece)->getCanBeCapturedEnPassant()) ? '1' : '0';
				gameStateString += codeText;
			}
		}

	const char* gameStateByteSha256 = sha256(gameStateString).c_str(); // Big thanks : http://www.zedwood.com/article/cpp-sha256-function

	hashCode = 5381; // Big thanks : http://www.cse.yorku.ca/~oz/hash.html
	int c;
	while (c = *gameStateByteSha256++)
		hashCode = ((hashCode << 5) + hashCode) + c; /* hash * 33 + c */

	delete gameStateByteSha256;
	std::cout << hashCode << "\n";
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