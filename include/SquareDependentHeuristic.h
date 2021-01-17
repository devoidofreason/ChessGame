#ifndef SQUAREDEPENDENTHEURISTIC_H
#define SQUAREDEPENDENTHEURISTIC_H

#include "Board.h"

class SquareDependentHeuristic
{
public:
	virtual float evaluatePiece(Board*, Square*) = 0;
protected:
	float ABS(float);
};

#endif