#ifndef PAWNHEURISTIC_H
#define PAWNHEURISTIC_H

#include "SquareDependentHeuristic.h"

class PawnHeuristic : public SquareDependentHeuristic
{
public:
	float evaluatePiece(Board*, Square*) override;
};

#endif