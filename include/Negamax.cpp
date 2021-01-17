#include "Negamax.h"
#include "SortHeuristic.h"

#include <vector>
#include <omp.h>
#include <algorithm>

Negamax::Negamax(int depth, HeuristicComposer* h){
	this->depth = depth;
	this->h = h;
}

Board* Negamax::getBestMove(Board* board){
	std::string column1, column2;
	std::vector<Board*> children = board->generateChildren();
	#pragma omp parallel
	{
		#pragma omp single
		{
			for(int i=0; i<children.size(); i++)
				#pragma omp task
				children[i]->evaluation = -negamaxStep(children[i], depth, -INF, INF);
			#pragma omp taskwait
		}
	}
	Board* ret = children[0];
	float max = ret->evaluation;
	for(int i=0; i<children.size(); i++)
		if(max < children[i]->evaluation){
			max = children[i]->evaluation;
			ret = children[i];
		}
	for(int i=0; i<children.size(); i++)
		if(children[i] != ret)
			delete children[i];
	children.clear();
	return ret;
}

bool compareStates(Board* b1, Board* b2){
	SortHeuristic sortHeuristic;
	return sortHeuristic.evaluatePosition(b1) > sortHeuristic.evaluatePosition(b2);
}

float Negamax::negamaxStep(Board* board, int depth, float alpha, float beta){
	if(depth == 0 || board->getStatus() != 0)
		return h->getEvaluation(board);
	float val = -INF;
	std::vector<Board*> children = board->generateChildren();
	std::sort(children.begin(), children.end(), compareStates);
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
	delete h;
}