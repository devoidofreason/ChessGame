#include "include\\Game.h"

using namespace std;

int main(){
	Game *G = new Game();
	G->performGame();
	delete G;
	system("pause");
	return 0;
}