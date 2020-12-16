#include "Game.h"
#include "King.h"
#include <iostream>
#include <string>
#include <conio.h>

Game::Game(){
	board = new Board();
	humanPlayerWhite = true;
	humanPlayerBlack = true;
}

void Game::performGame(){
	std::vector<Board*> children = board->generateChildren();
	while(children.size()){
		gameStory.push_back(board->hashCode);
		for(int i=0; i<children.size(); i++)
			delete children[i];
		children.clear();
		if(board->whosTurn == 1){
			if(humanPlayerWhite)
				performHumanMove();
			else;
		}
		else{
			if(humanPlayerBlack)
				performHumanMove();
			else;
		}
		if(gameStory.size() > 4){
			int* ocurred = new int[gameStory.size()];
			for(int i=0; i<gameStory.size(); i++)
				ocurred[i] = 0;
			for(int i=0; i<gameStory.size(); i++)
				for(int j=0; j<gameStory.size(); j++)
					if(gameStory[j] == gameStory[i])
						ocurred[i] ++;
			for(int i=0; i<gameStory.size(); i++)
				if( !(ocurred[i] < 3) ){
					std::cout << "Draw\n";
					return;
				}
		}
		children = board->generateChildren();
	}
	if(static_cast<King*>(board->whiteKingPos->getPiece())->isInCheck(board, board->whiteKingPos))
		std::cout << "Black won!!!\n";
	else if(static_cast<King*>(board->blackKingPos->getPiece())->isInCheck(board, board->blackKingPos))
		std::cout << "White won!!!\n";
	else
		std::cout << "Draw!!!\n";
}

bool Game::performHumanMove(){
	std::vector<std::string> labels;
	std::vector<Board*> children = board->generateChildren(&labels);
	std::string column1, column2;
	board->printBoard();
	int c = -1;
	for(int i=0; i<labels.size()/2; i++){
		column1 = ( (i < 10) ? " " : "" );
		column1 += std::to_string(i);
		column1 += " : ";
		column1 += labels[i];
		column2 = ( (i + labels.size()/2 < 10) ? " " : "" );
		column2 += std::to_string(i + labels.size()/2);
		column2 += " : ";
		column2 += labels[i + labels.size()/2];
		std::cout << column1;
		for(int j=column1.length(); j<35; j++)
			std::cout << " ";
		std::cout << column2 << "\n";
	}
	if(labels.size() % 2 == 1){
		for(int j=0; j<35; j++)
			std::cout << " ";
		std::cout << labels.size() - 1 << " : " << labels[labels.size() - 1] << "\n";
	}
	std::cin >> c;
	delete board;
	board = children[c];
	for(int i=0; i<children.size(); i++)
		if(children[i] != board)
			delete children[i];
	children.clear();
	labels.clear();
}

Game::~Game(){
	delete board;
	gameStory.clear();
}