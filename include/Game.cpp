#include "Game.h"
#include <iostream>
#include <conio.h>

Game::Game(){
	board = new Board();
	humanPlayerWhite = true;
	humanPlayerBlack = true;
}

void Game::performGame(){
	std::vector<Board*> properChildren = board->generateChildren();
	while(properChildren.size()){
		properChildren.clear();
		performHumanMove();
		properChildren = board->generateChildren();
	}
	std::cout << "No more chilrden...\n";
}

bool Game::performHumanMove(){
	std::vector<std::string> labels;
	std::vector<Board*> chilrden = board->generateChildren(&labels);
	board->printBoard();
	int c = -1;
	for(int i=0; i<labels.size(); i++){
		std::cout << ( (i<10) ? " " : "" ) << i << " : " << labels[i] << "\t\t";
		if(i % 2)
			std::cout << "\n";
	}
	std::cin >> c;
	delete board;
	labels.clear();
	board = chilrden[c];
}

Game::~Game(){
	delete board;
}