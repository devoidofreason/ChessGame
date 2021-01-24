#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include "sha256.h" // Big thanks to Mr. Olivier Gay
// http://www.zedwood.com/article/cpp-sha256-function

#include <iostream>
#include <algorithm>
#include <cstdlib>

Board::Board(){
	board = new Square** [8];
	for(int i=0; i<8; i++){
		board[i] = new Square* [8];
		for(int j=0; j<8; j++)
			board[i][j] = new Square(i, j);
	}

	/*

	int owner = -1;
	Piece* newPiece;

	newPiece = new King(owner);
	pieces.push_back(newPiece);
	board[0][4]->setPiece(newPiece);

	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[0][0]->setPiece(newPiece);

	newPiece = new Pawn(owner);
	pieces.push_back(newPiece);
	board[1][0]->setPiece(newPiece);

	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[0][7]->setPiece(newPiece);

	newPiece = new Pawn(owner);
	pieces.push_back(newPiece);
	board[1][7]->setPiece(newPiece);

	owner = 1;

	newPiece = new King(owner);
	pieces.push_back(newPiece);
	board[7][4]->setPiece(newPiece);

	

	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[7][7]->setPiece(newPiece);

	newPiece = new Pawn(owner);
	pieces.push_back(newPiece);
	board[6][7]->setPiece(newPiece);

	newPiece = new Rook(owner);
	pieces.push_back(newPiece);
	board[7][0]->setPiece(newPiece);

	newPiece = new Pawn(owner);
	pieces.push_back(newPiece);
	board[6][0]->setPiece(newPiece);

	blackKingPos = board[0][4];
	whiteKingPos = board[7][4];

	*/

	whosTurn = 1;
	capturedPiece = 0;

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
	prevHashes.push_back(hashCode);
}

Board::Board(Board* parent){
	board = new Square** [8];
	for(int i=0; i<8; i++){
		board[i] = new Square* [8];
		for(int j=0; j<8; j++)
			board[i][j] = new Square(i, j);
	}

	whosTurn = -parent->whosTurn;
	capturedPiece = 0;

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
	for(int i=0; i<parent->prevHashes.size(); i++)
		prevHashes.push_back(parent->prevHashes[i]);
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
			if(board[i][j] == square1 || board[i][j] == square2)
				std::cout << "<";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";
}

std::vector<Board*> Board::generateChildren(){
	std::vector<std::string> v;
	std::vector<Board*> ret = generateChildren(&v);
	v.clear();
	return ret;
}

