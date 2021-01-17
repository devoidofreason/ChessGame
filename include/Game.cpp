#include "Piece.h"
#include "HeuristicComposer.h"
#include "Game.h"

#include <iostream>
#include <fstream>

Game::Game(bool humanPlayerWhite, bool humanPlayerBlack){
	board = new Board();
	negamax = new Negamax(3, new HeuristicComposer(true, true, true, true));
	// MaterialHeuristic, ActivityHeuristic, PawnHeuristic, KnightHeuristic
	this->humanPlayerWhite = humanPlayerWhite;
	this->humanPlayerBlack = humanPlayerBlack;
}

void Game::performGame(){
	while(board->getStatus() == 0){
		if(board->whosTurn == 1){
			if(humanPlayerWhite)
				performHumanMove();
			else
				performAiMove();
		}
		else{
			if(humanPlayerBlack)
				performHumanMove();
			else
				performAiMove();
		}
	}
	int status = board->getStatus();
	board->printBoard();
	HeuristicComposer* m = negamax->h;
	std::cout << "Evalutaion : " << board->whosTurn * m->getEvaluation(board) << "\n";
	if(status == DRAW)
		std::cout << "Draw.\n";
	else if(status == WHITE_WINS)
		std::cout << "White wins by checkmate.\n";
	else if(status == BLACK_WINS)
		std::cout << "Black wins by checkmate.\n";
}

void Game::performHumanMove(){
	std::vector<std::string> labels;
	std::vector<Board*> children = board->generateChildren(&labels);
	std::string column1, column2;
	int c;
	board->printBoard();
	HeuristicComposer* m = negamax->h;
	std::cout << "Evalutaion : " << board->whosTurn * m->getEvaluation(board) << "\n";
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

void Game::performAiMove(){
	board->printBoard();
	HeuristicComposer* m = negamax->h;
	std::cout << "Evalutaion : " << board->whosTurn * m->getEvaluation(board) << "\n";
	Board* tmp = board;
	board = negamax->getBestMove(board);
	delete tmp;
}

Game::~Game(){
	delete board;
	delete negamax;
}