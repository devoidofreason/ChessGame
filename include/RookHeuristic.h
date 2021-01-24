#ifndef ROOKHEURISTIC_H
#define ROOKHEURISTIC_H

#include "SquareDependentHeuristic.h"

class RookHeuristic : public SquareDependentHeuristic
{
public:
	float evaluatePiece(Board*, Square*) override;
};

#endif