std::vector<Board*> Board::generateChildren(std::vector<std::string>* labels){
	Board* newState;
	std::vector<Board*> ret;
	Piece* piece;
	Piece* capturedPiece;
	std::vector<Square*> possibleSquares;
	std::string label1, label2;
	for(int i=0; i<pieces.size(); i++)
		if(whosTurn == pieces[i]->getOwner() && pieces[i]->getCodeText() == 'P')
			static_cast<Pawn*>(pieces[i])->disallowCaptureEnPassant();
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++){
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
						if(capturedPiece = newState->board[x][y]->getPiece()){
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), capturedPiece), newState->pieces.end());
							newState->capturedPiece = capturedPiece->getCodeText();
							delete capturedPiece;
							label2 += "x ";
						}
						else if(y != j && !newState->board[x][y]->getPiece()){ // En passant - execute
							capturedPiece = newState->board[i][y]->getPiece();
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), capturedPiece), newState->pieces.end());
							newState->capturedPiece = capturedPiece->getCodeText();
							delete capturedPiece;
							newState->board[i][y]->setPiece(0);
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
							newState->prevHashes.push_back(newState->hashCode);
							newState->square1 = newState->board[i][j];
							newState->square2 = newState->board[x][y];
							label2 += "xEn ";
							labels->push_back(label2);
							ret.push_back(newState);
							continue;
						}
						if( x == i - (2 * piece->getOwner()) ) // En passant - allow
							static_cast<Pawn*>(newState->board[i][j]->getPiece())->enableCaptureEnPassant();
						if(x == 0 || x == 7){ // Promotion
							newState->whosTurn = -newState->whosTurn;
							std::string tmp;
							Piece* newPiece;
							Board* newStateAfterPromotion;
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), newState->board[i][j]->getPiece()), newState->pieces.end());
							delete newState->board[i][j]->getPiece();
							newState->board[i][j]->setPiece(0);
							// Queen
							newStateAfterPromotion = new Board(newState);
							newPiece = new Queen(piece->getOwner());
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[x][y]->setPiece(newPiece);
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
							newState->prevHashes.push_back(newState->hashCode);
							newStateAfterPromotion->square1 = newState->board[i][j];
							newStateAfterPromotion->square2 = newState->board[x][y];
							tmp = label2 + " -> Q";
							labels->push_back(tmp);
							ret.push_back(newStateAfterPromotion);
							// Rook
							newStateAfterPromotion = new Board(newState);
							newPiece = new Rook(piece->getOwner());
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[x][y]->setPiece(newPiece);
							newStateAfterPromotion->calculateHashCode();
							newState->prevHashes.push_back(newState->hashCode);
							newStateAfterPromotion->square1 = newState->board[i][j];
							newStateAfterPromotion->square2 = newState->board[x][y];
							tmp = label2 + " -> R";
							labels->push_back(tmp);
							ret.push_back(newStateAfterPromotion);
							// Bishop
							newStateAfterPromotion = new Board(newState);
							newPiece = new Bishop(piece->getOwner());
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[x][y]->setPiece(newPiece);
							newStateAfterPromotion->calculateHashCode();
							newState->prevHashes.push_back(newState->hashCode);
							newStateAfterPromotion->square1 = newState->board[i][j];
							newStateAfterPromotion->square2 = newState->board[x][y];
							tmp = label2 + " -> B";
							labels->push_back(tmp);
							ret.push_back(newStateAfterPromotion);
							// Knight
							newStateAfterPromotion = new Board(newState); 
							newPiece = new Knight(piece->getOwner());
							newStateAfterPromotion->pieces.push_back(newPiece);
							newStateAfterPromotion->board[x][y]->setPiece(newPiece);
							newStateAfterPromotion->calculateHashCode();
							newState->prevHashes.push_back(newState->hashCode);
							newStateAfterPromotion->square1 = newState->board[i][j];
							newStateAfterPromotion->square2 = newState->board[x][y];
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
						newState->prevHashes.push_back(newState->hashCode);
						newState->square1 = newState->board[i][j];
						newState->square2 = newState->board[x][y];
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
							newState->pieces.erase(std::remove(newState->pieces.begin(), newState->pieces.end(), capturedPiece), newState->pieces.end());
							newState->capturedPiece = capturedPiece->getCodeText();
							delete capturedPiece;
							label2 += "x ";
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
						newState->prevHashes.push_back(newState->hashCode);
						newState->square1 = newState->board[i][j];
						newState->square2 = newState->board[x][y];
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
							newState->capturedPiece = capturedPiece->getCodeText();
							delete capturedPiece;
							label2 += "x ";
						}
						if(y == j - 2){ // Queen side castles
							newState->board[x][3]->setPiece(newState->board[x][0]->getPiece());
							newState->board[x][0]->setPiece(0);
							newState->board[x][2]->setPiece(newState->board[x][4]->getPiece());
							newState->board[x][4]->setPiece(0);
							if(whosTurn == 1){
								newState->whiteKingPos = newState->board[x][2];
								static_cast<King*>(newState->whiteKingPos->getPiece())->setWasMoved();
							}
							else{
								newState->blackKingPos = newState->board[x][2];
								static_cast<King*>(newState->blackKingPos->getPiece())->setWasMoved();
							}
							newState->calculateHashCode();
							newState->prevHashes.push_back(newState->hashCode);
							newState->square1 = newState->board[i][j];
							newState->square2 = newState->board[x][y];
							label2 += "O-O-O ";
							labels->push_back(label2);
							ret.push_back(newState);
							continue;
						}
						else if(y == j + 2){ // King side castles
							newState->board[x][5]->setPiece(newState->board[x][7]->getPiece());
							newState->board[x][7]->setPiece(0);
							newState->board[x][6]->setPiece(newState->board[x][4]->getPiece());
							newState->board[x][4]->setPiece(0);
							if(whosTurn == 1){
								newState->whiteKingPos = newState->board[x][6];
								static_cast<King*>(newState->whiteKingPos->getPiece())->setWasMoved();
							}
							else{
								newState->blackKingPos = newState->board[x][6];
								static_cast<King*>(newState->blackKingPos->getPiece())->setWasMoved();
							}
							newState->calculateHashCode();
							newState->prevHashes.push_back(newState->hashCode);
							newState->square1 = newState->board[i][j];
							newState->square2 = newState->board[x][y];
							label2 += "O-O ";
							labels->push_back(label2);
							ret.push_back(newState);
							continue;
						}
						static_cast<King*>(newState->board[i][j]->getPiece())->setWasMoved();
						newState->board[x][y]->setPiece(newState->board[i][j]->getPiece());
						newState->board[i][j]->setPiece(0);
						if(whosTurn == 1)
							newState->whiteKingPos = newState->board[x][y];
						else
							newState->blackKingPos = newState->board[x][y];
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
						newState->prevHashes.push_back(newState->hashCode);
						newState->square1 = newState->board[i][j];
						newState->square2 = newState->board[x][y];
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
							newState->capturedPiece = capturedPiece->getCodeText();
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
						newState->prevHashes.push_back(newState->hashCode);
						newState->square1 = newState->board[i][j];
						newState->square2 = newState->board[x][y];
						labels->push_back(label2);
						ret.push_back(newState);
					}
				}
				possibleSquares.clear();
			}
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

	std::string stringHashCode = sha256(gameStateString);

	hashCode = 5381; // Big thanks : http://www.cse.yorku.ca/~oz/hash.html
	int c;
	while (c = *gameStateByteSha256++)
		hashCode = ((hashCode << 5) + hashCode) + c; /* hash * 33 + c */
}

