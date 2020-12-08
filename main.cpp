#include <stdlib.h>
#include "include\\Board.h"

using namespace std;

int main(){
	Board *A = new Board();
	A->printBoard();
	delete A;
	system("pause");
	return 0;
}