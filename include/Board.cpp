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

#include <conio.h>

Board::Board(){
	board = new Square** [8];
	for(int i=0; i<8; i++){
		board[i] = new Square* [8];
		for(int j=0; j<8; j++)
			board[i][j] = new Square(i, j);
	}

	whosTurn = 1;
 	
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

	blackKingPos = board[0][4];
	whiteKingPos = board[7][4];
	
	calculateHashCode();
}

Board::Board(Board* parent){
	board = new Square** [8];
	for(int i=0; i<8; i++){
		board[i] = new Square* [8];
		for(int j=0; j<8; j++)
			board[i][j] = new Square(i, j);
	}
	whosTurn = -parent->whosTurn;

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

	int x, y;
	x = parent->whiteKingPos->getX();
	y = parent->whiteKingPos->getY();
	whiteKingPos = board[x][y];
	x = parent->blackKingPos->getX();
	y = parent->blackKingPos->getY();
	blackKingPos = board[x][y];
}

bool Board::onBoard(int x, int y){
	return (x>=0 && x<8) ? ( (y>=0 && y<8) ? true : false ) : false;
}

Square* Board::resolveSquareCode(std::string squareCode){
	if(squareCode.length() < 2)
		return 0;
	int x = (int)('8' - squareCode[1]);
	int y = (int)(squareCode[0] - 'a');
	if(onBoard(x, y))
		return board[x][y];
	return 0;
}

void Board::printBoard(){
	system("cls");
	std::cout << "     ";
	for(int i=0; i<8; i++)
		std::cout << " " << char('a' + i) << " ";
	std::cout << "\n";
	for(int i=0; i<8; i++){
		std::cout << "\n\n" << char('8' - i) << "    ";
		for(int j=0; j<8; j++){
			if(board[i][j]->getPiece())
				std::cout << ( (board[i][j]->getPiece()->getOwner() == -1 ) ? "-" : " " )
					<< board[i][j]->getPiece()->getCodeText();
			else
				std::cout  << " " << char(176);
			std::cout << " ";
		}
	}
	std::cout << "\n\n" << stringHashCode << "\n" << hashCode << "\n\n";
}

void Board::printBoard(Square* square){
	system("cls");
	if(!square)
		return;
	if(!square->getPiece())
		return;
	std::vector<Square*> possibleSquares = square->getPiece()->possibleSquares(this, square);
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
	std::cout << "\n" << stringHashCode << "\n" << hashCode << "\n";
}

