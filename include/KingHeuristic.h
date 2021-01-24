#ifndef KINGHEURISTIC_H
#define KINGHEURISTIC_H

#include "SquareDependentHeuristic.h"

class KingHeuristic : public SquareDependentHeuristic
{
public:
	float evaluatePiece(Board*, Square*) override;
};

#endif