#include "HeuristicComposer.h"
#include "MaterialHeuristic.h"
#include "ActivityHeuristic.h"
#include "PawnHeuristic.h"
#include "KnightHeuristic.h"

HeuristicComposer::HeuristicComposer(bool m, bool h1, bool h2, bool h3){
	this->m = m;
	h = new MaterialHeuristic();
	computed.push_back(h1);
	computed.push_back(h2);
	computed.push_back(h3);
	heuristics.push_back(new ActivityHeuristic());
	heuristics.push_back(new PawnHeuristic());
	heuristics.push_back(new KnightHeuristic());
}

float HeuristicComposer::getEvaluation(Board* board){
	int gameStatus = board->getStatus();
	if(gameStatus == WHITE_WINS)
		return INF * board->whosTurn;
	else if(gameStatus == BLACK_WINS)
		return -INF * board->whosTurn;
	else if(gameStatus == DRAW)
		return 0.0f;
	float ret = 0.0f;
	if(m)					// Square independent heuristic
		ret += h->evaluatePosition(board);
	for(int i=0; i<8; i++)	// Square dependent heuristics
		for(int j=0; j<8; j++)
			for(int k=0; k<heuristics.size(); k++)
				if(computed[k])
					ret += heuristics[k]->evaluatePiece(board, board->board[i][j]);
	return ret;
}

HeuristicComposer::~HeuristicComposer(){
	for(int i=0; i<heuristics.size(); i++)
		delete heuristics[i];
}