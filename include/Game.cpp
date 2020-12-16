#include "Game.h"
#include <iostream>
#include <string>
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
	for(int i=0; i<labels.size()/2; i++){
		std::string column1 = ( (i < 10) ? " " : "" );
		column1 += std::to_string(i);
		column1 += " : ";
		column1 += labels[i];
		std::string column2 = ( (i + labels.size()/2 < 10) ? " " : "" );
		column2 += std::to_string(i + labels.size()/2);
		column2 += " : ";
		column2 += labels[i + labels.size()/2];
		std::cout << column1;
		for(int j=column1.length(); j<35; j++)
			std::cout << " ";
		std::cout << column2 << "\n";
	}
	if(labels.size() % 2 == 1){
		for(int i=0; i<35; i++)
			std::cout << " ";
		std::cout << labels.size() - 1 << " : " << labels[labels.size() - 1] << "\n";
	}
	std::cin >> c;
	delete board;
	labels.clear();
	board = chilrden[c];
}

Game::~Game(){
	delete board;
}