std::vector<Board*> Board::generateChildren(){
	Board* newState;
	std::vector<Board*> ret;
	Piece* piece;
	Piece* capturedPiece;
	std::vector<Square*> possibleSquares;
	Square* whiteKingPos;
	Square* blackKingPos;
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			if(piece = board[i][j]->getPiece()){
				char codeText = piece->getCodeText();
				if(whosTurn != piece->getOwner())
					continue;
				possibleSquares = piece->possibleSquares(this, board[i][j]);
				if(codeText == 'P'){ // Pawns
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						newState = new Board(this);
						if(whosTurn == piece->getOwner())
							static_cast<Pawn*>(newState->board[i][j]->getPiece())->updateCanBeCapturedEnPassant();
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							delete capturedPiece;
						}
						else if(y != j && !newState->board[x][y]->getPiece()){ // En passant - execute
							capturedPiece = newState->board[x + piece->getOwner()][y]->getPiece();
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							delete capturedPiece;
							newState->board[x + piece->getOwner()][y]->setPiece(0);
						}
						else if( x == i - (2 * piece->getOwner()) ) // En passant - allow
							static_cast<Pawn*>(newState->board[i][j]->getPiece())->enableCaptureEnPassant();
						else if(x == 0 || x == 7){ // Promotion
							Piece* newPiece;
							Board* newStateAfterPromotion;
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							newStateAfterPromotion = new Board(newState); // Queen
							newPiece = new Queen(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							if(whosTurn == 1){
								if(static_cast<King*>(newStateAfterPromotion->whiteKingPos->getPiece())->isInCheck(newStateAfterPromotion, newStateAfterPromotion->whiteKingPos)){
									delete newState;
									delete newStateAfterPromotion;
									delete newPiece;
									continue;
								}
							}
							else{
								if(static_cast<King*>(newStateAfterPromotion->blackKingPos->getPiece())->isInCheck(newStateAfterPromotion, newStateAfterPromotion->blackKingPos)){
									delete newState;
									delete newStateAfterPromotion;
									delete newPiece;
									continue;
								}
							}
							newStateAfterPromotion->calculateHashCode();
							ret.push_back(newStateAfterPromotion);
							newStateAfterPromotion = new Board(newState); // Rook
							newPiece = new Rook(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							newStateAfterPromotion->calculateHashCode();
							ret.push_back(newStateAfterPromotion);
							newStateAfterPromotion = new Board(newState); // Bishop
							newPiece = new Bishop(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							newStateAfterPromotion->calculateHashCode();
							ret.push_back(newStateAfterPromotion);
							newStateAfterPromotion = new Board(newState); // Knight
							newPiece = new Knight(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							newStateAfterPromotion->calculateHashCode();
							ret.push_back(newStateAfterPromotion);
							delete newState;
							continue;
						}
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						if(whosTurn == 1){
							if(static_cast<King*>(newState->whiteKingPos->getPiece())->isInCheck(newState, newState->whiteKingPos)){
									delete newState;
									continue;
								}
							}
						else{
							if(static_cast<King*>(newState->blackKingPos->getPiece())->isInCheck(newState, newState->blackKingPos)){
								delete newState;
								continue;
							}
						}
						newState->calculateHashCode();
						ret.push_back(newState);
					}
				} 
				else if(codeText == 'R'){ // Rooks
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						newState = new Board(this);
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							delete capturedPiece;
						}
						static_cast<Rook*>(newState->board[i][j]->getPiece())->setWasMoved(); // Rook - moved?
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						if(whosTurn == 1){
							if(static_cast<King*>(newState->whiteKingPos->getPiece())->isInCheck(newState, newState->whiteKingPos)){
								delete newState;
								continue;
							}
						}
						else{
							if(static_cast<King*>(newState->blackKingPos->getPiece())->isInCheck(newState, newState->blackKingPos)){
								delete newState;
								continue;
							}
						}
						newState->calculateHashCode();
						ret.push_back(newState);
					}
				}
				else if(codeText == 'K'){ // Kings
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						newState = new Board(this);
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), capturedPiece), newState->pieces.end());
							delete capturedPiece;
						}
						if(y == i + 2){ // Queen side castles
							newState->board[x][3]->setPiece(newState->board[x][0]->getPiece());
							newState->board[x][0]->setPiece(0);
							newState->board[x][2]->setPiece(newState->board[x][4]->getPiece());
							newState->board[x][4]->setPiece(0);
							newState->calculateHashCode();
							ret.push_back(newState);
							continue;
						}
						else if(y == i - 2){ // King side castles
							newState->board[x][5]->setPiece(newState->board[x][7]->getPiece());
							newState->board[x][7]->setPiece(0);
							newState->board[x][6]->setPiece(newState->board[x][4]->getPiece());
							newState->board[x][4]->setPiece(0);
							newState->calculateHashCode();
							ret.push_back(newState);
							continue;
						}
						if(whosTurn == 1){
							static_cast<King*>(newState->whiteKingPos->getPiece())->setWasMoved();
							newState->whiteKingPos = newState->board[x][y];
						}
						else{
							static_cast<King*>(newState->blackKingPos->getPiece())->setWasMoved();
							newState->blackKingPos = newState->board[x][y];
						}
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						newState->calculateHashCode();
						ret.push_back(newState);
					}
				}
				else{ // Other pieces
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						newState = new Board(this);
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), capturedPiece), newState->pieces.end());
							delete capturedPiece;
						}
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						if(whosTurn == 1){
							if(static_cast<King*>(newState->whiteKingPos->getPiece())->isInCheck(newState, newState->whiteKingPos)){
								delete newState;
								continue;
							}
						}
						else{
							if(static_cast<King*>(newState->blackKingPos->getPiece())->isInCheck(newState, newState->blackKingPos)){
								delete newState;
								continue;
							}
						}
						newState->calculateHashCode();
						ret.push_back(newState);
					}
				}
				possibleSquares.clear();
			}
	return ret;
}

