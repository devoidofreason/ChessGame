#ifndef KNIGHTHEURISTIC_H
#define KNIGHTHEURISTIC_H

#include "SquareDependentHeuristic.h"

class KnightHeuristic : public SquareDependentHeuristic
{
public:
	float evaluatePiece(Board*, Square*) override;
};

#endif