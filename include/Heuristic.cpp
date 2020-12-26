#include "Heuristic.h"

float Heuristic::gameStatusValue(Board* board){
	int status = board->getStatus();
	if(status == WHITE_WINS)
		return INF;
	else if(status == BLACK_WINS)
		return -INF;
	return 0.0f;
}