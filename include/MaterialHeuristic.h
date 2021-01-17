#ifndef MATERIALHEURISTIC_H
#define MATERIALHEURISTIC_H

#include "Heuristic.h"

class MaterialHeuristic : public Heuristic
{
public:
	float evaluatePosition(Board*) override;
};

#endif