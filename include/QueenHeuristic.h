#ifndef QUEENHEURISTIC_H
#define QUEENHEURISTIC_H

#include "SquareDependentHeuristic.h"

class QueenHeuristic : public SquareDependentHeuristic
{
public:
	float evaluatePiece(Board*, Square*) override;
};

#endif