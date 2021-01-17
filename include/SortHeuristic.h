#ifndef SORTHEURISTIC_H
#define SORTHEURISTIC_H

#include "Heuristic.h"

class SortHeuristic : public Heuristic
{
public:
	float evaluatePosition(Board*) override;
};

#endif