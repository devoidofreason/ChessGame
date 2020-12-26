#include "Negamax.h"
#include "MaterialHeuristic.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <conio.h>

Negamax::Negamax(int depth){
	this->depth = depth;
	heuristic = new MaterialHeuristic();
	srand(time(0));
}

Board* Negamax::getBestMove(Board* board){
	std::string column1, column2;

	std::vector<Board*> children = board->generateChildren();

	for(int i=0; i<children.size(); i++)
		children[i]->evaluation = -negamaxStep(children[i], depth, -INF, INF);
	Board* ret = children[ rand() % children.size() ];
	float max = ret->evaluation;
	for(int i=0; i<children.size(); i++)
		if(max < children[i]->evaluation){
			max = children[i]->evaluation;
			ret = children[i];
		}
	// Free mem
	/*
	board->printBoard();
	for(int i=0; i<labels.size()/2; i++){
		column1 = ( (i < 10) ? " " : "" );
		column1 += std::to_string(i);
		column1 += " : ";
		column1 += labels[i];
		column2 = ( (i + labels.size()/2  < 10) ? " " : "" );
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
	for(int i=0; i<children.size(); i++){
		std::cout << i << " : " << statesEvaluations[i] << "\n";
	}
	getche();
	*/
	for(int i=0; i<children.size(); i++)
		if(children[i] != ret)
			delete children[i];
	children.clear();
	return ret;
}

float Negamax::negamaxStep(Board* board, int depth, float alpha, float beta){
	if(depth == 0 || board->getStatus() != 0)
		return heuristic->evaluatePosition(board);
	float val = -INF;
	std::vector<Board*> children = board->generateChildren();
	for(int i=0; i<children.size(); i++){
		float tmp = -negamaxStep(children[i], depth - 1, -beta, -alpha);
		if(tmp > val)
			val = tmp;
		if(val > alpha)
			alpha = val;
		if(alpha >= beta){
			for(int i=0; i<children.size(); i++)
				delete children[i];
			children.clear();
			return alpha;
		}
	}
	// Free mem
	for(int i=0; i<children.size(); i++)
		delete children[i];
	children.clear();
	return val;
}

Negamax::~Negamax(){
	delete heuristic;
}

bool Negamax::compareStates(Board* b1, Board* b2){

}