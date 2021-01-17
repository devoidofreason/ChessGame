#ifndef HEURISTICCOMPOSER_H
#define HEURISTICCOMPOSER_H

#include "Heuristic.h"
#include "SquareDependentHeuristic.h"
#include "Board.h"

#include <vector>

#define	INF	1000000000.0f

class HeuristicComposer
{
public:
	HeuristicComposer(bool, bool, bool, bool);
	// MaterialHeuristic, ActivityHeuristic, PawnHeuristic, KnightHeuristic
	float getEvaluation(Board*);
	~HeuristicComposer();
private:
	std::vector<bool> computed;
	std::vector<SquareDependentHeuristic*> heuristics;
	Heuristic* h;
	bool m;
};

#endif