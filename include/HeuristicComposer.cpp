#include "HeuristicComposer.h"
#include "MaterialHeuristic.h"
#include "ActivityHeuristic.h"
#include "PawnHeuristic.h"
#include "KnightHeuristic.h"
#include "BishopHeuristic.h"
#include "RookHeuristic.h"
#include "QueenHeuristic.h"
#include "KingHeuristic.h"

HeuristicComposer::HeuristicComposer(bool m, bool h1, bool h2, bool h3, bool h4, bool h5, bool h6, bool h7){
	this->m = m;
	h = new MaterialHeuristic();
	computed.push_back(h1);
	computed.push_back(h2);
	computed.push_back(h3);
	computed.push_back(h4);
	computed.push_back(h5);
	computed.push_back(h6);
	computed.push_back(h7);
	heuristics.push_back(new ActivityHeuristic());
	heuristics.push_back(new PawnHeuristic());
	heuristics.push_back(new KnightHeuristic());
	heuristics.push_back(new BishopHeuristic());
	heuristics.push_back(new RookHeuristic());
	heuristics.push_back(new QueenHeuristic());
	heuristics.push_back(new KingHeuristic());
}

float HeuristicComposer::getEvaluation(Board* board, int gameStatus, int depth){
	float ret = 0.0f;
	if(gameStatus == WHITE_WINS)
		return (INF + (100.0f * (float)depth) ) * board->whosTurn;
	else if(gameStatus == BLACK_WINS)
		return -(INF + (100.0f * (float)depth) ) * board->whosTurn;
	else if(gameStatus == DRAW)
		return 0.0f;
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