int Board::getStatus(){
	int sumWhite = 0;
	int sumBlack = 0;
	std::vector<Board*> children = generateChildren();
	if(prevHashes.size() > 4){
		int* ocurred = new int[prevHashes.size()];
		for(int i=0; i<prevHashes.size(); i++)
			ocurred[i] = 0;
		for(int i=0; i<prevHashes.size(); i++)
			for(int j=0; j<prevHashes.size(); j++)
				if(i != j && prevHashes[j] == prevHashes[i])
					ocurred[i] ++;
		for(int i=0; i<prevHashes.size(); i++)
			if( !(ocurred[i] < 2) ){
				return DRAW;
			}
		delete [] ocurred;
	}
	for(int i=0; i<pieces.size(); i++){
		if(pieces[i]->getCodeText() == 'P'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 1000;
			else
				sumBlack += 1000;
		}
		else if(pieces[i]->getCodeText() == 'Q'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 1000;
			else
				sumBlack += 1000;
		}
		else if(pieces[i]->getCodeText() == 'R'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 1000;
			else
				sumBlack += 1000;
		}
		else if(pieces[i]->getCodeText() == 'B'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 3;
			else
				sumBlack += 3;
		}
		else if(pieces[i]->getCodeText() == 'N'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 3;
			else
				sumBlack += 3;
		}
	}
	int ret = -1;
	if(sumWhite < 6 && sumBlack < 6)
		ret = DRAW;
	else if(children.size())
		ret = 0;
	else{
		if(whosTurn == 1){
			if(static_cast<King*>(whiteKingPos->getPiece())->isInCheck(this, whiteKingPos))
				ret = BLACK_WINS;
			else
				ret = DRAW;
		}
		else{
			if(static_cast<King*>(blackKingPos->getPiece())->isInCheck(this, blackKingPos))
				ret = WHITE_WINS;
			else
				ret = DRAW;
		}
	}
	for(int i=0; i<children.size(); i++)
		delete children[i];
	children.clear();
	return ret;
}

bool Board::drawBy3FoldRepetition(){
	if(prevHashes.size() > 4){
		int* ocurred = new int[prevHashes.size()];
		for(int i=0; i<prevHashes.size(); i++)
			ocurred[i] = 0;
		for(int i=0; i<prevHashes.size(); i++)
			for(int j=0; j<prevHashes.size(); j++)
				if(i != j && prevHashes[j] == prevHashes[i])
					ocurred[i] ++;
		for(int i=0; i<prevHashes.size(); i++)
			if( !(ocurred[i] < 2) ){
				return true;
			}
		delete [] ocurred;
	}
	return false;
}

bool Board::drawByInsufficientMaterial(){
	int sumWhite = 0;
	int sumBlack = 0;
	for(int i=0; i<pieces.size(); i++){
		if(pieces[i]->getCodeText() == 'P'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 1000;
			else
				sumBlack += 1000;
		}
		else if(pieces[i]->getCodeText() == 'Q'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 1000;
			else
				sumBlack += 1000;
		}
		else if(pieces[i]->getCodeText() == 'R'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 1000;
			else
				sumBlack += 1000;
		}
		else if(pieces[i]->getCodeText() == 'B'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 3;
			else
				sumBlack += 3;
		}
		else if(pieces[i]->getCodeText() == 'N'){
			if(pieces[i]->getOwner() == 1)
				sumWhite += 3;
			else
				sumBlack += 3;
		}
	}
	if(sumWhite < 6 && sumBlack < 6)
		return true;
	return false;
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