#ifndef NEGAMAX_H
#define NEGAMAX_H
#include "Heuristic.h"
#include "Board.h"

class Negamax
{
public:
	Negamax(int);
	Board* getBestMove(Board*);
	float negamaxStep(Board*, int, float, float);
	Heuristic* heuristic;
	~Negamax();
private:
	int depth;
	bool compareStates(Board*, Board*);
};

#endif