#ifndef BISHOPHEURISTIC_H
#define BISHOPHEURISTIC_H

#include "SquareDependentHeuristic.h"

class BishopHeuristic : public SquareDependentHeuristic
{
public:
	float evaluatePiece(Board*, Square*) override;
};

#endif