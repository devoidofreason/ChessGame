#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "Board.h"

class Heuristic
{
public:
	virtual float evaluatePosition(Board*) = 0;
};

#endif