std::vector<Board*> Board::generateChildren(std::vector<std::string>* labels){
	Board* newState;
	std::vector<Board*> ret;
	Piece* piece;
	Piece* capturedPiece;
	std::vector<Square*> possibleSquares;
	Square* whiteKingPos;
	Square* blackKingPos;
	std::string label1, label2;
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			if(piece = board[i][j]->getPiece()){
				char codeText = piece->getCodeText();
				if(whosTurn != piece->getOwner())
					continue;
				label1 = "";
				label1 += (whosTurn == -1 ) ? "-" : " ";
				label1 += codeText;
				label1 += " ";
				label1 += char('a' + j);
				label1 += char('8' - i);
				label1 += " -> ";
				possibleSquares = piece->possibleSquares(this, board[i][j]);
				if(codeText == 'P'){ // Pawns
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						label2 = label1;
						label2 += char('a' + y);
						label2 += char('8' - x);
						label2 += " ";
						newState = new Board(this);
						if(whosTurn == piece->getOwner())
							static_cast<Pawn*>(newState->board[i][j]->getPiece())->updateCanBeCapturedEnPassant();
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							delete capturedPiece;
							label2 += "x ";
						}
						else if(y != j && !newState->board[x][y]->getPiece()){ // En passant - execute
							capturedPiece = newState->board[x + piece->getOwner()][y]->getPiece();
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							delete capturedPiece;
							newState->board[x + piece->getOwner()][y]->setPiece(0);
							label2 += "xEn ";
						}
						else if( x == i - (2 * piece->getOwner()) ) // En passant - allow
							static_cast<Pawn*>(newState->board[i][j]->getPiece())->enableCaptureEnPassant();
						if(x == 0 || x == 7){ // Promotion
							std::string tmp;
							Piece* newPiece;
							Board* newStateAfterPromotion;
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							newStateAfterPromotion = new Board(newState); // Queen
							newPiece = new Queen(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							if(whosTurn == 1){
								if(static_cast<King*>(newStateAfterPromotion->whiteKingPos->getPiece())->isInCheck(newStateAfterPromotion, newStateAfterPromotion->whiteKingPos)){
									delete newState;
									delete newStateAfterPromotion;
									delete newPiece;
									continue;
								}
							}
							else{
								if(static_cast<King*>(newStateAfterPromotion->blackKingPos->getPiece())->isInCheck(newStateAfterPromotion, newStateAfterPromotion->blackKingPos)){
									delete newState;
									delete newStateAfterPromotion;
									delete newPiece;
									continue;
								}
							}
							newStateAfterPromotion->calculateHashCode();
							tmp = label2 + " -> Q";
							labels->push_back(tmp);
							ret.push_back(newStateAfterPromotion);
							newStateAfterPromotion = new Board(newState); // Rook
							newPiece = new Rook(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							newStateAfterPromotion->calculateHashCode();
							tmp = label2 + " -> R";
							labels->push_back(tmp);
							ret.push_back(newStateAfterPromotion);
							newStateAfterPromotion = new Board(newState); // Bishop
							newPiece = new Bishop(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							newStateAfterPromotion->calculateHashCode();
							tmp = label2 + " -> B";
							labels->push_back(tmp);
							ret.push_back(newStateAfterPromotion);
							newStateAfterPromotion = new Board(newState); // Knight
							newPiece = new Knight(piece->getOwner());
							static_cast<Pawn*>(newStateAfterPromotion->board[i][j]->getPiece())->promotePawn(newStateAfterPromotion->board[x][y], newPiece);
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[i][j]->setPiece(0);
							newStateAfterPromotion->calculateHashCode();
							tmp = label2 + " -> N";
							labels->push_back(tmp);
							ret.push_back(newStateAfterPromotion);
							delete newState;
							continue;
						}
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						if(whosTurn == 1){
							if(static_cast<King*>(newState->whiteKingPos->getPiece())->isInCheck(newState, newState->whiteKingPos)){
									delete newState;
									continue;
								}
							}
						else{
							if(static_cast<King*>(newState->blackKingPos->getPiece())->isInCheck(newState, newState->blackKingPos)){
								delete newState;
								continue;
							}
						}
						newState->calculateHashCode();
						labels->push_back(label2);
						ret.push_back(newState);
					}
				} 
				else if(codeText == 'R'){ // Rooks
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						label2 = label1;
						label2 += char('a' + y);
						label2 += char('8' - x);
						label2 += " ";
						newState = new Board(this);
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[x][y]->getPiece()), newState->pieces.end());
							delete capturedPiece;
						}
						static_cast<Rook*>(newState->board[i][j]->getPiece())->setWasMoved(); // Rook - moved?
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						if(whosTurn == 1){
							if(static_cast<King*>(newState->whiteKingPos->getPiece())->isInCheck(newState, newState->whiteKingPos)){
								delete newState;
								continue;
							}
						}
						else{
							if(static_cast<King*>(newState->blackKingPos->getPiece())->isInCheck(newState, newState->blackKingPos)){
								delete newState;
								continue;
							}
						}
						newState->calculateHashCode();
						labels->push_back(label2);
						ret.push_back(newState);
					}
				}
				else if(codeText == 'K'){ // Kings
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						label2 = label1;
						label2 += char('a' + y);
						label2 += char('8' - x);
						label2 += " ";
						newState = new Board(this);
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), capturedPiece), newState->pieces.end());
							delete capturedPiece;
							label2 += "x ";
						}
						if(y == i + 2){ // Queen side castles
							newState->board[x][3]->setPiece(newState->board[x][0]->getPiece());
							newState->board[x][0]->setPiece(0);
							newState->board[x][2]->setPiece(newState->board[x][4]->getPiece());
							newState->board[x][4]->setPiece(0);
							newState->calculateHashCode();
							label2 += "O-O-O ";
							labels->push_back(label2);
							ret.push_back(newState);
							continue;
						}
						else if(y == i - 2){ // King side castles
							newState->board[x][5]->setPiece(newState->board[x][7]->getPiece());
							newState->board[x][7]->setPiece(0);
							newState->board[x][6]->setPiece(newState->board[x][4]->getPiece());
							newState->board[x][4]->setPiece(0);
							newState->calculateHashCode();
							label2 += "O-O ";
							labels->push_back(label2);
							ret.push_back(newState);
							continue;
						}
						if(whosTurn == 1){
							static_cast<King*>(newState->whiteKingPos->getPiece())->setWasMoved();
							newState->whiteKingPos = newState->board[x][y];
						}
						else{
							static_cast<King*>(newState->blackKingPos->getPiece())->setWasMoved();
							newState->blackKingPos = newState->board[x][y];
						}
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						newState->calculateHashCode();
						labels->push_back(label2);
						ret.push_back(newState);
					}
				}
				else{ // Other pieces
					for(int v=0; v<possibleSquares.size(); v++){
						int x, y;
						x = possibleSquares[v]->getX();
						y = possibleSquares[v]->getY();
						label2 = label1;
						label2 += char('a' + y);
						label2 += char('8' - x);
						label2 += " ";
						newState = new Board(this);
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), capturedPiece), newState->pieces.end());
							delete capturedPiece;
							label2 += "x ";
						}
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						if(whosTurn == 1){
							if(static_cast<King*>(newState->whiteKingPos->getPiece())->isInCheck(newState, newState->whiteKingPos)){
								delete newState;
								continue;
							}
						}
						else{
							if(static_cast<King*>(newState->blackKingPos->getPiece())->isInCheck(newState, newState->blackKingPos)){
								delete newState;
								continue;
							}
						}
						newState->calculateHashCode();
						labels->push_back(label2);
						ret.push_back(newState);
					}
				}
				possibleSquares.clear();
			}
	return ret;
}

void Board::calculateHashCode(){
	std::string gameStateString = (whosTurn == 1) ? "1" : "0";
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

	stringHashCode = sha256(gameStateString);

	hashCode = 5381; // Big thanks : http://www.cse.yorku.ca/~oz/hash.html
	int c;
	while (c = *gameStateByteSha256++)
		hashCode = ((hashCode << 5) + hashCode) + c; /* hash * 33 + c */

	delete [] gameStateByteSha256;
}

Board::~Board(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
			delete board[i][j];
		delete [] board[i];
	}
	delete [] board;
	for(int i=0; i<pieces.size(); i++)
		delete pieces[i];
	pieces.clear();
}