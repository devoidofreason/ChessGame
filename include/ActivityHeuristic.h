#ifndef ACTIVITYHEURISTIC_H
#define ACTIVITYHEURISTIC_H

#include "SquareDependentHeuristic.h"

class ActivityHeuristic : public SquareDependentHeuristic
{
public:
	float evaluatePiece(Board*, Square*) override;
};

#endif