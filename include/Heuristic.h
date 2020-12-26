#ifndef HEURISTIC_H
#define HEURISTIC_H
#include "Board.h"

#define	INF	1000000000.0f

class Heuristic
{
public:
	float gameStatusValue(Board*);
	virtual float evaluatePosition(Board*) = 0;
};

#endif