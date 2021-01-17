#ifndef NEGAMAX_H
#define NEGAMAX_H

#include "HeuristicComposer.h"
#include "Board.h"

class Negamax
{
public:
	Negamax(int, HeuristicComposer*);
	// MaterialHeuristic, ActivityHeuristic
	Board* getBestMove(Board*);
	float negamaxStep(Board*, int, float, float);
	HeuristicComposer* h;
	~Negamax();
private:
	int depth;
};

#endif