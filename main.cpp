#include <stdlib.h>
#include <iostream>
#include "include\\Board.h"

using namespace std;

int main(){
	Board* A = new Board();
	Board* B = new Board(A);
	B->printBoard();
	std::string test;
	while(std::cin >> test)
		B->printBoard(B->resolveSquareCode(test));
	delete A;
	delete B;
	system("pause");
	return 0;
}