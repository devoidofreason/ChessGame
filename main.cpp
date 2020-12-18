#include <iostream>
#include <conio.h>
#include "include\\Game.h"

using namespace std;

int main(){
	Game *G = new Game();
	//G->testGame("log.txt");
	G->performGame();
	delete G;
	system("pause");
	return 0;
}