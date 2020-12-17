#ifndef HEURISTIC_H
#define HEURISTIC_H
#include "Board.h"

class Heuristic
{
public:
	virtual float evaluatePosition() = 0;
};

#endif